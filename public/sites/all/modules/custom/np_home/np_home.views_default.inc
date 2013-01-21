<?php
/**
 * @file
 * np_home.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function np_home_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'home';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Home';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Home';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'news-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'news-list';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'listing';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'news-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Verification Status */
  $handler->display->display_options['fields']['field_verification_status']['id'] = 'field_verification_status';
  $handler->display->display_options['fields']['field_verification_status']['table'] = 'field_data_field_verification_status';
  $handler->display->display_options['fields']['field_verification_status']['field'] = 'field_verification_status';
  $handler->display->display_options['fields']['field_verification_status']['label'] = '';
  $handler->display->display_options['fields']['field_verification_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_verification_status']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_verification_status']['alter']['text'] = '| [field_verification_status]';
  $handler->display->display_options['fields']['field_verification_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_verification_status']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_verification_status']['type'] = 'event_status_summary';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['changed']['alter']['text'] = '<div class="news-status">
<span class="date">Updated [changed]</span> [field_verification_status]
</div>';
  $handler->display->display_options['fields']['changed']['element_type'] = 'div';
  $handler->display->display_options['fields']['changed']['element_class'] = 'news-status';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'time ago';
  /* Field: Content: What happened */
  $handler->display->display_options['fields']['field_cmptd_description']['id'] = 'field_cmptd_description';
  $handler->display->display_options['fields']['field_cmptd_description']['table'] = 'field_data_field_cmptd_description';
  $handler->display->display_options['fields']['field_cmptd_description']['field'] = 'field_cmptd_description';
  $handler->display->display_options['fields']['field_cmptd_description']['label'] = '';
  $handler->display->display_options['fields']['field_cmptd_description']['alter']['max_length'] = '120';
  $handler->display->display_options['fields']['field_cmptd_description']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_cmptd_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cmptd_description']['type'] = 'computed_field_unsanitized';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'frontpage';
  $translatables['home'] = array(
    t('Master'),
    t('Home'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('author'),
    t('| [field_verification_status]'),
    t('<div class="news-status">
<span class="date">Updated [changed]</span> [field_verification_status]
</div>'),
    t('Page'),
  );
  $export['home'] = $view;

  $view = new view();
  $view->name = 'home_carousel';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Home Carousel';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Home Carousel';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'slide-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'slides';
  $handler->display->display_options['style_options']['wrapper_class'] = 'slideshow flexslider';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'home' => 'home',
  );
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
    'image_style' => '300x195',
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
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'news-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['changed']['alter']['text'] = '<div class="news-caption">
<h3 class="news-title">[title]</h3> <span class="date">| Updated [changed]</span>
</div>';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'time ago';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $translatables['home_carousel'] = array(
    t('Master'),
    t('Home Carousel'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('<div class="news-caption">
<h3 class="news-title">[title]</h3> <span class="date">| Updated [changed]</span>
</div>'),
    t('Block'),
  );
  $export['home_carousel'] = $view;

  return $export;
}
