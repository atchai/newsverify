<?php
/**
 * @file
 * np_core.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function np_core_filter_default_formats() {
  $formats = array();

  // Exported format: HTML.
  $formats['html'] = array(
    'format' => 'html',
    'name' => 'HTML',
    'cache' => '1',
    'status' => '1',
    'weight' => '-9',
    'filters' => array(),
  );

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => '1',
    'status' => '1',
    'weight' => '-8',
    'filters' => array(
      'filter_html_escape' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => '1',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => '2',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Publisher HTML.
  $formats['publisher_html'] = array(
    'format' => 'publisher_html',
    'name' => 'Publisher HTML',
    'cache' => '1',
    'status' => '1',
    'weight' => '-10',
    'filters' => array(
      'np_inline_filter' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
