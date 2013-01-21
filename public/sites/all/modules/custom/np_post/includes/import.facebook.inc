<?php
/**
 * @file
 * NewsPlatform Facebook import functionality
 */

/**
 * Facebook fetcher
 */
class NPPostFacebookFetcher extends NPPostHTTPFetcher {

    public function __construct($url) {
        global $base_url;
        $fbid = FALSE;

        // Parse FB URL to determine content ID
        $parts = parse_url($url);
        if (!empty($parts['path'])) {
            if ($parts['path'] == '/photo.php') {
                $fbid = $this->getQueryParam('fbid', $parts);

            } elseif ($parts['path'] == '/permalink.php') {
                $story_fbid = $this->getQueryParam('story_fbid', $parts);
                $id = $this->getQueryParam('id', $parts);
                if ($story_fbid !== FALSE && $id !== FALSE) {
                    $fbid = sprintf('%d_%d', $id, $story_fbid);
                }

            } elseif (preg_match('#/posts/(\d+)$#', $parts['path'], $matches)) {
                $fbid = $matches[1];
            }
        }

        if ($fbid !== FALSE) {
            // Set FB graph API request url
            $this->url = sprintf('https://graph.facebook.com/%s', $fbid);

            // Get a FB OAuth token
            $params = array(
                'client_id' => variable_get('np_post_fb_id', ''),
                'client_secret' => variable_get('np_post_fb_secret', ''),
                'redirect_uri' => $base_url,
                'grant_type' => 'client_credentials',
            );
            $token_url = $this->buildUrl('https://graph.facebook.com/oauth/access_token', $params);
            $response = $this->request($token_url);
            if ($response->code == 200 && preg_match('#^access_token=#', $response->data)) {
                // Append OAuth token to graph API request URL
                $this->url .= '?' . $response->data;
            } else {
                $this->url = FALSE;
                watchdog('np_post', 'Unable to get access token from Facebook for @url',
                    array('@url' => $url), WATCHDOG_ERROR);
            }
        }
    }

    private function getQueryParam($key, &$parts) {
        if (empty($parts['query'])) {
            return FALSE;
        }
        parse_str($parts['query'], $query);
        if (empty($query[$key])) {
            return FALSE;
        }
        return $query[$key];
    }

}

/**
 * Facebook Processor
 */
class NPPostFacebookProcessor extends NPPostProcessor {

    private $tid;

    public function __construct($url) {
        parent::__construct($url);
        $this->tid = $this->termLookup('provider', 'Facebook');
    }

    protected function process($item) {
        // Plain text body
        if (!empty($item->message)) {
            $item->body_plain = $item->message;
        } elseif (!empty($item->description)) {
            $item->body_plain = $item->description;
        } elseif (!empty($item->about)) {
            $item->body_plain = $item->about;
        } elseif (!empty($item->name)) {
            $item->body_plain = $item->name;
        } else {
            $item->body_plain = '';
        }

        // HTML body
        $item->body_html = '';
        if (!empty($item->picture)) {
            $item->body_html .= $this->createImg($item->picture, $item->title, $item->url);
        }
        if (!empty($item->body_plain)) {
            $item->body_html .= $this->createPara($item->body_plain);
        }

        // Provider (always Facebook)
        $item->provider_tid = $this->tid;

        // Request author information
        if (!empty($item->from->id)) {
            $item->author_nid = $this->getFBUser($item->from->id);
        }

        return $item;
    }

    /**
     * Fetch a FB user from an ID and get/create an author node
     */
    private function getFBUser($fbid) {
        // Fetch author information
        $fetcher = new NPPostHTTPFetcher(sprintf('https://graph.facebook.com/%s', $fbid));
        $response = $fetcher->fetch();
        if ($response === FALSE) {
            return FALSE;
        }

        // Parse author response
        $item = $this->parse($response);
        if ($item === FALSE) {
            return FALSE;
        }

        // Verify the author has a URL
        if (empty($item->link)) {
            return FALSE;
        }

        // Use "username" property as author name, if available
        if (!empty($item->username)) {
            $item->name = $item->username;
        }

        // Set provider term ID
        $item->provider_tid = $this->tid;

        // Get/create author node and return ID
        return $this->getAuthor($item, 'link', 'name', 'provider_tid');
    }

}
