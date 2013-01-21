<?php

/**
 * @file
 * SimpleAds Filters.
 */

/**
 * Implements hook_filter_info().
 */
function simpleads_filter_info() {
  $filters = array();
  $filters['simpleads'] = array(
    'title' => t('SimpleAds Filter'),
    'description' => t('Substitutes [ads:TID limit:N] with Ad block.'),
    'process callback' => '_simpleads_filter_process',
    'tips callback' => '_simpleads_filter_tips',
    'weight' => -1,
  );
  return $filters;
}

/**
 * Filter Process callback.
 */
function _simpleads_filter_process($text, $filter, $format, $langcode, $cache, $cache_id) {
  if (preg_match_all('/\[ads(\:(.+))?( .+)?\]/isU', $text, $matches_code)) {
    foreach ($matches_code[0] as $ci => $code) {
      $ad = array(
        'tid' => $matches_code[2][$ci],
        'ads_page' => '',
        'width' => '',
        'height' => '',
      );
      if ($matches_code[3][$ci] && preg_match_all('/\s+([a-zA-Z_]+)\:(\s+)?([0-9a-zA-Z\/]+)/i', $matches_code[3][$ci], $matches_attributes)) {
        foreach ($matches_attributes[0] AS $key => $attribute) {
          $ad[$matches_attributes[1][$key]] = $matches_attributes[3][$key];
        }
      }
      // Injecting an Ad into content.
      $content_ad = theme('simpleads_block', array('tid' => $ad['tid'], 'prefix' => 'content-' . $ci, 'ads_limit' => $ad['limit'], 'ads_page' => $ad['ads_page'], 'ads_width' => $ad['width'], 'ads_height' => $ad['height']));
      $pattern = str_replace(array('[', ']'), array('\[', '\]'), $matches_code[0][$ci]);
      $text = preg_replace('/' . $pattern . '/is', $content_ad, $text);
    }
  }

  return $text;
}

/**
 * Filter Tips callback.
 */
function _simpleads_filter_tips($filter, $format, $long = FALSE) {
  return t('You may insert Ads with [ads:term_id limit:N] where term_id - Ad Group and N - number of Ads to display');
}

/**
 * Implements hook_wysiwyg_plugin().
 */
function simpleads_wysiwyg_plugin($editor, $version) {

  _simpleads_filter_add_settings('wysiwyg_' . $editor);

  switch ($editor) {
    case 'tinymce':
      $plugins['simpleads'] = array(
        'path' => drupal_get_path('module', 'simpleads') . '/editors/tinymce',
        'filename' => 'editor_plugin.js',
        'buttons' => array('simpleads' => t('Inject ads into content')),
        'load' => TRUE,
      );
      break;
    case 'ckeditor':
      $plugins['simpleads'] = array(
        'path' => drupal_get_path('module', 'simpleads') . '/editors/ckeditor/',
        'buttons' => array('simpleads' => t('Inject ads into content')),
        'load' => TRUE,
      );
      break;
    case 'fckeditor':
      $plugins['simpleads'] = array(
        'path' => drupal_get_path('module', 'simpleads') . '/editors/fckeditor/',
        'buttons' => array('simpleads' => t('Inject ads into content')),
        'load' => TRUE,
      );
      break;
  }

  return $plugins;
}

/**
 * WYSIWYG Popup page.
 */
function _simpleads_filter_dashboard_page($editor) {

  module_invoke('admin_menu', 'suppress');

  switch ($editor) {
    case 'wysiwyg_tinymce':
      drupal_add_js(wysiwyg_get_path('tinymce') . '/jscripts/tiny_mce/tiny_mce_popup.js');
      drupal_add_js(drupal_get_path('module', 'simpleads') . '/editors/tinymce/simpleads_filter.js');
      break;

    case 'ckeditor':
    case 'wysiwyg_ckeditor':
      drupal_add_js(drupal_get_path('module', 'simpleads') . '/editors/ckeditor/simpleads_filter_dialog.js');
      break;

    case 'fckeditor':
    case 'wysiwyg_fckeditor':
      drupal_add_js(drupal_get_path('module', 'simpleads') . '/editors/fckeditor/simpleads/simpleads_filter_dialog.js');
      break;
  }

  $form = render(drupal_get_form('_simpleads_filter_form'));

  print theme('simpleads_filter_dashboard', array('form' => $form));
  exit();
}

