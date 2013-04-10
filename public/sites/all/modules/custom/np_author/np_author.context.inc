<?php
/**
 * @file
 * np_author.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function np_author_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'author';
  $context->description = '';
  $context->tag = 'blocks';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'author' => 'author',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'np_event-np_author_events' => array(
          'module' => 'np_event',
          'delta' => 'np_author_events',
          'region' => 'after_content',
          'weight' => '-10',
        ),
        'menu-menu-our-approach' => array(
          'module' => 'menu',
          'delta' => 'menu-our-approach',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('blocks');
  $export['author'] = $context;

  return $export;
}
