<?php

/**
 * hook_views_plugins()
 */
function mca_airline_order_management_views_plugins() {
 $plugins = array ();
 $plugins ['query'] ['mca_airline_order_management_views_plugin'] = array (
  'title' => t ( 'AutoTopup Package Query' ),
  'handler' => 'mca_airline_order_management_views_plugin_query'
 );
 return $plugins;
}

/**
 * hook_views_data()
 */
function mca_airline_order_management_views_data() {
 $data ['mca_airline_order_management'] ['table'] ['group'] = t ( 'MCA - Airline Order Management' );
 $data ['mca_airline_order_management'] ['table'] ['base'] = array (
  'field' => 'id', // This is the identifier field for the view.
  'title' => t ( 'MCA - Airline Order Management' ),
  'query class' => 'mca_airline_order_management_views_plugin'
 );

 $data ['mca_airline_order_management'] ['id'] = array (
  'title' => t ( 'Id' ),
  'help' => t ( 'Id' ),
  'field' => array (
   'handler' => 'views_handler_field'
  )
 );

 $data ['mca_airline_order_management'] ['msin'] = array (
  'title' => t ( 'MSIN' ),
  'help' => t ( 'MSIN' ),
  'field' => array (
   'handler' => 'views_handler_field'
  )
 );

 $data ['mca_airline_order_management'] ['customer'] = array (
  'title' => t ( 'Customer' ),
  'help' => t ( 'Customer' ),
  'field' => array (
   'handler' => 'views_handler_field'
  )
 );

 $data ['mca_airline_order_management'] ['total'] = array (
  'title' => t ( 'Total' ),
  'help' => t ( 'Total' ),
  'field' => array (
   'handler' => 'views_handler_field'
  )
 );

 $data ['mca_airline_order_management'] ['createdat'] = array (
  'title' => t ( 'Created' ),
  'help' => t ( 'Created' ),
  'field' => array (
   'handler' => 'views_handler_field'
  )
 );

 $data ['mca_airline_order_management'] ['updatedat'] = array (
  'title' => t ( 'Updated' ),
  'help' => t ( 'Updated' ),
  'field' => array (
   'handler' => 'views_handler_field'
  )
 );

 $data ['mca_airline_order_management'] ['status'] = array (
  'title' => t ( 'Status' ),
  'help' => t ( 'Status' ),
  'field' => array (
   'handler' => 'views_handler_field'
  )
 );

 $data ['mca_airline_order_management'] ['desc'] = array (
  'title' => t ( 'Description' ),
  'help' => t ( 'Description' ),
  'field' => array (
   'handler' => 'views_handler_field'
  )
 );

 $data ['mca_airline_order_management'] ['filter_order_id'] = array (
  'title' => t ( 'Order Id' ),
  'help' => t ( 'Order' ),
  'filter' => array (
   'handler' => 'views_handler_filter_string_orderId'
  )
 );

 $data ['mca_airline_order_management'] ['filter_customer'] = array (
  'title' => t ( 'Customer' ),
  'help' => t ( 'Customer' ),
  'filter' => array (
   'handler' => 'views_handler_filter_string'
  )
 );

 $data ['mca_airline_order_management'] ['filter_channel'] = array (
  'title' => t ( 'Channel' ),
  'help' => t ( 'Channle' ),
  'filter' => array (
   'handler' => 'views_handler_filter_string_filter_channel'
  )
 );

 $data ['mca_airline_order_management'] ['filter_status'] = array (
  'title' => t ( 'Status' ),
  'help' => t ( 'Status' ),
  'filter' => array (
   'handler' => 'views_handler_filter_string_filter_status'
  )
 );

 $data ['mca_airline_order_management'] ['filter_created_From'] = array (
  'title' => t ( 'From' ),
  'help' => t ( 'Date created from' ),
  'filter' => array (
   'handler' => 'views_handler_filter_string_date_from'
  )
 );

 $data ['mca_airline_order_management'] ['filter_customer_name_mobile'] = array (
  'title' => t ( 'Customer name, mobile' ),
  'help' => t ( 'Customer name or mobile' ),
  'filter' => array (
   'handler' => 'views_handler_filter_string_name_moblie'
  )
 );

 $data ['mca_airline_order_management'] ['filter_created_to'] = array (
  'title' => t ( 'To' ),
  'help' => t ( 'Date created to' ),
  'filter' => array (
   'handler' => 'views_handler_filter_string_date_to'
  )
 );

 $data ['mca_airline_order_management'] ['filter_check_box'] = array (
  'title' => t ( 'Order able to change' ),
  'help' => t ( 'Order able to change' ),
  'filter' => array (
   'handler' => 'views_check_box_filter'
  )
 );

 return $data;
}

