<?php
/**
 * @file
 * Provides infrequently used functions and hooks for menu_block.
 */

/**
 * Implements hook_theme().
 */
function _menu_block_theme(&$existing, $type, $theme, $path) {
  // Add theme hook suggestion patterns for the core theme functions used in
  // this module. We can't add them during hook_theme_registry_alter() because
  // we will already have missed the opportunity for the theme engine's
  // theme_hook() to process the pattern. And we can't run the pattern ourselves
  // because we aren't given the type, theme and path in that hook.
  $existing['menu_tree']['pattern'] = 'menu_tree__';
  $existing['menu_link']['pattern'] = 'menu_link__';

  return array(
    'menu_block_wrapper' => array(
      'template' => 'menu-block-wrapper',
      'variables' => array('content' => array(), 'config' => array(), 'delta' => NULL),
      'pattern' => 'menu_block_wrapper__',
    ),
    'menu_block_menu_order' => array(
      'render element' => 'element',
      'file' => 'menu_block.admin.inc',
    ),
  );
}

/**
 * Implements hook_ctools_plugin_directory().
 */
function _menu_block_ctools_plugin_directory($module, $plugin) {
  if ($module == 'ctools' && !empty($plugin)) {
    return "plugins/{$plugin}";
  }
}

/**
 * Alters the block admin form to add delete links next to menu blocks.
 */
function _menu_block_form_block_admin_display_form_alter(&$form, $form_state) {
  foreach (menu_block_load_all() as $delta => $menu_block) {
    if ('Default' !== $menu_block->type) {
      $form['blocks']['menu_block_' . $delta]['delete'] = array(
        '#type' => 'link',
        '#title' => $menu_block->type == 'Overridden' ? t('revert') : t('delete'),
        '#href' => url('admin/structure/menu_block/list/' . $delta . '/' . ($menu_block->type == 'Overridden' ? 'revert' : 'delete'), array(
          'absolute' => TRUE,
          'query' => array('destination' => ltrim(request_uri(), '/')),
        )),
      );
    }
  }
  if (variable_get('menu_block_suppress_core')) {
    foreach (array_keys(menu_get_menus(FALSE)) AS $delta) {
      if (empty($form['blocks']['menu_' . $delta]['region']['#default_value'])) {
        unset($form['blocks']['menu_' . $delta]);
      }
    }
    foreach (array_keys(menu_list_system_menus()) AS $delta) {
      if (empty($form['blocks']['system_' . $delta]['region']['#default_value'])) {
        unset($form['blocks']['system_' . $delta]);
      }
    }
  }
}

/**
 * Menu callback: confirm deletion of menu blocks.
 */
function menu_block_delete($form, &$form_state, $delta = 0) {
  $title = _menu_block_format_title(menu_block_get_config($delta));
  $form['block_title'] = array('#type' => 'hidden', '#value' => $title);
  $form['delta'] = array('#type' => 'hidden', '#value' => $delta);

  return confirm_form($form, t('Are you sure you want to delete the "%name" block?', array('%name' => $title)), 'admin/structure/block', NULL, t('Delete'), t('Cancel'));
}

/**
 * Deletion of menu blocks.
 */
function menu_block_delete_submit($form, &$form_state) {
  // Remove the menu block configuration variables.
  $delta = $form_state['values']['delta'];
  $block_ids = variable_get('menu_block_ids', array());
  unset($block_ids[array_search($delta, $block_ids)]);
  sort($block_ids);
  variable_set('menu_block_ids', $block_ids);
  variable_del("menu_block_{$delta}_title_link");
  variable_del("menu_block_{$delta}_admin_title");
  variable_del("menu_block_{$delta}_parent");
  variable_del("menu_block_{$delta}_level");
  variable_del("menu_block_{$delta}_follow");
  variable_del("menu_block_{$delta}_depth");
  variable_del("menu_block_{$delta}_expanded");
  variable_del("menu_block_{$delta}_sort");

  db_delete('block')
    ->condition('module', 'menu_block')
    ->condition('delta', $delta)
    ->execute();
  db_delete('block_role')
    ->condition('module', 'menu_block')
    ->condition('delta', $delta)
    ->execute();
  drupal_set_message(t('The block "%name" has been removed.', array('%name' => $form_state['values']['block_title'])));
  cache_clear_all();
  $form_state['redirect'] = 'admin/structure/block';
  return;
}

/**
 * Implements hook_block_info().
 */
function _menu_block_block_info() {
  $blocks = array();
  foreach (menu_block_load_all() as $delta => $menu_block) {
    $blocks[$delta]['info'] = check_plain($menu_block->label);
    // Menu blocks can't be cached because each menu item can have
    // a custom access callback. menu.inc manages its own caching.
    $blocks[$delta]['cache'] = DRUPAL_NO_CACHE;
  }
  return $blocks;
}

/**
 * Implements hook_block_configure().
 */
function _menu_block_block_configure($delta = '') {
  ctools_include('export');
  module_load_include('inc', 'menu_block', 'plugins/export_ui/menu_block');

  $form = array();
  $form_state = array(
    'item' => ctools_export_crud_load('menu_blocks', $delta),
    'menu_block' => 'block',
  );
  menu_block_export_ui_form($form, $form_state);

  return $form;
}

