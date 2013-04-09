(function ($){
Drupal.behaviors.quickbar_extras_admin = {
  attach: function(context, settings) {
    if ($('#edit-show-username').is(':not(:checked)')) {
      $('fieldset#username-options').css('display', 'none');
    }
    
    $('#edit-show-username').click(function() {
      toggle_username_link('fieldset#username-options', $(this).is(':checked'));
    });
    
    function toggle_username_link(wrapper, visible) {
      if (visible) {
        $(wrapper).slideDown('fast');
      }
      else {
        $(wrapper).slideUp('fast');
      }
    }
  }
}
})(jQuery);