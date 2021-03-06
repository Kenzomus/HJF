<?php
/**
 * @file
 * Picture - map breakpoints and image styles
 */

/**
 * Select breakpoint group form.
 */
function picture_select_breakpoint_group_form($form, &$form_state) {
  $groups = breakpoints_breakpoint_group_load_all();
  $options = array();
  foreach ($groups as $group) {
    $options[$group->machine_name] = $group->name;
  }
  if ($options) {
    $form['breakpoint_group'] = array(
      '#title' => t('Breakpoint group'),
      '#type' => 'select',
      '#required' => TRUE,
      '#description' => t('Select a breakpoint group.'),
      '#options' => $options,
      '#default_value' => $form_state['item']->getBreakpointGroup() ? $form_state['item']->getBreakpointGroup()->name : NULL,
    );
  }
  else {
    $form['breakpoint_group'] = array(
      '#title' => t('Breakpoint group'),
      '#type' => 'item',
      '#markup' => t(
        'There are no breakpoint groups. !create_link.',
        array('!create_link' => l(t('Create a breakpoint group'), 'admin/config/media/breakpoints/groups/add'))
      ),
    );
  }

  return $form;
}

function picture_select_breakpoint_group_form_validate($form, &$form_state) {
  if (!isset($form_state['values']['breakpoint_group']) || empty($form_state['values']['breakpoint_group'])) {
    form_error($form['breakpoint_group'], t('No breakpoint group was selected.'));
  }
}

/**
 * Submit callback.
 */
function picture_select_breakpoint_group_form_submit($form, &$form_state) {
  $form_state['item']->setBreakpointGroup($form_state['values']['breakpoint_group']);
}

