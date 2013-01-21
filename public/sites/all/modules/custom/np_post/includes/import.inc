<?php
/**
 * @file
 * NewsPlatform social media post import functionality
 */

interface NPPostFetcherInterface {
    public function __construct($url);
    public function fetch();
}

/**
 * HTTP fetcher
 */
class NPPostHTTPFetcher implements NPPostFetcherInterface {

    protected $url = FALSE;

    public function __construct($url) {
        $this->url = $url;
    }

    /**
     * Request the resource and return the response body on success
     */
    public function fetch() {
        if ($this->url === FALSE) {
            return FALSE;
        }

        $response = $this->request($this->url);
        if ($response === FALSE) {
            return FALSE;

        } elseif (!in_array($response->code, array(200, 201, 202, 203, 204, 205, 206))) {
            watchdog('np_post', 'Importing @url failed with code @code',
                array('@url' => $this->url, '@code' => $response->code), WATCHDOG_ERROR);
            return FALSE;

        } elseif (empty($response->data)) {
            watchdog('np_post', 'Importing @url failed, response data was empty',
                array('@url' => $this->url), WATCHDOG_ERROR);
            return FALSE;
        }

        return $response->data;
    }

    /**
     * Wrapper function around HTTP request lib
     */
    protected function request($url) {
        module_load_include('inc', 'np_post', 'includes/http_request');
        try {
            $response = http_request_get($url);
        } catch (HRCurlException $e) {
            watchdog('np_post', 'Request for @url failed with: @msg',
                array('@url' => $url, '@msg' => $e->getMessage()), WATCHDOG_ERROR);
            return FALSE;
        }
        return $response;
    }

    /**
     * Helper function to build a URL with GET parameters
     */
    protected function buildUrl($url, $params) {
        return sprintf('%s?%s', $url, http_build_query($params));
    }
}

/**
 * Base class for importing a node
 */
class NPPostProcessor {

    // Constants
    const UNIMPORTED = 0x00;
    const CREATED = 0x01;
    const UPDATED = 0x02;

    protected static $postType = 'post';
    protected static $authorType = 'author';

    protected static $defaultAuthor = 'Anonymous';

    // Public properties
    public $post = FALSE;
    public $postStatus = FALSE;

    public $author = FALSE;
    public $authorSatus = FALSE;

    // Private properties
    protected $url;
    protected $lang = LANGUAGE_NONE;

    public function __construct($url) {
        $this->postStatus = self::UNIMPORTED;
        $this->authorStatus = self::UNIMPORTED;
        $this->url = $url;
    }

    /**
     * Run the import process
     */
    public function run($data) {
        $item = $this->parse($data);
        if ($item === FALSE) {
            return FALSE;
        }

        $item = $this->process($item);
        if ($item === FALSE) {
            return FALSE;
        }

        if ($this->getEntity($item) === FALSE) {
            return FALSE;
        }

        if ($this->mapFields($item) === FALSE) {
            return FALSE;
        }

        return $this->saveEntity();
    }

    /**
     * Parse the response data as JSON
     */
    public function parse(&$data) {
        $item = json_decode($data);
        if ($item === NULL) {
            watchdog('np_post', 'Unable to parse @url as JSON. Got: @data',
                array('@url' => $this->url, '@data' => $data), WATCHDOG_ERROR);
            return FALSE;
        }

        $item->url = $this->url;
        return $item;
    }

    /**
     * Stub function for processing the response object
     */
    protected function process($item) {
        return $item;
    }

    /**
     * Create a new entity or fetch an existing one based on the post URL
     */
    protected function getEntity(&$item) {
        // Check for existing node (match on node title)
        $fieldMap = $this->getFieldMap();
        $query = new EntityFieldQuery();
        $result = $query
            ->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', self::$postType)
            ->propertyCondition('title', $item->{$fieldMap['title']}, '=')
            ->execute();

        if (isset($result['node'])) {
            $nids = array_keys($result['node']);
            $this->post = node_load(array_shift($nids));
            if (!$this->post) {
                watchdog('np_post', 'Unable to load previous imported node for @url',
                    array('@url' => $this->url), WATCHDOG_ERROR);
                return FALSE;
            }
            $this->lang = $this->post->language;
            $this->postStatus = self::UPDATED;
        } else {
            // Build new node
            $this->post = new stdClass();
            $this->post->type = self::$postType;
            $this->post->changed = REQUEST_TIME;
            $this->post->created = REQUEST_TIME;
            $this->post->language = $this->lang;
            node_object_prepare($this->post);
            $this->post->log = 'Inital import';
            $this->postStatus = self::CREATED;
        }

        return TRUE;
    }

