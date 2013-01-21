<?php

/*
 * - np_post uses view mode 'in_event_page' for listing the posts on the event node view page
 * - np_author uses view mode 'micro' for listing the author name and rating, particularly on a post
 * - np_inline uses view mode 'inline' for listing events embedded within a story
 */
function np_alpha_preprocess_node(&$vars) {
  if(isset($vars['view_mode'])) {
    $vars['classes_array'][] = 'view-mode-' . $vars['view_mode'];
    $vars['classes_array'][] = 'node-' . $vars['type'] . '-view-mode-' . $vars['view_mode'];
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__' . $vars['view_mode'];
  }
}