/**
 * Implements hook_block_save().
 */
function _menu_block_block_save($delta = '', $edit = array()) {
  if (!empty($delta)) {
    ctools_include('export');
    $menu_block = ctools_export_crud_load('menu_blocks', $delta);
    foreach (array_keys((array) $menu_block) as $key) {
      if (isset($edit[$key])) {
        $menu_block->{$key} = $edit[$key];
      }
    }
    ctools_export_crud_save('menu_blocks', $menu_block);
  }
}

/**
 * Menu callback: admin settings form.
 *
 * @return
 *   The settings form used by Menu block.
 */
function menu_block_admin_settings_form($form, &$form_state) {
  // Option to suppress core's blocks of menus.
  $form['menu_block_suppress_core'] = array(
    '#type' => 'checkbox',
    '#title' => t('Suppress Drupal’s standard menu blocks'),
    '#default_value' => variable_get('menu_block_suppress_core', 0),
    '#description' => t('On the blocks admin page, hide Drupal’s standard blocks of menus.'),
    '#access' => module_exists('block'),
  );

  // Retrieve core's menus.
  $menus = menu_get_menus();
  // Retrieve all the menu names provided by hook_menu_block_get_sort_menus().
  $menus = array_merge($menus, module_invoke_all('menu_block_get_sort_menus'));
  asort($menus);

  // Load stored configuration.
  $menu_order = variable_get('menu_block_menu_order', array('main-menu' => '', 'user-menu' => ''));
  // Remove any menus no longer in the list of all menus.
  foreach (array_keys($menu_order) as $menu) {
    if (!isset($menus[$menu])) {
      unset($menu_order[$menu]);
    }
  }

  // Merge the saved configuration with any un-configured menus.
  $all_menus = $menu_order + $menus;

  $form['heading'] = array(
    '#markup' => '<p>' . t('If a block is configured to use <em>"the menu selected by the page"</em>, the block will be generated from the first "available" menu that contains a link to the page.') . '</p>',
  );

  // Orderable list of menu selections.
  $form['menu_order'] = array(
    '#tree' => TRUE,
    '#theme' => 'menu_block_menu_order',
  );

  $order = 0;
  $total_menus = count($all_menus);
  foreach (array_keys($all_menus) as $menu_name) {
    $form['menu_order'][$menu_name] = array(
      'title' => array(
        '#markup' => check_plain($menus[$menu_name]),
      ),
      'available' => array(
        '#type' => 'checkbox',
        '#attributes' => array('title' => t('Select from the @menu_name menu', array('@menu_name' => $menus[$menu_name]))),
        '#default_value' => isset($menu_order[$menu_name]),
      ),
      'weight' => array(
        '#type' => 'weight',
        '#default_value' => $order - $total_menus,
        '#delta' => $total_menus,
        '#id' => 'edit-menu-block-menus-' . $menu_name,
      ),
    );
    $order++;
  }

  $form['footer_note'] = array(
    '#markup' => '<p>' . t('The above list will <em>not</em> affect menu blocks that are configured to use a specific menu.') . '</p>',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Form submission handler.
 */
function menu_block_admin_settings_form_submit($form, &$form_state) {
  $menu_order = array();
  foreach ($form_state['values']['menu_order'] AS $menu_name => $row) {
    if ($row['available']) {
      // Add available menu and its weight to list.
      $menu_order[$menu_name] = (int) $row['weight'];
    }
  }
  // Sort the keys by the weight stored in the value.
  asort($menu_order);
  foreach ($menu_order AS $menu_name => $weight) {
    // Now that the array is sorted, the weight is redundant data.
    $menu_order[$menu_name] = '';
  }
  variable_set('menu_block_menu_order', $menu_order);
  if ($form_state['values']['menu_block_suppress_core']) {
    variable_set('menu_block_suppress_core', 1);
  }
  else {
    variable_del('menu_block_suppress_core');
  }
  drupal_set_message(t('The configuration options have been saved.'));
}

/**
 * Theme a drag-to-reorder table of menu selection checkboxes.
 */
function theme_menu_block_menu_order($variables) {
  $element = $variables['element'];
  drupal_add_tabledrag('menu-block-menus', 'order', 'sibling', 'menu-weight');

  $variables = array(
    'header' => array(
      t('Menu'),
      t('Available'),
      t('Weight'),
    ),
    'rows' => array(),
    'attributes' => array('id' => 'menu-block-menus'),
  );

  // Generate table of draggable menu names.
  foreach (element_children($element) as $menu_name) {
    $element[$menu_name]['weight']['#attributes']['class'] = array('menu-weight');
    $variables['rows'][] = array(
      'data' => array(
        drupal_render($element[$menu_name]['title']),
        drupal_render($element[$menu_name]['available']),
        drupal_render($element[$menu_name]['weight']),
      ),
      'class' => array('draggable'),
    );
  }

  return theme('table', $variables);
}
