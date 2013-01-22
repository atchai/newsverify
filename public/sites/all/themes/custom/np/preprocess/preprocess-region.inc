<?php

function np_alpha_preprocess_region(&$vars) {

  // get search box for region--search.tpl.php
  $vars['search_box'] = '';
  if (module_exists('search')) {
    $form = drupal_get_form('search_block_form');
    $vars['search_box'] = drupal_render($form);
  }

}
