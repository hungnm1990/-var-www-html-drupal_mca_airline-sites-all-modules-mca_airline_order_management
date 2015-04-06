<?php
function mca_airline_order_management_add() {
 return drupal_get_form ( "mca_airline_order_management_form" );
}
function mca_airline_order_management_form($form, $form_state, $entity) {
 $data = json_decode ( $entity );

 $form ['contenr'] = mca_airline_order_management_generate_table ( $data->list [0] ); // change $data->list [0]->items to change $data->list [0]

 $form ['note_item'] = array (
  '#type' => 'textfield',
  '#title' => 'Note: ',
  '#required' => TRUE,
  '#default_value' => ''
 );

 $form ['summary'] = array (
  '#type' => 'item',
  '#markup' => '<b>Total: ' . number_format ( $data->list [0]->amount ) . '</b>'
 );

 $form ['entity'] = array (
  '#type' => 'value',
  '#value' => $data->list [0]
 );

 $form ['submit_fail'] = array (
  '#type' => 'submit',
  '#value' => 'Fail',
  '#submit' => array (
   'mca_airline_order_management_submit_fail'
  ),
  '#validate' => array (
   'mca_airline_order_management_submit_validate'
  )
 );

 $form ['submit_complete'] = array (
  '#type' => 'submit',
  '#value' => 'Complete',
  '#submit' => array (
   'mca_airline_order_management_submit_complete'
  ),
  '#validate' => array (
   'mca_airline_order_management_submit_validate'
  )
 );

 $form ['submit_cancel_order'] = array (
  '#type' => 'submit',
  '#value' => 'Cancel Order',
  '#submit' => array (
   'mca_airline_order_management_cancel_order_submit'
  )
 );

 foreach ( $data->list [0]->items as $key => $item ) {
  $form ['data_' . $key] = array (
   '#type' => 'fieldset',
   '#title' => $item->name,
   '#collapsible' => TRUE,
   '#collapsed' => TRUE
  );

  if (isset ( $item->meta->method ) && $item->meta->method == 'manual') {
   $form ['data_' . $key] ['content'] = array (
    '#type' => 'item',
    '#title' => '',
    '#markup' => theme ( 'booking_info_detail', array (
     'value' => $item->meta->booking_info
    ) )
   );
  } else {
   $response_data = get_booking_info ( $item->meta->itinerary->id );
   if (! empty ( $response_data )) {
    $form ['data_' . $key] ['content'] = array (
     '#type' => 'item',
     '#title' => '',
     '#markup' => theme ( 'booking_info_detail', array (
      'value' => $response_data
     ) )
    );
   }
  }
 }

 $form ['back'] = array (
  '#type' => 'item',
  '#markup' => l ( 'Back', 'air_order' )
 );

 return $form;
}

// get booking info function
function get_booking_info($itinerary_id) {
 $url = variable_get ( 'mca_air_service_management_rest' ) . 'itinerary/' . $itinerary_id;

 $response = drupal_http_request ( $url, array (
  "method" => "GET"
 ) );

 if ($response) {
  if ($response->code == 200) {
   if (! empty ( $response->data )) {
    return json_decode ( $response->data );
   }
  }
 }
}

/*
 * FAIL
 */
function mca_airline_order_management_submit_fail($form, &$form_state) {
 $checkbox = array_filter ( $form_state ['values'] ['tableselect_element'] );

 $url = variable_get ( "mca_airline_order_management_rest" ) . "update.json";
 $data = $form_state ['values'] ['entity']->items;

 foreach ( $checkbox as $value ) {

  $data_rest = array(
  'order_id' => $data [$value - 1]->order_id,
  'type' => 'AIR',
  'status' => 'failed',
  'meta' => array(
   'admin_user' => 'admin',
   'reason_update' => '',
   '-update' => array(
    'status', 'internalStatus','meta.reason_update'
   )
  )
 );

 $options = array (
   'method' => 'POST',
   'data' => json_encode ( $data_rest ),
   'headers' => array (
    'Content-Type' => 'application/json'
   )
  );

 $a = 1;
 $response = drupal_http_request ( $url, $options );
 if ($response) {
  if ($response->code == 200) {
   drupal_set_message ( "Update item status 'Failed' success, item:" . $data [$value - 1]->name );
   drupal_set_message ( "URL: " + $url );
   drupal_set_message ( "DATA SEND: " + json_encode ( $data_rest ) );
  } else {
   drupal_set_message ( "Update item status 'Failed' fail, item: " . $data [$value - 1]->name, "warning" );
   drupal_set_message ( "URL: " . $url, "warning" );
   drupal_set_message ( "DATA SEND: " . json_encode ( $data_rest ), "warning" );
  }
 } else {
  drupal_set_message ( "Connection fail", "warning" );
 }
}
}

/*
 * COMPLETE
 */
