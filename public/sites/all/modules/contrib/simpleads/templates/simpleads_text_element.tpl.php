<?php

/**
 * @file
 * SimpleAds Text ad.
 * 
 * Avaialable variables
 * array $ad
 * array $settings
 * string $text_ad
 * 
 */
?>
<div class="simplead-container text-ad <?php if (isset($css_attributes)): print $css_attributes; endif; ?>">
  <?php print $text_ad; ?>
</div>