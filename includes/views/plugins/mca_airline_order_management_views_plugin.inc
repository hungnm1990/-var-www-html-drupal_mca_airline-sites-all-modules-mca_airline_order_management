<?php

/**
 * baonguyen
 */
class mca_airline_order_management_views_plugin_query extends views_plugin_query_default {
 var $override_current_page = - 1;
 var $items_per_page = - 1;
 function execute(&$view) {
  $data = $this->url_with_condtion ();
  // $data['channel'] = 'AIR';

  $url = variable_get ( "mca_airline_order_management_rest" ) . "search.json";

  $headers = array (
   'Content-Type' => 'application/json'
  );

  // Get all
  $limit = isset ( $this->limit ) ? $this->limit : 0;
  $offset = isset ( $this->offset ) ? (($this->offset / $limit) + 1) : 0;

  $data ['page_size'] = $limit;
  // $data['pageNumber'] = $offset;

  $options = array (
   'method' => 'POST',
   'data' => json_encode ( $data ),
   'headers' => $headers
  );

  $response = drupal_http_request ( $url, $options );
  if ($response) {
   if ($response->code == 200) {

    $data_json = get_object_vars ( json_decode ( $response->data ) );
    $data_docs = $data_json ['list']; // items

    $this->pager->total_items = $data_json ['total'];

    // notify pager of the total change
    $this->pager->update_page_info ();

    foreach ( $data_docs as $docs ) {
     $row = new stdClass ();
     // Get MSIN
     $msin_str = '';
     foreach ( $docs->items as $msin ) {
      $msin_str .= $msin->MSIN . ' ';
     }

     $row->id = $docs->order_id; // Base field
     $row->mca_airline_order_management_msin = $msin_str;
     $row->mca_airline_order_management_customer = $docs->customer_info->customer_id;
     $row->mca_airline_order_management_total = isset ( $docs->amount ) ? $docs->amount : '';
     $row->mca_airline_order_management_createdat = $docs->created_at;
     $row->mca_airline_order_management_updatedat = isset ( $docs->updated_at ) ? $docs->updated_at : '';
     $row->mca_airline_order_management_status = $docs->status.'-'.$docs->internal_status ;
     $row->mca_airline_order_management_desc = isset ( $docs->description ) ? $docs->description : '';
     $view->result [] = $row;
    }
   }
  }
 }
 function url_with_condtion() {
  $conds = array_key_exists ( 'user_conditions', $this->where ) ? $this->where ['user_conditions'] : array ();
  $full_url = array ();
  $data = array ();
  //$full_url ['q'] = '';

  foreach ( $conds as $each_condition ) {
   $filter_type = $each_condition ['field']; // Get all field condiotion
   $value = trim ( $each_condition ['value'] ); // Get value condition

   // if ($filter_type == 'mca_airline_order_management.filter_name') {
                                                // $value = trim ( $value );
                                                // $full_url ['filter_name'] = '%' . $value . '%';
                                                // }

   // if ($filter_type == 'mca_airline_order_management.filter_desc') {
                                                // $value = trim ( $value );
                                                // $full_url ['filter_desc'] = '%' . $value . '%';
                                                // }

   if ($filter_type == 'mca_airline_order_management.filter_order_id') {
    $data ['order_id'] = $value;
   }
   if ($filter_type == 'mca_airline_order_management.filter_created_From') {
    $full_url ['createdFrom'] = $value . 'T22:30:00';
   }
   // if ($filter_type == 'mca_airline_order_management.filter_channel') {
   // $full_url ['filter_channel'] = $value;
   // }
   if ($filter_type == 'mca_airline_order_management.filter_customer_name_mobile') {
    $full_url ['customer'] = $value;
   }
   if ($filter_type == 'mca_airline_order_management.filter_created_to') {
    $full_url ['createdTo'] = $value . 'T22:30:00';
   }
   if ($filter_type == 'mca_airline_order_management.filter_status') {
    $data ['status'] = $value;
   }
   if ($filter_type == 'mca_airline_order_management.filter_check_box') {
    $full_url ['able_to_change'] = $value;
   }
  }
  if (! empty ( $full_url )) {
   $data ['meta'] = $full_url;
  }
  return $data;
 }

 /**
  * Override add_where (non-PHPdoc)
  *
  * @see views_plugin_query_default::add_where()
  */
 function add_where($group, $field, $value = NULL, $operator = NULL) {
  $value = is_array ( $value ) ? reset ( $value ) : $value;
  $this->where ['user_conditions'] [] = array (
   'field' => $field,
   'value' => $value,
   'operator' => $operator
  );
 }
 function set_current_page($current_page) {
  $this->override_current_page = $current_page;
 }
 function set_items_per_page($items_per_page) {
  $this->items_per_page = $items_per_page;
 }
 function get_current_page() {
  return $this->override_current_page == - 1 ? $this->pager->get_current_page () + 1 : $this->override_current_page;
 }
 function get_items_per_page() {
  return $this->items_per_page == - 1 ? $this->pager->get_items_per_page () : $this->items_per_page;
 }
}