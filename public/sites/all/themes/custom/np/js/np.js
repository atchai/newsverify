(function($) {

// Configuration
var mobileWidth = 767,
    webFontLoaded = false;

/* JQuery Masonry
 * See preprocess-html.inc in subthemes to see where Drupal.np.masonry() is called.
 * We do it this way because jQuery.masonry() needs to be called *after* custom webfonts are loaded
 * or else the height of the bricks is calculated incorrectly and the bricks overlap
----------------------------------------------------------------------------------------------------*/
Drupal.np = {
  webFontLoad: function() {
    if (webFontLoaded) {
      $(window).trigger('resize');
    } else {
      $(window).load(function() {
        Drupal.np.masonry();
        Drupal.np.menu();
      });
      webFontLoaded = true;
    }
  },

  masonry: function () {
    // Bind masonry layout to window resize
    $(window).bind('resize', function() {
      $('.view-home ul.news-list, .view-taxonomy ul.news-list, .view-search ul.news-list').isotope({
        itemSelector: 'li.news-item',
        containerStyle: {
          overflow: 'visible',
          position: 'relative'
        }
      });
    });
    // Trigger resize for initial layout
    $(window).trigger('resize');
  },

  /* Menu - JS Interaction
   * See preprocess-html.inc in np subthemes to see where Drupal.np.masonry() is called.
   * Called at the same time after the font loading, as size calculation is the same problem as
   * with the masonry function.
  ----------------------------------------------------------------------------------------------------*/
  menu: function () {
    if ($(window).width() >= mobileWidth) {

      // Add the more link to the html
      $('<div id="menu-more-container"><a href="#">' + Drupal.t('More') + '</a></div>').insertAfter('#block-menu-menu-section');

      $('#menu-more-container a').click(function(event) {
        // Prevent the click from activating.
        event.preventDefault();

        // 12 column is 960px, but we need ~80px for the "more" link, so 880px available for the first row of ul li items
        var remainingWidth = 880;
        var cutoffItem = -1;
        $('#block-menu-menu-section ul.menu li').each(function(i) {

          // With each new ul li, reduce the remaining horizontal space available.
          // outerWidth(true) includes width, padding, border and margin - e.g the true space taken.
          // Note: .outerWidth(true) is not giving accurate results, it's returning a little too small. E.G
          // E.G if firefox inspect shows 110, it's returning 99. I *suspect* that is because of custom fonts
          // A workaround, is to approximate, so taking off another ~10%.
          // UPDATE: Have shifted to be triggered by google web fonts loader AFTER fonts have finished loading.
          // Thus we use a new multiple of 0% as it should measure widths correctly now.
          remainingWidth = remainingWidth - ($(this).outerWidth(true) + $(this).outerWidth(true) * 0.0);

          // Formally this should be 0, but I'm leaving a few pixels spare to cover for browser variations
          if (remainingWidth <= 10) {
            // We're now below the remaining width for one row. So the ul li item that should be the last in the
            // row is the one before this one e.g i - 1
            cutoffItem = i - 1;

            // Return false immediately to stop the each loop
            return false;
          }
        });

        // Only act if there are enough menu items to go onto a new line
        if (cutoffItem != -1) {
          // Now loop through all the ul li items again, and hide all those after
          // the last one on the first line - e.g the cutoffItem
          $('#block-menu-menu-section ul.menu li').each(function(i) {
            // Before the cutoff - e.g the first line
            if (i <= cutoffItem) {
              $(this).toggleClass('menu-more-closed');
            }
            if (i >= cutoffItem) {
              $(this).toggle(0);
            }
          })
        }

      });

      // Trigger the click event to do the initial hide of the additional rows of ul li items
      $('#menu-more-container a').trigger('click');
    }
  }
};

Drupal.behaviors.np = {
  attach: function (context) {
    /* Mobile AND Desktop
    ----------------------------------------------------------------------------------------------------*/
    // Search Example
    $('.views-exposed-form .form-item-search-fulltext input.form-text').example(Drupal.t('Search'), {className: 'search_example'});

    /* Desktop Only
    ----------------------------------------------------------------------------------------------------*/
    var windowWidth = $(window).width();

    if (windowWidth >= mobileWidth) {

      // Add event summary pop-up overlays
      $('.event-status-summary-container').each(function(){
        $(this).find('.event-status-link-container-overlay a.event-summary-link').qtip({
          content: {
            text: $(this).find('.event-status-content-container'),
          },
          position: {
            my: 'top right',
            at: 'bottom left',
            target: $(this).find('.event-status-link-container-overlay a.event-summary-link'),
            viewport: $(window)
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

      // Select advert containers and all their children
      var $ads = $('.simplead-container'),
          $children = $ads.find('*');

      // Find the height of the tallest element among the ad container children
      var tallest = Math.max.apply(Math, $children.map(function(){ return $(this).height(); }).get());

      // Set all ad containers to largest height value
      $ads.height(tallest);

      // Add a "load" event for all ad container children
      $children.one('load', function() {
        if ($(this).height() > tallest) {
          // If this child is the tallest now that
          // it's been loaded, update all ad containers
          tallest = $(this).height();
          $ads.height(tallest);
        }
      }).each(function() {
        // Fire load event manually if this element
        // is already loaded (it's cached)
        if(this.complete) {
          $(this).load();
        }
      });

      // Carousel config
      var carouselItemWidth = 320;

    /* Mobile Only
    ----------------------------------------------------------------------------------------------------*/
    } else {

      // Carousel config
      var carouselItemWidth = 300;

      // Automatically resize embedded YouTube videos
      var ytMargin = 40,
          ytEventMargin = 60;

      $('iframe').each(function() {

        var $video = $(this),
            newWidth = windowWidth;

        if ($video.parents('.node-type-event').size() > 0) {
            newWidth -= ytEventMargin;
        } else {
            newWidth -= ytMargin;
        }

        $video
            .width(newWidth)
            .height(newWidth * (this.height / this.width))
			.removeAttr('width')
			.removeAttr('height');

      });

    }

    // Initialise carousel
    $('.view-home-carousel .slideshow').flexslider({
      animation: 'slide',
      easing: 'linear',
      animationLoop: true,
      controlNav: false,
      itemWidth: carouselItemWidth,
      itemMargin: 0
    });

  }
};

})(jQuery);
