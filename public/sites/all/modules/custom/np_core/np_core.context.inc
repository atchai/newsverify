<?php
/**
 * @file
 * np_core.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function np_core_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'global';
  $context->description = '';
  $context->tag = 'blocks';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'np_core-np_core_small_logo' => array(
          'module' => 'np_core',
          'delta' => 'np_core_small_logo',
          'region' => 'search',
          'weight' => '-10',
        ),
        'views--exp-search-page' => array(
          'module' => 'views',
          'delta' => '-exp-search-page',
          'region' => 'search',
          'weight' => '-9',
        ),
        'np_core-np_core_site_slogan' => array(
          'module' => 'np_core',
          'delta' => 'np_core_site_slogan',
          'region' => 'branding_left',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '0',
        ),
        'responsive_dropdown_menus-menu-section' => array(
          'module' => 'responsive_dropdown_menus',
          'delta' => 'menu-section',
          'region' => 'pre_content',
          'weight' => '-9',
        ),
        'views-footer_ads-block' => array(
          'module' => 'views',
          'delta' => 'footer_ads-block',
          'region' => 'after_content',
          'weight' => '0',
        ),
        'menu_block-1' => array(
          'module' => 'menu_block',
          'delta' => '1',
          'region' => 'footer_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('blocks');
  $export['global'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mobile';
  $context->description = '';
  $context->tag = 'blocks';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'np_core-np_core_menu_title' => array(
          'module' => 'np_core',
          'delta' => 'np_core_menu_title',
          'region' => 'search',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('blocks');
  $export['mobile'] = $context;

  return $export;
}
