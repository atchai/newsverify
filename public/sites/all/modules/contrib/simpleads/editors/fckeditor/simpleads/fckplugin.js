/**
 * @file
 * SimpleAds FCKEditor Plugin
 */
var path = Drupal.settings.simpleads.url.wysiwyg_fckeditor;
var basePath =  Drupal.settings.basePath;
var modulePath = Drupal.settings.simpleads.modulepath;

FCKCommands.RegisterCommand( 'simpleads', new FCKDialogCommand( 'simpleads', '&nbsp;', path, 580, 250 ) ) ;

var oSimpleAdsItem = new FCKToolbarButton( 'simpleads', 'simpleads');
oSimpleAdsItem.IconPath = basePath + modulePath + '/editors/fckeditor/simpleads/simpleads_filter.png';
FCKToolbarItems.RegisterItem( 'simpleads', oSimpleAdsItem );