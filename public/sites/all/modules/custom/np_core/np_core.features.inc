<?php
/**
 * @file
 * np_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function np_core_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "menu_block" && $api == "menu_block") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function np_core_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
