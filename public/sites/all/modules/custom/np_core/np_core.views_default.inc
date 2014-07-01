<?php
/**
 * @file
 * np_core.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function np_core_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'footer_ads';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Footer Ads';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'simpleads';
  $handler->display->display_options['style_options']['ads_rotation_type'] = '0';
  $handler->display->display_options['style_options']['ads_rotation_delay'] = '5';
  /* Field: Content: Ad Group */
  $handler->display->display_options['fields']['field_ad_category']['id'] = 'field_ad_category';
  $handler->display->display_options['fields']['field_ad_category']['table'] = 'field_data_field_ad_category';
  $handler->display->display_options['fields']['field_ad_category']['field'] = 'field_ad_category';
  $handler->display->display_options['fields']['field_ad_category']['label'] = '';
  $handler->display->display_options['fields']['field_ad_category']['element_label_colon'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'simpleads' => 'simpleads',
  );
  /* Filter criterion: Content: Status (field_ad_status) */
  $handler->display->display_options['filters']['field_ad_status_value']['id'] = 'field_ad_status_value';
  $handler->display->display_options['filters']['field_ad_status_value']['table'] = 'field_data_field_ad_status';
  $handler->display->display_options['filters']['field_ad_status_value']['field'] = 'field_ad_status_value';
  $handler->display->display_options['filters']['field_ad_status_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Ad Group (field_ad_category) */
  $handler->display->display_options['filters']['field_ad_category_tid']['id'] = 'field_ad_category_tid';
  $handler->display->display_options['filters']['field_ad_category_tid']['table'] = 'field_data_field_ad_category';
  $handler->display->display_options['filters']['field_ad_category_tid']['field'] = 'field_ad_category_tid';
  $handler->display->display_options['filters']['field_ad_category_tid']['value'] = array(
    65 => '65',
  );
  $handler->display->display_options['filters']['field_ad_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_ad_category_tid']['vocabulary'] = 'ad_groups';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['block_description'] = 'News Platform: Footer Ads';
  $translatables['footer_ads'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Block'),
    t('News Platform: Footer Ads'),
  );
  $export['footer_ads'] = $view;

  $view = new view();
  $view->name = 'taxonomy';
  $view->description = 'A view to emulate Drupal core\'s handling of taxonomy/term.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Taxonomy';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'news-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'news-list';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'listing';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Thumbnail Image */
  $handler->display->display_options['fields']['field_story_thumb']['id'] = 'field_story_thumb';
  $handler->display->display_options['fields']['field_story_thumb']['table'] = 'field_data_field_story_thumb';
  $handler->display->display_options['fields']['field_story_thumb']['field'] = 'field_story_thumb';
  $handler->display->display_options['fields']['field_story_thumb']['label'] = '';
  $handler->display->display_options['fields']['field_story_thumb']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_thumb']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_thumb']['settings'] = array(
    'image_style' => '66x51',
    'image_link' => 'content',
  );
  /* Field: Content: Verification Status */
  $handler->display->display_options['fields']['field_verification_status']['id'] = 'field_verification_status';
  $handler->display->display_options['fields']['field_verification_status']['table'] = 'field_data_field_verification_status';
  $handler->display->display_options['fields']['field_verification_status']['field'] = 'field_verification_status';
  $handler->display->display_options['fields']['field_verification_status']['label'] = '';
  $handler->display->display_options['fields']['field_verification_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_verification_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_verification_status']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'time ago';
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_what_description']['id'] = 'field_what_description';
  $handler->display->display_options['fields']['field_what_description']['table'] = 'field_data_field_what_description';
  $handler->display->display_options['fields']['field_what_description']['field'] = 'field_what_description';
  $handler->display->display_options['fields']['field_what_description']['label'] = '';
  $handler->display->display_options['fields']['field_what_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_what_description']['type'] = 'text_plain';
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_story_summary']['id'] = 'field_story_summary';
  $handler->display->display_options['fields']['field_story_summary']['table'] = 'field_data_field_story_summary';
  $handler->display->display_options['fields']['field_story_summary']['field'] = 'field_story_summary';
  $handler->display->display_options['fields']['field_story_summary']['label'] = '';
  $handler->display->display_options['fields']['field_story_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_summary']['type'] = 'text_plain';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '2';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Has taxonomy term ID depth modifier */
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['id'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['field'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['specify_validation'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
    'story' => 'story',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'taxonomy/term/%';
  $translatables['taxonomy'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('All'),
    t('%1'),
    t('Page'),
  );
  $export['taxonomy'] = $view;

  return $export;
}
