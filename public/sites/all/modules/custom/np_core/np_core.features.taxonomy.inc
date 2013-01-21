<?php
/**
 * @file
 * np_core.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function np_core_taxonomy_default_vocabularies() {
  return array(
    'ad_groups' => array(
      'name' => 'Ad Groups',
      'machine_name' => 'ad_groups',
      'description' => 'Ad Groups',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'section' => array(
      'name' => 'Section',
      'machine_name' => 'section',
      'description' => 'Site section',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
