<?php
/**
 * @file
 * np_admin.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function np_admin_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function np_admin_views_api() {
  return array("version" => "3.0");
}
