<?php
/**
 * @file
 * CTools Export UI plugin for Menu Block.
 */

/**
 * CTools Export UI required function for plugin definition
 */
function menu_block_menu_block_ctools_export_ui() {
  return array(
    'schema' => 'menu_blocks',

    'menu' => array(
      'menu prefix' => 'admin/structure',
      'menu item' => 'menu_block',
      'menu title' => 'Menu Blocks',
      'menu description' => 'Administer Menu Blocks.',
    ),

    'title singular' => t('menu block'),
    'title singular proper' => t('Menu Block'),
    'title plural' => t('menu blocks'),
    'title plural proper' => t('Menu Blocks'),

    'form' => array(
      'settings' => 'menu_block_export_ui_form',
    ),

    'export' => array(
      'admin_title' => 'label',
      'admin_description' => 'description',
    ),
  );
}

/**
 * Menu Block settings form.
 */
function menu_block_export_ui_form(&$form, &$form_state) {
  list($form_state['item']->menu_name, $form_state['item']->parent_mlid) = explode(':', !empty($form_state['item']->parent) ? $form_state['item']->parent : 'main-menu:0');

  $form['#attached']['js'][] = drupal_get_path('module', 'menu_block') . '/menu-block.js';
  $form['#attached']['css'][] = drupal_get_path('module', 'menu_block') . '/menu-block-admin.css';
  $form['#attached']['library'][] = array('system', 'ui.button');

  $form['menu-block-wrapper-start'] = array(
    '#markup' => '<div id="menu-block-settings">',
    '#weight' => -20,
  );

  $form['display_options'] = array(
    '#type' => 'radios',
    '#title' => t('Display'),
    '#default_value' => 'basic',
    '#options' => array(
      'basic' => t('Basic options'),
      'advanced' => t('Advanced options'),
    ),
    '#attributes' => array('class' => array('clearfix')),
    '#weight' => -19,
  );

  $form['title_link'] = array(
    '#type' => 'checkbox',
    '#title' => t('Block title as link'),
    '#default_value' => $form_state['item']->title_link,
    '#description' => t('Make the default block title a link to that menu item. An overridden block title will not be a link.'),
  );
  if (isset($form_state['menu_block']) && 'block' == $form_state['menu_block']) {
    $form['title_link']['#states'] = array(
      'visible' => array(
        ':input[name=title]' => array('value' => ''),
      ),
    );
  }
  elseif (isset($form['override_title'])) {
    $form['title_link']['#states'] = array(
      'visible' => array(
        ':input[name=override_title]' => array('checked' => FALSE),
      ),
    );
  }

  $menus = menu_block_get_all_menus();
  $form['menu_name'] = array(
    '#type' => 'select',
    '#title' => t('Menu'),
    '#default_value' => $form_state['item']->menu_name,
    '#options' => $menus,
    '#description' => t('The preferred menus used by <em>&lt;the menu selected by the page&gt;</em> can be customized on the <a href="!url">Menu block settings page</a>.', array('!url' => url('admin/config/user-interface/menu-block'))),
    '#attributes' => array('class' => array('menu-block-menu-name')),
  );

  $form['level'] = array(
    '#type' => 'select',
    '#title' => t('Starting level'),
    '#default_value' => $form_state['item']->level,
    '#options' => array(
      '1'  => t('1st level (primary)'),
      '2'  => t('2nd level (secondary)'),
      '3'  => t('3rd level (tertiary)'),
      '4'  => t('4th level'),
      '5'  => t('5th level'),
      '6'  => t('6th level'),
      '7'  => t('7th level'),
      '8'  => t('8th level'),
      '9'  => t('9th level'),
    ),
    '#description' => t('Blocks that start with the 1st level will always be visible. Blocks that start with the 2nd level or deeper will only be visible when the trail to the active menu item is in the block\'s tree.'),
  );

  $form['follow'] = array(
    '#type' => 'checkbox',
    '#title' => t('Make the starting level follow the active menu item.'),
    '#default_value' => !empty($form_state['item']->follow),
    '#description' => t('If the active menu item is deeper than the level specified above, the starting level will follow the active menu item. Otherwise, the starting level of the tree will remain fixed.'),
    '#element_validate' => array('menu_block_configure_form_follow_validate'),
  );
  $form['follow_parent'] = array(
    '#type' => 'select',
    '#title' => t('Starting level will be'),
    '#default_value' => $form_state['item']->follow,
    '#options' => array(
      'active' => t('Active menu item'),
      'child' => t('Children of active menu item'),
    ),
    '#description' => t('When following the active menu item, specify if the starting level should be the active menu item or its children.'),
    '#states' => array(
      'visible' => array(
        ':input[name=follow]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['depth'] = array(
    '#type' => 'select',
    '#title' => t('Maximum depth'),
    '#default_value' => $form_state['item']->depth,
    '#options' => array(
      '1'  => '1',
      '2'  => '2',
      '3'  => '3',
      '4'  => '4',
      '5'  => '5',
      '6'  => '6',
      '7'  => '7',
      '8'  => '8',
      '9'  => '9',
      '0'  => t('Unlimited'),
    ),
    '#description' => t('From the starting level, specify the maximum depth of the menu tree.'),
  );

  $form['expanded'] = array(
    '#type' => 'checkbox',
    '#title' => t('<strong>Expand all children</strong> of this tree.'),
    '#default_value' => $form_state['item']->expanded,
  );

  $form['sort'] = array(
    '#type' => 'checkbox',
    '#title' => t('<strong>Sort</strong> menu tree by the active menu item’s trail.'),
    '#default_value' => $form_state['item']->sort,
    '#description' => t('Sort each item in the active trail to the top of its level. When used on a deep or wide menu tree, the active menu item’s children will be easier to see when the page is reloaded.'),
  );

  $form['parent_mlid'] = array(
    '#type' => 'select',
    '#title' => t('Fixed parent item'),
    '#default_value' => $form_state['item']->parent,
    '#options' => menu_parent_options($menus, array('mlid' => 0)),
    '#description' => t('Alter the "starting level" and "maximum depth" options to be relative to the fixed parent item. The tree of links will only contain children of the selected menu item.'),
    '#attributes' => array('class' => array('menu-block-parent-mlid')),
    '#element_validate' => array('menu_block_configure_form_parent_validate'),
  );
  $form['parent_mlid']['#options'][MENU_TREE__CURRENT_PAGE_MENU . ':0'] = '<' . t('the menu selected by the page') . '>';

  $form['menu-block-wrapper-close'] = array('#markup' => '</div>');

  // Set visibility of advanced options.
  foreach (array('title_link', 'follow', 'follow_parent', 'expanded', 'sort', 'parent_mlid') as $key) {
    $form[$key]['#states']['visible'][':input[name=display_options]'] = array('value' => 'advanced');
    if (!empty($form_state['item']->{$key})) {
      $form['display_options']['#default_value'] = 'advanced';
    }
  }
}

/**
 * Validates the parent element of the block configuration form.
 */
function menu_block_configure_form_parent_validate($element, &$form_state) {
  // Determine the fixed parent item's menu and mlid.
  list($menu_name, $parent_mlid) = explode(':', $form_state['values']['parent_mlid']);
  if ($parent_mlid) {
    // If mlid is set, its menu overrides the menu_name option.
    $form_state['values']['menu_name'] = $menu_name;
  }
  else {
    // Otherwise the menu_name overrides the parent item option.
    $form_state['values']['parent_mlid'] = $menu_name . ':0';
  }
  // The value of "parent" stored in the database/config array is the menu name
  // combined with the optional parent menu item's mlid.
  $form_state['values']['parent'] = $form_state['values']['parent_mlid'];
}

/**
 * Validates the follow element of the block configuration form.
 */
function menu_block_configure_form_follow_validate($element, &$form_state) {
  // The value of "follow" stored in the database/config array is either FALSE
  // or the value of the "follow_parent" form element.
  if ($form_state['values']['follow'] && !empty($form_state['values']['follow_parent'])) {
    $form_state['values']['follow'] = $form_state['values']['follow_parent'];
  }
}
