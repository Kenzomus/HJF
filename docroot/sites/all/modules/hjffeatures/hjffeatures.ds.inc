<?php
/**
 * @file
 * hjffeatures.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function hjffeatures_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|services|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'services';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|services|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function hjffeatures_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|funding_opportunity|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'funding_opportunity';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_relate_sponsor',
        1 => 'field_related_program',
        4 => 'field_proposal_deadline',
        5 => 'field_proposal_required',
        7 => 'field_opportunity_number',
      ),
      'right' => array(
        2 => 'field_related_announcement_type',
        3 => 'field_related_url',
        6 => 'field_proposal_invitation',
        8 => 'field_preproposal_loideadline',
        9 => 'field_prepropsal_loideadline_dat',
      ),
    ),
    'fields' => array(
      'field_relate_sponsor' => 'left',
      'field_related_program' => 'left',
      'field_related_announcement_type' => 'right',
      'field_related_url' => 'right',
      'field_proposal_deadline' => 'left',
      'field_proposal_required' => 'left',
      'field_proposal_invitation' => 'right',
      'field_opportunity_number' => 'left',
      'field_preproposal_loideadline' => 'right',
      'field_prepropsal_loideadline_dat' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|funding_opportunity|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|services|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'services';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'zf_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_category',
        1 => 'title',
        2 => 'body',
        3 => 'field_rads',
        4 => 'field_icon',
        5 => 'field_contact_email',
        6 => 'field_contact_phone',
        7 => 'field_related_opportunities',
      ),
    ),
    'fields' => array(
      'field_category' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'field_rads' => 'ds_content',
      'field_icon' => 'ds_content',
      'field_contact_email' => 'ds_content',
      'field_contact_phone' => 'ds_content',
      'field_related_opportunities' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|services|default'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function hjffeatures_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'another_client_view';
  $ds_view_mode->label = 'another_client_view';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['another_client_view'] = $ds_view_mode;

  return $export;
}
