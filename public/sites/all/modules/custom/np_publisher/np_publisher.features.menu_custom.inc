<?php
/**
 * @file
 * np_publisher.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function np_publisher_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-publisher-quickbar.
  $menus['menu-publisher-quickbar'] = array(
    'menu_name' => 'menu-publisher-quickbar',
    'title' => 'Publisher Quickbar',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Publisher Quickbar');


  return $menus;
}
