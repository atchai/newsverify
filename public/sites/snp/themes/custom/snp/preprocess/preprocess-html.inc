<?php

/* JQuery Masonry
 * See np.js in np theme to see Drupal.np.masonry() definition.
 * We do it this way because jQuery.masonry() needs to be called *after* custom webfonts are loaded
 * or else the height of the bricks is calculated incorrectly and the bricks overlap
 */
function snp_alpha_preprocess_html(&$vars) {
  drupal_add_js('http://ajax.googleapis.com/ajax/libs/webfont/1.4.10/webfont.js', 'external');
  if (!isset($vars['page']['page_top'])) {
    $vars['page']['page_top'] = array();
  }
  $vars['page']['page_top']['google_webfont_loader'] = array(
    '#markup' => '
      <script type="text/javascript">
        WebFont.load({
          monotype: {
            projectId: \'16ce1457-b9c2-4ac2-8b7f-e6c0125da63a\',
          },
          active: Drupal.np.webFontLoad,
          inactive: Drupal.np.webFontLoad
        });
      </script>
    '
  );
}
