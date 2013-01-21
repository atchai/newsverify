> Module Name: SimpleAds
> Author: Minnur Yunusov <minnur.yunusov@gmail.com>

---

This module provides a way to feature advertisements on a Drupal website.
It displays graphical, text and flash ads in configurable blocks.
It records and reports useful statistics.
It is easy to configure and does not depend on other contrib modules.

FEATURES:

- Customizable groups for different ad types

- Automatically generates ad blocks for different ad types

- Many configuration options for individual ad blocks including ad size
and number of ads to display in a block

- Convenient dashboard for quick review of active ads

- User-friendly ad scheduler makes it easy to schedule ad activation
and expiration.
(Enter Activation or Expiration Date by typing Now, +1 week, +1 year, etc..)

- Capture useful statistics including ad impressions, clicks for 1
hours, one day, one week, one month, 3 months, 6 months, 1 year,
and all time.

- Option to count clicks/impressions only for certain user roles

- Generates live ad statistics report

- Ad blocks can be themed. Simply copy templates to your theme folder.

- Dynamic Ad rotation (configurable on block configuration screen)

- Integration with WYSIWYG module (supports TinyMCE, CKEditor, FCKEditor).
Plugin allows to inject Ads into content.

- Integration with Views. Enable sample View in Structure > Views.

- Integration with Domain Access module.

- Integration with Nodequeue module.

- Text Ads allows to advertise any text. If you would like to advertise
videos from YouTube, Vimeo, Blip.TV or other sites, simply install
Video Filter module and enable WYSIWYG plugin.

- Support Flash Ads. 
Upload SWF file and it will automatically show up in your block.

CAMPAIGNS

- By clicks
- By impressions
- By days
- All 3 options (whichever comes first)

CONFIGURATION:

If your site is behind a reverse proxy (e.g. Varnish) the unique impressions
count will be incorrect because it will record the IP address of the proxy
rather than the client. Make sure you set variables 'reverse_proxy' and
'reverse_proxy_addresses' to suit your infrastructure.