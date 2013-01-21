<?php
/**
 * @file
 * np_core.menu_block.inc
 */

/**
 * Implements hook_menu_block_defaults().
 */
function np_core_menu_block_defaults() {
  $export = array();

  $menu_block = new stdClass();
  $menu_block->disabled = FALSE; /* Edit this to true to make a default menu_block disabled initially */
  $menu_block->api_version = 1;
  $menu_block->name = '1';
  $menu_block->label = 'Footer Column Menu';
  $menu_block->description = '';
  $menu_block->depth = 0;
  $menu_block->expanded = 1;
  $menu_block->follow = '';
  $menu_block->level = 1;
  $menu_block->parent = 'main-menu:0';
  $menu_block->sort = 0;
  $menu_block->title_link = 0;
  $export['1'] = $menu_block;

  return $export;
}