/**
 * Return the theme name to be used when showing linkit dashboard
 */
function _simpleads_filter_dashboard_theme() {
  return variable_get('admin_theme', 'seven');
}

/**
 * Template preprocess function for simpleads_filter_dashboard().
 */
function template_preprocess_simpleads_filter_dashboard(&$vars) {
  $vars['head_title'] = t('SimpleAds Filter');
  $vars['head'] = drupal_get_html_head();
  $vars['help'] = theme('help');
  $vars['language'] = $GLOBALS['language'];
  $vars['language']->dir = $GLOBALS['language']->direction ? 'rtl' : 'ltr';
  $vars['messages'] = isset($vars['show_messages']) ? theme('status_messages') : '';
  $vars['css'] = drupal_add_css();
  $vars['styles'] = drupal_get_css();
  $vars['scripts'] = drupal_get_js();
}

/**
 * SimpleAds Filter form to insert Ads.
 */
function _simpleads_filter_form() {

  $form['simpleads_filter'] = array(
    '#type' => 'fieldset',
    '#title' => t('Insert Ad Block'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#attributes' => array('class' => array('clearfix')),
  );

  $ad_group_vid = db_select('taxonomy_vocabulary', 'tv')->fields('tv', array('vid'))->condition('machine_name', 'ad_groups')->execute()->fetchField();
  $results = db_select('taxonomy_term_data', 'td')->fields('td', array('tid', 'name'))->condition('vid', $ad_group_vid)->execute();
  $terms = array();
  foreach ($results as $record) {
    $terms[$record->tid] = check_plain($record->name);
  }

  $options = array();
  for ($i = 1; $i < 11; $i++) {
    $options[$i] = $i;
  }

  $form['simpleads_filter']['tid'] = array(
    '#type' => 'select',
    '#title' => t('Ad Group'),
    '#options' => $terms,
  );

  $form['simpleads_filter']['num'] = array(
    '#type' => 'select',
    '#title' => t('Number of Ads to Display'),
    '#options' => $options,
  );

  $form['insert'] = array(
    '#type' => 'button',
    '#value' => t('Insert'),
    '#attributes' => array('style' => 'margin-right: 5px;'),
  );

  $form['cancel'] = array(
    '#type' => 'button',
    '#value' => t('Cancel'),
  );

  return $form;
}

/**
 * Implements hook_element_info_alter().
 */
function simpleads_element_info_alter(&$types) {
  if (isset($types['text_format']['#pre_render']) && is_array($types['text_format']['#pre_render'])) {
    if (in_array('ckeditor_pre_render_text_format', $types['text_format']['#pre_render'])) {
      _simpleads_filter_add_settings('ckeditor');
    }
  }
}

/**
 * SimpleAds Filter global JS variables.
 */
function _simpleads_filter_add_settings($editor) {
  static $editor_settings_added = array();
  static $global_settings_added = FALSE;

  if (!isset($editor_settings_added[$editor])) {
    $editor_settings_added[$editor] = TRUE;
    $settings = array(
      'simpleads' => array('url' => array($editor => url('simpleads/dashboard/' . $editor))),
    );
    drupal_add_js($settings, 'setting');
  }

  if (!$global_settings_added) {
    $global_settings_added = TRUE;
    $settings = array(
      'simpleads' => array(
        'modulepath' => drupal_get_path('module', 'simpleads'),
      ),
    );
    drupal_add_js($settings, 'setting');
  }
}