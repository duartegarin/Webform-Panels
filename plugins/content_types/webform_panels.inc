<?php

/**
 * @file
 * Main file for the the webform content type definition.
 *
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Rendered Webform'),
  'description' => t('Shows a rendered Webform.'),
  'category' => t('Webforms'),
  'edit form' => 'webform_panels_webform_panels_edit_form',
  'render callback' => 'webform_panels_webform_panels_render',
  'admin info' => 'webform_panels_webform_panels_admin_info',
  'defaults' => array(
    'selected_forms' => 1,
  ),

);

/**
 * Implements the 'admin info' callback for the panel pane.
 */
function webform_panels_webform_panels_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass();
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';

    return $block;
  }
}

/**
 * Edit form callback for the content type.
 */
function webform_panels_webform_panels_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['selected_forms'] = array(

    '#title' => t('Webform to embed'),
    '#description' => t('Used to embed the selected webform in the page.'),
    '#type' => 'select',
    '#options' => webform_panels_get_all_forms(),
    '#default_value' => $conf['selected_forms'],
    '#required' => TRUE,
  );
  return $form;
}

/**
 * Retrieves all nodes that have webform components associated with them.
 * @return $options
 */
function webform_panels_get_all_forms() {

  $query = db_select('webform_component', 'w')->fields('w', array('nid'))->distinct();
  $options = array();

  foreach($query->execute() as $result){

    $results[] = $result->nid;
  }

  $nodes = node_load_multiple($results);

  foreach($nodes as $node){

    $options[$node->nid] = $node->title;
  }

  return $options;
}

/**
 * The submit form stores the data in $conf.
 */
function webform_panels_webform_panels_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function webform_panels_webform_panels_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();

  // initial content is blank
  $block->title = '';
  $block->content = '';

  // Add in the content
  $node = node_load($conf['selected_forms']);
  $render = node_view($node);

  $block->content .= render($render);

  return $block;
}
