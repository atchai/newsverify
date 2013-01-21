<?php

/**
 * @file
 * Default simple view template to display ads.
 */
?>
<?php if (isset($tid) && isset($ads_list) && !empty($ads_list)) : ?>
<div class="simpleads-<?php print $tid; ?><?php if ($prefix) :?>-<?php print $prefix; ?><?php endif; ?>">
  <?php print $ads_list; ?>
</div>
<?php endif; ?>