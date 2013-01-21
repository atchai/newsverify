<?php
/**
 * @file
 * This is currently a stub file that will be used to describe the addthis
 * implementation API.
 */

/**
 * Implements hook_addthis_markup_alter.
 *
 * @param array $markup
 *   $markup contain an array with the structure of the addthis markup.
 */
function hook_addthis_markup_alter(&$markup) {

  // Let's add a custom CSS class for given a particular desing to our
  // twitter button, so we can change the look
  if (!empty($markup['twitter'])) {
    $markup['twitter']['#attributes']['class'][] = "custom_twitter_class";
  }
}
