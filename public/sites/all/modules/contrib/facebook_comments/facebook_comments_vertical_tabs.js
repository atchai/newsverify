
(function ($) {

/**
 * Provide summary information for vertical tabs.
 */
Drupal.behaviors.facebook_commentsFieldsetSummaries = {
  attach: function (context) {
	// Provide summary when editting a node.
	$('fieldset.edit-facebook-comments', context).drupalSetSummary(function(context) {
      if ($('#edit-facebook-comments-enabled').attr('checked')) {
        return Drupal.t('Comments enabled');
      }
      else {
        return Drupal.t('Comments disabled');
      }
    });
  }
};

})(jQuery);
