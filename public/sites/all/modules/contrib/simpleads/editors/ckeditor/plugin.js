/**
 * @file
 * SimpleAds CKEditor Plugin
 */

(function ($) {
  CKEDITOR.plugins.add('simpleads', {

    requires : [],

    init: function(editor) {

      editor.ui.addButton('simpleads', {
        label: 'SimpleAds filter',
        command: 'simpleads',
        icon: this.path + 'simpleads_filter.png'
      });

      editor.addCommand('simpleads', {
        exec : function () {
          var path = (Drupal.settings.simpleads.url.wysiwyg_ckeditor) ? Drupal.settings.simpleads.url.wysiwyg_ckeditor : Drupal.settings.simpleads.url.ckeditor
          var media = window.showModalDialog(path, { 'opener' : window, 'editorname' : editor.name }, "dialogWidth:580px; dialogHeight:250px; center:yes; resizable:yes; help:no;");
        }
      });
      editor._.simpleadsFnNum = CKEDITOR.tools.addFunction(insert, editor);
    }
    
  });

  function insert(params, editor) {
    var selection = editor.getSelection(),
        ranges = selection.getRanges(),
        range, textNode;

    editor.fire('saveSnapshot');

    var str = '[ads:' + params.tid;
    if (params.num) {
      str += ' limit:' + params.num;
    }
    else {
      str += ' limit:1';
    }
    str += ']';

    for ( var i = 0, len = ranges.length ; i < len ; i++ ) {
      range = ranges[i];
      range.deleteContents();

      textNode = CKEDITOR.dom.element.createFromHtml(str);
      range.insertNode(textNode);
    }

    range.moveToPosition(textNode, CKEDITOR.POSITION_AFTER_END);
    range.select();

    editor.fire('saveSnapshot');
  }

})(jQuery);
