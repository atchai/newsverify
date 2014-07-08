<?php
/**
 * @file
 * np_event.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function np_event_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'latest_from_location';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Latest from location';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest news';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'clearfix';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Thumbnail Image */
  $handler->display->display_options['fields']['field_story_thumb']['id'] = 'field_story_thumb';
  $handler->display->display_options['fields']['field_story_thumb']['table'] = 'field_data_field_story_thumb';
  $handler->display->display_options['fields']['field_story_thumb']['field'] = 'field_story_thumb';
  $handler->display->display_options['fields']['field_story_thumb']['label'] = '';
  $handler->display->display_options['fields']['field_story_thumb']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_story_thumb']['element_class'] = 'image';
  $handler->display->display_options['fields']['field_story_thumb']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_thumb']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_story_thumb']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_thumb']['settings'] = array(
    'image_style' => '66x51',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'j M Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Verification Status */
  $handler->display->display_options['fields']['field_verification_status']['id'] = 'field_verification_status';
  $handler->display->display_options['fields']['field_verification_status']['table'] = 'field_data_field_verification_status';
  $handler->display->display_options['fields']['field_verification_status']['field'] = 'field_verification_status';
  $handler->display->display_options['fields']['field_verification_status']['label'] = '';
  $handler->display->display_options['fields']['field_verification_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_verification_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_verification_status']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_verification_status']['type'] = 'event_status_summary';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<h3>[title]</h3>
<div class="date">[created]</div>
[field_verification_status]
<div class="clear-block">&nbsp;</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'title-date-status-container';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_story_summary']['id'] = 'field_story_summary';
  $handler->display->display_options['fields']['field_story_summary']['table'] = 'field_data_field_story_summary';
  $handler->display->display_options['fields']['field_story_summary']['field'] = 'field_story_summary';
  $handler->display->display_options['fields']['field_story_summary']['label'] = '';
  $handler->display->display_options['fields']['field_story_summary']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_story_summary']['element_class'] = 'summary';
  $handler->display->display_options['fields']['field_story_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_summary']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_story_summary']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_story_summary']['settings'] = array(
    'trim_length' => '200',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Location (field_location) */
  $handler->display->display_options['arguments']['field_location_tid']['id'] = 'field_location_tid';
  $handler->display->display_options['arguments']['field_location_tid']['table'] = 'field_data_field_location';
  $handler->display->display_options['arguments']['field_location_tid']['field'] = 'field_location_tid';
  $handler->display->display_options['arguments']['field_location_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_location_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_location_tid']['title'] = 'Latest news from %1';
  $handler->display->display_options['arguments']['field_location_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_location_tid']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['field_location_tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['field_location_tid']['default_argument_options']['anyall'] = '+';
  $handler->display->display_options['arguments']['field_location_tid']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['field_location_tid']['default_argument_options']['vocabularies'] = array(
    'location' => 'location',
  );
  $handler->display->display_options['arguments']['field_location_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_location_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_location_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_location_tid']['validate']['type'] = 'taxonomy_term';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
    'story' => 'story',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $translatables['latest_from_location'] = array(
    t('Master'),
    t('Latest news'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<h3>[title]</h3>
<div class="date">[created]</div>
[field_verification_status]
<div class="clear-block">&nbsp;</div>'),
    t('All'),
    t('Latest news from %1'),
    t('Block'),
  );
  $export['latest_from_location'] = $view;

  $view = new view();
  $view->name = 'related_stories';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Related Stories';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Analysis';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'news-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'news-list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Thumbnail Image */
  $handler->display->display_options['fields']['field_story_thumb']['id'] = 'field_story_thumb';
  $handler->display->display_options['fields']['field_story_thumb']['table'] = 'field_data_field_story_thumb';
  $handler->display->display_options['fields']['field_story_thumb']['field'] = 'field_story_thumb';
  $handler->display->display_options['fields']['field_story_thumb']['label'] = '';
  $handler->display->display_options['fields']['field_story_thumb']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_story_thumb']['element_class'] = 'image';
  $handler->display->display_options['fields']['field_story_thumb']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_thumb']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_story_thumb']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_thumb']['settings'] = array(
    'image_style' => '150x105',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_class'] = 'news-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['exclude'] = TRUE;
  $handler->display->display_options['fields']['changed']['element_type'] = 'span';
  $handler->display->display_options['fields']['changed']['element_class'] = 'updated';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'j M Y';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '<div class="related-content"><span class="updated">[changed] </span><span class="author">[name]</span></div>';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['anyall'] = '+';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['vocabularies'] = array(
    'location' => 'location',
    'tags' => 'tags',
  );
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  $handler->display->display_options['arguments']['tid']['add_table'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'story' => 'story',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $translatables['related_stories'] = array(
    t('Master'),
    t('Analysis'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('author'),
    t('<div class="related-content"><span class="updated">[changed] </span><span class="author">[name]</span></div>'),
    t('All'),
    t('Block'),
  );
  $export['related_stories'] = $view;

  $view = new view();
  $view->name = 'sources';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Sources';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Event Sources';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_author_rating' => 'field_author_rating',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_author_rating' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Credibility Rating */
  $handler->display->display_options['fields']['field_author_rating']['id'] = 'field_author_rating';
  $handler->display->display_options['fields']['field_author_rating']['table'] = 'field_data_field_author_rating';
  $handler->display->display_options['fields']['field_author_rating']['field'] = 'field_author_rating';
  $handler->display->display_options['fields']['field_author_rating']['label'] = '';
  $handler->display->display_options['fields']['field_author_rating']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_author_rating']['type'] = 'taxonomy_term_rating_scale';
  /* Field: Content: Credibility Rating Explanation */
  $handler->display->display_options['fields']['field_author_narrative']['id'] = 'field_author_narrative';
  $handler->display->display_options['fields']['field_author_narrative']['table'] = 'field_data_field_author_narrative';
  $handler->display->display_options['fields']['field_author_narrative']['field'] = 'field_author_narrative';
  $handler->display->display_options['fields']['field_author_narrative']['label'] = '';
  $handler->display->display_options['fields']['field_author_narrative']['element_label_colon'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'author' => 'author',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['nid_type'] = 'nids';
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'empty';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'author' => 'author',
  );

  /* Display: Full List */
  $handler = $view->new_display('block', 'Full List', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Simple List */
  $handler = $view->new_display('block', 'Simple List', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Credibility Rating */
  $handler->display->display_options['fields']['field_author_rating']['id'] = 'field_author_rating';
  $handler->display->display_options['fields']['field_author_rating']['table'] = 'field_data_field_author_rating';
  $handler->display->display_options['fields']['field_author_rating']['field'] = 'field_author_rating';
  $handler->display->display_options['fields']['field_author_rating']['label'] = 'Credibility';
  $handler->display->display_options['fields']['field_author_rating']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_author_rating']['type'] = 'taxonomy_term_rating_scale';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Author';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $translatables['sources'] = array(
    t('Master'),
    t('Event Sources'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Full List'),
    t('Simple List'),
    t('Credibility'),
    t('Author'),
  );
  $export['sources'] = $view;

  return $export;
}
