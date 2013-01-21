<?php

/**
 * @file
 * SimpleAds Flash ad.
 */

$width = !empty($settings['ads_width']) ? check_plain($settings['ads_width']) : '120';
$height = !empty($settings['ads_height']) ? check_plain($settings['ads_height']) : '120';

?>
<?php if ($ad['flash']) : ?>
<div class="simplead-container flash-ad <?php if (isset($css_attributes)): print $css_attributes; endif; ?>">
  <object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000" codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=6,0,40,0" width="<?php print $width; ?>" height="<?php print $height; ?>" id="ad-<?php print $ad['nid']; ?>"> 
  
    <param name="movie" value="<?php print $ad['flash']; ?>" />
    <param name="quality" value="high" />
    <param name="bgcolor" value="#ffffff" />
    <?php if ($ad['url']) : ?>
      <?php // Passing URL to redirect ?>
      <param value="clickTAG=<?php print url($ad['url']); ?>" name="flashvars">
    <?php endif; ?>
  
    <embed src="<?php print $ad['flash']; ?>" quality="high" bgcolor="#ffffff" width="<?php print $width; ?>" height="<?php print $height; ?>" name="ad-<?php print $ad['nid']; ?>" align="" type="application/x-shockwave-flash" pluginspage="http://www.macromedia.com/go/getflashplayer"></embed> 
  
  </object>
</div>
<?php endif; ?>