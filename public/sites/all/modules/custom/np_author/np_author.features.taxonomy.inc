<?php
/**
 * @file
 * np_author.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function np_author_taxonomy_default_vocabularies() {
  return array(
    'author_rating' => array(
      'name' => 'Author Rating',
      'machine_name' => 'author_rating',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
