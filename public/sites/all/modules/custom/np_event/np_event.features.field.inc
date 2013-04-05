<?php
/**
 * @file
 * np_event.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function np_event_field_default_fields() {
  $fields = array();

  // Exported field: 'field_collection_item-field_where_location-field_location_geo'.
  $fields['field_collection_item-field_where_location-field_location_geo'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_location_geo',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'geofield',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'geofield',
    ),
    'field_instance' => array(
      'bundle' => 'field_where_location',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Enter in decimal or compass format. For example, in decimal format - Longitude: 12.3465 Latitude: 46.0388 or in Compass format - Longitude: 46° 2\' 21.81" N  Latitude: 12° 20\' 40.71" E"',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'geofield',
          'settings' => array(
            'data' => 'full',
            'format' => 'decimal_degrees',
            'labels' => 0,
          ),
          'type' => 'geofield_latlon',
          'weight' => '1',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'geofield',
          'settings' => array(
            'data' => 'full',
            'format' => 'decimal_degrees',
            'labels' => 0,
          ),
          'type' => 'geofield_latlon',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_location_geo',
      'label' => 'Coordinates',
      'required' => 0,
      'settings' => array(
        'local_solr' => array(
          'enabled' => FALSE,
          'lat_field' => 'lat',
          'lng_field' => 'lng',
        ),
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'geofield',
        'settings' => array(),
        'type' => 'geofield_latlon',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_where_location-field_location_name'.
  $fields['field_collection_item-field_where_location-field_location_name'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_location_name',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'field_where_location',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_location_name',
      'label' => 'Name',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-event-field_addthis'.
  $fields['node-event-field_addthis'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_addthis',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'addthis',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => '0',
      'type' => 'addthis',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'addthis_displays',
          'settings' => array(
            'button_size' => 'small',
            'extra_css' => '',
          ),
          'type' => 'addthis_basic_button',
          'weight' => '1',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'addthis_displays',
          'settings' => array(
            'button_size' => 'small',
            'extra_css' => '',
          ),
          'type' => 'addthis_basic_button',
          'weight' => '1',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '26',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '20',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '15',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '18',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_addthis',
      'label' => 'AddThis',
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'addthis',
        'settings' => array(),
        'type' => 'addthis_button_widget',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-event-field_cmptd_author'.
  $fields['node-event-field_cmptd_author'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cmptd_author',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'computed_field',
      'settings' => array(
        'code' => '$entity_field[0][\'value\'] = "";',
        'database' => array(
          'data_default' => '',
          'data_index' => 0,
          'data_length' => '32',
          'data_not_NULL' => 0,
          'data_precision' => '10',
          'data_scale' => '2',
          'data_size' => 'normal',
          'data_type' => 'varchar',
        ),
        'display_format' => '$sub_username = theme(\'username\', array(\'account\' => $entity));
$display_output =  t(\'!username\', array(\'!username\' => $sub_username));',
        'store' => 0,
      ),
      'translatable' => '0',
      'type' => 'computed',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '16',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_plain',
          'weight' => '23',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
        'listing' => array(
          'label' => 'hidden',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_unsanitized',
          'weight' => '0',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_cmptd_author',
      'label' => 'Author',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'computed_field',
        'settings' => array(),
        'type' => 'computed',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-event-field_cmptd_date'.
  $fields['node-event-field_cmptd_date'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cmptd_date',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'computed_field',
      'settings' => array(
        'code' => '$entity_field[0][\'value\'] = "";',
        'database' => array(
          'data_default' => '',
          'data_index' => 0,
          'data_length' => '32',
          'data_not_NULL' => 0,
          'data_precision' => '10',
          'data_scale' => '2',
          'data_size' => 'normal',
          'data_type' => 'varchar',
        ),
        'display_format' => '// Careful with variable names (e.g $display) as this will override any set in computed_field_field_formatter_view!!!
$calc_display = array(
  \'label\' => \'hidden\',
  \'type\' => \'date_default\',
  \'settings\' => array(
    \'format_type\' => \'long\',
    \'fromto\' => \'both\'
  )
);
$render = field_view_field(\'node\', $entity, \'field_when_date\', $calc_display, NULL);
$display_output  = render($render);

if (isset($entity->field_when_v_status[LANGUAGE_NONE][0][\'tid\'])) {
 $calc_display = array(
  \'label\' => \'hidden\',
  \'type\' => \'event_status_summary\',
  \'settings\' => array(
   \'overlay\' => FALSE,
   \'anchor\' => \'group_when\'
  )
 );
 $render = field_view_field(\'node\', $entity, \'field_when_v_status\', $calc_display, NULL);
 $display_output  .= render($render);
}',
        'store' => 0,
      ),
      'translatable' => '0',
      'type' => 'computed',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '19',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_unsanitized',
          'weight' => '3',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '15',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
        'summary' => array(
          'label' => 'inline',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_unsanitized',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_cmptd_date',
      'label' => 'When',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'computed_field',
        'settings' => array(),
        'type' => 'computed',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-event-field_cmptd_description'.
  $fields['node-event-field_cmptd_description'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cmptd_description',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'computed_field',
      'settings' => array(
        'code' => '$entity_field[0][\'value\'] = "";',
        'database' => array(
          'data_default' => '',
          'data_index' => 0,
          'data_length' => '32',
          'data_not_NULL' => 0,
          'data_precision' => '10',
          'data_scale' => '2',
          'data_size' => 'normal',
          'data_type' => 'varchar',
        ),
        'display_format' => '// Careful with variable names (e.g $display) as this will override any set in computed_field_field_formatter_view!!!
$calc_display = array(
  \'label\' => \'hidden\',
  \'type\' => \'default_formatter\',
  \'settings\' => array()
);
$render = field_view_field(\'node\', $entity, \'field_what_description\', $calc_display, NULL);
$display_output  = render($render);

if (isset($entity->field_what_v_status[LANGUAGE_NONE][0][\'tid\'])) {
 $calc_display = array(
  \'label\' => \'hidden\',
  \'type\' => \'event_status_summary\',
  \'settings\' => array(
   \'overlay\' => FALSE,
   \'anchor\' => \'group_what\'
  )
 );
 $render = field_view_field(\'node\', $entity, \'field_what_v_status\', $calc_display, NULL);
 $display_output  .= render($render);
}',
        'store' => 0,
      ),
      'translatable' => '0',
      'type' => 'computed',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'deleted' => '0',
      'description' => 'Repeating the description field for multiple display in the node view',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '18',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_unsanitized',
          'weight' => '5',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
        'summary' => array(
          'label' => 'inline',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_unsanitized',
          'weight' => '2',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_cmptd_description',
      'label' => 'What happened',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'computed_field',
        'settings' => array(),
        'type' => 'computed',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-event-field_cmptd_description_full'.
  $fields['node-event-field_cmptd_description_full'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cmptd_description_full',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'computed_field',
      'settings' => array(
        'code' => '$entity_field[0][\'value\'] = "";',
        'database' => array(
          'data_default' => '',
          'data_index' => 0,
          'data_length' => '32',
          'data_not_NULL' => 0,
          'data_precision' => '10',
          'data_scale' => '2',
          'data_size' => 'normal',
          'data_type' => 'varchar',
        ),
        'display_format' => '// Careful with variable names (e.g $display) as this will override any set in computed_field_field_formatter_view!!!

$display_output = \'\';

if (isset($entity->field_what_v_status[LANGUAGE_NONE][0][\'tid\'])) {
 $calc_display = array(
  \'label\' => \'hidden\',
  \'type\' => \'event_status_summary\',
  \'settings\' => array(
   \'overlay\' => FALSE,
   \'anchor\' => \'group_what\'
  )
 );
 $render = field_view_field(\'node\', $entity, \'field_what_v_status\', $calc_display, NULL);
 $display_output  .= render($render);
}

$calc_display = array(
  \'label\' => \'hidden\',
  \'type\' => \'default_formatter\',
  \'settings\' => array()
);
$render = field_view_field(\'node\', $entity, \'field_what_description\', $calc_display, NULL);
$display_output  .= render($render);',
        'store' => 0,
      ),
      'translatable' => '0',
      'type' => 'computed',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_unsanitized',
          'weight' => '5',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_cmptd_description_full',
      'label' => 'What Happened',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'computed_field',
        'settings' => array(),
        'type' => 'computed',
        'weight' => '11',
      ),
    ),
  );

  // Exported field: 'node-event-field_cmptd_last_updated'.
  $fields['node-event-field_cmptd_last_updated'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cmptd_last_updated',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'computed_field',
      'settings' => array(
        'code' => '$entity_field[0][\'value\'] = "";',
        'database' => array(
          'data_default' => '',
          'data_index' => 0,
          'data_length' => '32',
          'data_not_NULL' => 0,
          'data_precision' => '10',
          'data_scale' => '2',
          'data_size' => 'normal',
          'data_type' => 'varchar',
        ),
        'display_format' => '$sub_timeago = format_interval(time() - $entity->changed, 2, NULL);
$display_output =  t(\'!datetime ago\', array(\'!datetime\' => $sub_timeago));',
        'store' => 0,
      ),
      'translatable' => '0',
      'type' => 'computed',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '15',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_plain',
          'weight' => '24',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'listing' => array(
          'label' => 'hidden',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_unsanitized',
          'weight' => '1',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_cmptd_last_updated',
      'label' => 'Last Updated',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'computed_field',
        'settings' => array(),
        'type' => 'computed',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-event-field_cmptd_what_posts_first'.
  $fields['node-event-field_cmptd_what_posts_first'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cmptd_what_posts_first',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'computed_field',
      'settings' => array(
        'code' => '$entity_field[0][\'value\'] = "";',
        'database' => array(
          'data_default' => '',
          'data_index' => 0,
          'data_length' => '32',
          'data_not_NULL' => 0,
          'data_precision' => '10',
          'data_scale' => '2',
          'data_size' => 'normal',
          'data_type' => 'varchar',
        ),
        'display_format' => '$display_output = \'\';

if (isset($entity->field_what_posts[LANGUAGE_NONE][0])) {
 $post = node_load($entity->field_what_posts[LANGUAGE_NONE][0][\'target_id\']);
 $render = node_view($post, \'inline\');
 $display_output = render($render);
}
',
        'store' => 0,
      ),
      'translatable' => '0',
      'type' => 'computed',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '22',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '16',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'hidden',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_unsanitized',
          'weight' => '0',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '16',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_cmptd_what_posts_first',
      'label' => 'First What Post',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'computed_field',
        'settings' => array(),
        'type' => 'computed',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'node-event-field_cmptd_when_full'.
  $fields['node-event-field_cmptd_when_full'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cmptd_when_full',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'computed_field',
      'settings' => array(
        'code' => '$entity_field[0][\'value\'] = "";',
        'database' => array(
          'data_default' => '',
          'data_index' => 0,
          'data_length' => '32',
          'data_not_NULL' => 0,
          'data_precision' => '10',
          'data_scale' => '2',
          'data_size' => 'normal',
          'data_type' => 'varchar',
        ),
        'display_format' => '// Careful with variable names (e.g $display) as this will override any set in computed_field_field_formatter_view!!!

$display_output = \'\';

if (isset($entity->field_when_v_status[LANGUAGE_NONE][0][\'tid\'])) {
 $calc_display = array(
  \'label\' => \'hidden\',
  \'type\' => \'event_status_summary\',
  \'settings\' => array(
   \'overlay\' => FALSE,
   \'anchor\' => \'group_when\'
  )
 );
 $render = field_view_field(\'node\', $entity, \'field_when_v_status\', $calc_display, NULL);
 $display_output  .= render($render);
}

$calc_display = array(
  \'label\' => \'hidden\',
  \'type\' => \'date_default\',
  \'settings\' => array(
    \'format_type\' => \'long\',
    \'fromto\' => \'both\'
  )
);
$render = field_view_field(\'node\', $entity, \'field_when_date\', $calc_display, NULL);
$display_output  .= render($render);',
        'store' => 0,
      ),
      'translatable' => '0',
      'type' => 'computed',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_unsanitized',
          'weight' => '3',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_plain',
          'weight' => '25',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_cmptd_when_full',
      'label' => 'When',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'computed_field',
        'settings' => array(),
        'type' => 'computed',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'node-event-field_cmptd_where'.
  $fields['node-event-field_cmptd_where'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cmptd_where',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'computed_field',
      'settings' => array(
        'code' => '$entity_field[0][\'value\'] = "";',
        'database' => array(
          'data_default' => '',
          'data_index' => 0,
          'data_length' => '32',
          'data_not_NULL' => 0,
          'data_precision' => '10',
          'data_scale' => '2',
          'data_size' => 'normal',
          'data_type' => 'varchar',
        ),
        'display_format' => '// Careful with variable names (e.g $display) as this will override any set in computed_field_field_formatter_view!!!
$calc_display = array(
  \'label\' => \'hidden\',
  \'type\' => \'field_collection_fields\',
  \'settings\' => array(
    \'view_mode\' => \'teaser\',
  )
);

$render = field_view_field(\'node\', $entity, \'field_where_location\', $calc_display, NULL);
$display_output  = render($render);

if (isset($entity->field_where_v_status[LANGUAGE_NONE][0][\'tid\'])) {
 $calc_display = array(
  \'label\' => \'hidden\',
  \'type\' => \'event_status_summary\',
  \'settings\' => array(
   \'overlay\' => FALSE,
   \'anchor\' => \'group_where\'
  )
 );
 $render = field_view_field(\'node\', $entity, \'field_where_v_status\', $calc_display, NULL);
 $display_output  .= render($render);
}',
        'store' => 0,
      ),
      'translatable' => '0',
      'type' => 'computed',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '17',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_unsanitized',
          'weight' => '4',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '16',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
        ),
        'summary' => array(
          'label' => 'inline',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_unsanitized',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_cmptd_where',
      'label' => 'Where',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'computed_field',
        'settings' => array(),
        'type' => 'computed',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-event-field_cmptd_where_full'.
  $fields['node-event-field_cmptd_where_full'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cmptd_where_full',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'computed_field',
      'settings' => array(
        'code' => '$entity_field[0][\'value\'] = "";',
        'database' => array(
          'data_default' => '',
          'data_index' => 0,
          'data_length' => '32',
          'data_not_NULL' => 0,
          'data_precision' => '10',
          'data_scale' => '2',
          'data_size' => 'normal',
          'data_type' => 'varchar',
        ),
        'display_format' => '// Careful with variable names (e.g $display) as this will override any set in computed_field_field_formatter_view!!!

$display_output = \'\';

if (isset($entity->field_where_v_status[LANGUAGE_NONE][0][\'tid\'])) {
 $calc_display = array(
  \'label\' => \'hidden\',
  \'type\' => \'event_status_summary\',
  \'settings\' => array(
   \'overlay\' => FALSE,
   \'anchor\' => \'group_where\'
  )
 );
 $render = field_view_field(\'node\', $entity, \'field_where_v_status\', $calc_display, NULL);
 $display_output  .= render($render);
}

$calc_display = array(
  \'label\' => \'hidden\',
  \'type\' => \'field_collection_fields\',
  \'settings\' => array(
    \'view_mode\' => \'teaser\',
  )
);

$render = field_view_field(\'node\', $entity, \'field_where_location\', $calc_display, NULL);
$display_output  .= render($render);',
        'store' => 0,
      ),
      'translatable' => '0',
      'type' => 'computed',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_unsanitized',
          'weight' => '4',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_cmptd_where_full',
      'label' => 'Where',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'computed_field',
        'settings' => array(),
        'type' => 'computed',
        'weight' => '10',
      ),
    ),
  );

  // Exported field: 'node-event-field_cmptd_why_we_think_its'.
  $fields['node-event-field_cmptd_why_we_think_its'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cmptd_why_we_think_its',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'computed_field',
      'settings' => array(
        'code' => '$entity_field[0][\'value\'] = "";',
        'database' => array(
          'data_default' => '',
          'data_index' => 0,
          'data_length' => '32',
          'data_not_NULL' => 0,
          'data_precision' => '10',
          'data_scale' => '2',
          'data_size' => 'normal',
          'data_type' => 'varchar',
        ),
        'display_format' => '$term = taxonomy_term_load($entity->field_verification_status[LANGUAGE_NONE][0][\'tid\']);
$display_output  = \'<div class="why-we-think-its">\' . t(\'Why we think it\\\'s !status\', array(\'!status\' => $term->name)) . \'</div>\';

// Careful with variable names (e.g $display) as this will override any set in computed_field_field_formatter_view!!!
$calc_display = array(
  \'label\' => \'hidden\',
  \'type\' => \'default_formatter\',
  \'settings\' => array()
);

$render = field_view_field(\'node\', $entity, \'field_verification_narrative\', $calc_display, NULL);
$display_output  .= render($render);',
        'store' => 0,
      ),
      'translatable' => '0',
      'type' => 'computed',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '20',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '14',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '13',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'summary' => array(
          'label' => 'hidden',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_unsanitized',
          'weight' => '4',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_cmptd_why_we_think_its',
      'label' => 'Why we think its',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'computed_field',
        'settings' => array(),
        'type' => 'computed',
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'node-event-field_facebook_like'.
  $fields['node-event-field_facebook_like'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_facebook_like',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'addthis',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => '0',
      'type' => 'addthis',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'addthis_displays',
          'settings' => array(
            'buttons_size' => 'addthis_16x16_style',
            'counter_orientation' => 'horizontal',
            'extra_css' => '',
            'share_services' => 'facebook_like',
          ),
          'type' => 'addthis_basic_toolbox',
          'weight' => '0',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'addthis_displays',
          'settings' => array(
            'buttons_size' => 'addthis_16x16_style',
            'counter_orientation' => 'horizontal',
            'extra_css' => '',
            'share_services' => 'facebook_like',
          ),
          'type' => 'addthis_basic_toolbox',
          'weight' => '0',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '25',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '18',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '16',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '19',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_facebook_like',
      'label' => 'Facebook Like',
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'addthis',
        'settings' => array(),
        'type' => 'addthis_button_widget',
        'weight' => '0',
      ),
    ),
  );

  // Exported field: 'node-event-field_location'.
  $fields['node-event-field_location'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_location',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'location',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '23',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '17',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '33',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '22',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '18',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '21',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_location',
      'label' => 'Location',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '21',
      ),
    ),
  );

  // Exported field: 'node-event-field_section'.
  $fields['node-event-field_section'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_section',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'section',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '14',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '13',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '18',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '15',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '12',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_section',
      'label' => 'Section',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '24',
      ),
    ),
  );

  // Exported field: 'node-event-field_sources'.
  $fields['node-event-field_sources'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_sources',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'viewfield',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'viewfield',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => array(
        0 => array(
          'vname' => 'sources|block',
          'vargs' => '[node:sources]',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'viewfield',
          'settings' => array(),
          'type' => 'viewfield_default',
          'weight' => '9',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'viewfield',
          'settings' => array(),
          'type' => 'viewfield_default',
          'weight' => '9',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
        'summary' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_sources',
      'label' => 'Sources',
      'required' => 0,
      'settings' => array(
        'allowed_views' => array(
          'admin_views_node' => 0,
          'admin_views_user' => 0,
          'event_sources' => 0,
          'home' => 0,
          'home_carousel' => 0,
          'latest_from_location' => 0,
          'nodequeue_1' => 0,
          'np_admin' => 0,
          'related_stories' => 0,
          'search' => 0,
          'sources' => 'sources',
        ),
        'force_default' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_select',
        'weight' => '12',
      ),
    ),
  );

  // Exported field: 'node-event-field_sources_simple'.
  $fields['node-event-field_sources_simple'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_sources_simple',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'viewfield',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'viewfield',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => array(
        0 => array(
          'vname' => 'sources|block_1',
          'vargs' => '[node:sources]',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '21',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '15',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '14',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'summary' => array(
          'label' => 'hidden',
          'module' => 'viewfield',
          'settings' => array(),
          'type' => 'viewfield_default',
          'weight' => '3',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_sources_simple',
      'label' => 'Sources Simple',
      'required' => 0,
      'settings' => array(
        'allowed_views' => array(
          'admin_views_node' => 0,
          'admin_views_user' => 0,
          'event_summary_test' => 0,
          'home' => 0,
          'home_carousel' => 0,
          'nodequeue_1' => 0,
          'np_admin' => 0,
          'search' => 0,
          'sources' => 'sources',
          'taxonomy' => 0,
        ),
        'force_default' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_select',
        'weight' => '13',
      ),
    ),
  );

  // Exported field: 'node-event-field_submitted'.
  $fields['node-event-field_submitted'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_submitted',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'computed_field',
      'settings' => array(
        'code' => '$entity_field[0][\'value\'] = "";',
        'database' => array(
          'data_default' => '',
          'data_index' => 0,
          'data_length' => '32',
          'data_not_NULL' => 0,
          'data_precision' => '10',
          'data_scale' => '2',
          'data_size' => 'normal',
          'data_type' => 'varchar',
        ),
        'display_format' => '$sub_username = theme(\'username\', array(\'account\' => $entity));
$sub_timeago = format_interval(time() - $entity->created, 2, NULL);

$display_output =  t(\'!username | !datetime ago\', array(\'!username\' => $sub_username, \'!datetime\' => $sub_timeago));',
        'store' => 0,
      ),
      'translatable' => '0',
      'type' => 'computed',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_unsanitized',
          'weight' => '2',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_unsanitized',
          'weight' => '2',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '21',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '12',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '15',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_submitted',
      'label' => 'Submitted',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'computed_field',
        'settings' => array(),
        'type' => 'computed',
        'weight' => '14',
      ),
    ),
  );

  // Exported field: 'node-event-field_tags'.
  $fields['node-event-field_tags'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tags',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'tags',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '6',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '6',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '32',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '21',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '17',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '20',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_tags',
      'label' => 'Tags',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => '22',
      ),
    ),
  );

  // Exported field: 'node-event-field_verification_narrative'.
  $fields['node-event-field_verification_narrative'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_verification_narrative',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '9',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '8',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '34',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '31',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '26',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_verification_narrative',
      'label' => 'Verification Narrative',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '3',
        ),
        'type' => 'text_textarea',
        'weight' => '17',
      ),
    ),
  );

  // Exported field: 'node-event-field_verification_status'.
  $fields['node-event-field_verification_status'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_verification_status',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'verification_status',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'np_event_summary',
          'settings' => array(
            'hyperlink' => '',
            'overlay' => 0,
          ),
          'type' => 'event_status_summary',
          'weight' => '8',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '7',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'hidden',
          'module' => 'np_event_summary',
          'settings' => array(
            'hyperlink' => '',
            'overlay' => TRUE,
          ),
          'type' => 'event_status_summary',
          'weight' => '1',
        ),
        'listing' => array(
          'label' => 'hidden',
          'module' => 'np_event_summary',
          'settings' => array(
            'hyperlink' => '',
            'overlay' => TRUE,
          ),
          'type' => 'event_status_summary',
          'weight' => '2',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '22',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'np_event_summary',
          'settings' => array(
            'hyperlink' => '',
            'overlay' => TRUE,
          ),
          'type' => 'event_status_summary',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_verification_status',
      'label' => 'Verification Status',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '16',
      ),
    ),
  );

  // Exported field: 'node-event-field_what_description'.
  $fields['node-event-field_what_description'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_what_description',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '21',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '21',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '14',
        ),
        'listing' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => '120',
          ),
          'type' => 'text_trimmed',
          'weight' => '3',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_what_description',
      'label' => 'Description',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '23',
      ),
    ),
  );

  // Exported field: 'node-event-field_what_never_empty'.
  $fields['node-event-field_what_never_empty'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_what_never_empty',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'computed_field',
      'settings' => array(
        'code' => '$entity_field[0][\'value\'] = "";',
        'database' => array(
          'data_default' => '',
          'data_index' => 0,
          'data_length' => '32',
          'data_not_NULL' => 0,
          'data_precision' => '10',
          'data_scale' => '2',
          'data_size' => 'normal',
          'data_type' => 'varchar',
        ),
        'display_format' => '$display_output = \'<span class="empty">&nbsp;</span>\';',
        'store' => 0,
      ),
      'translatable' => '0',
      'type' => 'computed',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_unsanitized',
          'weight' => '18',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_unsanitized',
          'weight' => '18',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '17',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '12',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_what_never_empty',
      'label' => 'Never Empty',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'computed_field',
        'settings' => array(),
        'type' => 'computed',
        'weight' => '23',
      ),
    ),
  );

  // Exported field: 'node-event-field_what_posts'.
  $fields['node-event-field_what_posts'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_what_posts',
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'direction' => 'DESC',
            'property' => 'created',
            'type' => 'property',
          ),
          'target_bundles' => array(
            'post' => 'post',
          ),
        ),
        'target_type' => 'node',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'entityreference',
          'settings' => array(
            'links' => 1,
            'view_mode' => 'in_event_page',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => '22',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'links' => 1,
            'view_mode' => 'in_event_page',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => '22',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '27',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '22',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '26',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_what_posts',
      'label' => 'Posts',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'np_post',
        'settings' => array(),
        'type' => 'post_import_widget',
        'weight' => '26',
      ),
    ),
  );

  // Exported field: 'node-event-field_what_v_narrative'.
  $fields['node-event-field_what_v_narrative'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_what_v_narrative',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '20',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '20',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '31',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '29',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '24',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '28',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_what_v_narrative',
      'label' => 'Verification Narrative',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '3',
        ),
        'type' => 'text_textarea',
        'weight' => '25',
      ),
    ),
  );

  // Exported field: 'node-event-field_what_v_status'.
  $fields['node-event-field_what_v_status'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_what_v_status',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'verification_status',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '19',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '19',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '24',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '19',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '19',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '23',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_what_v_status',
      'label' => 'Verification Status',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '24',
      ),
    ),
  );

  // Exported field: 'node-event-field_when_date'.
  $fields['node-event-field_when_date'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_when_date',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'date',
      'settings' => array(
        'cache_count' => '4',
        'cache_enabled' => 0,
        'granularity' => array(
          'day' => 'day',
          'hour' => 'hour',
          'minute' => 'minute',
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'timezone_db' => 'UTC',
        'todate' => 'optional',
        'tz_handling' => 'site',
      ),
      'translatable' => '0',
      'type' => 'datetime',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
          ),
          'type' => 'date_default',
          'weight' => '19',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
          ),
          'type' => 'date_default',
          'weight' => '19',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '13',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '17',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_when_date',
      'label' => 'Date',
      'required' => 0,
      'settings' => array(
        'default_value' => 'blank',
        'default_value2' => 'blank',
        'default_value_code' => '',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'display_all_day' => 1,
          'increment' => '30',
          'input_format' => 'm/d/Y - H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'text_parts' => array(),
          'year_range' => '-3:+3',
        ),
        'type' => 'date_popup',
        'weight' => '18',
      ),
    ),
  );

  // Exported field: 'node-event-field_when_never_empty'.
  $fields['node-event-field_when_never_empty'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_when_never_empty',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'computed_field',
      'settings' => array(
        'code' => '$entity_field[0][\'value\'] = "";',
        'database' => array(
          'data_default' => '',
          'data_index' => 0,
          'data_length' => '32',
          'data_not_NULL' => 0,
          'data_precision' => '10',
          'data_scale' => '2',
          'data_size' => 'normal',
          'data_type' => 'varchar',
        ),
        'display_format' => '$display_output = \'<span class="empty">&nbsp;</span>\';',
        'store' => 0,
      ),
      'translatable' => '0',
      'type' => 'computed',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_unsanitized',
          'weight' => '16',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_unsanitized',
          'weight' => '16',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '20',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '14',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_when_never_empty',
      'label' => 'Never Empty',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'computed_field',
        'settings' => array(),
        'type' => 'computed',
        'weight' => '17',
      ),
    ),
  );

  // Exported field: 'node-event-field_when_posts'.
  $fields['node-event-field_when_posts'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_when_posts',
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'direction' => 'DESC',
            'property' => 'created',
            'type' => 'property',
          ),
          'target_bundles' => array(
            'post' => 'post',
          ),
        ),
        'target_type' => 'node',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'entityreference',
          'settings' => array(
            'links' => 1,
            'view_mode' => 'in_event_page',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => '20',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'links' => 1,
            'view_mode' => 'in_event_page',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => '20',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '22',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '26',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '13',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '16',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_when_posts',
      'label' => 'Posts',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'np_post',
        'settings' => array(),
        'type' => 'post_import_widget',
        'weight' => '21',
      ),
    ),
  );

  // Exported field: 'node-event-field_when_v_narrative'.
  $fields['node-event-field_when_v_narrative'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_when_v_narrative',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '18',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '18',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '30',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '28',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '21',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '25',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_when_v_narrative',
      'label' => 'Verification Narrative',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '3',
        ),
        'type' => 'text_textarea',
        'weight' => '20',
      ),
    ),
  );

  // Exported field: 'node-event-field_when_v_status'.
  $fields['node-event-field_when_v_status'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_when_v_status',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'verification_status',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '17',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '17',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '28',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '24',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '25',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '29',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_when_v_status',
      'label' => 'Verification Status',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '19',
      ),
    ),
  );

  // Exported field: 'node-event-field_where_location'.
  $fields['node-event-field_where_location'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_where_location',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'field_collection',
      'settings' => array(
        'hide_blank_items' => TRUE,
        'path' => '',
      ),
      'translatable' => '0',
      'type' => 'field_collection',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'field_collection',
          'settings' => array(
            'view_mode' => 'full',
          ),
          'type' => 'field_collection_fields',
          'weight' => '20',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'field_collection',
          'settings' => array(
            'view_mode' => 'full',
          ),
          'type' => 'field_collection_fields',
          'weight' => '20',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '12',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_where_location',
      'label' => 'Location',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'field_collection',
        'settings' => array(),
        'type' => 'field_collection_embed',
        'weight' => '24',
      ),
    ),
  );

  // Exported field: 'node-event-field_where_never_empty'.
  $fields['node-event-field_where_never_empty'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_where_never_empty',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'computed_field',
      'settings' => array(
        'code' => '$entity_field[0][\'value\'] = "";',
        'database' => array(
          'data_default' => '',
          'data_index' => 0,
          'data_length' => '32',
          'data_not_NULL' => 0,
          'data_precision' => '10',
          'data_scale' => '2',
          'data_size' => 'normal',
          'data_type' => 'varchar',
        ),
        'display_format' => '$display_output = \'<span class="empty">&nbsp;</span>\';',
        'store' => 0,
      ),
      'translatable' => '0',
      'type' => 'computed',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_unsanitized',
          'weight' => '17',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'computed_field',
          'settings' => array(),
          'type' => 'computed_field_unsanitized',
          'weight' => '17',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '19',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '13',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_where_never_empty',
      'label' => 'Never Empty',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'computed_field',
        'settings' => array(),
        'type' => 'computed',
        'weight' => '22',
      ),
    ),
  );

  // Exported field: 'node-event-field_where_posts'.
  $fields['node-event-field_where_posts'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_where_posts',
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'direction' => 'DESC',
            'property' => 'created',
            'type' => 'property',
          ),
          'target_bundles' => array(
            'post' => 'post',
          ),
        ),
        'target_type' => 'node',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'entityreference',
          'settings' => array(
            'links' => 1,
            'view_mode' => 'in_event_page',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => '21',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'links' => 1,
            'view_mode' => 'in_event_page',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => '21',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '23',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '25',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '14',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '17',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_where_posts',
      'label' => 'Posts',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'np_post',
        'settings' => array(),
        'type' => 'post_import_widget',
        'weight' => '28',
      ),
    ),
  );

  // Exported field: 'node-event-field_where_v_narrative'.
  $fields['node-event-field_where_v_narrative'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_where_v_narrative',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '19',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '19',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '29',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '30',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '23',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '27',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_where_v_narrative',
      'label' => 'Verification Narrative',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '3',
        ),
        'type' => 'text_textarea',
        'weight' => '27',
      ),
    ),
  );

  // Exported field: 'node-event-field_where_v_status'.
  $fields['node-event-field_where_v_status'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_where_v_status',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'verification_status',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '18',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '18',
        ),
        'in_event_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'inline' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '27',
        ),
        'listing' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '23',
        ),
        'micro' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '20',
        ),
        'summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '24',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_where_v_status',
      'label' => 'Verification Status',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '26',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-verification_status-field_rating'.
  $fields['taxonomy_term-verification_status-field_rating'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_rating',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => '0',
          1 => '1',
          2 => '2',
          3 => '3',
          4 => '4',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_integer',
    ),
    'field_instance' => array(
      'bundle' => 'verification_status',
      'default_value' => array(
        0 => array(
          'value' => '0',
        ),
      ),
      'deleted' => '0',
      'description' => 'Assign this verification status a rating to control the default verification status graphic. A value of "1" is the lowest verification status (displayed in red) and "4" is the highest (displayed in green).',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_rating',
      'label' => 'Rating',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-verification_status-field_verification_status_image'.
  $fields['taxonomy_term-verification_status-field_verification_status_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_verification_status_image',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'verification_status',
      'deleted' => '0',
      'description' => 'You can optionally upload an image to represent this verification status, wherever it\'s displayed on the front end of the site. If this field is left blank the default verification status graphic will be used instead.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => 1,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_verification_status_image',
      'label' => 'Image',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'file_directory' => '',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'insert' => 0,
          'insert_absolute' => 0,
          'insert_class' => '',
          'insert_default' => 'auto',
          'insert_styles' => array(
            'auto' => 0,
            'icon_link' => 0,
            'image' => 0,
            'image_150x105' => 0,
            'image_206xh' => 0,
            'image_280x170' => 0,
            'image_300x195' => 0,
            'image_300x197' => 0,
            'image_309xh' => 0,
            'image_320x210' => 0,
            'image_480x320' => 0,
            'image_618xh' => 0,
            'image_620x413' => 0,
            'image_66x51' => 0,
            'image_70x60' => 0,
            'image_89x80' => 0,
            'image_large' => 0,
            'image_medium' => 0,
            'image_thumbnail' => 0,
            'link' => 0,
            'np_image_full' => 0,
            'np_image_full_caption' => 0,
            'np_image_half_left' => 0,
            'np_image_half_left_caption' => 0,
            'np_image_half_right' => 0,
            'np_image_half_right_caption' => 0,
            'np_image_third_left' => 0,
            'np_image_third_left_caption' => 0,
            'np_image_third_right' => 0,
            'np_image_third_right_caption' => 0,
          ),
          'insert_width' => '',
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '3',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('AddThis');
  t('Assign this verification status a rating to control the default verification status graphic. A value of "1" is the lowest verification status (displayed in red) and "4" is the highest (displayed in green).');
  t('Author');
  t('Coordinates');
  t('Date');
  t('Description');
  t('Enter in decimal or compass format. For example, in decimal format - Longitude: 12.3465 Latitude: 46.0388 or in Compass format - Longitude: 46° 2\' 21.81" N  Latitude: 12° 20\' 40.71" E"');
  t('Facebook Like');
  t('First What Post');
  t('Image');
  t('Last Updated');
  t('Location');
  t('Name');
  t('Never Empty');
  t('Posts');
  t('Rating');
  t('Repeating the description field for multiple display in the node view');
  t('Section');
  t('Sources');
  t('Sources Simple');
  t('Submitted');
  t('Tags');
  t('Verification Narrative');
  t('Verification Status');
  t('What Happened');
  t('What happened');
  t('When');
  t('Where');
  t('Why we think its');
  t('You can optionally upload an image to represent this verification status, wherever it\'s displayed on the front end of the site. If this field is left blank the default verification status graphic will be used instead.');

  return $fields;
}
