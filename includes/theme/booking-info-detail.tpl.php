<?php
$string = '<div class="inte_detail">';
$string .= '<ul>';
foreach($value as $key => $detail){
 // if($detail)
 $a = 1;
 if($key == 'agentInfo'){
//   foreach($detail as $key_agent => $agentInfo){
//    $string .= '<li>';
//    $string .= $key_agent . ': ' . $agentInfo;
//    $string .= '</li>';
//   }
 }else if($key == 'fareInfos'){
  $a = 1;
  foreach($detail as $key_fare => $fareInfos){
   $a = 1;
   $string .= '<li><ul>';
   $string .= '<h3>' . 'fareInfos' . '</h3>';
   foreach($fareInfos as $key1 => $value1){
    $string .= '<li>';
    $string .= $key1 . ': ' . $value1;
    $string .= '</li>';
   }
   $string .= '</ul></li>';
  }
 }

 else if($key == 'passengerInfos'){
  $a = 1;
  foreach($detail as $key_pass => $passengerInfos){
   $a = 1;
   $string .= '<li><ul>';
   $string .= '<h3>' . 'passengerInfos' . '</h3>';
   foreach($passengerInfos as $key2 => $value2){
    $string .= '<li>';
    $string .= $key2 . ': ' . $value2;
    $string .= '</li>';
   }
   $string .= '</ul></li>';
  }
 }else if($key == 'contactInfo'){
  $a = 1;
  $string .= '<li><ul>';
  $string .= '<h3>' . 'contactInfo' . '</h3>';
  foreach($detail as $key_contact => $contactInfo){
   $a = 1;
   $string .= '<li>';
   $string .= $key_contact . ': ' . $contactInfo;
   $string .= '</li>';
  }
  $string .= '</ul></li>';
 }else if($key == 'ticketingInfo'){
  $a = 1;
  $string .= '<li><ul>';
  $string .= '<h3>' . 'ticketingInfo' . '</h3>';
  foreach($detail as $key_tickting => $ticketingInfo){
   $a = 1;
   $string .= '<li>';
   $string .= $key_tickting . ': ' . $ticketingInfo;
   $string .= '</li>';
  }
  $string .= '</ul></li>';
 }
}

$string .= '</ul>';
$string .= '</div>';

echo $string;
?>
