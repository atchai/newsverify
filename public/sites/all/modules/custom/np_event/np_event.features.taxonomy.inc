<?php
/**
 * @file
 * np_event.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function np_event_taxonomy_default_vocabularies() {
  return array(
    'verification_status' => array(
      'name' => 'Verification Status',
      'machine_name' => 'verification_status',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
