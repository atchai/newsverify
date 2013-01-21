<?php

/**
 * @file
 * SimpleAds template for AJAX callback.
 */

?>
<?php if (isset($settings['ads_rotation_type']) && $total_ads > 1 && $settings['ads_rotation_type'] > 0) : ?>
<script type="text/javascript">
(function ($) {
  $(document).ready(function() {
    $("div#<?php print $settings['block_delta']; ?>").simpleads_rotator({
      rotation_type: <?php print $settings['ads_rotation_type']; ?>, 
      delay: <?php print $settings['ads_rotation_delay'] * 1000; ?>, 
      delta: '<?php print $settings['block_delta']; ?>'
    });
  });
}(jQuery));
</script>
<?php endif; ?>

<?php // $content - list of ads ?>
<div id="<?php print $settings['block_delta']; ?>">
  <?php print $content; ?>
</div>