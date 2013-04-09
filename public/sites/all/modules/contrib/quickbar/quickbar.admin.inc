<?php

/**
 * @file
 * Handles quickbar administration
 *
 * Assign roles a toolbar.
 */

/**
 * Page to administer quickbar
 *
 * Sets which role uses which menu for it's quickbar.
 *
 * @return
 *  A form setting quicbar menus per role.
 */
function quickbar_form() {
  $form['intro'] = array(
    '#markup' => '<p>' . t('Choose which menu should be used for each role. If a user has multiple roles they will get the menu of the higher role which has an assigned menu.') . '</p>',
  );
  
  $available_menus = menu_get_menus();

  $roles = user_roles();
  $weighted_roles = unserialize(variable_get('quickbar_role_weights', ''));
  $stored_menus = unserialize(variable_get('quickbar_role_menus', ''));
  foreach ($roles as $rid => $name) {
    if (empty($weighted_roles[$rid])) {
      $weighted_roles[$rid] = 0;
    }
  }
  
  // Add 'None' so that the admin can choose for no menu to be assigned to a role.
  array_unshift($available_menus, 'None');

  foreach ($weighted_roles as $rid => $weight) {
    $form['toolbar:' . $rid] = array(
      '#weight' => $weight,
      'title' => array(
        '#markup' => $roles[$rid],
      ),
      'weight' => array(
        '#type' => 'weight',
        '#default_value' => $weight,
      ),
      'menu' => array(
        '#type' => 'select',
        '#default_value' => $stored_menus[$rid],
        '#options' => $available_menus,
      ),
      // This is just to key off of in the theme function, so we don't render
      // elements that are not meant to be part of the table. There might be
      // a better way to handle this ??
      'rid' => array(
        '#type' => 'hidden',
        '#value' => $rid,
      ),
      'operations' => array(
        'configure' => array(
          '#type' => 'link',
          '#title' => t('configure'),
          '#href' => 'admin/config/user-interface/quickbar/' . $rid . '/edit',
        ),
      ),
    );
  }
  
  $form['#tree'] = TRUE;

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Submit handler for quickbar_form()
 *
 * @see quickbar_form()
 * @ingroup forms
 */
function quickbar_form_submit(&$form, &$form_state) {
  $roles = user_roles();
  $weights = array();
  $menus = array();
  foreach ($roles as $rid => $name) {
    $menus[$rid] = $form_state['values']['toolbar:' . $rid]['menu'];
    $weights[$rid] = $form_state['values']['toolbar:' . $rid]['weight'];
  }

  variable_set('quickbar_role_weights', serialize($weights));
  variable_set('quickbar_role_menus', serialize($menus));

  drupal_set_message(t('Your configuration has been saved.'));
}

/**
 * Theme handler for quickbar_form()
 *
 * @see theme_quickbar_form()
 * @ingroup themable
 */
function theme_quickbar_form($variables) {
  $form = $variables['form'];

  $output = drupal_render($form['intro']);

  drupal_add_tabledrag('quickbar-role-order', 'order', 'sibling', 'quickbar-role-order-weight');

  $header = array(
    t('Role'),
    t('Assigned Menu'),
    t('Weight'),
    t('Operations'),
  );
  
  // Build the table rows.
  $rows = array();
  foreach (element_children($form) as $item) {
    $element = &$form[$item];
    
    // Build a list of operations.
    $operations = array(drupal_render($element['operations']));
    
    // Add special class to be used with tabledrag.js
    if (isset($element['weight'])) {
      $element['weight']['#attributes']['class'] = array('quickbar-role-order-weight');
    }
    
    if (isset($element['rid'])) {
      $row = array();
      $row[] = drupal_render($element['title']);
      $row[] = drupal_render($element['menu']);
      $row[] = drupal_render($element['weight']);
      $row = array_merge($row, $operations);
      $row = array('data' => $row);
      $row['class'][] = 'draggable';
      $rows[] = $row;
    }
  }

  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'quickbar-role-order')));
  $output .= drupal_render_children($form);

  return $output;
}

// Route to our form.
function _quickbar_configure_page($rid) {
  $output = drupal_get_form('quickbar_configure_form', $rid);

  return $output;
}

/**
 * Page to configure a toolbar
 *
 * Configures the settings for a toolbar.
 *
 * @return
 *  A form setting the settings for a toolbar.
 */
function quickbar_configure_form($form_state, $info) {
  $iconset_info = module_invoke_all('quickbar_iconset_info');

  $iconsets = array('_none' => 'None');
  foreach ($iconset_info as $iconset_id => $iconset_data) {
    $iconsets[$iconset_id] = $iconset_data['title'];
  }
  
  $settings = variable_get('quickbar_settings_' . arg(4), array());

  $form = array(
    'settings' => array(
      '#type'  => 'fieldset',
      '#title' => t('General Settings'),
      'iconset' => array(
        '#type'          => 'select',
        '#title'         => 'Iconset',
        '#description'   => 'Choose the iconset for the toolbar.',
        '#default_value' => (isset($settings['iconset']) ? $settings['iconset'] : ''),
        '#options'       => $iconsets,
      ),
      'sticky' => array(
        '#type'          => 'checkbox',
        '#title'         => 'Make the toolbar sticky at the top',
        '#description'   => 'If checked, the toolbar will always be visible as the user scrolls down the page.',
        '#default_value' => (isset($settings['sticky']) ? $settings['sticky'] : ''),
      ),
      'float' => array(
        '#type'          => 'checkbox',
        '#title'         => "Make the toolbar 'float' over page",
        '#description'   => 'If checked, the toolbar will overlay the top portion of the webpage.',
        '#default_value' => (isset($settings['float']) ? $settings['float'] : ''),
        '#states'        => array(
          'visible' => array(
            ':input#edit-settings-sticky' => array('checked' => FALSE),
          ),
        ),
      ),
      'nofollow' => array(
        '#title' => 'Do not follow top-level links',
        '#description' => 'If checked, top-level links of toolbar will only open secondary menus.',
        '#type' => 'checkbox',
        '#default_value' => (isset($settings['nofollow']) ? $settings['nofollow'] : ''),
      ),
    ),
    'submit' => array(
      '#type'  => 'submit',
      '#value' => t('Save configuration'),
    ),
    '#tree' => TRUE,
  );

  return $form;
}

/**
 * Submit handler for quickbar_configure_form()
 *
 * @see quickbar_configure_form()
 * @ingroup forms
 */
function quickbar_configure_form_submit(&$form, &$form_state) {
  variable_set('quickbar_settings_' . arg(4), $form_state['values']['settings']);

  drupal_set_message('The toolbar settings have been saved.');

  // Go back to the quickbar form.
  $form_state['redirect'] = 'admin/config/user-interface/quickbar';
}