<?php
/**
  * Form Builder. Configure Melted Playout Server
  * 
  * @ingroup forms
  * @see system_settings_form().
  */
function melted_admin_settings() {
  //Ip address or hostname of the Melted Server
  $form['melted_server_config_ip'] = array(
    '#type' => 'textfield',
    '#title' => 'Hostname',
    '#default_value' => variable_get('melted_server_config_ip','localhost'),
    '#description' => t('Enter the Servername or Ip Address of the Melted Server. Usually this will be set to localhost'),
    '#required' => TRUE,
    '#length' => 20,
    '#maxlength' => 50,
  );

  $form['melted_server_config_port'] = array(
    '#type' => 'textfield',
    '#title' => 'Port',
    '#description' => t('The Port of the Melted Server. Usually 5250.'),
    '#default_value' => variable_get('melted_server_config_port',5250),
    '#required' => TRUE,
    '#length' => 5,
    '#malength' => 5,
   );

return  system_settings_form($form);
 
}

/** Validate if the Melted Server can be contacted
  *
  */

function melted_admin_settings_validate($form, &$form_state) {

  $mysettings = array(
    'host' => $form['melted_server_config_ip']['#value'],
    'port' => $form['melted_server_config_port']['#value'],
    'mode' => 1,
                );

  $melted = new Client($mysettings['host'],$mysettings['port']); 
  $melted->connect();
  $isConnected=$melted->connected; 
  $melted->disconnect();
 
  //Set Form Error when not Connected using drupal_set_message allows us to save the value anyway, in case they are correct, but the Melted Server is not running yet.
  if ($isConnected != 1) {
    drupal_set_message(t('The connection to the Melted Server: %host:%port could not be established.<br>Make sure your Melted Server is running and the check the configuration again.  ', array('%host' => $mysettings['host'],'%port' => $mysettings['port'])),'error');
  } else {
    // set Status to successful connected
    drupal_set_message(t('The connection to the Melted Server: %host:%port was established successfully!', array('%host' => $mysettings['host'],'%port' => $mysettings['port'])),'status');
  }
}
