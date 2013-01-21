<?php

/**
 * @file
 * SimpleAds Updates.
 */

/**
 *  Add new fields to store Text and Flash ads.
 *  Make Image Ad field to not required.
 */
function simpleads_update_7001(&$sandbox) {

  $t = get_t();

  $fields = array(
    array(
      'field_name' => 'field_ad_flash',
      'type' => 'file',
      'cardinality' => 1,
      'translatable' => TRUE,
      'locked' => FALSE,
      'indexes' => array('fid' => array('fid')),
      'settings' => array(
        'uri_scheme' => 'public',
        'default_image' => FALSE,
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
      ),
    ),
  );
  foreach ($fields as $field) {
    field_create_field($field);
  }

  $instance = array(
    'field_name' => 'field_ad_flash',
    'entity_type' => 'node',
    'label' => $t('Flash Ad'),
    'bundle' => 'simpleads',
    'description' => $t('Upload Flash file for this Ad.'),
    'required' => FALSE,

    'settings' => array(
      'file_directory' => 'field/flash',
      'file_extensions' => 'swf',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'alt_field' => FALSE,
      'title_field' => '',
    ),

    'widget' => array(
      'type' => 'file_generic',
      'settings' => array(
      ),
      'weight' => 0,
    ),

    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'file_default',
        'weight' => -1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'file_default',
        'weight' => -1,
      ),
    ),
  );
  field_create_instance($instance);
  $instance = array(
    'field_name' => 'field_ad_image',
    'entity_type' => 'node',
    'label' => $t('Ad Image'),
    'bundle' => 'simpleads',
    'description' => $t('Upload an image for this Ad.'),
    'required' => FALSE,

    'settings' => array(
      'file_directory' => 'field/image',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'alt_field' => TRUE,
      'title_field' => '',
    ),

    'widget' => array(
      'type' => 'image_image',
      'settings' => array(
        'progress_indicator' => 'throbber',
        'preview_image_style' => 'thumbnail',
      ),
      'weight' => -2,
    ),

    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'image',
        'settings' => array('image_style' => 'large', 'image_link' => ''),
        'weight' => -1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'image',
        'settings' => array('image_style' => 'medium', 'image_link' => 'content'),
        'weight' => -1,
      ),
    ),
  );
  field_update_instance($instance);

  $instance = array(
    'field_name' => 'field_ad_category',
    'entity_type' => 'node',
    'label' => $t('Ad Group'),
    'bundle' => 'simpleads',
    'required' => TRUE,
    'widget' => array(
      'type' => 'options_select',
      'weight' => -4,
    ),
    'display' => array(
      'default' => array('type' => 'hidden'),
      'teaser' => array('type' => 'hidden')
    ),
  );
  field_update_instance($instance);

  $fields = array(
    array(
      'field_name' => 'field_ad_text',
      'type' => 'text',
      'cardinality' => 1,
      'translatable' => TRUE,
      'locked' => FALSE,
      'settings' => array(),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
      ),
    ),
  );
  foreach ($fields as $field) {
    field_create_field($field);
  }

  $instance = array(
    'field_name' => 'field_ad_text',
    'entity_type' => 'node',
    'label' => $t('Text Ad'),
    'bundle' => 'simpleads',
    'description' => $t('Enter your text ad. If you would like to embed media, please configure WYSIWYG editor and input format settings.'),
    'required' => FALSE,

    'settings' => array(
      'rows' => 5,
      'text_processing' => 1,
    ),

    'widget' => array(
      'type' => 'text_textarea',
      'settings' => array(
      ),
      'weight' => 1,
      'module' => 'text',
    ),

    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'text_default',
        'weight' => -1,
        'module' => 'text',
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'text_default',
        'weight' => -1,
      ),
    ),
  );
  field_create_instance($instance);

  $fields = array(
    array(
      'field_name' => 'field_ad_type',
      'type' => 'list_text',
      'cardinality' => 1,
      'translatable' => TRUE,
      'locked' => FALSE,
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'graphic' => $t('Image Ad'),
          'text' => $t('Text Ad'),
          'flash' => $t('Flash Ad'),
        ),
        'allowed_values_function' => '',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
      ),
    ),
  );
  foreach ($fields as $field) {
    field_create_field($field);
  }

  $instance = array(
    'field_name' => 'field_ad_type',
    'entity_type' => 'node',
    'label' => $t('Ad Type'),
    'bundle' => 'simpleads',
    'description' => $t('Please select Ad type.'),
    'required' => TRUE,
    'default_value' => array(
      0 => array(
        'value' => 'graphic',
      ),
    ),
    'settings' => array(
      'allowed_values'  => array(
        'graphic' => $t('Image Ad'),
        'text' => $t('Text Ad'),
        'flash' => $t('Flash Ad'),
      ),
      'user_register_form' => FALSE,
    ),
    'user_register_form' => FALSE,
    'widget' => array(
      'active' => 1,
      'type' => 'options_select',
      'weight' => -3,
      'module' => 'list',
    ),

    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'list_default',
        'module' => 'list',
        'weight' => -1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'list_default',
        'module' => 'list',
        'weight' => -1,
      ),
    ),
  );
  field_create_instance($instance);
}

