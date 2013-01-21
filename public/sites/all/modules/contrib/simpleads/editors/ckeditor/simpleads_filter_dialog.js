/**
 * @file
 * SimpleAds CKEditor Plugin.
 */

var simpleads_dialog = {};
(function ($) {

  simpleads_dialog = {
    init : function() {
    CKEDITOR = dialogArguments.opener.CKEDITOR;
    var name = dialogArguments.editorname;
    editor = CKEDITOR.instances[name];
  },

  insert : function() {   
    var params = this._getParams();  
    if(params.file_url == "") {
      window.close();
    }
    else {      
      CKEDITOR.tools.callFunction(editor._.simpleadsFnNum, params, editor);   
      window.close();
    }
  },
  
  _getParams : function () {
    var params = {};
    $('fieldset:first-child input, fieldset:first-child select').each(function() {
      if($(this).attr('type') == "checkbox") {
        if($(this).is(':checked')) {
          params[$(this).attr('name')] = $(this).val();
        }
      } 
      else {
        if($(this).val() != "" && $(this).val() != "none") {
          params[$(this).attr('name')] = $(this).val();
        }
      }
    });

    return params;
  }
};

$(document).ready(function() {

  var CKEDITOR, editor;
  
  simpleads_dialog.init();

  $('#edit-insert').click(function() {
    simpleads_dialog.insert();
    return false;
  });

  $('#edit-cancel').click(function() {
    window.close();
    return false;
  });

});

})(jQuery);