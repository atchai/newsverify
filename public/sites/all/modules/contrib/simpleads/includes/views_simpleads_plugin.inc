<?php

/**
 * @file
 * Contains the list style plugin.
 */

/**
 * Style plugin to render SimpleAds.
 *
 * @ingroup views_style_plugins
 */
class views_simpleads_plugin extends views_plugin_style {

  /**
   * Set default options
   */
    function option_definition() {
      $options = parent::option_definition();
      $options['ads_rotation_type'] = array('default' => 0);
      $options['ads_rotation_delay'] = array('default' => 5);
      $options['ads_width'] = array('default' => '');
      $options['ads_height'] = array('default' => '');
    return $options;
  }

  /**
   * Provide a form for setting options.
   *
   * @param array $form
   * @param array $form_state
   */
  function options_form(&$form, &$form_state) {
    $effects = _simpleads_rotation_effects();
    $form['ads_rotation_type'] = array(
      '#type' => 'radios',
      '#title' => t('Ads auto rotation type'),
      '#options' => $effects,
      '#default_value' => $this->options['ads_rotation_type'],
    );
    $form['ads_rotation_delay'] = array(
      '#type' => 'textfield',
      '#title' => t('Ad rotation delay'),
      '#default_value' => $this->options['ads_rotation_delay'],
      '#description' => t('Delay value is in seconds'),
    );
    $form['ads_width'] = array(
      '#type' => 'textfield',
      '#title' => t('Ad width'),
      '#default_value' => $this->options['ads_width'],
    );
    $form['ads_height'] = array(
      '#type' => 'textfield',
      '#title' => t('Ad height'),
      '#default_value' => $this->options['ads_height'],
    );
  }
}