/**
 * Rearrange SimleAds fields.
 */
function simpleads_update_7002(&$sandbox) {

  $t = get_t();

  user_role_grant_permissions(DRUPAL_ANONYMOUS_RID, array('count ad impressions', 'count ad clicks'));

  $instance = array(
    'field_name' => 'field_ad_flash',
    'entity_type' => 'node',
    'label' => $t('Ad Flash'),
    'bundle' => 'simpleads',
    'description' => st('Upload Flash file for this Ad.'),
    'required' => FALSE,

    'settings' => array(
      'file_directory' => 'field/flash',
      'file_extensions' => 'swf',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'alt_field' => FALSE,
      'title_field' => '',
    ),

    'widget' => array(
      'type' => 'file_generic',
      'settings' => array(
      ),
      'weight' => -1,
    ),

    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'file_default',
        'weight' => -1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'file_default',
        'weight' => -1,
      ),
    ),
  );
  field_update_instance($instance);

  $instance = array(
    'field_name' => 'field_ad_url',
    'entity_type' => 'node',
    'bundle' => 'simpleads',
    'label' => $t('URL Address'),
    'required' => FALSE,
    'widget' => array(
      'type' => 'text_textfield',
      'settings' => array(
        'size' => 60,
      ),
      'weight' => 1,
    ),
    'settings' => array(
      'text_processing' => 0,
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'text_default',
        'settings' => array(),
      ),
    ),
  );
  field_update_instance($instance);
}

/**
 * Modify block settings field.
 */
function simpleads_update_7003(&$sandbox) {

  $t = get_t();

  db_change_field('simpleads_blocks', 'settings', 'settings', array('type' => 'text', 'not null' => TRUE, 'description' => 'Serialized data (settings)'));

  $instance = array(
    'field_name' => 'field_ad_text',
    'entity_type' => 'node',
    'label' => $t('Text Ad'),
    'bundle' => 'simpleads',
    'description' => $t('Enter your text ad. If you would like to embed media, please configure WYSIWYG editor and input format settings.'),
    'required' => FALSE,
    'settings' => array(
      'rows' => 5,
      'text_processing' => 1,
    ),
    'widget' => array(
      'type' => 'text_textarea',
      'settings' => array(
      ),
      'weight' => 0,
      'module' => 'text',
    ),

    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'text_default',
        'weight' => -1,
        'module' => 'text',
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'text_default',
        'weight' => -1,
      ),
    ),
  );
  field_update_instance($instance);

  $instance = array(
    'field_name' => 'field_ad_url',
    'entity_type' => 'node',
    'bundle' => 'simpleads',
    'label' => $t('URL Address'),
    'required' => FALSE,
    'widget' => array(
      'type' => 'text_textfield',
      'settings' => array(
        'size' => 60,
      ),
      'weight' => 1,
    ),
    'settings' => array(
      'text_processing' => 0,
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'text_default',
        'settings' => array(),
      ),
    ),
  );
  field_update_instance($instance);
}

/**
 * Create a new field for URL window targeting.
 */
