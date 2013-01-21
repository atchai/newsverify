<?php

/**
 * @file
 * SimpleAds Statistics.
 */

/**
 * Callback for Ad Statistics page.
 */
function _simpleads_stat_tab($nid) {
  $result = " ";

  $form_after_stats = drupal_render(drupal_get_form('_simpleads_after_stats_form'));

  if (is_numeric($nid)) {
    $node = node_load($nid);
    if ($node) {
      $stats = _simpleads_get_statistics('simpleads_clicks', $nid);
      $stat_results = array();
      foreach ($stats as $key => $val) {
        $header[]['data'] = t($key);
        $stat_results[]['data'] = $val;
      }

      $clicks[] = $stat_results;

      $stats = _simpleads_get_statistics('simpleads_impressions', $nid);
      $stat_results = array();
      foreach ($stats as $key => $val) {
        $stat_results[]['data'] = $val;
      }

      $impressions[] = $stat_results;

      $term_name = "";
      $op_links = l(t('Edit'), 'node/' . $node->nid . '/edit', array('query' => array('destination' => 'admin/content/simpleads')));
      if (isset($node->field_ad_category[$node->language]) && !empty($node->field_ad_category[$node->language][0]['tid'])) {
        $term = taxonomy_term_load($node->field_ad_category[$node->language][0]['tid']);
        $term_name = $term->name;
      }
      elseif (isset($node->field_ad_category[LANGUAGE_NONE]) && !empty($node->field_ad_category[LANGUAGE_NONE][0]['tid'])) {
        $term = taxonomy_term_load($node->field_ad_category[LANGUAGE_NONE][0]['tid']);
        $term_name = $term->name;
      }

      $result .= '<h1>' . t("@adgroup: @adtitle - !link", array('@adgroup' => $term_name, '@adtitle' => $node->title, '!link' => $op_links)) . '</h1>';
      $result .= '<span>' . _simpleads_stats_info($node, 'ad_status_detail') . '</span>';
      $result .= _simpleads_stats_info($node, 'detail');

      $result .= theme('table', array('header' => $header, 'rows' => $clicks, 'caption' => t('Ad Clicks / Unique Clicks')));
      $result .= theme('table', array('header' => $header, 'rows' => $impressions, 'caption' => t('Ad Impressions / Unique Impressions')));
      $result .= $form_after_stats;
    }
  }

  return $result;
}

/**
 * Empty Form placeholder. Allows other modules to alter the form and add custom data below Ads Statistics tables.
 */
function _simpleads_after_stats_form() {
  $form = array();
  $form['markup_field'] = array(
    '#markup' => '',
  );
  return $form;
}

/**
 * Empty Form placeholder. Allows other modules to alter the form and add custom data below Ads listing table.
 */
function _simpleads_after_listing_form() {
  $form = array();
  $form['markup_field'] = array(
    '#markup' => '',
  );
  return $form;
}

/**
 * Ad Groups Filter form.
 */
