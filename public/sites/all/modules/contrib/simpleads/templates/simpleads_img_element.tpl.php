<?php

/**
 * @file
 * SimpleAds Image ad.
 * 
 * Avaialable variables
 * array $ad
 * array $settings
 * array $image_attributes
 * array $link_attributes
 * 
 */
?>
<div class="simplead-container image-ad <?php if (isset($css_attributes)): print $css_attributes; endif; ?>">
  <?php print l(theme('image', $image_attributes), $ad['url'], $link_attributes); ?>
</div>