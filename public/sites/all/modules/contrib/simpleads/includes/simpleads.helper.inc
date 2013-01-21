<?php

/**
 * @file
 * SimpleAds Helper functions.
 */

/**
 * Helper function.
 * Returns data array for an adertisement block.
 *
 * @param int $tid
 * @param int $limit
 * @return array
 */
function _simpleads_load_ads($tid, $limit) {

  $result = array();
  $term_ids = array();

  if (is_array($tid)) $term_ids = $tid; else $term_ids[] = $tid;

  if (is_numeric($limit)) {

    $ad_settings = _simpleads_adgroup_settings($tid);
    $order_delta = isset($ad_settings['ads_order']) ? $ad_settings['ads_order'] : 'random';
    $queries = module_invoke_all('simpleads_order', $order_delta, $term_ids, $limit);

    if (count($queries) > 0) {
      foreach ($queries as $i => $query) {
        foreach ($queries[$i] as $row) {
          $node = node_load($row->nid);
          $active = TRUE;
          if (isset($node->field_ad_status[$node->language])) {
            if ($node->field_ad_status[$node->language][0]['value'] != 1) {
              $active = FALSE;
            }
          }
          if ($active) {
            $result[] = _simpleads_ads_data($node);
          }
        }
      }
    }

  }

  return $result;
}

/**
 * Helper function.
 * Builts array for templates.
 * @param object $node
 */
function _simpleads_ads_data($node) {
  $data = &drupal_static(__FUNCTION__);
  if (is_object($node)) {
    $type = 'graphic';
    if (isset($node->field_ad_type[$node->language]) && !empty($node->field_ad_type[$node->language][0]['value'])) {
      $type = $node->field_ad_type[$node->language][0]['value'];
    }
    $destination_url = "";
    if (isset($node->field_ad_url[$node->language]) && !empty($node->field_ad_url[$node->language][0]['value'])) {
      $destination_url = $node->field_ad_url[$node->language][0]['value'];
    }
    $image = "";
    $image_uri = "";
    $alt = "";
    if (isset($node->field_ad_image[$node->language]) && !empty($node->field_ad_image[$node->language][0]['uri'])) {
      $image = file_create_url($node->field_ad_image[$node->language][0]['uri']);
      $alt = $node->field_ad_image[$node->language][0]['alt'];
      $image_uri = $node->field_ad_image[$node->language][0]['uri'];
    }
    $flash = "";
    if (isset($node->field_ad_flash[$node->language]) && !empty($node->field_ad_flash[$node->language][0]['uri'])) {
      $flash = file_create_url($node->field_ad_flash[$node->language][0]['uri']);
    }
    $text_ad = "";
    $text_format = "plain_text";
    if (isset($node->field_ad_text[$node->language]) && !empty($node->field_ad_text[$node->language][0]['value'])) {
      if (isset($node->field_ad_text[$node->language]) && $node->field_ad_text[$node->language][0]['format'] != $text_format) {
        $text_format = $node->field_ad_text[$node->language][0]['format'];
        $text_ad = check_markup($node->field_ad_text[$node->language][0]['value'], $text_format);
      }
      else {
        $text_ad = strip_tags($node->field_ad_text[$node->language][0]['value']);
      }
    }
    $target = TRUE;
    if (isset($node->field_ad_url_taget[$node->language]) && $node->field_ad_url_taget[$node->language][0]['value'] == 0) {
      $target = FALSE;
    }

    $data = array(
      'type' => $type,
      'url' => url('simpleads/redirect/' . $node->nid, array('absolute' => TRUE)),
      'destination_url' => $destination_url,
      'target' => $target,
      'image' => $image,
      'image_uri' => $image_uri,
      'alt' => $alt,
      'nid' => $node->nid,
      'node' => $node,
      'text' => $text_ad,
      'text_format' => $text_format,
      'flash' => $flash,
    );
    drupal_alter('simpleads', $data);
    return $data;
  }
}

/**
 * Helper function.
 * Return rendered SimpleAds block template.
 *
 * @param array $nodes
 * @param int $tid
 * @param int $limit
 * @param array $settings1
 * @param array $settings2
 * @return string
 */
