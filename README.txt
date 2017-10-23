INTRODUCTION
------------
This module provides a ctools content type plugin to display nodes that have
webform components attached to them.

It provides subtypes to allow you to specify the node type of the node you want
to display, as well as the view mode you want to display it in, and it will only
show nodes that actually are webforms, instead of showing all nodes that can be
webforms.

* For a full description of the module, visit the project page:
  https://www.drupal.org/project/webform_panels
* To submit bug reports and feature suggestions, or to track changes:
  https://www.drupal.org/project/issues/webform_panels

REQUIREMENTS
------------
This module requires the following modules:
* Webform (https://drupal.org/project/webform)
* Panels (https://drupal.org/project/panels)
* Ctools (https://drupal.org/project/ctools)

INSTALLATION
------------
* Install as you would normally install a contributed drupal module. See:
  https://drupal.org/documentation/install/modules-themes/modules-7
  for further information.
* You will now have a new content type tab in the panel add content screen.

NOTES
------------
* Only content types that have nodes with webform components will be displayed
  in the subtypes screen of the webform content type section.
