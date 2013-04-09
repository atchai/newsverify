<?php
/**
 * @file
 * np_story.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function np_story_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:story.
  $config['node:story'] = array(
    'instance' => 'node:story',
    'config' => array(
      'abstract' => array(
        'value' => '[node:field_story_summary]',
      ),
      'og:image' => array(
        'value' => '[node:field_story_thumb]',
      ),
    ),
  );

  return $config;
}
