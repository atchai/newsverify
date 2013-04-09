<?php
/**
 * @file
 * np_author.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function np_author_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:author.
  $config['node:author'] = array(
    'instance' => 'node:author',
    'config' => array(),
  );

  return $config;
}