function _simpleads_group_filter_form() {
  $form = array();

  $terms = array('' => t('Show All'));
  $vid = db_select('taxonomy_vocabulary', 'tv')->fields('tv', array('vid'))->condition('tv.machine_name', 'ad_groups')->execute()->fetchField();
  $results = db_select('taxonomy_term_data', 'td')->fields('td', array('tid', 'name'))->condition('td.vid', $vid)->execute();
  foreach ($results as $record) {
    $terms[$record->tid] = $record->name;
  }

  $filter = array('adgroup' => '', 'adstatus' => '', 'adsperpage' => 35);
  $filters = variable_get('simpleads_filters', FALSE);
  if ($filters) {
    $filter = unserialize($filters);
  }

  $form['ad_filter'] = array(
    '#type' => 'fieldset',
  );

  $form['ad_filter']['css'] = array(
    '#markup' => '<style>
      #-simpleads-group-filter-form .form-item { float: left; margin-right: 10px; }
      #-simpleads-group-filter-form .form-item .form-submit { margin-top: 20px; }
      </style>',
  );

  $form['ad_filter']['adgroup'] = array(
    '#type' => 'select',
    '#title' => t('Ad Group'),
    '#options' => $terms,
    '#default_value' => $filter['adgroup'],
  );

  $statuses = array(
    '' => t('All'),
    1 => t('Active'),
    0 => t('Inactive'),
  );

  $form['ad_filter']['adstatus'] = array(
    '#type' => 'select',
    '#title' => t('Status'),
    '#options' => $statuses,
    '#default_value' => $filter['adstatus'],
  );

  $pages = array(
    5 => 5,
    10 => 10,
    25 => 25,
    35 => 35,
    45 => 45,
    75 => 75,
    100 => 100,
  );

  $form['ad_filter']['adsperpage'] = array(
    '#type' => 'select',
    '#title' => t('Ads per page'),
    '#options' => $pages,
    '#default_value' => $filter['adsperpage'],
  );

  $form['ad_filter']['filter'] = array(
    '#type' => 'submit',
    '#value' => t('Filter'),
    '#prefix' => '<div class="form-item">',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Form submit.
 */
function _simpleads_group_filter_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $filter = array(
    'adgroup' => $values['adgroup'],
    'adstatus' => $values['adstatus'],
    'adsperpage' => $values['adsperpage'],
  );
  variable_set('simpleads_filters', serialize($filter));
}

/**
 * Callback for Ads Listing page.
 */
function _simpleads_listing() {
  drupal_set_title(t('Advertisement Listing'));

  $filter_render = drupal_get_form('_simpleads_group_filter_form');
  $filter_form = drupal_render($filter_render);
  $listing_render = drupal_get_form('_simpleads_after_listing_form');
  $form_after_listing = drupal_render($listing_render);

  $header = array(
    array('data' => t('Ad Title')),
    array('data' => t('Ad Group')),
    array('data' => t('Status')),
    array('data' => t('Active')),
    array('data' => t('Operations')),
  );

  $filter = array('adgroup' => '', 'adstatus' => '', 'adsperpage' => 35);
  $filters = variable_get('simpleads_filters', FALSE);
  if ($filters) {
    $filter = unserialize($filters);
  }

  $results = _simpleads_ads_listing_query($filter);

  $rows = array();
  foreach ($results as $record) {

    $node = node_load($record->nid);
    if ($node) {

      $ad_title = _simpleads_stats_info($node, 'list');
      $ad_group = _simpleads_stats_info($node, 'ad_group');

      $rows[] = array(
        array('data' => $ad_title),
        array('data' => $ad_group),
        array('data' => _simpleads_stats_info($node, 'ad_status')),
        array('data' => _simpleads_stats_info($node, 'ad_activity')),
        array('data' => _simpleads_stats_info($node, 'ad_operations')),
      );
    }
  }
  return $filter_form . theme('table', array('header' => $header, 'rows' => $rows, 'empty' => t('There are no Ads'))) . theme('pager') . $form_after_listing;
}

/**
 * Helper function.
 * Display Ad statuses.
 */
function _simpleads_statuses($node) {
  $status = "";

  $start_time = "";
  $end_time = "";

  if (isset($node->field_ad_start_date[$node->language]) && !empty($node->field_ad_start_date[$node->language][0]['value'])) {
    $start_time = $node->field_ad_start_date[$node->language][0]['value'];
  }
  if (isset($node->field_ad_end_date[$node->language]) && !empty($node->field_ad_end_date[$node->language][0]['value'])) {
    $end_time = $node->field_ad_end_date[$node->language][0]['value'];
  }

  $ustart_time = strtotime(check_plain($start_time));
  $uend_time = strtotime(check_plain($end_time));
  $now = time();

  if ($node->status == 1) {
    $status .= t("Published");

    if ($start_time != '' && $end_time != '') {
      $status .= ", " . t("Active during (@startdate - @enddate)", array('@startdate' => $start_time, '@enddate' => $end_time));
    }
    elseif ($start_time == '' && $end_time != '') {
      $status .= ", " . t("Expires on @datetime", array('@datetime' => $end_time));
    }

  }
  else {
    $status .= t("Not Published");

    if ($start_time != '' && $end_time != '') {
      if ($uend_time <= $now) {
        $status = t("Expired on @datetime", array('@datetime' => $end_time));
      }
      else {
        $status .= ", " . t("Start from (@startdate - @enddate)", array('@startdate' => $start_time, '@enddate' => $end_time));
      }
    }
    elseif ($start_time == '' && $end_time != '') {
      if ($uend_time <= $now) {
        $status = t("Expired on @datetime", array('@datetime' => $end_time));
      }
      else {
        $status .= ", " . t("Expires on @datetime", array('@datetime' => $end_time));
      }
    }
  }
  return $status;
}

/**
 * Helper function.
 * Timestamp to days.
 */
function _simpleads_date_diff($node) {
  $start_time = "";
  $end_time = "";

  if (isset($node->field_ad_start_date[$node->language]) && !empty($node->field_ad_start_date[$node->language][0]['value'])) {
    $start_time = $node->field_ad_start_date[$node->language][0]['value'];
  }
  if (isset($node->field_ad_end_date[$node->language]) && !empty($node->field_ad_end_date[$node->language][0]['value'])) {
    $end_time = $node->field_ad_end_date[$node->language][0]['value'];
  }

  $ustart_time = strtotime($start_time);
  $uend_time = strtotime($end_time);
  $now = time();

  if ($ustart_time == '' && $uend_time != '') {
    return floor(($uend_time - $now) / 86400);
  }
  elseif ($ustart_time != '' && $uend_time != '') {
    return floor(($uend_time - $ustart_time) / 86400);
  }
  elseif ($ustart_time == '' && $uend_time == '') {
    return FALSE;
  }
  else {
    return 0;
  }
}

/**
 * Helper function.
 * Returns stats for given table name.
 */
function _simpleads_get_statistics($table, $nid) {
  $stats = array();

  $stats['Last Hour'] = db_select($table, 'sc')
  ->where("FROM_UNIXTIME(sc.timestamp) <= NOW() AND FROM_UNIXTIME(sc.timestamp) >= SUBDATE(NOW(), INTERVAL 1 HOUR)")->condition("sc.nid", $nid)
  ->countQuery()->execute()->fetchField() . '/' . db_select($table, 'sc')
  ->where("FROM_UNIXTIME(sc.timestamp) <= NOW() AND FROM_UNIXTIME(sc.timestamp) >= SUBDATE(NOW(), INTERVAL 1 HOUR)")->condition("sc.nid", $nid)->groupBy('sc.ip_address')
  ->countQuery()->execute()->fetchField();

  $stats['Today'] = db_select($table, 'sc')
  ->where("FROM_UNIXTIME(sc.timestamp, '%d%m%Y') = FROM_UNIXTIME(UNIX_TIMESTAMP(), '%d%m%Y')")->condition("sc.nid", $nid)
  ->countQuery()->execute()->fetchField() . '/' . db_select($table, 'sc')
  ->where("FROM_UNIXTIME(sc.timestamp, '%d%m%Y') = FROM_UNIXTIME(UNIX_TIMESTAMP(), '%d%m%Y')")->condition("sc.nid", $nid)->groupBy('sc.ip_address')
  ->countQuery()->execute()->fetchField();

  $stats['Yesterday'] = db_select($table, 'sc')
  ->where("FROM_UNIXTIME(sc.timestamp) <= NOW() AND FROM_UNIXTIME(sc.timestamp) >= SUBDATE(NOW(), INTERVAL 1 DAY)")->condition("sc.nid", $nid)
  ->countQuery()->execute()->fetchField() . '/' . db_select($table, 'sc')
  ->where("FROM_UNIXTIME(sc.timestamp) <= NOW() AND FROM_UNIXTIME(sc.timestamp) >= SUBDATE(NOW(), INTERVAL 1 DAY)")->condition("sc.nid", $nid)->groupBy('sc.ip_address')
  ->countQuery()->execute()->fetchField();

  $stats['Last Week'] = db_select($table, 'sc')
  ->where("FROM_UNIXTIME(sc.timestamp) <= NOW() AND FROM_UNIXTIME(sc.timestamp) >= SUBDATE(NOW(), INTERVAL 1 WEEK)")->condition("sc.nid", $nid)
  ->countQuery()->execute()->fetchField() . '/' . db_select($table, 'sc')
  ->where("FROM_UNIXTIME(sc.timestamp) <= NOW() AND FROM_UNIXTIME(sc.timestamp) >= SUBDATE(NOW(), INTERVAL 1 WEEK)")->condition("sc.nid", $nid)->groupBy('sc.ip_address')
  ->countQuery()->execute()->fetchField();

  $stats['Last Month'] = db_select($table, 'sc')
  ->where("FROM_UNIXTIME(sc.timestamp) <= NOW() AND FROM_UNIXTIME(sc.timestamp) >= SUBDATE(NOW(), INTERVAL 1 MONTH)")->condition("sc.nid", $nid)
  ->countQuery()->execute()->fetchField() . '/' . db_select($table, 'sc')
  ->where("FROM_UNIXTIME(sc.timestamp) <= NOW() AND FROM_UNIXTIME(sc.timestamp) >= SUBDATE(NOW(), INTERVAL 1 MONTH)")->condition("sc.nid", $nid)->groupBy('sc.ip_address')
  ->countQuery()->execute()->fetchField();

  $stats['3 Months'] = db_select($table, 'sc')
  ->where("FROM_UNIXTIME(sc.timestamp) <= NOW() AND FROM_UNIXTIME(sc.timestamp) >= SUBDATE(NOW(), INTERVAL 3 MONTH)")->condition("sc.nid", $nid)
  ->countQuery()->execute()->fetchField() . '/' . db_select($table, 'sc')
  ->where("FROM_UNIXTIME(sc.timestamp) <= NOW() AND FROM_UNIXTIME(sc.timestamp) >= SUBDATE(NOW(), INTERVAL 3 MONTH)")->condition("sc.nid", $nid)->groupBy('sc.ip_address')
  ->countQuery()->execute()->fetchField();

  $stats['6 Months'] = db_select($table, 'sc')
  ->where("FROM_UNIXTIME(sc.timestamp) <= NOW() AND FROM_UNIXTIME(sc.timestamp) >= SUBDATE(NOW(), INTERVAL 6 MONTH)")->condition("sc.nid", $nid)
  ->countQuery()->execute()->fetchField() . '/' . db_select($table, 'sc')
  ->where("FROM_UNIXTIME(sc.timestamp) <= NOW() AND FROM_UNIXTIME(sc.timestamp) >= SUBDATE(NOW(), INTERVAL 6 MONTH)")->condition("sc.nid", $nid)->groupBy('sc.ip_address')
  ->countQuery()->execute()->fetchField();

  $stats['1 year'] = db_select($table, 'sc')
  ->where("FROM_UNIXTIME(sc.timestamp) <= NOW() AND FROM_UNIXTIME(sc.timestamp) >= SUBDATE(NOW(), INTERVAL 1 YEAR)")->condition("sc.nid", $nid)
  ->countQuery()->execute()->fetchField() . '/' . db_select($table, 'sc')
  ->where("FROM_UNIXTIME(sc.timestamp) <= NOW() AND FROM_UNIXTIME(sc.timestamp) >= SUBDATE(NOW(), INTERVAL 1 YEAR)")->condition("sc.nid", $nid)->groupBy('sc.ip_address')
  ->countQuery()->execute()->fetchField();

  $stats['All Time'] = db_select($table)->condition('nid', $nid)->countQuery()->execute()->fetchField() . '/' . db_select($table)->condition('nid', $nid)->groupBy('ip_address')->countQuery()->execute()->fetchField();

  t('Last Hour');
  t('Today');
  t('Yesterday');
  t('Last Week');
  t('Last Month');
  t('3 Months');
  t('6 Months');
  t('1 year');
  t('All Time');

  return $stats;
}