function simpleads_update_7004(&$sandbox) {

  $t = get_t();

  $fields = array(
    array(
      'field_name' => 'field_ad_url_taget',
      'type' => 'list_boolean',
      'cardinality' => 1,
      'translatable' => TRUE,
      'settings' => array(
        'allowed_values' => array(
          0 => $t('Open destination URL in the same window'),
          1 => $t('Open destination URL in a new window'),
        ),
        'allowed_values_function' => '',
      ),
      'module' => 'list',
      'translatable' => TRUE,
      'entity_types' => array(),
    ),
  );
  foreach ($fields as $field) {
    field_create_field($field);
  }

  $instance = array(
    'field_name' => 'field_ad_url_taget',
    'entity_type' => 'node',
    'bundle' => 'simpleads',
    'label' => $t('Link Target'),
    'required' => FALSE,
    'widget' => array(
      'type' => 'options_onoff',
      'settings' => array(
        'display_label' => 0,
      ),
      'weight' => 2,
      'module' => 'options',
    ),
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'list_default',
        'module' => 'list',
        'settings' => array(),
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
  );
  field_create_instance($instance);

  $instance = array(
    'field_name' => 'field_ad_start_date',
    'entity_type' => 'node',
    'bundle' => 'simpleads',
    'label' => $t('Active Date'),
    'description' => $t('Allowed date formats: now, tomorrow, next week, 10 September 2011, +1 day, +1 week, +1 year, +1 week 2 days 4 hours 2 seconds, next Monday, last Friday, mm/dd/yyyy hh:mm am/pm'),
    'required' => FALSE,
    'widget' => array(
      'type' => 'text_textfield',
      'settings' => array(
        'size' => 60,
      ),
      'weight' => 3,
    ),
    'settings' => array(
      'text_processing' => 0,
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'text_default',
        'settings' => array(),
      ),
    ),
  );
  field_update_instance($instance);

  $instance = array(
    'field_name' => 'field_ad_end_date',
    'entity_type' => 'node',
    'bundle' => 'simpleads',
    'label' => $t('End Date'),
    'description' => $t('Allowed date formats: now, tomorrow, next week, 10 September 2011, +1 day, +1 week, +1 year, +1 week 2 days 4 hours 2 seconds, next Monday, last Friday, mm/dd/yyyy hh:mm am/pm'),
    'required' => FALSE,
    'widget' => array(
      'type' => 'text_textfield',
      'settings' => array(
        'size' => 60,
      ),
      'weight' => 4,
    ),
    'settings' => array(
      'text_processing' => 0,
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'text_default',
        'settings' => array(),
      ),
    ),
  );
  field_update_instance($instance);
}

/**
 * Create a new field for Ad status. Disalbe comments on SimpleAds content type.
 */
function simpleads_update_7005(&$sandbox) {

  $t = get_t();

  $fields = array(
    array(
      'field_name' => 'field_ad_status',
      'type' => 'list_boolean',
      'cardinality' => 1,
      'translatable' => TRUE,
      'settings' => array(
        'allowed_values' => array(
          0 => $t('This ad is inactive'),
          1 => $t('This ad is active'),
        ),
        'allowed_values_function' => '',
      ),
      'module' => 'list',
      'translatable' => TRUE,
      'entity_types' => array(),
    ),
  );
  foreach ($fields as $field) {
    field_create_field($field);
  }

  $instance = array(
    'field_name' => 'field_ad_status',
    'entity_type' => 'node',
    'bundle' => 'simpleads',
    'label' => $t('Status'),
    'description' => $t('Please use this field to show or hide ads even if the ad is active and published.'),
    'required' => FALSE,
    'widget' => array(
      'type' => 'options_onoff',
      'settings' => array(
        'display_label' => 0,
      ),
      'weight' => 5,
      'module' => 'options',
    ),
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'list_default',
        'module' => 'list',
        'settings' => array(),
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
  );
  field_create_instance($instance);

  // Set all published ads to be active.
  $result = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('n.status', 1)
    ->execute();
  foreach ($result as $row) {
    $node = node_load($row->nid);
    $node->field_ad_status[$node->language][0]['value'] = 1;
    node_save($node);
  }

  // Reset menu, comments and other default options.
  variable_set('menu_options_simpleads', array());
  variable_set('node_options_simpleads', array());
  variable_set('comment_simpleads', 1);
}