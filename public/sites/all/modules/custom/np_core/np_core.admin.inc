<?php

/**
 * @file
 * Contains the administration pages for News Platform
 *
 */

function np_core_settings($form, &$form_state) {

  $form['np_core_about_verification_page'] = array(
    '#type' => 'textfield',
    '#title' => t('Internal Drupal path for the about verification page. E.G node/8000'),
    '#default_value' => variable_get('np_core_about_verification_page', FALSE),
  );

  return system_settings_form($form);
}
