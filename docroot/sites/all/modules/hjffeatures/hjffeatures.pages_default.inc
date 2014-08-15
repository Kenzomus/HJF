<?php
/**
 * @file
 * hjffeatures.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function hjffeatures_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_http_response';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'http_response';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'node_service_edit',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '301',
    'destination' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'services' => 'services',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $export['node_view_http_response'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'node_service',
    'no_blocks' => 1,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Node from Node (on Node: related_services [field_related_services])',
        'keyword' => 'node_2',
        'name' => 'entity_from_field:field_related_services-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'services' => 'services',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'foundation_2col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'd76cb731-860e-44fe-b6e2-441b77fd561c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-664c8be1-dd6c-48b9-8eb9-ef17ee53863b';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'custom_content_Icon_body',
      'title' => '',
      'body' => '<div><img src="%node:field_icon" float:"Right"/>%node:body</div>
',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '664c8be1-dd6c-48b9-8eb9-ef17ee53863b';
    $display->content['new-664c8be1-dd6c-48b9-8eb9-ef17ee53863b'] = $pane;
    $display->panels['left'][0] = 'new-664c8be1-dd6c-48b9-8eb9-ef17ee53863b';
    $pane = new stdClass();
    $pane->pid = 'new-c1a6a4dc-17d4-49b9-a6c1-74a1761de73f';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_icon';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'file_view_mode' => 'default',
        'image_style' => 'large',
        'image_link' => '',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c1a6a4dc-17d4-49b9-a6c1-74a1761de73f';
    $display->content['new-c1a6a4dc-17d4-49b9-a6c1-74a1761de73f'] = $pane;
    $display->panels['left'][1] = 'new-c1a6a4dc-17d4-49b9-a6c1-74a1761de73f';
    $pane = new stdClass();
    $pane->pid = 'new-81a48521-ff46-43a0-9547-22441bb8b403';
    $pane->panel = 'left';
    $pane->type = 'node_body';
    $pane->subtype = 'node_body';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '81a48521-ff46-43a0-9547-22441bb8b403';
    $display->content['new-81a48521-ff46-43a0-9547-22441bb8b403'] = $pane;
    $display->panels['left'][2] = 'new-81a48521-ff46-43a0-9547-22441bb8b403';
    $pane = new stdClass();
    $pane->pid = 'new-c23cff28-2e14-43d4-86dc-7e6e23c9b309';
    $pane->panel = 'left';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
      'markup' => 'none',
      'id' => '',
      'class' => '',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'c23cff28-2e14-43d4-86dc-7e6e23c9b309';
    $display->content['new-c23cff28-2e14-43d4-86dc-7e6e23c9b309'] = $pane;
    $display->panels['left'][3] = 'new-c23cff28-2e14-43d4-86dc-7e6e23c9b309';
    $pane = new stdClass();
    $pane->pid = 'new-1ceec916-0363-40f3-ab7d-6441b29d2d84';
    $pane->panel = 'left';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 1,
      'override_title' => 0,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 1,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '1ceec916-0363-40f3-ab7d-6441b29d2d84';
    $display->content['new-1ceec916-0363-40f3-ab7d-6441b29d2d84'] = $pane;
    $display->panels['left'][4] = 'new-1ceec916-0363-40f3-ab7d-6441b29d2d84';
    $pane = new stdClass();
    $pane->pid = 'new-801c8542-0ce3-435e-a743-0aa7140bdf97';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_related_success_story';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 1,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Related success stories',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'stylizer:mysecondtes',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '801c8542-0ce3-435e-a743-0aa7140bdf97';
    $display->content['new-801c8542-0ce3-435e-a743-0aa7140bdf97'] = $pane;
    $display->panels['right'][0] = 'new-801c8542-0ce3-435e-a743-0aa7140bdf97';
    $pane = new stdClass();
    $pane->pid = 'new-e4675ede-a393-46e4-ba5f-71783ad70fc2';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_related_opportunities';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 1,
        'view_mode' => 'default',
        'links' => 1,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Related Funding Opportunities',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'stylizer:mysecondtes',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e4675ede-a393-46e4-ba5f-71783ad70fc2';
    $display->content['new-e4675ede-a393-46e4-ba5f-71783ad70fc2'] = $pane;
    $display->panels['right'][1] = 'new-e4675ede-a393-46e4-ba5f-71783ad70fc2';
    $pane = new stdClass();
    $pane->pid = 'new-eab33791-cc9b-470e-8669-18d9db0f2640';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_rads';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 1,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'stylizer:mysecondtes',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'eab33791-cc9b-470e-8669-18d9db0f2640';
    $display->content['new-eab33791-cc9b-470e-8669-18d9db0f2640'] = $pane;
    $display->panels['right'][2] = 'new-eab33791-cc9b-470e-8669-18d9db0f2640';
    $pane = new stdClass();
    $pane->pid = 'new-8f877d27-454d-4b10-82fd-0cedfbe0065a';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'contact_service';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'stylizer:mysecondtes',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '8f877d27-454d-4b10-82fd-0cedfbe0065a';
    $display->content['new-8f877d27-454d-4b10-82fd-0cedfbe0065a'] = $pane;
    $display->panels['right'][3] = 'new-8f877d27-454d-4b10-82fd-0cedfbe0065a';
    $pane = new stdClass();
    $pane->pid = 'new-fdb15fb1-6064-42a3-91c5-b4a7a9eb3b46';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_related_clientbis';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 0,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'stylizer:mysecondtes',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'fdb15fb1-6064-42a3-91c5-b4a7a9eb3b46';
    $display->content['new-fdb15fb1-6064-42a3-91c5-b4a7a9eb3b46'] = $pane;
    $display->panels['right'][4] = 'new-fdb15fb1-6064-42a3-91c5-b4a7a9eb3b46';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1ceec916-0363-40f3-ab7d-6441b29d2d84';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Funding Opportunity',
    'no_blocks' => 1,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'funding_opportunity' => 'funding_opportunity',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'foundation_2col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '688b9052-3a30-423c-a969-cdb40f656491';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4ae9dcf2-fe29-4166-ae57-92e19eda9eed';
    $pane->panel = 'left';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
      'markup' => 'none',
      'id' => '',
      'class' => '',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4ae9dcf2-fe29-4166-ae57-92e19eda9eed';
    $display->content['new-4ae9dcf2-fe29-4166-ae57-92e19eda9eed'] = $pane;
    $display->panels['left'][0] = 'new-4ae9dcf2-fe29-4166-ae57-92e19eda9eed';
    $pane = new stdClass();
    $pane->pid = 'new-dafa4bd3-f574-4e01-b62a-e918cf0e038f';
    $pane->panel = 'left';
    $pane->type = 'node_type_desc';
    $pane->subtype = 'node_type_desc';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'dafa4bd3-f574-4e01-b62a-e918cf0e038f';
    $display->content['new-dafa4bd3-f574-4e01-b62a-e918cf0e038f'] = $pane;
    $display->panels['left'][1] = 'new-dafa4bd3-f574-4e01-b62a-e918cf0e038f';
    $pane = new stdClass();
    $pane->pid = 'new-e89a65dc-9b1c-4cd4-bb12-857730db6f94';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_related_url';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'link_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e89a65dc-9b1c-4cd4-bb12-857730db6f94';
    $display->content['new-e89a65dc-9b1c-4cd4-bb12-857730db6f94'] = $pane;
    $display->panels['left'][2] = 'new-e89a65dc-9b1c-4cd4-bb12-857730db6f94';
    $pane = new stdClass();
    $pane->pid = 'new-fab9d119-5419-467d-9d27-e3ea9afadacd';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-cBaN9dBUMVumDA1BiijxLnEprq22gtJx';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'default',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fab9d119-5419-467d-9d27-e3ea9afadacd';
    $display->content['new-fab9d119-5419-467d-9d27-e3ea9afadacd'] = $pane;
    $display->panels['right'][0] = 'new-fab9d119-5419-467d-9d27-e3ea9afadacd';
    $pane = new stdClass();
    $pane->pid = 'new-14078331-bb51-4bb0-addc-d632326e1483';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_relate_sponsor';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 1,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'stylizer:mysecondtes',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '14078331-bb51-4bb0-addc-d632326e1483';
    $display->content['new-14078331-bb51-4bb0-addc-d632326e1483'] = $pane;
    $display->panels['right'][1] = 'new-14078331-bb51-4bb0-addc-d632326e1483';
    $pane = new stdClass();
    $pane->pid = 'new-25d5d43a-45c7-49f0-8557-23f481e7f7b7';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_related_program';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 1,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'stylizer:mysecondtes',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '25d5d43a-45c7-49f0-8557-23f481e7f7b7';
    $display->content['new-25d5d43a-45c7-49f0-8557-23f481e7f7b7'] = $pane;
    $display->panels['right'][2] = 'new-25d5d43a-45c7-49f0-8557-23f481e7f7b7';
    $pane = new stdClass();
    $pane->pid = 'new-4a5a36f4-9f64-49c4-9957-9585c5ab8684';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_related_announcement_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => 0,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'stylizer:mysecondtes',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '4a5a36f4-9f64-49c4-9957-9585c5ab8684';
    $display->content['new-4a5a36f4-9f64-49c4-9957-9585c5ab8684'] = $pane;
    $display->panels['right'][3] = 'new-4a5a36f4-9f64-49c4-9957-9585c5ab8684';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function hjffeatures_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'about';
  $page->task = 'page';
  $page->admin_title = 'About';
  $page->admin_description = 'create aan about page with panel to maximize the layout options';
  $page->path = 'content/about';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'About',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_about_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'about';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel_About',
    'no_blocks' => 1,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'foundation_1col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3fef53b8-bb70-4398-a7d4-94411c9a1c2d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c2cd4d0e-2e52-44aa-a903-3c629ae3e9cb';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>The Henry M. Jackson Foundation for the Advancement of Military Medicine, Inc. (HJF) is a global organization dedicated to advancing military medical research. We serve military, medical, academic and government clients by administering, managing and supporting preeminent scientific programs that benefit members of the armed forces and civilians alike.</p>

<p>The not-for-profit Foundation is authorized by Congress to support research at the Uniformed Services University of the Health Sciences (USU) and throughout military medicine. Since its founding in 1983, HJF has served as a vital link between the military medical community and its federal and private partners. The Foundation’s support and administrative capabilities allow military medical researchers and clinicians to maintain their scientific focus and to accomplish their research goals effectively and efficiently.</p>
',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c2cd4d0e-2e52-44aa-a903-3c629ae3e9cb';
    $display->content['new-c2cd4d0e-2e52-44aa-a903-3c629ae3e9cb'] = $pane;
    $display->panels['middle'][0] = 'new-c2cd4d0e-2e52-44aa-a903-3c629ae3e9cb';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['about'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'contact_panel';
  $page->task = 'page';
  $page->admin_title = 'Contact_Panel';
  $page->admin_description = 'contact form in panel with possibility to ad a map';
  $page->path = 'contact_research_initiatives_office';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => '',
    'name' => 'main-menu',
    'weight' => '8',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_contact_panel_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'contact_panel';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f2ed5240-3733-4784-a5a1-f419b47b6f85';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3350b043-8619-40d8-9791-41d0109f9fd0';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'webform-client-block-221';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3350b043-8619-40d8-9791-41d0109f9fd0';
    $display->content['new-3350b043-8619-40d8-9791-41d0109f9fd0'] = $pane;
    $display->panels['center'][0] = 'new-3350b043-8619-40d8-9791-41d0109f9fd0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-3350b043-8619-40d8-9791-41d0109f9fd0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['contact_panel'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'differentview';
  $page->task = 'page';
  $page->admin_title = 'Differentview';
  $page->admin_description = 'different view of funding opportunity';
  $page->path = 'Differentview';
  $page->access = array();
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Funding',
    'name' => 'navigation',
    'weight' => '4',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_differentview_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'differentview';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Paneldifferentview',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'foundation_1col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Different Ops';
  $display->uuid = '24759fa4-e582-4407-9064-f6ceef4dee0f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-378a33a7-cc97-4abc-a76d-dcc01e4a4767';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'filtered_html',
      'substitute' => TRUE,
      'name' => 'funding_folder',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '378a33a7-cc97-4abc-a76d-dcc01e4a4767';
    $display->content['new-378a33a7-cc97-4abc-a76d-dcc01e4a4767'] = $pane;
    $display->panels['middle'][0] = 'new-378a33a7-cc97-4abc-a76d-dcc01e4a4767';
    $pane = new stdClass();
    $pane->pid = 'new-cc7d441d-7b08-43b2-bf42-cca5d7bd0035';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'test_funding_filters';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'page',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'cc7d441d-7b08-43b2-bf42-cca5d7bd0035';
    $display->content['new-cc7d441d-7b08-43b2-bf42-cca5d7bd0035'] = $pane;
    $display->panels['middle'][1] = 'new-cc7d441d-7b08-43b2-bf42-cca5d7bd0035';
    $pane = new stdClass();
    $pane->pid = 'new-0accbba7-4c7a-4058-bd54-1f29e86edb98';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'funding_opportunities';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'page',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'default',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '0accbba7-4c7a-4058-bd54-1f29e86edb98';
    $display->content['new-0accbba7-4c7a-4058-bd54-1f29e86edb98'] = $pane;
    $display->panels['middle'][2] = 'new-0accbba7-4c7a-4058-bd54-1f29e86edb98';
    $pane = new stdClass();
    $pane->pid = 'new-965311c9-928c-4fc7-8beb-e8edef8f9a1b';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'tes_rads_parameter';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '965311c9-928c-4fc7-8beb-e8edef8f9a1b';
    $display->content['new-965311c9-928c-4fc7-8beb-e8edef8f9a1b'] = $pane;
    $display->panels['middle'][3] = 'new-965311c9-928c-4fc7-8beb-e8edef8f9a1b';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-0accbba7-4c7a-4058-bd54-1f29e86edb98';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['differentview'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'events_listing';
  $page->task = 'page';
  $page->admin_title = 'events_listing';
  $page->admin_description = 'provide a list of events';
  $page->path = 'events';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Events',
    'name' => 'main-menu',
    'weight' => '6',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_events_listing_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'events_listing';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
          1 => 'event_sidebar',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => '69.95180014355694',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      'event_sidebar' => array(
        'type' => 'region',
        'title' => 'event-sidebar',
        'width' => '30.04819985644306',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'event_sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1db6a692-a6f5-4f93-8d78-b79e3f092f79';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e1b74567-4f95-4a97-a207-7c6fdfc32b6a';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'event_listing-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e1b74567-4f95-4a97-a207-7c6fdfc32b6a';
    $display->content['new-e1b74567-4f95-4a97-a207-7c6fdfc32b6a'] = $pane;
    $display->panels['center'][0] = 'new-e1b74567-4f95-4a97-a207-7c6fdfc32b6a';
    $pane = new stdClass();
    $pane->pid = 'new-4029e408-3cc3-4eeb-a298-e072aa729aaf';
    $pane->panel = 'event_sidebar';
    $pane->type = 'views';
    $pane->subtype = 'events_calendar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'style' => '$',
        'settings' => array(
          'name' => '_temporary',
          'style_base' => 'pane_rounded_shadow',
          'palette' => array(
            'background' => '#FFFFFF',
            'text' => '#000000',
            'header-text' => '#000000',
            'header-border' => '#000000',
          ),
          'header_font' => array(
            'font' => 'Trebuchet MS, Trebuchet, Verdana, sans-serif',
            'size' => 'small',
            'letter_spacing' => '',
            'word_spacing' => '',
            'decoration' => '',
            'weight' => '',
            'style' => '',
            'variant' => '',
            'case' => '',
            'alignment' => '',
          ),
          'text_font' => array(
            'font' => 'Trebuchet MS, Trebuchet, Verdana, sans-serif',
            'size' => 'small',
            'letter_spacing' => '',
            'word_spacing' => '',
            'decoration' => '',
            'weight' => '',
            'style' => '',
            'variant' => '',
            'case' => '',
            'alignment' => '',
          ),
          'padding' => array(
            'top' => '',
            'right' => '',
            'bottom' => '',
            'left' => '',
          ),
          'header_border' => array(
            'thickness' => '',
            'style' => '',
          ),
        ),
      ),
      'style' => 'stylizer',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4029e408-3cc3-4eeb-a298-e072aa729aaf';
    $display->content['new-4029e408-3cc3-4eeb-a298-e072aa729aaf'] = $pane;
    $display->panels['event_sidebar'][0] = 'new-4029e408-3cc3-4eeb-a298-e072aa729aaf';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-4029e408-3cc3-4eeb-a298-e072aa729aaf';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['events_listing'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'funding_opportunity_panels_views_context';
  $page->task = 'page';
  $page->admin_title = 'funding_opportunity_panels_views context';
  $page->admin_description = 'funding_opportunity_panels_ create from views context';
  $page->path = 'funding_opportunity_panels';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Funding Ops',
    'name' => 'navigation',
    'weight' => '3',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_funding_opportunity_panels_views_context_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'funding_opportunity_panels_views_context';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel_Funding_Opoortunities',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'View: Funding Opportunities: ContextFunding_opportunities',
        'keyword' => 'view',
        'name' => 'view:funding_opportunities-ctools_context_1',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
          1 => 'right_side_bar',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => '53.98724082934609',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      'right_side_bar' => array(
        'type' => 'region',
        'title' => 'right_side_bar',
        'width' => '46.01275917065391',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'right_side_bar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'funding Opportunities';
  $display->uuid = 'c9209cab-88b8-4815-accb-a01845c8bf6b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f8949b00-885a-4fde-9349-63ebf9550b79';
    $pane->panel = 'center';
    $pane->type = 'views_view';
    $pane->subtype = 'views_view';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'context_view:funding_opportunities-ctools_context_1_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f8949b00-885a-4fde-9349-63ebf9550b79';
    $display->content['new-f8949b00-885a-4fde-9349-63ebf9550b79'] = $pane;
    $display->panels['center'][0] = 'new-f8949b00-885a-4fde-9349-63ebf9550b79';
    $pane = new stdClass();
    $pane->pid = 'new-214ae269-2d4f-47e3-bd98-864e5d3e568d';
    $pane->panel = 'right_side_bar';
    $pane->type = 'custom';
    $pane->subtype = 'tes_rads_parameter';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '214ae269-2d4f-47e3-bd98-864e5d3e568d';
    $display->content['new-214ae269-2d4f-47e3-bd98-864e5d3e568d'] = $pane;
    $display->panels['right_side_bar'][0] = 'new-214ae269-2d4f-47e3-bd98-864e5d3e568d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f8949b00-885a-4fde-9349-63ebf9550b79';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['funding_opportunity_panels_views_context'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'funding_parameters';
  $page->task = 'page';
  $page->admin_title = 'Funding_parameters';
  $page->admin_description = 'create a contex view with parameters';
  $page->path = 'Funding_parameters';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => '',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_funding_parameters_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'funding_parameters';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'View: funding_opportunities_parameter',
        'keyword' => 'view',
        'name' => 'view:funding_opportunities_parameter-ctools_context_1',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '2442af76-b623-46d0-8616-a09dfdec0e9d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9ab3a4c0-bee8-40b2-a69a-fcfa30ee1060';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'funding_opportunities_parameter';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'page',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'stylizer:testview',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9ab3a4c0-bee8-40b2-a69a-fcfa30ee1060';
    $display->content['new-9ab3a4c0-bee8-40b2-a69a-fcfa30ee1060'] = $pane;
    $display->panels['center'][0] = 'new-9ab3a4c0-bee8-40b2-a69a-fcfa30ee1060';
    $pane = new stdClass();
    $pane->pid = 'new-42dba241-b599-4d2b-a1a4-a8e108a0468d';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'funding_opportunities_parameter';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'ctools_context_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '42dba241-b599-4d2b-a1a4-a8e108a0468d';
    $display->content['new-42dba241-b599-4d2b-a1a4-a8e108a0468d'] = $pane;
    $display->panels['center'][1] = 'new-42dba241-b599-4d2b-a1a4-a8e108a0468d';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-42dba241-b599-4d2b-a1a4-a8e108a0468d';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['funding_parameters'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'homepage';
  $page->task = 'page';
  $page->admin_title = 'homepage';
  $page->admin_description = 'homepage ';
  $page->path = 'homepage';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Home',
    'name' => 'main-menu',
    'weight' => '1',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_homepage_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'homepage';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel_homepage',
    'no_blocks' => 1,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'foundation_2col_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '19c4129d-adb5-497a-8a65-d01e32612f60';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c3831772-0d5f-4c0c-85be-bccc09a90b3b';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'home_text',
      'title' => '',
      'body' => '<p>The Henry M. Jackson Foundation for the Advancement of Military Medicine, Inc. (HJF) is a global organization dedicated to advancing military medical research. We serve military, medical, academic and government clients by administering, managing and supporting preeminent scientific programs that benefit members of the armed forces and civilians alike.</p>
',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c3831772-0d5f-4c0c-85be-bccc09a90b3b';
    $display->content['new-c3831772-0d5f-4c0c-85be-bccc09a90b3b'] = $pane;
    $display->panels['left'][0] = 'new-c3831772-0d5f-4c0c-85be-bccc09a90b3b';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['homepage'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'services';
  $page->task = 'page';
  $page->admin_title = 'Services';
  $page->admin_description = '';
  $page->path = 'content/MyServices';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 1,
            1 => 2,
            2 => 3,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'MyServices',
    'name' => 'main-menu',
    'weight' => '4',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_services_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'services';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'View: Services',
        'keyword' => 'view',
        'name' => 'view:services-ctools_context_1',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'foundation_1col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '85108b5f-d95e-4fa9-87ba-8e7dbe659bc2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e7b81eb4-d4e9-4587-b3d2-8560a44987b9';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'services';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 1,
      'args' => '',
      'url' => '',
      'display' => 'page_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e7b81eb4-d4e9-4587-b3d2-8560a44987b9';
    $display->content['new-e7b81eb4-d4e9-4587-b3d2-8560a44987b9'] = $pane;
    $display->panels['middle'][0] = 'new-e7b81eb4-d4e9-4587-b3d2-8560a44987b9';
    $pane = new stdClass();
    $pane->pid = 'new-283f5530-6e68-4e68-999d-e50b2612aeaf';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'success_story';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'context' => array(
        0 => '',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '283f5530-6e68-4e68-999d-e50b2612aeaf';
    $display->content['new-283f5530-6e68-4e68-999d-e50b2612aeaf'] = $pane;
    $display->panels['middle'][1] = 'new-283f5530-6e68-4e68-999d-e50b2612aeaf';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-e7b81eb4-d4e9-4587-b3d2-8560a44987b9';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_services_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'services';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'service_node',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'foundation_2col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'service_node';
  $display->uuid = '1f20624a-d7bf-4cfe-9f84-bf81e87a5181';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-78965fcb-d3e7-491f-a2df-a4ec14d9be9d';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'success_story';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 1,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '78965fcb-d3e7-491f-a2df-a4ec14d9be9d';
    $display->content['new-78965fcb-d3e7-491f-a2df-a4ec14d9be9d'] = $pane;
    $display->panels['left'][0] = 'new-78965fcb-d3e7-491f-a2df-a4ec14d9be9d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['services'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'tes_front_panel';
  $page->task = 'page';
  $page->admin_title = 'tes_front_panel';
  $page->admin_description = '';
  $page->path = 'content/Home';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => '',
    'weight' => '0',
    'name' => 'navigation',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'weight' => 0,
      'name' => 'navigation',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_tes_front_panel_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'tes_front_panel';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Landing page',
    'no_blocks' => FALSE,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'front',
          'settings' => NULL,
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 1,
          1 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
          1 => 'side_bar',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => '78.1378468347307',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      'side_bar' => array(
        'type' => 'region',
        'title' => 'side_bar',
        'width' => '21.862153165269312',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(),
        'parent' => 'main',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'side_bar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0d5caf3d-a16d-48aa-9d4b-721d02e43ebc';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2147fac4-9e4e-441a-902f-165eacc93d02';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'home_text',
      'title' => '',
      'body' => '<p>The Henry M. Jackson Foundation for the Advancement of Military Medicine, Inc. (HJF) is a global organization dedicated to advancing military medical research. We serve military, medical, academic and government clients by administering, managing and supporting preeminent scientific programs that benefit members of the armed forces and civilians alike.</p>
',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2147fac4-9e4e-441a-902f-165eacc93d02';
    $display->content['new-2147fac4-9e4e-441a-902f-165eacc93d02'] = $pane;
    $display->panels['center'][0] = 'new-2147fac4-9e4e-441a-902f-165eacc93d02';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['tes_front_panel'] = $page;

  return $pages;

}