function _simpleads_render_ajax_template($nodes, $tid, $limit, $settings1 = array(), $settings2 = array()) {
  $settings = array();
  $result = "";
  $count = 0;
  foreach ($nodes as $ad) {
    $ad_block = db_select('simpleads_blocks', 'sb')->fields('sb', array('settings'))->condition('sb.tid', $tid)->execute()->fetchField();
    $this_ad_setting = unserialize($ad_block);

    if (count($settings1) > 0) $ad_setting = array_merge($this_ad_setting, $settings1);
    else $ad_setting = $this_ad_setting;

    $css_class = array();
    if ($count == 0) $css_class = array('first');
    else {
      if ($count == (count($nodes) - 1)) {
        $css_class = array('last');
      }
    }

    if ($ad['type'] == 'graphic') {
      $result .= theme('simpleads_img_element', array('ad' => $ad, 'settings' => $ad_setting, 'css_class' => $css_class));
    }
    elseif ($ad['type'] == 'text') {
      $result .= theme('simpleads_text_element', array('ad' => $ad, 'settings' => $ad_setting, 'css_class' => $css_class));
    }
    else {
      $result .= theme('simpleads_flash_element', array('ad' => $ad, 'settings' => $ad_setting, 'css_class' => $css_class));
    }
    $count++;
  }
  $this_block_settings = _simpleads_adgroup_settings($tid);

  if (count($settings2) > 0) $settings = array_merge($this_block_settings, $settings2);
  else $settings = $this_block_settings;

  return theme('simpleads_ajax_call', array('content' => $result, 'total_ads' => $count, 'tid' => $tid, 'settings' => $settings));
}

/**
 * Helper function.
 * Return node id from arguments (used in hook_menu).
 */
function simpleadsid_to_arg($arg) {
  if ($arg == '%') return 'none'; else return $arg;
}

/**
 * Access callback.
 * Node Ad stats tab.
 */
function _simpleads_node_stat_tab() {
  if (arg(0) == 'node' && is_numeric(arg(1))) {
    $node = node_load(arg(1));
    if (is_object($node) && $node->type == 'simpleads' && user_access('access ad statistics')) return TRUE; else return FALSE;
  }
  else {
    return FALSE;
  }
}

/**
 * Helper procedure.
 * Saves ad clicks.
 *
 * @param int $nid
 */
function _simpleads_save_click($node) {
  module_invoke_all('simpleads_ad_click', 'insert', $node);
}

/**
 * Helper procedure.
 * Deletes ad clicks.
 *
 * @param int $nid
 */
function _simpleads_delete_click($node) {
  module_invoke_all('simpleads_ad_click', 'delete', $node);
}

/**
 * Helper procedure.
 * Saves ad impressions
 *
 * @param int $nid
 */
function _simpleads_save_impression($node) {
  module_invoke_all('simpleads_ad_impression', 'insert', $node);
}

/**
 * Helper procedure.
 * Deletes ad impressions.
 *
 * @param int $nid
 */
function _simpleads_delete_impression($node) {
  module_invoke_all('simpleads_ad_impression', 'delete', $node);
}

/**
 * Helper functon.
 * Increases impressions counter.
 *
 * @global object $user
 * @param object $node
 */
function _simpleads_increase_impression($node) {
  global $user;
  _simpleads_save_impression($node);
}

/**
 * Helper function.
 * Return TRUE if the visitor is a bot.
 * @return boolean
 */
