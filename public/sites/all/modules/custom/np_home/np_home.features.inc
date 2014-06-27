<?php
/**
 * @file
 * np_home.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function np_home_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function np_home_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function np_home_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: home
  $nodequeues['home'] = array(
    'name' => 'home',
    'title' => 'Home',
    'subqueue_title' => '',
    'size' => 6,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'types' => array(
      0 => 'story',
    ),
    'roles' => array(
      0 => 2,
    ),
    'count' => 0,
  );

  return $nodequeues;
}
