<?php
/**
 * @file
 * np_author.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function np_author_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function np_author_node_info() {
  $items = array(
    'author' => array(
      'name' => t('Author'),
      'base' => 'node_content',
      'description' => t('The author of a social media Post'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
