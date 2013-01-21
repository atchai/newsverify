<?php

/**
 * @file
 * SimpleAds Block template
 *
 * Use Javascript code below when you enable caching,
 * otherwise it will be cached and rotating will not work.
 * 
 * $ads_page
 *   Url to Advertise page (configurable in block settings).
 *
 * $tid
 *   Term ID
 *
 * $prefix
 *   Unique number (to identify container for ads)
 *
 * $ads
 *   Array of Ads
 *
 * $ads_width
 *   Ad width
 *
 * $ads_height
 *   Ad height
 *
 * $ads_limit
 *   Numer of ads to dispaly
 *
 * Note: Consider using only one method (javascript or static output),
 * otherwise ad impression counter will be doubled.
 *
 */

  $settings = array(
    'ads_width' => check_plain($ads_width),
    'ads_height' => check_plain($ads_height),
  );

?>
<?php if (count($ads) > 0) : ?>
<div class="header">
  <div class="ad-link"><?php if(!is_null($ads_page) && !empty($ads_page)) : print l(t('Advertise with us'), $ads_page); endif; ?></div>
</div>
<div class="adslist">
  <script type="text/javascript">
    _simpelads_load('.simpleads-<?php print $tid; ?><?php if ($prefix) : ?>-<?php print $prefix; ?><?php endif; ?>', <?php print $tid; ?>, <?php print check_plain($ads_limit); ?>);
  </script>
  <?php /* If you would like to modify class attrbiute, please don't forget to update 
    the first argument in function call above (_simpleads_load(...)).
  */
  ?>
  <div class="simpleads-<?php print $tid; ?><?php if ($prefix) :?>-<?php print $prefix; ?><?php endif; ?>"></div>

  <?php // Code below displays ad, but if Drupal cache enabled, the ad remains the same until the cache not cleared or not expired. ?>
  <?php /* if (count($ads) > 0) : ?>
    <?php foreach ($ads as $ad) : ?>
      <?php if ($ad['type'] == 'graphic') : ?>
        <?php print theme('simpleads_img_element', array('ad' => $ad, 'settings' => $settings)); ?>
      <?php elseif ($ad['type'] == 'text') : ?>
        <?php print theme('simpleads_text_element', array('ad' => $ad, 'settings' => $settings)); ?>
      <?php else : ?>
        <?php print theme('simpleads_flash_element', array('ad' => $ad, 'settings' => $settings)); ?>
      <?php endif; ?>
    <?php endforeach; ?>
  <?php endif; */ ?>

</div>
<?php endif; ?>