function _simpleads_bot_detect() {
  if (preg_match('/bot|crawl|slurp|spider/i', $_SERVER['HTTP_USER_AGENT'])) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

/**
 * Helper function.
 * Returns node object if not executed in hook_cron().
 *
 * @param object $node
 * @param string $who
 * @return object
 */
function _simpleads_activate_deactive_ad($node, $who = 'cron') {
  $start_time = '';
  $end_time = '';

  if (isset($node->field_ad_start_date[$node->language]) && !empty($node->field_ad_start_date[$node->language][0]['value'])) {
    $start_time = $node->field_ad_start_date[$node->language][0]['value'];
  }
  if (isset($node->field_ad_end_date[$node->language]) && !empty($node->field_ad_end_date[$node->language][0]['value'])) {
    $end_time = $node->field_ad_end_date[$node->language][0]['value'];
  }

  $start_time = (int)strtotime($start_time);
  $end_time = (int)strtotime($end_time);

  $now = REQUEST_TIME;

  if ($start_time != '' && $end_time != '') {
    if ($now >= $start_time && $end_time > $now) {
      $node->status = 1;
      if ($who == 'cron') {
        node_save($node);
      }
    }
    elseif ($end_time <= $now) {
      $node->status = 0;
      if ($who == 'cron') {
        node_save($node);
      }
    }
  }
  elseif ($start_time == '' && $end_time != '') {
    if ($end_time <= $now) {
      $node->status = 0;
      if ($who == 'cron') {
        node_save($node);
      }
    }
    else {
      $node->status = 1;
      if ($who == 'cron') {
        node_save($node);
      }
    }
  }
  else {
    if ($now >= $start_time && $start_time != '') {
      $node->status = 1;
      if ($who == 'cron') {
        node_save($node);
      }
    }
  }
  if ($who != 'cron') {
    return $node;
  }
  else {
    module_invoke_all('simpleads_status_change', $node, $node->status);
  }
}

/**
 * Helper function.
 * Get block settings by ad group id.
 *
 * @param int $tid
 * @return array
 */
function _simpleads_adgroup_settings($tid) {
  if (is_numeric($tid)) {
    $block = db_select('simpleads_blocks', 'sb')->fields('sb')->condition('sb.tid', $tid)->execute()->fetchObject();
    return unserialize($block->settings);
  }
  else {
    return FALSE;
  }
}

/**
 * Helper funciton.
 * Returns array of supported effects types for blocks.
 */
function _simpleads_rotation_effects() {
  return array(
    0 => t('None'),
    1 => t('Default'),
    2 => t('Fast FadeIn'),
  );
}

/**
 * Helper function.
 * Adds additional information to statistics page.
 *
 * @param object $node
 * @param string $op
 * @return string
 */
function _simpleads_stats_info($node, $op = 'list') {
  $result = array();
  $c = 0;
  if ($hook = module_invoke_all('simpleads_stats_info', $node, $op)) {
    if (is_array($hook) && !empty($hook)) {
      foreach ($hook as $data) {
        $result[] = '<div class="stat-item">' . $data . '</div>';
      }
      return '<div class="simpleads-stat-' . $op . '">' . join("", $result) . '</div>';
    }
  }
}

/**
 * Helper function.
 * Build query to get the list of ads for the Ads Listing page.
 *
 * @param array $filter
 * @return query
 */
function _simpleads_ads_listing_query($filter = array()) {
  if ($filter['adgroup'] == '') {
    $query = db_select('node', 'n')->extend('PagerDefault')->limit($filter['adsperpage']);
    $query->fields('n', array('nid'));
    $query->condition('n.type', 'simpleads');

    if ($filter['adstatus'] != '') {
      $query->condition('n.status', $filter['adstatus']);
    }
    $results = $query->execute();
  }
  else {
    $query = db_select('node', 'n')->extend('PagerDefault')->limit($filter['adsperpage']);
    $query->leftJoin('taxonomy_index', 'ti', 'ti.nid = n.nid');
    $query->fields('n', array('nid'));
    $query->addTag('node_access');
    $query->condition('n.type', 'simpleads');
    if (isset($filter['adgroup'])) {
      $query->condition('ti.tid', $filter['adgroup']);
    }

    if ($filter['adstatus'] != '') {
      $query->condition('n.status', $filter['adstatus']);
    }

    $results = $query->execute();
  }
  return $results;
}

/**
 * Helper function.
 * Validates redirection URL.
 */
function _simpleads_validate_url($url) {
  if (!preg_match("~^(?:f|ht)tps?://~i", $url)) {
    // Allow internal url if user has access to it.
    if (drupal_valid_path($url)) {
      $url = url($url, array('absolute' => TRUE));
    }
    else {
      $url = 'http://' . $url;
    }
  }
  else {
    $url = url($url, array('absolute' => TRUE));
  }
  return $url;
}

/**
 * Helper function.
 */
function _simpleads_theme_attributes_init($vars) {
  $vars['attributes_array'] = array();
  $vars['title_attributes_array'] = array();
  $vars['content_attributes_array'] = array();
  $vars['classes_array'] = array('');
  if (isset($vars['css_class']) && count($vars['css_class']) > 0) {
    $vars['css_attributes'] = join(" ", $vars['css_class']);
  }
  else {
    $vars['css_attributes'] = '';
  }
  return $vars;
}