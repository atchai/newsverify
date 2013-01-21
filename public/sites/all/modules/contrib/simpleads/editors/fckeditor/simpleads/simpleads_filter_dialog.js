/**
 * @file
 * SimpleAds FCKEditor Plugin.
 */

var dialog	= window.parent ;
var oEditor = dialog.InnerDialogLoaded() ;

var FCK = oEditor.FCK;

dialog.SetAutoSize(true) ;
dialog.SetOkButton(true) ;

(function ($) {

  $(document).ready(function() {
    $('#edit-cancel, #edit-insert').hide();
    $('*', document).keydown(function(ev) {
      if (ev.keyCode == 13) {
        return false;
      }
    });
  });

})(jQuery);

function Ok() {

  var sInnerHtml ;

  (function ($) {
    var ad_group_tid = $('#edit-tid').val();

    if(ad_group_tid == "") {
      dialog.Cancel();
    }

    var str = '[ads:' + ad_group_tid;

    if ($('#edit-num').val() !== '') {
      str += ' limit:' + $('#edit-num').val();
    }
    else {
      str += ' limit:1';
    }
    str += ']';

    oEditor.FCKUndo.SaveUndoStep();

    var text = oEditor.FCK.InsertHtml(str);

  })(jQuery);

  return true;

}


