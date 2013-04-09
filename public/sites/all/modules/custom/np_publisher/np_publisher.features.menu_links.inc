<?php
/**
 * @file
 * np_publisher.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function np_publisher_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-publisher-quickbar:admin/content
  $menu_links['menu-publisher-quickbar:admin/content'] = array(
    'menu_name' => 'menu-publisher-quickbar',
    'link_path' => 'admin/content',
    'router_path' => 'admin/content',
    'link_title' => 'My Content',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-publisher-quickbar:admin/content/authors
  $menu_links['menu-publisher-quickbar:admin/content/authors'] = array(
    'menu_name' => 'menu-publisher-quickbar',
    'link_path' => 'admin/content/authors',
    'router_path' => 'admin/content/authors',
    'link_title' => 'Authors',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
  );
  // Exported menu link: menu-publisher-quickbar:admin/content/events
  $menu_links['menu-publisher-quickbar:admin/content/events'] = array(
    'menu_name' => 'menu-publisher-quickbar',
    'link_path' => 'admin/content/events',
    'router_path' => 'admin/content/events',
    'link_title' => 'Events',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: menu-publisher-quickbar:node/add
  $menu_links['menu-publisher-quickbar:node/add'] = array(
    'menu_name' => 'menu-publisher-quickbar',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Add Content',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-publisher-quickbar:node/add/event
  $menu_links['menu-publisher-quickbar:node/add/event'] = array(
    'menu_name' => 'menu-publisher-quickbar',
    'link_path' => 'node/add/event',
    'router_path' => 'node/add/event',
    'link_title' => 'Event',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-publisher-quickbar:node/add/story
  $menu_links['menu-publisher-quickbar:node/add/story'] = array(
    'menu_name' => 'menu-publisher-quickbar',
    'link_path' => 'node/add/story',
    'router_path' => 'node/add/story',
    'link_title' => 'Story',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add Content');
  t('Authors');
  t('Event');
  t('Events');
  t('My Content');
  t('Story');


  return $menu_links;
}
