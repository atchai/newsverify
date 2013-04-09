<?php
/**
 * @file
 * np_event.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function np_event_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:event.
  $config['node:event'] = array(
    'instance' => 'node:event',
    'config' => array(
      'abstract' => array(
        'value' => '[node:field-cmptd-description-full]',
      ),
    ),
  );

  return $config;
}
