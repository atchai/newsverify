<?php
/**
 * @file
 * np_home.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function np_home_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home';
  $context->description = '';
  $context->tag = 'blocks';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-home_carousel-block' => array(
          'module' => 'views',
          'delta' => 'home_carousel-block',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'np_core-np_core_front_page_menu_title' => array(
          'module' => 'np_core',
          'delta' => 'np_core_front_page_menu_title',
          'region' => 'navigation',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('blocks');
  $export['home'] = $context;

  return $export;
}
