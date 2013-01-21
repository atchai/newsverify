<?php
/**
 * @file
 * np_location.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function np_location_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-location.
  $menus['menu-location'] = array(
    'menu_name' => 'menu-location',
    'title' => 'Location',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Location');


  return $menus;
}
