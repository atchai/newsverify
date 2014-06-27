<?php
/**
 * @file
 * np_location.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function np_location_taxonomy_default_vocabularies() {
  return array(
    'location' => array(
      'name' => 'Location',
      'machine_name' => 'location',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
