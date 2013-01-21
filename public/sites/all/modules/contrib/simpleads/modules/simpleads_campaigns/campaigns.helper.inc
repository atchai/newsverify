<?php

/**
 * @file
 * SimpleAds helper functions.
 */

/**
 * Helper function.
 * Timestamp to days.
 *
 * @param int $ustart_time
 * - Start timestamp
 *
 * @param int $uend_time
 * - End timestamp
 */
function _simpleads_campains_date_diff($ustart_time, $uend_time) {
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
 * Check campaign criterias and set ads to active/inactive states.
 */
function _simpleads_campaigns_watch() {

  $results = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('n.status', 1)
    ->condition('n.type', 'simpleads_campaign')
    ->orderBy('n.title')
    ->execute();

  foreach ($results as $row) {
    _simpleads_campaigns_complete($row->nid);
  }
}

/**
 * Helper function.
 * Deactivate ad if the ad riches campaings limits.
 * @param int $nid
 */
function _simpleads_campaigns_complete($campaign_nid, $ad_node = FALSE) {
  // Check campaign filter for all ads within the given campaign.
  if (!is_object($ad_node)) {
    $campaign = node_load($campaign_nid);
    $query = db_select('node', 'n');
    $query->join('field_data_field_adcamp_list', 'l', 'l.entity_id = n.nid AND l.revision_id = n.vid');
    $query->fields('n', array('nid'));
    $query->condition('n.status', 1)
      ->condition('n.type', 'simpleads')
      ->condition('l.field_adcamp_list_value', $campaign->nid)
      ->orderBy('n.title');
    $ads = $query->execute();
  }
  // check compaign filter for single ad.
  else {
    $node = $ad_node;
    $ads = array($node);
    if (isset($node->field_adcamp_list[$node->language]) && is_numeric($node->field_adcamp_list[$node->language][0]['safe_value'])) {
      $campaign = node_load($node->field_adcamp_list[$node->language][0]['safe_value']);
    }
  }

  $by_impressions = FALSE;
  $impressions_number = "";
  $by_clicks = FALSE;
  $clicks_number = "";
  $by_days = FALSE;
  $days_number = "";

  $campaign_start_time = "";
  if (isset($campaign->field_adcamp_start[$campaign->language]) && !empty($campaign->field_adcamp_start[$campaign->language][0]['value'])) {
    $campaign_start_time = $campaign->field_adcamp_start[$campaign->language][0]['value'];
  }
  $campaign_start_time = strtotime($campaign_start_time);

  if (isset($campaign->field_adcamp_impression[$campaign->language]) && $campaign->field_adcamp_impression[$campaign->language][0]['value'] == 1) {
    $by_impressions = TRUE;
    if (isset($campaign->field_adcamp_impressions[$campaign->language]) && !empty($campaign->field_adcamp_impressions[$campaign->language][0]['safe_value'])) {
      $impressions_number = $campaign->field_adcamp_impressions[$campaign->language][0]['safe_value'];
    }
  }

  if (isset($campaign->field_adcamp_click[$campaign->language]) && $campaign->field_adcamp_click[$campaign->language][0]['value'] == 1) {
    $by_clicks = TRUE;
    if (isset($campaign->field_adcamp_clicks[$campaign->language]) && !empty($campaign->field_adcamp_clicks[$campaign->language][0]['safe_value'])) {
      $clicks_number = $campaign->field_adcamp_clicks[$campaign->language][0]['safe_value'];
    }
  }

  if (isset($campaign->field_adcamp_day[$campaign->language]) && $campaign->field_adcamp_day[$campaign->language][0]['value'] == 1) {
    $by_days = TRUE;
    if (isset($campaign->field_adcamp_days[$campaign->language]) && !empty($campaign->field_adcamp_days[$campaign->language][0]['safe_value'])) {
      $days_number = $campaign->field_adcamp_days[$campaign->language][0]['safe_value'];
    }
  }

  foreach ($ads as $ad) {
    if (!is_object($ad_node)) {
      $node = node_load($ad->nid);
    }
    $all_clicks = _simpleads_campaigns_count_ad_clicks($campaign_start_time, $ad->nid);
    $all_impressions = _simpleads_campaigns_count_ad_impressions($campaign_start_time, $ad->nid);

    $campaign_end_time = REQUEST_TIME - (24 * 3600 * $days_number);
    $days_left = _simpleads_campains_date_diff($campaign_end_time, $campaign_start_time);
    if ($by_impressions && $by_clicks && $by_days) {
      if ($all_impressions >= $impressions_number || $all_clicks >= $clicks_number || $days_left <= 0) {
        module_invoke_all('simpleads_campaign_complete', $node);
      }
    }
    elseif ($by_impressions && $by_clicks && !$by_days) {
      if ($all_impressions >= $impressions_number || $all_clicks >= $clicks_number) {
        module_invoke_all('simpleads_campaign_complete', $node);
      }
    }
    elseif (!$by_impressions && $by_clicks && !$by_days) {
      if ($all_clicks >= $clicks_number) {
        module_invoke_all('simpleads_campaign_complete', $node);
      }
    }
    elseif (!$by_impressions && !$by_clicks && !$by_days) {
      if ($days_left <= 0) {
        module_invoke_all('simpleads_campaign_complete', $node);
      }
    }
    elseif ($by_impressions && !$by_clicks && !$by_days) {
      if ($all_impressions >= $impressions_number) {
        module_invoke_all('simpleads_campaign_complete', $node);
      }
    }

  }
}

/**
 * Helper function.
 * Get number of unique impressions.
 *
 * @param int $timestamp
 * @param int $nid
 */
function _simpleads_campaigns_count_ad_impressions($timestamp, $nid) {
  $count = db_select('simpleads_impressions', 'sc')
  ->condition("sc.nid", $nid)->condition('sc.timestamp', $timestamp, '>=')->groupBy('sc.ip_address')
  ->countQuery()->execute()->fetchField();
  return $count;
}

/**
 * Helper function.
 * Get number of unique clicks.
 *
 * @param int $timestamp
 * @param int $nid
 */
function _simpleads_campaigns_count_ad_clicks($timestamp, $nid) {
  $count = db_select('simpleads_clicks', 'sc')
  ->condition("sc.nid", $nid)->condition('sc.timestamp', $timestamp, '>=')->groupBy('sc.ip_address')
  ->countQuery()->execute()->fetchField();
  return $count;
}