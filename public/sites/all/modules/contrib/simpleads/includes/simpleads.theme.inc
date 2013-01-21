<?php

/**
 * @file
 * SimpleAds Theme.
 */

/**
 * Implements hook_theme().
 */
function simpleads_theme($existing, $type, $theme, $path) {
  return array(
    'simpleads_block' => array(
      'variables' => array('tid' => NULL, 'prefix' => NULL, 'ads_limit' => NULL, 'ads_page' => NULL, 'ads_width' => NULL, 'ads_height' => NULL),
      'path' => $path . '/templates',
      'template' => 'simpleads_block',
      'preprocess functions' => array(
        'simpleads_preprocess_simpleads_block',
      ),
    ),
    'simpleads_ajax_call' => array(
      'variables' => array('content' => NULL, 'total_ads' => NULL, 'tid' => NULL, 'settings' => NULL),
      'path' => $path . '/templates',
      'template' => 'simpleads_ajax_call',
    ),
    'simpleads_img_element' => array(
      'variables' => array('ad' => NULL, 'settings' => NULL, 'css_class' => NULL),
      'path' => $path . '/templates',
      'template' => 'simpleads_img_element',
      'preprocess functions' => array(
        'simpleads_preprocess_simpleads_img_element',
      ),
    ),
    'simpleads_text_element' => array(
      'variables' => array('ad' => NULL, 'settings' => NULL, 'css_class' => NULL),
      'path' => $path . '/templates',
      'template' => 'simpleads_text_element',
      'preprocess functions' => array(
        'simpleads_preprocess_simpleads_text_element',
      ),
    ),
    'simpleads_flash_element' => array(
      'variables' => array('ad' => NULL, 'settings' => NULL, 'css_class' => NULL),
      'path' => $path . '/templates',
      'template' => 'simpleads_flash_element',
      'preprocess functions' => array(
        'simpleads_preprocess_simpleads_flash_element',
      ),
    ),
    'simpleads_filter_dashboard' => array(
      'variables' => array('form' => NULL),
      'path' => $path . '/templates',
      'template' => 'simpleads_filter_dashboard',
    ),
  );
}

/**
 * Preprocess for simpleads_block.tpl.php
 */
function simpleads_preprocess_simpleads_block(&$vars) {
  global $user;
  $ads = array();

  $vars = _simpleads_theme_attributes_init($vars);

  $tid = $vars['tid'];
  $limit = $vars['ads_limit'];

  if (is_numeric($tid)) {
    $ads = _simpleads_load_ads($tid, $limit);
  }
  $vars['ads'] = $ads;
  $vars['user_id'] = $user->uid;
}

/**
 * Preprocess for simpleads_img_element.tpl.php
 */
function simpleads_preprocess_simpleads_img_element(&$vars) {
  $link_attributes = array();
  $image_attributes = array();
  $vars = _simpleads_theme_attributes_init($vars);
  _simpleads_increase_impression($vars['ad']['node']);
  // Image attributes
  $image_attributes['path'] = $vars['ad']['image_uri'];
  $image_attributes['alt'] = check_plain($vars['ad']['alt']);
  if (isset($vars['settings']['ads_width']) && is_numeric($vars['settings']['ads_width'])) {
    $image_attributes['width'] = check_plain($vars['settings']['ads_width']);
  }
  if (isset($vars['settings']['ads_height']) && is_numeric($vars['settings']['ads_height'])) {
    $image_attributes['height'] = check_plain($vars['settings']['ads_height']);
  }

  // Link attributes
  $link_attributes['html'] = TRUE;
  if ($vars['ad']['target'] && !user_access('administer nodes')) {
    $link_attributes['attributes']['target'] = '_blank';
  }

  $vars['link_attributes'] = $link_attributes;
  $vars['image_attributes'] = $image_attributes;
}

/**
 * Preprocess for simpleads_text_element.tpl.php
 */
function simpleads_preprocess_simpleads_text_element(&$vars) {
  $link_attributes = array();
  $vars = _simpleads_theme_attributes_init($vars);
  _simpleads_increase_impression($vars['ad']['node']);
  // Link attributes
  $link_attributes['html'] = TRUE;
  if ($vars['ad']['target'] && !user_access('administer nodes')) {
    $link_attributes['attributes']['target'] = '_blank';
  }
  $text_ad = "";
  if (!empty($vars['ad']['destination_url']) && $vars['ad']['text_format'] == 'plain_text') {
    $text_ad = l($vars['ad']['text'], $vars['ad']['url'], $link_attributes);
  }
  else {
    $text_ad = $vars['ad']['text'];
  }

  $vars['text_ad'] = $text_ad;
}

/**
 * Preprocess for simpleads_flash_element.tpl.php
 */
function simpleads_preprocess_simpleads_flash_element(&$vars) {
  $vars = _simpleads_theme_attributes_init($vars);
  _simpleads_increase_impression($vars['ad']['node']);
}

/**
 * Preprocess for SimpleAds Views template.
 * views-simpleads.tpl.php
 */
function template_preprocess_views_simpleads(&$vars) {
  $tid = 0;
  $ads = array();
  $ad_settings = array();
  $block_settings = array();
  $view = $vars['view'];
  $rows = $vars['rows'];
  $options = $vars['options'];
  $limit = check_plain($view->query->limit);

  if (count($rows) > 0) {
    foreach ($rows as $i => $data) {
      if (isset($data->field_field_ad_category[0])) {
        $tid = $data->field_field_ad_category[0]['raw']['tid'];
        $node = $data->_field_data['nid']['entity'];
        $ads[] = _simpleads_ads_data($node);
      }
    }
  };

  $prefix = 'views-' . $view->name . '-' . $tid . '-' . rand(1, 1000);

  $ad_settings['ads_height'] = $options['ads_height'];
  $ad_settings['ads_width'] = $options['ads_width'];

  $block_settings['ads_rotation_type'] = $options['ads_rotation_type'];
  $block_settings['ads_rotation_delay'] = $options['ads_rotation_delay'];
  $block_settings['block_delta'] = $prefix;

  $vars['tid'] = $tid;
  $vars['prefix'] = $prefix;
  $vars['ads_list'] = _simpleads_render_ajax_template($ads, $tid, $limit, $ad_settings, $block_settings);
}