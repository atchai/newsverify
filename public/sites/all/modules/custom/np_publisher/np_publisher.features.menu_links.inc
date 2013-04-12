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
    'weight' => '-46',
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
    'weight' => '-44',
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
    'weight' => '-45',
  );
  // Exported menu link: menu-publisher-quickbar:node/add/author
  $menu_links['menu-publisher-quickbar:node/add/author'] = array(
    'menu_name' => 'menu-publisher-quickbar',
    'link_path' => 'node/add/author',
    'router_path' => 'node/add/author',
    'link_title' => 'Add Author',
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
  // Exported menu link: menu-publisher-quickbar:node/add/event
  $menu_links['menu-publisher-quickbar:node/add/event'] = array(
    'menu_name' => 'menu-publisher-quickbar',
    'link_path' => 'node/add/event',
    'router_path' => 'node/add/event',
    'link_title' => 'Add Event',
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
  // Exported menu link: menu-publisher-quickbar:node/add/page
  $menu_links['menu-publisher-quickbar:node/add/page'] = array(
    'menu_name' => 'menu-publisher-quickbar',
    'link_path' => 'node/add/page',
    'router_path' => 'node/add/page',
    'link_title' => 'Add Page',
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
  // Exported menu link: menu-publisher-quickbar:node/add/story
  $menu_links['menu-publisher-quickbar:node/add/story'] = array(
    'menu_name' => 'menu-publisher-quickbar',
    'link_path' => 'node/add/story',
    'router_path' => 'node/add/story',
    'link_title' => 'Add Story',
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
  // Exported menu link: menu-publisher-quickbar:user/logout
  $menu_links['menu-publisher-quickbar:user/logout'] = array(
    'menu_name' => 'menu-publisher-quickbar',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log Out',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-43',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add Author');
  t('Add Event');
  t('Add Page');
  t('Add Story');
  t('Authors');
  t('Events');
  t('Log Out');
  t('My Content');


  return $menu_links;
}
