/**
 * @file
 * SimpleAds Campaigns JS helper.
 */

(function ($) {
  Drupal.behaviors.simpleads_campaigns = {
    attach: function(context) {
      var impressions = $('#edit-field-adcamp-impression input[id^=edit-field-adcamp-impression-]');
      _simpelads_campaigns_switch_form(impressions, 'impressions');
      $('#edit-field-adcamp-impression input[id^=edit-field-adcamp-impression-]').change(function(){
        _simpelads_campaigns_switch_form($(this), 'impressions');
      });
      var clicks = $('#edit-field-adcamp-click input[id^=edit-field-adcamp-click-]');
      _simpelads_campaigns_switch_form(clicks, 'clicks');
      $('#edit-field-adcamp-click input[id^=edit-field-adcamp-click-]').change(function(){
        _simpelads_campaigns_switch_form($(this), 'clicks');
      });
      var days = $('#edit-field-adcamp-day input[id^=edit-field-adcamp-day-]');
      _simpelads_campaigns_switch_form(days, 'days');
      $('#edit-field-adcamp-day input[id^=edit-field-adcamp-day-]').change(function(){
        _simpelads_campaigns_switch_form($(this), 'days');
      });

      var campaigns = $('#edit-campaign').val();
      if (campaigns == '_none') {
        $('#edit-field-ad-end-date').show();
      }
      else {
        $('#edit-field-ad-end-date').hide();
      }

      $('#edit-campaign').change(function(){
        if ($(this).val() == '_none') {
          $('#edit-field-ad-end-date').slideDown();
        }
        else {
          $('#edit-field-ad-end-date').slideUp();
        }
      });

    }
  };
}(jQuery));

/**
 * Show/hide form elements.
 */
function _simpelads_campaigns_switch_form(el, type) {
  (function ($) {
    el_impressions = $('form#simpleads-campaign-node-form #edit-field-adcamp-impressions');
    el_clicks = $('form#simpleads-campaign-node-form #edit-field-adcamp-clicks');
    el_days = $('form#simpleads-campaign-node-form #edit-field-adcamp-days');
    if (el.attr('checked') == true && type == 'impressions') {
      el_impressions.slideDown();
    }
    if (el.attr('checked') == false && type == 'impressions') {
      el_impressions.slideUp();
    }
    if (el.attr('checked') == true && type == 'clicks') {
      el_clicks.slideDown();
    }
    if (el.attr('checked') == false && type == 'clicks') {
      el_clicks.slideUp();
    }
    if (el.attr('checked') == true && type == 'days') {
      el_days.slideDown();
    }
    if (el.attr('checked') == false && type == 'days') {
      el_days.slideUp();
    }
  }(jQuery));
}