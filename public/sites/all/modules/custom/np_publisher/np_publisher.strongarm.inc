<?php
/**
 * @file
 * np_publisher.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function np_publisher_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quickbar_extras_settings_2';
  $strongarm->value = 'a:5:{s:4:"menu";a:7:{s:8:"mlid_403";s:4:"left";s:8:"mlid_404";s:4:"left";s:8:"mlid_405";s:4:"left";s:8:"mlid_406";s:4:"left";s:8:"mlid_407";s:4:"left";s:8:"mlid_408";s:4:"left";s:8:"mlid_420";s:4:"left";}s:13:"show_username";i:1;s:20:"show_username_prefix";s:7:"Hello, ";s:20:"show_username_suffix";s:0:"";s:18:"show_username_link";i:0;}';
  $export['quickbar_extras_settings_2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quickbar_role_menus';
  $strongarm->value = 'a:3:{i:1;s:1:"0";i:2;s:23:"menu-publisher-quickbar";i:3;s:1:"0";}';
  $export['quickbar_role_menus'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quickbar_role_weights';
  $strongarm->value = 'a:3:{i:1;s:2:"-8";i:2;s:2:"-9";i:3;s:3:"-10";}';
  $export['quickbar_role_weights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quickbar_settings_2';
  $strongarm->value = array(
    'iconset' => 'quickbar',
    'sticky' => 0,
    'float' => 0,
    'nofollow' => 0,
  );
  $export['quickbar_settings_2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_pictures';
  $strongarm->value = 1;
  $export['user_pictures'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_default';
  $strongarm->value = '';
  $export['user_picture_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_dimensions';
  $strongarm->value = '85x85';
  $export['user_picture_dimensions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_file_size';
  $strongarm->value = '1024';
  $export['user_picture_file_size'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_guidelines';
  $strongarm->value = '';
  $export['user_picture_guidelines'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_path';
  $strongarm->value = 'pictures';
  $export['user_picture_path'] = $strongarm;

  return $export;
}
