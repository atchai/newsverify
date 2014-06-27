(function($) {
  Drupal.behaviors.np_event_summary = {
    attach: function (context) {
  
      // Defined vars based on screen width
      windowWidth = $(window).width();
      mobileWidth = 767;
      
      // Desktop
      if (windowWidth >= mobileWidth) {
        $('.event-status-summary-container').each(function(){ 
          $(this).find('.event-status-link-container-overlay a.event-summary-link').qtip({
            content: {
              text: $(this).find('.event-status-content-container'),
            },
            position: {
              my: 'top right',
              at: 'bottom left',
              target: $(this).find('.event-status-link-container-overlay a.event-summary-link')
            },
            show: {
              event: 'click',
              delay: 0,
              solo: true,
            },
            hide: {
              leave: false,
              fixed: true,
              delay: 1000,
            },
            events: {
              show: function(event, api) {
                // Doesn't appear to work for our purposes of preventing the original click event
              }
            },
            style: {
              def: false
            }
          });
          
          // Using event.preventDefault() or event.originalEvent.preventDefault();
          // in the qTip show event hook doesn't seem to work in stopping the
          // click event. So we just do it here.  
          $(this).find('.event-status-link-container-overlay a.event-summary-link').click(function(e) {
            e.preventDefault(); 
          });
        });
      }
      // Mobile 
      else {
        
      }
  
    }
  };
})(jQuery);
