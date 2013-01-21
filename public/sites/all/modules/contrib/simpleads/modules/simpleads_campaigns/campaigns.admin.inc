<?php

/**
 * @file
 * SimpleAds Campaigns menu callbacks.
 */

/**
 * Menu callback.
 * Redirect to SimpleAd Campiagn creation form.
 */
function _simpleads_campaign_new() {
  drupal_goto('node/add/simpleads-campaign', array('query' => array('destination' => 'admin/content/simpleads_campaigns')));
}

/**
 * Menu callback.
 * Campaigns listing page.
 */
function _simpleads_campaign_listing() {
  drupal_set_title(t('Advertisement Campaigns'));

  $header = array(
    array('data' => ''),
    array('data' => t('Campaign')),
    array('data' => t('Start Date')),
    array('data' => t('Impressions')),
    array('data' => t('Clicks')),
    array('data' => t('Days')),
    array('data' => t('Active')),
    array('data' => t('Operations')),
  );

  $query = db_select('node', 'n')->extend('PagerDefault')->limit(15);
  $query->fields('n', array('nid'));
  $query->condition('n.type', 'simpleads_campaign');
  $query->orderBy('n.changed', 'DESC');
  $results = $query->execute();

  $rows = array();
  foreach ($results as $i => $record) {

    $query = db_select('node', 'n');
    $query->join('field_data_field_adcamp_list', 'l', 'l.entity_id = n.nid AND l.revision_id = n.vid');
    $query->fields('n', array('nid'));
    $query->fields('l', array('field_adcamp_list_value'));
    $query->condition('n.type', 'simpleads');
    $query->condition('l.field_adcamp_list_value', $record->nid);
    $query->addTag('node_access');
    $count = $query->countQuery()->execute()->fetchField();

    $node = node_load($record->nid);
    if ($node) {
      $impressions = '-';
      if (isset($node->field_adcamp_impression[$node->language]) && $node->field_adcamp_impression[$node->language][0]['value'] == 1) {
        if (isset($node->field_adcamp_impressions[$node->language]) && !empty($node->field_adcamp_impressions[$node->language][0]['safe_value'])) {
          $impressions = $node->field_adcamp_impressions[$node->language][0]['safe_value'];
        }
      }
      $clicks = '-';
      if (isset($node->field_adcamp_click[$node->language]) && $node->field_adcamp_click[$node->language][0]['value'] == 1) {
        if (isset($node->field_adcamp_clicks[$node->language]) && !empty($node->field_adcamp_clicks[$node->language][0]['safe_value'])) {
          $clicks = $node->field_adcamp_clicks[$node->language][0]['safe_value'];
        }
      }
      $days = '-';
      if (isset($node->field_adcamp_day[$node->language]) && $node->field_adcamp_day[$node->language][0]['value'] == 1) {
        if (isset($node->field_adcamp_days[$node->language]) && !empty($node->field_adcamp_days[$node->language][0]['safe_value'])) {
          $days = $node->field_adcamp_days[$node->language][0]['safe_value'];
        }
      }
      $start_date = '-';
      if (isset($node->field_adcamp_start[$node->language]) && !empty($node->field_adcamp_start[$node->language][0]['value'])) {
        if (isset($node->field_adcamp_start[$node->language]) && !empty($node->field_adcamp_start[$node->language][0]['safe_value'])) {
          $start_date = $node->field_adcamp_start[$node->language][0]['safe_value'];
        }
      }
      $is_active = t('No');
      if ($node->status == 1) {
        $is_active = t('Yes');
      }
      $rows[] = array(
        array('data' => ($i + 1)),
        array('data' => l($node->title, 'admin/content/simpleads_campaigns/' . $node->nid) . ' (' . $count . ')'),
        array('data' => $start_date),
        array('data' => $impressions),
        array('data' => $clicks),
        array('data' => $days),
        array('data' => $is_active),
        array('data' => l(t('View'), 'admin/content/simpleads_campaigns/' . $node->nid, array('query' => array('destination' => 'admin/content/simpleads_campaigns'))) . '&nbsp;&nbsp; ' .
          l(t('Edit'), 'node/' . $node->nid . '/edit', array('query' => array('destination' => 'admin/content/simpleads_campaigns'))) . '&nbsp;&nbsp; ' .
          l(t('Delete'), 'node/' . $node->nid . '/delete', array('query' => array('destination' => 'admin/content/simpleads_campaigns'))) . '&nbsp;&nbsp; '
        ),
      );
    }
  }
  return theme('table', array('header' => $header, 'rows' => $rows, 'empty' => t('There are no Campaigns'))) . theme('pager');
}