function mca_airline_order_management_submit_complete($form, &$form_state) {
 $checkbox = array_filter ( $form_state ['values'] ['tableselect_element'] );

 $url = variable_get ( "mca_airline_order_management_rest" ) . "update.json";
 $data = $form_state ['values'] ['entity']->items;

 foreach ( $checkbox as $value ) {

  $data_rest = array (
   'order_id' => $data [$value - 1]->order_id,
   'type' => 'AIR',
   'items' => array (
    array (
     'id' => $data [$value - 1]->id,
     'status' => 'completed',
     'meta' => array(
      'reason_update' => ''
     )
    )
   ),
   'meta' => array (
    'admin_user' => 'admin',
    '-update' => array('item.status','item.meta.reason_update')
   )
  );

  $options = array (
   'method' => 'POST',
   'data' => json_encode ( $data_rest ),
   'headers' => array (
    'Content-Type' => 'application/json'
   )
  );

  $a = 1;
  $response = drupal_http_request ( $url, $options );
  if ($response) {
   if ($response->code == 200) {
    drupal_set_message ( "Update item status 'Completed' success, item:" . $data [$value - 1]->name );
    drupal_set_message ( "URL: " + $url );
    drupal_set_message ( "DATA SEND: " + json_encode ( $data_rest ) );
   } else {
    drupal_set_message ( "Update item status 'Completed' fail, item: " . $data [$value - 1]->name, "warning" );
    drupal_set_message ( "URL: " . $url, "warning" );
    drupal_set_message ( "DATA SEND: " . json_encode ( $data_rest ), "warning" );
   }
  } else {
   drupal_set_message ( "Connection fail", "warning" );
  }
 }
}

/*
 * CANCEL ALL ITEM IN ORDER
 */
function mca_airline_order_management_cancel_order_submit($form, &$form_state) {

 $checkbox = array_filter ( $form_state ['values'] ['tableselect_element'] );

 $url = variable_get ( "mca_airline_order_management_rest" ) . "update.json";
 $data = $form_state ['values'] ['entity']->items;
 foreach ( $checkbox as $key => $value ) {

   $data_rest = array (
 "order_id" => $data [$value - 1]->order_id,
   "type" => "AIR",
   "items" => array(
      "status" => "cancelled",
      "id" => $data [$value - 1]->id,
      "meta" =>    array(
      "reason_update" => ""
   )
   ),
   "meta" => array(
      "admin_user" => "admin",
      "-update" => array("item.status", "item.meta.reason_update")
   )
  );

  $options = array (
   'method' => 'POST',
   'data' => json_encode ( $data_rest ),
   'headers' => array (
    'Content-Type' => 'application/json'
   )
  );

  $a = 1;
  $response = drupal_http_request ( $url, $options );
  if ($response) {
   if ($response->code == 200) {
    drupal_set_message ( "Update item status 'Cancelled' success, item:" . $data [$value - 1]->name );
    drupal_set_message ( "URL: " + $url );
    drupal_set_message ( "DATA SEND: " + json_encode ( $data_rest ) );
   } else {
    drupal_set_message ( "Update item status 'Cancelled' fail, item: " . $data [$value - 1]->name, "warning" );
    drupal_set_message ( "URL: " . $url, "warning" );
    drupal_set_message ( "DATA SEND: " . json_encode ( $data_rest ), "warning" );
   }
  } else {
   drupal_set_message ( "Connection fail", "warning" );
  }
 }
}

/*
 * VALIDATE
 */
function mca_airline_order_management_submit_validate($form, &$form_state) {
 $a = 1;
 $checkbox = array_diff ( $form_state ['values'] ['tableselect_element'], array (
  0
 ) );

 $a = 1;
 if (count ( $checkbox ) == 0) {
  form_set_error ( "", "Please select checkbox" );
 }
}

/*
 * Generate table
 */
function mca_airline_order_management_generate_table($data) {
 $options = array ();
 $i = 0;
 $reservation_code = '';

 foreach ( $data->items as $item ) {

  if (! isset ( $item->meta->booking_info->ticketingInfo->reservationCode )) {

   $request_data = get_booking_info ( $item->meta->itinerary->id );
   if (! empty ( $request_data )) {
    $reservation_code = $request_data->ticketingInfo->reservationCode;
   }
  } else {

   $reservation_code = $item->meta->booking_info->ticketingInfo->reservationCode;
  }

  $options [$i + 1] = array (
   'item' => $item->name,
   'msin' => $item->MSIN,
   'ReservationCode' => $reservation_code,
   'quantity' => $item->quantity,
   'price' => number_format ( $item->unit_price ),
   'sum' => number_format ( $item->unit_price * $item->quantity ),
   'status' => $item->status . '-' . $data->internal_status, // change here show internal status
   'note' => isset ( $item->note ) ? $item->note : ''
  );
  $i ++;
 }

 $header = array (
  'item' => t ( 'Item' ),
  'msin' => t ( 'MSIN' ),
  'ReservationCode' => t ( 'Reservation Code' ),
  'quantity' => t ( 'Quantity' ),
  'price' => t ( 'Price' ),
  'sum' => t ( 'Sum' ),
  'status' => t ( 'Status' ),
  'note' => t ( 'Note' )
 );

 $form ['tableselect_element'] = array (
  '#type' => 'tableselect',
  '#header' => $header,
  '#options' => $options,
  '#empty' => t ( 'Not found any item.' )
 );

 return $form;
}
