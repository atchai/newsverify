<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

function np_form_alter(&$form, &$form_state, $form_id) {
  if ($form['#id'] == 'views-exposed-form-search-page') {
    unset($form['#info']['filter-search_api_views_fulltext']['label']);
  }
}

/*
 * Fields of type text_long (e.g in story nodes) contain divs which are floated left and right for images.
 * Thus we need to clearfix these fields so that the next fields (e.g the section tags on a story)
 * display nicely. This is probably not the best way to manage this but will do for now.
 * 
 * UPDATE: As fields are or are not filled in, display is unreliable. Clearfix on all may fix this.
 */
function np_preprocess_field(&$vars) {
  $element = $vars['element'];
  $vars['classes_array'][] = 'clearfix';
}
