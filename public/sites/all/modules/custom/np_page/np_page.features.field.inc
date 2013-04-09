<?php
/**
 * @file
 * np_page.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function np_page_field_default_fields() {
  $fields = array();

  // Exported field: 'node-page-body'.
  $fields['node-page-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
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
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'page',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
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
          'weight' => 0,
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
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => 600,
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Body',
      'required' => 0,
      'settings' => array(
        'display_summary' => 1,
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '20',
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-page-field_addthis'.
  $fields['node-page-field_addthis'] = array(
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
      'bundle' => 'page',
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
          'weight' => 0,
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

  // Exported field: 'node-page-field_facebook_like'.
  $fields['node-page-field_facebook_like'] = array(
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
      'bundle' => 'page',
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
            'share_services' => 'facebook_like,twitter',
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
          'weight' => 0,
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

  // Exported field: 'node-page-field_submitted'.
  $fields['node-page-field_submitted'] = array(
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
      'bundle' => 'page',
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
          'weight' => 0,
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
        'weight' => '6',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('AddThis');
  t('Body');
  t('Facebook Like');
  t('Submitted');

  return $fields;
}