// filter order id
class views_handler_filter_string_orderId extends views_handler_filter_string {
 function value_form(&$form, &$form_state) {
  parent::value_form ( $form, $form_state );
  $form ['value'] ['#suffix'] = t ( '<style>#edit-filter-order-id-wrapper { float: none; clear: both;}</style>' );
  $form ['value'] ['#attributes'] = array (
   'placeholder' => t ( 'Order Id' )
  );
 }
}

// filter date created
class views_handler_filter_string_date_from extends views_handler_filter_string {
 function value_form(&$form, &$form_state) {
  parent::value_form ( $form, $form_state );
  $form ['value'] ['#suffix'] = t ( '<style>#edit-filter-created-from-wrapper { float: none; clear: both;}</style>' );
  $form ['value'] ['#type'] = 'date_popup';
  $form ['value'] ['#date_format'] = 'Y-m-d';
  $form ['value'] ['#date_label_position'] = '';
  $form ['value'] ['#attributes'] = array (
   'placeholder' => t ( 'Created from' )
  );
 }
}

// filter chanel
class views_handler_filter_string_filter_channel extends views_handler_filter_in_operator {
 function value_form(&$form, &$form_state) {
  parent::value_form ( $form, $form_state );
  $form ['value'] ['#suffix'] = t ( '<style>#edit-filter-channel-wrapper { float: none; clear: both;}</style>' );
 }
 function get_value_options() {
  $status_arr = array (
   'web' => t ( 'Web' ),
   'sms' => t ( 'SMS' )
  );

  foreach ( $status_arr as $value => $status ) {
   $this->value_options [$value] = $status;
  }
 }
}

// filter customer name or mobile
class views_handler_filter_string_name_moblie extends views_handler_filter_string {
 function value_form(&$form, &$form_state) {
  parent::value_form ( $form, $form_state );
  $form ['value'] ['#suffix'] = t ( '<style>#edit-filter-customer-name-mobile-wrapper { float: none; clear: both;}</style>' );
  $form ['value'] ['#attributes'] = array (
   'placeholder' => t ( 'Customer name, mobile number' )
  );
 }
}

// filter date created to
class views_handler_filter_string_date_to extends views_handler_filter_string {
 function value_form(&$form, &$form_state) {
  parent::value_form ( $form, $form_state );
  $form ['value'] ['#suffix'] = t ( '<style>#edit-filter-created-to-wrapper { float: none; clear: both;}</style>' );
  $form ['value'] ['#type'] = 'date_popup';
  $form ['value'] ['#date_format'] = 'Y-m-d';
  $form ['value'] ['#date_label_position'] = '';
  $form ['value'] ['#attributes'] = array (
   'placeholder' => t ( 'Created to' )
  );
 }
}

/*
 * Filter status
 */
class views_handler_filter_string_filter_status extends views_handler_filter_in_operator {
 function value_form(&$form, &$form_state) {
  parent::value_form ( $form, $form_state );
  $form ['value'] ['#suffix'] = t ( '<style>#edit-filter-status-wrapper { float: none; clear: both;}</style>' );
 }
 function get_value_options() {
  $status_arr = array (
   'pending' => t ( 'Pending' ),
   'processing' => t ( 'Processing' ),
   'completed' => t ( 'Completed' ),
   'failed' => t ( 'Failed' ),
   'cancelled' => t ( 'Cancelled' )
  );

  foreach ( $status_arr as $value => $status ) {
   $this->value_options [$value] = $status;
  }
 }
}

// check box field
class views_check_box_filter extends views_handler_filter_in_operator {
 function value_form(&$form, &$form_state) {
  parent::value_form ( $form, $form_state );
  $form ['value'] ['#suffix'] = t ( '<style>#edit-filter-check-box-wrapper { float: none; clear: both;}</style>' );
  $form ['value'] = array (
   '#type' => 'checkboxes',
   '#title' => t ( 'Order able to change' ),
   '#multiple' => FALSE,
   '#required' => FALSE,
   '#options' => array (
    '1' => 'Order able to change'
   ),
   '#no_convert' => TRUE
  );
 }
 function get_value_options() {
  $status_arr = array (
   '1' => t ( 'Order able to change' )
  );

  foreach ( $status_arr as $value => $status ) {
   $this->value_options [$value] = $status;
  }
 }
}

// date popup process alter remove description
function mca_airline_order_management_date_popup_process_alter(&$element, &$form_state, $context) {
 if ($element ['#name'] == 'filter_created_From') {
  unset ( $element ['date'] ['#description'] );
 }
 if ($element ['#name'] == 'filter_created_to') {
  unset ( $element ['date'] ['#description'] );
 }
}
function mca_airline_order_management_form_views_exposed_form_alter(&$form, &$form_state, $form_id) {
 $form ['submit'] = array (
  '#type' => 'submit',
  '#suffix' => t ( '<style>#edit-filter-check-box-wrapper { float: none; clear: both;}</style>' ),
  '#value' => t ( 'Search' )
 );
}




