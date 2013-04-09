(function ($) {
  Drupal.behaviors.quickbar_help = {
    attach: function(context, settings) {
      $('#quickbar .help-icon').click(function(e) {
        e.preventDefault();
        $('#quickbar-help-box').slideToggle('fast');
      });
      
      $('#quickbar-help-box').css('max-height', $(window).height() - 125 + 'px');
      
      $('#quickbar-help-box .close-button').click(function() {
        $('#quickbar-help-box').slideToggle('fast');
      });
    }
  }
})(jQuery);