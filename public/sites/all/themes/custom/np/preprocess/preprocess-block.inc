<?php

/*
 * - np_post uses view mode 'in_event_page' for listing the posts on the event node view page
 * - np_author uses view mode 'micro' for listing the author name and rating, particularly on a post
 */
function np_alpha_preprocess_block(&$vars) {
  if ($vars['block_html_id'] == 'block-menu-menu-section') {
    $vars['block']->subject = NULL;
  }
}