/**
 * Menu callback.
 * Campaign details.
 */
function _simpleads_campaign_details($nid) {
  if (is_numeric($nid)) {
    $campaign_information = array();
    $campaign = node_load($nid);
    drupal_set_title(t('Advertisement Campaign'));

    $header = array(
      array('data' => ''),
      array('data' => t('Advertisement')),
      array('data' => t('Impressions left')),
      array('data' => t('Clicks left')),
      array('data' => t('Days left')),
      array('data' => t('Ad Status')),
      array('data' => t('Operations')),
    );

    $campaign_information[] = '<div><h2>' . $campaign->title . ' - ' . l(t('Edit'), 'node/' . $campaign->nid . '/edit', array('query' => array('destination' => 'admin/content/simpleads_campaigns'))) . '</h2></div>';
    $campaign_information[] = '<div><em>' . t('The ad remains in Active state until it reaches the number of impressions, clicks or the number of days, whichever comes first.') . '</em></div>';
    $campaign_information[] = '<hr>';

    if (isset($campaign->field_adcamp_start[$campaign->language]) && !empty($campaign->field_adcamp_start[$campaign->language][0]['safe_value'])) {
      $campaign_information[] = t('Started on !date', array('!date' => '<strong>' . $campaign->field_adcamp_start[$campaign->language][0]['safe_value'] . '</strong>'));
    }

    if (isset($campaign->field_adcamp_impression[$campaign->language]) && $campaign->field_adcamp_impression[$campaign->language][0]['value'] == 1) {
      if (isset($campaign->field_adcamp_impressions[$campaign->language]) && !empty($campaign->field_adcamp_impressions[$campaign->language][0]['safe_value'])) {
        $campaign_information[] = '<div>' . t('Impressions limit: !num', array('!num' => '<strong>' . $campaign->field_adcamp_impressions[$campaign->language][0]['safe_value'] . '</strong>')) . '</div>';
      }
    }
    if (isset($campaign->field_adcamp_click[$campaign->language]) && $campaign->field_adcamp_click[$campaign->language][0]['value'] == 1) {
      if (isset($campaign->field_adcamp_clicks[$campaign->language]) && !empty($campaign->field_adcamp_clicks[$campaign->language][0]['safe_value'])) {
        $campaign_information[] = '<div>' . t('Clicks limit: !num', array('!num' => '<strong>' . $campaign->field_adcamp_clicks[$campaign->language][0]['safe_value'] . '</strong>')) . '</div>';
      }
    }
    if (isset($campaign->field_adcamp_day[$campaign->language]) && $campaign->field_adcamp_day[$campaign->language][0]['value'] == 1) {
      if (isset($campaign->field_adcamp_days[$campaign->language]) && !empty($campaign->field_adcamp_days[$campaign->language][0]['safe_value'])) {
        $campaign_information[] = '<div>' . t('Days limit: !num', array('!num' => '<strong>' . $campaign->field_adcamp_days[$campaign->language][0]['safe_value'] . '</strong>')) . '</div>';
      }
    }
    $campaign_information[] = '<br />';

    $query = db_select('node', 'n')->extend('PagerDefault')->limit(25);
    $query->join('field_data_field_adcamp_list', 'l', 'l.entity_id = n.nid AND l.revision_id = n.vid');
    $query->fields('n', array('nid'));
    $query->fields('l', array('field_adcamp_list_value'));
    $query->condition('n.type', 'simpleads');
    $query->condition('l.field_adcamp_list_value', $campaign->nid);
    $query->addTag('node_access');
    $query->orderBy('n.changed', 'DESC');
    $results = $query->execute();

    $campaign_start_time = "";
    if (isset($campaign->field_adcamp_start[$campaign->language]) && !empty($campaign->field_adcamp_start[$campaign->language][0]['value'])) {
      $campaign_start_time = $campaign->field_adcamp_start[$campaign->language][0]['value'];
    }
    $campaign_start_time = strtotime($campaign_start_time);

    $rows = array();
    foreach ($results as $i => $record) {

      $css_complete = "";
      $node = node_load($record->nid);
      if ($campaign) {
        $impressions = '-';
        if (isset($campaign->field_adcamp_impression[$campaign->language]) && $campaign->field_adcamp_impression[$campaign->language][0]['value'] == 1) {
          if (isset($campaign->field_adcamp_impressions[$campaign->language]) && !empty($campaign->field_adcamp_impressions[$campaign->language][0]['safe_value'])) {
            $count = _simpleads_campaigns_count_ad_impressions($campaign_start_time, $node->nid);
            $impressions = $campaign->field_adcamp_impressions[$campaign->language][0]['safe_value'] - $count;
            if ($impressions <= 0) {
              $impressions = t('Complete');
              $css_complete = 'complete';
            }
          }
        }
        $clicks = '-';
        if (isset($campaign->field_adcamp_click[$campaign->language]) && $campaign->field_adcamp_click[$campaign->language][0]['value'] == 1) {
          if (isset($campaign->field_adcamp_clicks[$campaign->language]) && !empty($campaign->field_adcamp_clicks[$campaign->language][0]['safe_value'])) {
            $count = _simpleads_campaigns_count_ad_clicks($campaign_start_time, $node->nid);
            $clicks = $campaign->field_adcamp_clicks[$campaign->language][0]['safe_value'] - $count;
            if ($clicks <= 0) {
              $clicks = t('Complete');
              $css_complete = 'complete';
            }
          }
        }
        $days = '-';
        if (isset($campaign->field_adcamp_day[$campaign->language]) && $campaign->field_adcamp_day[$campaign->language][0]['value'] == 1) {
          if (isset($campaign->field_adcamp_days[$campaign->language]) && !empty($campaign->field_adcamp_days[$campaign->language][0]['safe_value'])) {
            $days = $campaign->field_adcamp_days[$campaign->language][0]['safe_value'];
            $campaign_end_time = REQUEST_TIME - (24 * 3600 * $days);
            $count = _simpleads_campains_date_diff($campaign_end_time, $campaign_start_time);
            if ($count <= 0) {
              $days = t('Complete');
              $css_complete = 'complete';
            }
            else {
              $days = $count;
            }
          }
        }
        $ad_status = t('Inactive');
        if (isset($node->field_ad_status[$node->language])) {
          if ($node->field_ad_status[$node->language][0]['value'] == 1) {
            $ad_status = t('Active');
          }
        }
        $rows[] = array(
          'data' => array(
            ($i + 1),
            l($node->title, 'admin/content/simpleads/' . $record->nid . '/stat'),
            $impressions,
            $clicks,
            $days,
            $ad_status,
            l(t('Edit'), 'node/' . $node->nid . '/edit', array('query' => array('destination' => 'admin/content/simpleads_campaigns/' . $nid)))
          ),
          'class' => array($css_complete),
        );
      }
    }
    return join("", $campaign_information)
      . theme('table', array('header' => $header, 'rows' => $rows, 'empty' => t('There are no ads in this campaign'))) . theme('pager');
  }
  else {
    return t('Invalid campaign id');
  }
}