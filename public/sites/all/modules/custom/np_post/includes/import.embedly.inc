<?php
/**
 * @file
 * NewsPlatform Embedly import functionality
 */

/**
 * Embedly Fetcher
 */
class NPPostEmbedlyFetcher extends NPPostHTTPFetcher {
    public function __construct($url) {
        $params = array(
            'url' => $url,
            'maxwidth' => variable_get('np_post_embedly_width', ''),
            'key' => variable_get('np_post_embedly_key', ''),
        );
        $this->url = $this->buildUrl('http://api.embed.ly/1/oembed', $params);
    }
}

/**
 * Embdely Processor
 */
class NPPostEmbedlyProcessor extends NPPostProcessor {

    protected function getFieldMap() {
        // Alter base field mapping to directly use Embedly's plain text and description fields
        $fieldMap = parent::getFieldMap();
        $fieldMap['field_post_body_plain']['value'] = 'description';
        $fieldMap['field_post_body_html']['value'] = 'html';
        return $fieldMap;
    }

    protected function process($item) {
        // Create default HTML display if none is provided
        if (empty($item->html)) {
            $item->html = '';
            if (!empty($item->thumbnail_url)) {
                $item->html .= $this->createImg($item->thumbnail_url, $item->title, $item->url);
            }
            if (!empty($item->description)) {
                $item->html .= $this->createPara($item->description);
            }
            if (!empty($item->url) && ($item->type == 'photo')) {
                $item->html .= $this->createImg($item->url);;
            }
        }

        // Lookup provider based on Emdebly's provider_name field
        if (!empty($item->provider_name)) {
            $item->provider_tid = $this->termLookup('provider', $item->provider_name);
        }

        $item->author_nid = $this->getAuthor($item, 'author_url', 'author_name', 'provider_tid');

        return $item;
    }

}
