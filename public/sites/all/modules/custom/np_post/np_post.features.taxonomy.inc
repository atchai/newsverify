<?php
/**
 * @file
 * np_post.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function np_post_taxonomy_default_vocabularies() {
  return array(
    'provider' => array(
      'name' => 'Provider',
      'machine_name' => 'provider',
      'description' => 'Social media networks (e.g. Twitter, Facebook, etc)',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
