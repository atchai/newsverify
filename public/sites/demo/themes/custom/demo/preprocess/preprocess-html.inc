<?php

/* JQuery Masonry
 * See np.js in np theme to see Drupal.np.masonry() definition.
 */
function demo_alpha_preprocess_html(&$vars) {
  if (!isset($vars['page']['page_top'])) {
    $vars['page']['page_top'] = array();
  }
  $vars['page']['page_top']['js_init'] = array(
    '#markup' => '
      <script type="text/javascript">
        jQuery(document).ready(function() {
          Drupal.np.masonry();
          Drupal.np.menu();
        });
      </script>
    '
  );
}