function picture_mapping_form(&$form, &$form_state) {
  $picture_mapping = $form_state['item'];
  $form['info']['label']['#required'] = TRUE;
  $form['info']['machine_name']['#title'] = t('Machine name');
  $groups = breakpoints_breakpoint_group_load_all();
  $options = array();
  foreach ($groups as $group) {
    $options[$group->machine_name] = $group->name;
  }
  $form['breakpoint_group'] = array(
    '#title' => t('Breakpoint group'),
    '#type' => 'select',
    '#required' => TRUE,
    '#description' => t('Select a breakpoint group.'),
    '#options' => $options,
    '#default_value' => $picture_mapping->getBreakpointGroup()->name,
    '#ajax' => array(
      'callback' => 'picture_mapping_form_change_breakpoint_group',
      'wrapper' => 'picture-mapping-container',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  $form['mapping'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'picture-mapping-container',
    ),
    '#tree' => TRUE,
  );

  $image_styles = image_style_options(TRUE) + array(
    PICTURE_EMPTY_IMAGE => t('Empty image'),
    PICTURE_ORIGINAL_IMAGE => t('Original image'),
  );
  foreach ($picture_mapping->getMappings() as $breakpoint_id => $mapping) {
    foreach ($mapping as $multiplier => $mapping_definition) {
      $breakpoint = breakpoints_breakpoint_load_by_fullkey($breakpoint_id);
      $label = $multiplier . ' ' . $breakpoint->name . ' [' . $breakpoint->breakpoint . ']';
      $form['mapping'][$breakpoint_id][$multiplier] = array(
        '#type' => 'fieldset',
        '#title' => check_plain($label),
      );
      $form['mapping'][$breakpoint_id][$multiplier]['mapping_type'] = array(
        '#title' => t('Type'),
        '#type' => 'radios',
        '#options' => array(
          '_none' => t('Do not use this breakpoint'),
          'image_style' => t('Use image styles'),
          'sizes' => t('Use the sizes attribute'),
        ),
        '#default_value' => isset($mapping_definition['mapping_type']) ? $mapping_definition['mapping_type'] : '_none',
      );
      $form['mapping'][$breakpoint_id][$multiplier]['image_style'] = array(
        '#type' => 'select',
        '#title' => t('Image style'),
        '#options' => $image_styles,
        '#default_value' => isset($mapping_definition['image_style']) ? $mapping_definition['image_style'] : '',
        '#description' => t('Select an image style for this breakpoint.'),
        '#states' => array(
          'visible' => array(
            ':input[name="mapping[' . $breakpoint_id . '][' . $multiplier . '][mapping_type]"]' => array('value' => 'image_style'),
          ),
        ),
      );
      $form['mapping'][$breakpoint_id][$multiplier]['sizes'] = array(
        '#type' => 'textfield',
        '#title' => t('Sizes'),
        '#default_value' => isset($mapping_definition['sizes']) ? $mapping_definition['sizes'] : '',
        '#description' => t('Enter the value for the sizes attribute (e.g. "(min-width:700px) 700px, 100vw").'),
        '#states' => array(
          'visible' => array(
            ':input[name="mapping[' . $breakpoint_id . '][' . $multiplier . '][mapping_type]"]' => array('value' => 'sizes'),
          ),
        ),
      );
      $form['mapping'][$breakpoint_id][$multiplier]['sizes_image_styles'] = array(
        '#title' => t('Image styles'),
        '#type' => 'checkboxes',
        '#options' => array_diff_key($image_styles, array('' => '')),
        '#default_value' => isset($mapping_definition['sizes_image_styles']) ? $mapping_definition['sizes_image_styles'] : array(),
        '#states' => array(
          'visible' => array(
            ':input[name="mapping[' . $breakpoint_id . '][' . $multiplier . '][mapping_type]"]' => array('value' => 'sizes'),
          ),
        ),
      );

    }
  }
  $form['#tree'] = FALSE;
  return $form;
}

function picture_mapping_form_change_breakpoint_group($form, &$form_state) {
  return $form['mapping'];
}

/**
 * Validate callback.
 */
function picture_mapping_form_validate($form, &$form_state) {
  $picture_mapping = $form_state['item'];
  if ($form_state['triggering_element']['#type'] != 'submit') {
    $picture_mapping->setBreakpointGroup($form_state['values']['breakpoint_group']);
    $form_state['rebuild'] = TRUE;
    return;
  }
  $picture_mapping->setLabel($form_state['values']['label']);
  $picture_mapping->setMachineName($form_state['values']['machine_name']);
  $picture_mapping->setMappings($form_state['values']['mapping']);
  // Make sure at least one mapping is defined.
  if (!$picture_mapping->hasMappings()) {
    form_error($form['mapping'], t('Please select at least one mapping.'));
  }
}

/**
 * Chooses which picture groups are available in the CKEditor image dialog.
 */
function picture_ckeditor_settings() {
  $form = array();
  $picture_mappings = picture_get_mapping_options();
  $ckeditor_mappins = array();

  // Check if picture mappings have been configured before proceeding.
  if ($picture_mappings) {
    // Create a settings form.
    $form['description'] = array(
      '#type' => 'item',
      '#title' => t('Choose which picture mappings will be available in the CKEditor image dialog.'),
      '#description' => 'See picture_wysiwyg.css for an example of how to style these images in your theme using the selectors suggested below.',
    );

    // Retrieve pre-existing settings.
    $ckeditor_mappings = variable_get('picture_ckeditor_mappings', array());

    // Loop through each picture mapping and place a checkbox and weight.
    foreach ($picture_mappings as $machine_name => $display_name) {
      $form[$machine_name] = array(
        '#type' => 'fieldset',
        '#title' => t('@name picture mapping', array('@name' => $display_name)),
      );
      $form[$machine_name]['enabled'] = array(
        '#type' => 'checkbox',
        '#default_value' => isset($ckeditor_mappings[$machine_name]) ? $ckeditor_mappings[$machine_name]['enabled'] : 0,
        '#title' => t('Include @name picture mapping in the CKEditor image dialog', array('@name' => $display_name)),
      );
      $form[$machine_name]['css'] = array(
        '#type' => 'item',
        '#markup' => 'Consider using the selector <code>span[data-picture-mapping="' . $machine_name . '"]</code> in your theme CSS.',
      );
      $form[$machine_name]['weight'] = array(
        '#type' => 'select',
        '#title' => t('Weight'),
        '#options' => drupal_map_assoc(array(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)),
        '#default_value' => isset($ckeditor_mappings[$machine_name]) ? $ckeditor_mappings[$machine_name]['weight'] : 1,
        '#description' => t('Control the sort order of picture mappings in the CKEditor "size" drop-down. Higher weights sink to the bottom of the list.'),
      );
      $form[$machine_name]['fallback'] = array(
        '#type' => 'select',
        '#title' => t('Fallback image style'),
        '#options' => drupal_map_assoc(array_keys(image_styles())),
        '#default_value' => isset($ckeditor_mappings[$machine_name]) ? $ckeditor_mappings[$machine_name]['fallback'] : NULL,
      );
    }
    $form['#tree'] = TRUE;
    $form['ckeditor_label'] = array(
      '#type' => 'textfield',
      '#title' => t('Label in the CKEditor image dialog'),
      '#description' => t('This sets the label for the drop-down select box containing these picture mappings in the CKEditor image dialog'),
      '#default_value' => variable_get('picture_ckeditor_label', 'Image size (required)'),
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => 'Save',
    );
  }
  else {
    $form['info'] = array(
      '#markup' => t('No picture mappings found. !create', array('!create' => l(t('Create one now.'), 'admin/config/media/picture/add'))),
    );
  }
  return $form;
}

/**
 * Validate handler for the picture_ckeditor_settings form.
 * It checks that a fallback image style is selected for every
 * picture mapping that has been enabled for the CKEditor image dialog.
 */
function picture_ckeditor_settings_validate($form, &$form_state) {
  $picture_mappings = picture_mapping_load_all();
  foreach ($picture_mappings as $picture_mapping) {
    $machine_name = $picture_mapping->getMachineName();
    if ($form_state['values'][$machine_name]['enabled'] == 1) {
      if (empty($form_state['values'][$machine_name]['fallback'])) {
        form_set_error($machine_name . '][fallback', t('Please choose a fallback image style for this picture mapping'));
      }
    }
  }
}

/**
 * Submit handler for the picture_ckeditor_settings form. Places chosen picture
 * groups into the variables table.
 */
function picture_ckeditor_settings_submit($form, &$form_state) {
  $picture_mappings = picture_mapping_load_all();
  $ckeditor_mappings = array();

  // Loop each picture mapping and record the settings.
  foreach ($picture_mappings as $picture_mapping) {
    $machine_name = $picture_mapping->getMachineName();
    $ckeditor_mappings[$machine_name]['enabled'] = $form_state['values'][$machine_name]['enabled'];
    $ckeditor_mappings[$machine_name]['weight'] = $form_state['values'][$machine_name]['weight'];
    $ckeditor_mappings[$machine_name]['fallback'] = $form_state['values'][$machine_name]['fallback'];
  }

  uasort($ckeditor_mappings, 'picture_compare_weights');
  variable_set('picture_ckeditor_mappings', $ckeditor_mappings);
  variable_set('picture_ckeditor_label', $form_state['values']['ckeditor_label']);
  drupal_set_message(t('Your settings have been saved'));
}

/**
  * Helper function to sort picture groups for the CKEditor image dialog
  */
function picture_compare_weights($a, $b) {
  if ($a['weight'] == $b['weight']) {
    return 0;
  }
  return ($a['weight'] < $b['weight']) ? -1 : 1;
}
