<?php
/**
 * @file
 * Core NewsPlatform tokens
 */

/**
 * Implements function hook_token_info().
 */
function np_core_token_info() {
    return array(
        'tokens' => array(
            'site' => array(
                'logo-url' => array(
                    'name' => t('Site logo URL'),
                    'description' => t('The absolute URL to the site logo image'),
                ),
            ),
        ),
    );
}

/**
 * Implements hook_tokens().
 */
function np_core_tokens($type, $tokens, array $data = array(), array $options = array()) {
    $replacements = array();
    if ($type == 'site') {
        foreach ($tokens as $name => $original) {
            if ($name == 'logo-url') {
                $replacements[$original] = theme_get_setting('logo');
            }
        }
    }
    return $replacements;
}
