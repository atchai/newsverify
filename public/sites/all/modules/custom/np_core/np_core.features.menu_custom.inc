<?php
/**
 * @file
 * np_core.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function np_core_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-section.
  $menus['menu-section'] = array(
    'menu_name' => 'menu-section',
    'title' => 'Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Menu');


  return $menus;
}
