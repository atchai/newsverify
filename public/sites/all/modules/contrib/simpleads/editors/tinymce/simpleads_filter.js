/**
 * @file
 * SimpleAds TinyMCE plugin
 */

var simpleads_dialog = {};

(function ($) {
  
  simpleads_dialog = {
  
    insert : function() {
      var ed = tinyMCEPopup.editor, e;

      tinyMCEPopup.restoreSelection();
      tinyMCEPopup.execCommand("mceBeginUndoLevel");
		
      var ad_group_tid = $('#edit-tid').val();
  
      if (ad_group_tid == "") {
        ed.execCommand('mceRepaint');
        tinyMCEPopup.execCommand("mceEndUndoLevel");
        tinyMCEPopup.close();
      } 
      else {
        var str = '[ads:' + ad_group_tid;
  
        if ($('#edit-num').val() !== '') {
          str += ' limit:' + $('#edit-num').val();
        }
        else {
          str += ' limit:1';
        }
        str += ']';
  
         ed.execCommand('mceInsertContent', false, str);
      }
  
      tinyMCEPopup.execCommand("mceEndUndoLevel");
      tinyMCEPopup.close();
    }
  
  };

  Drupal.behaviors.simpleads_tinymce =  {
  
    attach: function(context, settings) {
      $('#edit-insert').click(function() {
        simpleads_dialog.insert();
      });
  
      $('#edit-cancel').click(function() {
        tinyMCEPopup.close();
      });
    }
  
  }

})(jQuery);