    /**
     * Define basic mapping of improted item's properties to entity fields
     */
    protected function getFieldMap() {
        return array(
            'title' => 'url',
            'field_post_body_plain' => array(
                'value' => 'body_plain',
                'other' => array(
                    'format' => 'plain_text',
                ),
            ),
            'field_post_body_html' => array(
                'value' => 'body_html',
                'other' => array(
                    'format' => 'html',
                ),
            ),
            'field_post_author' => array(
                'target_id' => 'author_nid',
            ),
            'field_post_provider' => array(
                'tid' => 'provider_tid',
            ),
        );
    }

    /**
     * Map item properties to entity fields
     */
    protected function mapFields(&$item) {
        foreach($this->getFieldMap() as $dst => $info) {
            if (is_array($info)) {
                $value = array();
                foreach($info as $col => $src) {
                    if ($col == 'other') {
                        $value += $src;
                    } elseif (!empty($item->{$src})) {
                        $value[$col] = $item->{$src};
                    }
                }
                if (count($value)) {
                    $this->post->{$dst} = array($this->lang => array($value));
                }
            } elseif (!empty($item->{$info})) {
                $this->post->{$dst} = $item->{$info};
            }
        }
        return TRUE;
    }

    /**
     * Save an entity and return its primary ID
     */
    protected function saveEntity() {
        $saved = entity_save('node', $this->post);
        if ($saved === FALSE) {
            watchdog('np_post', 'Unable to save entity when importing post',
                array('@url' => $this->url), WATCHDOG_ERROR);
            return FALSE;
        }
        return TRUE;
    }

    /**
     * Helper function to lookup a taxonomy term ID given a vocabulary and a term name
     */
    protected function termLookup($vocab, $name) {
        $vocab = taxonomy_vocabulary_machine_name_load($vocab);
        $query = new EntityFieldQuery();
        $result = $query
            ->entityCondition('entity_type', 'taxonomy_term')
            ->propertyCondition('vid', (int) $vocab->vid, '=')
            ->propertyCondition('name', $name, '=')
            ->execute();
        if (!isset($result['taxonomy_term'])) {
            return FALSE;
        }
        $tids = array_keys($result['taxonomy_term']);
        return array_shift($tids);
    }

    /**
     * Helper function to create an HTML paragraph
     */
    protected function createPara($text) {
        return sprintf('<p>%s</p>', check_plain($text));
    }

    /**
     * Helper function to create an HTML image (optionally linked)
     */
    protected function createImg($path, $alt = '', $url = FALSE) {
        $img = theme('image', array(
            'path' => $path,
            'alt' => $alt,
        ));
        if ($url !== FALSE) {
            $img = l(
                $img, $url,
                array('html' => TRUE, 'attributes' => array('target' => '_blank'))
            );
        }
        return $img;
    }

    /**
     * Create a new author entity or fetch an existing one based on the author URL
     */
    protected function getAuthor(&$item, $url_key, $name_key, $provider_key) {

        if (empty($item->{$url_key})) {
            // No author URL, so use default author
            $query = new EntityFieldQuery;
            $query->entityCondition('entity_type', 'node')
                ->entityCondition('bundle', self::$authorType)
                ->propertyCondition('title', self::$defaultAuthor);
            $result = $query->execute();

            if (empty($result['node'])) {
                watchdog('np_post', 'Unable to find default Author node when importing @url',
                    array('@url' => $item->url), WATCHDOG_ERROR);
                return FALSE;
            }

            $nids = array_keys($result['node']);
            $author_nid = array_shift($nids);

        } else {

            $url = $item->{$url_key};

            // Query field_accounts field_collection items on the author URL
            $query = new EntityFieldQuery;
            $query->entityCondition('entity_type', 'field_collection_item')
                ->entityCondition('bundle', 'field_accounts')
                ->fieldCondition('field_account_url', 'url', $url);
            $result = $query->execute();

            if (empty($result['field_collection_item'])) {
                // No existing Author found, so create a new one
                $name = FALSE;
                if (!empty($item->{$name_key})) {
                    $name = $item->{$name_key};
                }

                $provider = FALSE;
                if (!empty($item->{$provider_key})) {
                    $provider = $item->{$provider_key};
                }

                return $this->createAuthor($url, $name, $provider);
            }

            // Found existing author field_collection item so load
            $ids = array_keys($result['field_collection_item']);
            $author_account = field_collection_item_load(array_shift($ids));

            $author_nid = $author_account->hostEntityId();

        }

        // Load author node
        $this->author = node_load($author_nid);

        // Set status
        $this->authorStatus = self::UPDATED;

        // Return the parent entity's ID
        return $this->author->nid;
    }

