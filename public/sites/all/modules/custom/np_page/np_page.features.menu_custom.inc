<?php
/**
 * @file
 * np_page.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function np_page_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-our-approach.
  $menus['menu-our-approach'] = array(
    'menu_name' => 'menu-our-approach',
    'title' => 'Our Approach',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Our Approach');


  return $menus;
}
