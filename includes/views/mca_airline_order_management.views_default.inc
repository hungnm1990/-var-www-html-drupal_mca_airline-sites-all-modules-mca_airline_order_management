<?php

/**
 *
 * @author baonguyen
 *
 */
function mca_airline_order_management_views_default_views(){
 $views = array();
 $list = mca_airline_order_management_views_default_views_list();
 $views[$list->name] = $list;

 return $views;
}

function mca_airline_order_management_views_default_views_list(){
 $view = new view();
$view->name = 'mca_airline_order_management';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'mca_airline_order_management';
$view->human_name = 'MCA - Airline Order Management';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'MCA - Airline Order Management';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  2 => '2',
);
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
$handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'id' => 'id',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'id' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Field: MCA - Airline Order Management: Id */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'mca_airline_order_management';
$handler->display->display_options['fields']['id']['field'] = 'id';
/* Field: MCA - Airline Order Management: MSIN */
$handler->display->display_options['fields']['msin']['id'] = 'msin';
$handler->display->display_options['fields']['msin']['table'] = 'mca_airline_order_management';
$handler->display->display_options['fields']['msin']['field'] = 'msin';
/* Field: MCA - Airline Order Management: Customer */
$handler->display->display_options['fields']['customer']['id'] = 'customer';
$handler->display->display_options['fields']['customer']['table'] = 'mca_airline_order_management';
$handler->display->display_options['fields']['customer']['field'] = 'customer';
/* Field: MCA - Airline Order Management: Total */
$handler->display->display_options['fields']['total']['id'] = 'total';
$handler->display->display_options['fields']['total']['table'] = 'mca_airline_order_management';
$handler->display->display_options['fields']['total']['field'] = 'total';
/* Field: MCA - Airline Order Management: Status */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'mca_airline_order_management';
$handler->display->display_options['fields']['status']['field'] = 'status';
/* Field: MCA - Airline Order Management: Description */
$handler->display->display_options['fields']['desc']['id'] = 'desc';
$handler->display->display_options['fields']['desc']['table'] = 'mca_airline_order_management';
$handler->display->display_options['fields']['desc']['field'] = 'desc';
/* Field: MCA - Airline Order Management: Created */
$handler->display->display_options['fields']['createdat']['id'] = 'createdat';
$handler->display->display_options['fields']['createdat']['table'] = 'mca_airline_order_management';
$handler->display->display_options['fields']['createdat']['field'] = 'createdat';
/* Field: MCA - Airline Order Management: Updated */
$handler->display->display_options['fields']['updatedat']['id'] = 'updatedat';
$handler->display->display_options['fields']['updatedat']['table'] = 'mca_airline_order_management';
$handler->display->display_options['fields']['updatedat']['field'] = 'updatedat';
/* Filter criterion: MCA - Airline Order Management: Order Id */
$handler->display->display_options['filters']['filter_order_id']['id'] = 'filter_order_id';
$handler->display->display_options['filters']['filter_order_id']['table'] = 'mca_airline_order_management';
$handler->display->display_options['filters']['filter_order_id']['field'] = 'filter_order_id';
$handler->display->display_options['filters']['filter_order_id']['group'] = 1;
$handler->display->display_options['filters']['filter_order_id']['exposed'] = TRUE;
$handler->display->display_options['filters']['filter_order_id']['expose']['operator_id'] = 'filter_order_id_op';
$handler->display->display_options['filters']['filter_order_id']['expose']['operator'] = 'filter_order_id_op';
$handler->display->display_options['filters']['filter_order_id']['expose']['identifier'] = 'filter_order_id';
$handler->display->display_options['filters']['filter_order_id']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);
/* Filter criterion: MCA - Airline Order Management: Customer name, mobile */
$handler->display->display_options['filters']['filter_customer_name_mobile']['id'] = 'filter_customer_name_mobile';
$handler->display->display_options['filters']['filter_customer_name_mobile']['table'] = 'mca_airline_order_management';
$handler->display->display_options['filters']['filter_customer_name_mobile']['field'] = 'filter_customer_name_mobile';
$handler->display->display_options['filters']['filter_customer_name_mobile']['group'] = 1;
$handler->display->display_options['filters']['filter_customer_name_mobile']['exposed'] = TRUE;
$handler->display->display_options['filters']['filter_customer_name_mobile']['expose']['operator_id'] = 'filter_customer_name_mobile_op';
$handler->display->display_options['filters']['filter_customer_name_mobile']['expose']['operator'] = 'filter_customer_name_mobile_op';
$handler->display->display_options['filters']['filter_customer_name_mobile']['expose']['identifier'] = 'filter_customer_name_mobile';
$handler->display->display_options['filters']['filter_customer_name_mobile']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);
/* Filter criterion: MCA - Airline Order Management: From */
$handler->display->display_options['filters']['filter_created_From']['id'] = 'filter_created_From';
$handler->display->display_options['filters']['filter_created_From']['table'] = 'mca_airline_order_management';
$handler->display->display_options['filters']['filter_created_From']['field'] = 'filter_created_From';
$handler->display->display_options['filters']['filter_created_From']['group'] = 1;
$handler->display->display_options['filters']['filter_created_From']['exposed'] = TRUE;
$handler->display->display_options['filters']['filter_created_From']['expose']['operator_id'] = 'filter_created_From_op';
$handler->display->display_options['filters']['filter_created_From']['expose']['operator'] = 'filter_created_From_op';
$handler->display->display_options['filters']['filter_created_From']['expose']['identifier'] = 'filter_created_From';
$handler->display->display_options['filters']['filter_created_From']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);
/* Filter criterion: MCA - Airline Order Management: To */
$handler->display->display_options['filters']['filter_created_to']['id'] = 'filter_created_to';
$handler->display->display_options['filters']['filter_created_to']['table'] = 'mca_airline_order_management';
$handler->display->display_options['filters']['filter_created_to']['field'] = 'filter_created_to';
$handler->display->display_options['filters']['filter_created_to']['group'] = 1;
$handler->display->display_options['filters']['filter_created_to']['exposed'] = TRUE;
$handler->display->display_options['filters']['filter_created_to']['expose']['operator_id'] = 'filter_created_to_op';
$handler->display->display_options['filters']['filter_created_to']['expose']['operator'] = 'filter_created_to_op';
$handler->display->display_options['filters']['filter_created_to']['expose']['identifier'] = 'filter_created_to';
$handler->display->display_options['filters']['filter_created_to']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);
/* Filter criterion: MCA - Airline Order Management: Status */
$handler->display->display_options['filters']['filter_status']['id'] = 'filter_status';
$handler->display->display_options['filters']['filter_status']['table'] = 'mca_airline_order_management';
$handler->display->display_options['filters']['filter_status']['field'] = 'filter_status';
$handler->display->display_options['filters']['filter_status']['group'] = 1;
$handler->display->display_options['filters']['filter_status']['exposed'] = TRUE;
$handler->display->display_options['filters']['filter_status']['expose']['operator_id'] = 'filter_status_op';
$handler->display->display_options['filters']['filter_status']['expose']['operator'] = 'filter_status_op';
$handler->display->display_options['filters']['filter_status']['expose']['identifier'] = 'filter_status';
$handler->display->display_options['filters']['filter_status']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'air_order';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Airline Order Management';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

 return $view;
}