    /**
     * Create a new author entity and associated field_collection item
     */
    protected function createAuthor($url, $name = FALSE, $provider = FALSE) {
        // Create new Author node
        $this->author = new stdClass();
        $this->author->type = self::$authorType;
        $this->author->changed = REQUEST_TIME;
        $this->author->created = REQUEST_TIME;
        $this->author->language = $this->lang;
        node_object_prepare($this->author);
        $this->author->log = 'Automtically created when importing Post';

        if ($name !== FALSE) {
            $this->author->title = $name;
        } else {
            $this->author->title = $url;
        }

        node_save($this->author);

        // Create new field_accounts field_collection item
        $item = entity_create('field_collection_item', array('field_name' => 'field_accounts'));
        $item->setHostEntity('node', $this->author);
        $item->field_account_url = array($this->lang => array(array('url' => $url)));

        if ($name !== FALSE) {
            $item->field_account_url[$this->lang][0]['title'] = $name;
        }

        if ($provider !== FALSE) {
            $item->field_account_provider = array($this->lang => array(array('tid' => $provider)));
        }

        $item->save();

        // Add field_collection item to Author node and save
        $this->author->field_accounts = array($this->lang => array(array('value' => $item->item_id)));
        node_save($this->author);

        // Set status
        $this->authorStatus = self::CREATED;

        return $this->author->nid;
    }

}

/**
 * Importer class that runs the fetcher and processor
 */
class NPPostImporter {

    private $url = FALSE;
    private $fetcher = FALSE;
    private $processor = FALSE;

    /**
     * Initialise importer with Facebook fetcher/parser when URL is for facebook.com
     * For all other URLs use the Embedly fetcher/parser
     */
    public function __construct($url) {
        $this->url = trim($url);
        $parts = @parse_url($this->url);

        if ($parts === FALSE || empty($parts['host'])) {
            drupal_set_message(t('Invalid post URL @url', array('@url' => $url)), 'error');

        } else if (in_array($parts['host'], array('www.facebook.com'))) {
            $this->fetcher = new NPPostFacebookFetcher($this->url);
            $this->processor = new NPPostFacebookProcessor($this->url);

        } else {
            $this->fetcher = new NPPostEmbedlyFetcher($this->url);
            $this->processor = new NPPostEmbedlyProcessor($this->url);

        }

    }

    /**
     * Run post import
     */
    public function import() {
        if ($this->url === FALSE || $this->fetcher === FALSE || $this->processor === FALSE) {
            return FALSE;
        }

        // Fetch post
        $data = $this->fetcher->fetch();
        if ($data !== FALSE) {

            // Import post
            $imported = $this->processor->run($data);
            if ($imported !== FALSE) {

                // Display success message
                $this->displaySuccessMessage();
                return TRUE;

            }

        }

        // Fetch/import failed so display error message
        drupal_set_message(t('Unable to import post @url', array('@url' => $this->url)), 'error');
        return FALSE;
    }

    /**
     * Get imported post ID
     */
    public function getPostId() {
        if (empty($this->processor->post->nid)) {
            return FALSE;
        }
        return $this->processor->post->nid;
    }

    /**
     * Display a message after a post has been imported successfully
     */
    private function displaySuccessMessage() {
        if ($this->processor->authorStatus == NPPostProcessor::CREATED) {
            $msg = 'Created new author !author';
        } else {
            $msg = 'Linked to author !author';
        }

        $link = l(
            $this->processor->author->title,
            sprintf('node/%d/edit', $this->processor->author->nid),
            array('attributes' => array('target' => '_blank'))
        );

        drupal_set_message(t($msg, array('!author' => $link)), 'status');
    }

}
