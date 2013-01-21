<?php
/**
 * @file
 * np_event.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function np_event_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'event';
  $context->description = '';
  $context->tag = 'blocks';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'event' => 'event',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '0',
        ),
        'views-related_stories-block' => array(
          'module' => 'views',
          'delta' => 'related_stories-block',
          'region' => 'content',
          'weight' => '10',
        ),
        'views-latest_from_location-block' => array(
          'module' => 'views',
          'delta' => 'latest_from_location-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'menu-menu-our-approach' => array(
          'module' => 'menu',
          'delta' => 'menu-our-approach',
          'region' => 'sidebar_second',
          'weight' => '-11',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('blocks');
  $export['event'] = $context;

  return $export;
}
