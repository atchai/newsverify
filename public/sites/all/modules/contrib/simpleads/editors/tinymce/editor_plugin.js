/**
 * @file
 * SimpleAds TinyMCE plugin
 */

(function ($) {
  
  tinymce.create('tinymce.plugins.simpleads', {
  
    init : function(ed, url) {
  
      ed.addCommand('mceSimpleAds', function() {
        ed.windowManager.open({
          file : Drupal.settings.simpleads.url.wysiwyg_tinymce,
          width : 580,
          height : 250,
          inline : true,
          scrollbars : 1,
          popup_css : false
        },
        {
          plugin_url : url
        });
      });
  
      ed.addButton('simpleads', {
        title : 'SimpleAds',
        cmd : 'mceSimpleAds',
        image : url + '/images/simpleads_filter.png'
      });
  
    },
  
    getInfo : function() {
      return {
        longname : 'SimpleAds',
        author : 'SimpleAds Filter',
        version : tinymce.majorVersion + "." + tinymce.minorVersion
      };
    }
  });
  
  tinymce.PluginManager.add('simpleads', tinymce.plugins.simpleads);
  
})(jQuery);