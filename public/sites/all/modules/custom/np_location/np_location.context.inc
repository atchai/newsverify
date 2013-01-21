<?php
/**
 * @file
 * np_location.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function np_location_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'location';
  $context->description = '';
  $context->tag = 'blocks';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'location*' => 'location*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-location' => array(
          'module' => 'menu',
          'delta' => 'menu-location',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('blocks');
  $export['location'] = $context;

  return $export;
}
