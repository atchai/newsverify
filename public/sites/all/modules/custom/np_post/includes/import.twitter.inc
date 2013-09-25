<?php
/**
 * @file
 * NewsPlatform Twitter import functionality
 */

/**
 * Twitter Fetcher
 */
class NPPostTwitterFetcher extends NPPostHTTPFetcher {

    public function __construct($url) {
        // Get tweet ID from URL
        if (preg_match('#(\d+)/?\s*$#', $url, $matches)) {
            $this->url = $this->buildUrl('https://api.twitter.com/1/statuses/oembed.json', array('id' => $matches[1]));
        }
    }
}

/**
 * Twitter Processor
 */
class NPPostTwitterProcessor extends NPPostProcessor {

    private $tid;

    public function __construct($url) {
        parent::__construct($url);
        $this->tid = $this->termLookup('provider', 'Twitter');
    }

    protected function process($item) {
        // Get tweet embed HTML
        $item->body_html = $item->html;
        $item->body_plain = strip_tags($item->html);

        // Provider (always Twitter)
        $item->provider_tid = $this->tid;

        // Get author
        $item->author_nid = $this->getAuthor($item, 'author_url', 'author_name', 'provider_tid');

        return $item;
    }

}
