<?php
/**
 * @file Drop the elected table previously created via importer.
 */

/**
 * Handler for _drop_table form and corresponding confirmation 
 *
 * @param  $form_state
 */
function _importer_drop_table($form_state) {
  if (isset($form_state['values']['table_to_drop']) && $form_state['values']['op'] == 'Drop') {
    return _importer_drop_table_form_confirm($form_state);
  }
  if (isset($form_state['values']['filenames']) && count($form_state['values']['filenames']) != 0 && $form_state['values']['op'] == 'Delete') {
    return _importer_delete_file_form_confirm($form_state);
  }  
  return _importer_drop_table_form($form_state);  
}

/**
 * Form used to drop selected table
 *
 * @global $db_type
 * @param  $form_state
 */
function _importer_drop_table_form($form_state) {
  global $db_type, $db_prefix;

  $sql = "";
  if ($db_type == 'mysql' || $db_type == 'mysqli') {
    $sql = "SHOW TABLES LIKE '" . $db_prefix . "import\_%'";
  }
  elseif ($db_type == 'pgsql') {
    $sql = "SELECT tablename FROM {pg_tables} WHERE tablename LIKE '" . $db_prefix . "import_%' ORDER BY tablename";
  }
  else {
    drupal_set_message(t('Unrecognized database type %dbtype', array(
      '%dbtype' => $db_type
    )));
    $render_tables = FALSE;
  }
  $result = db_query($sql);
  $tables = array();
  while ($row = db_fetch_array($result)) {
    foreach ($row as $tablename) {
      $unprefixed = schema_unprefix_table($tablename);
      $tables[$unprefixed] = $unprefixed;
    }
  }
  
  $form['drop_table_set'] = array(
    '#type' => 'fieldset',
    '#title' => t('Drop table'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE
  );

  $form['drop_table_set']['table_to_drop'] = array(
    '#type' => 'select',
    '#title' => 'Select table to drop',
    '#default_value' => $tables[key($tables)],
    '#options' => $tables,    
  );
  
  $form['drop_table_set']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Drop',
  );
  
  $form['delete_file_set'] = array(
    '#type' => 'fieldset',
    '#title' => t('Delete files'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE
  );  
  
  $files = importer_list_files(FALSE);

  $form['delete_file_set']['filenames'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => 'Select files to delete',
    '#options' => $files, 
  );
  $form['delete_file_set']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Delete',
  );  
  
  return $form;
}

/**
 * Confirmation for _drop_table form
 *
 * @param  $form_state
 */
function _importer_drop_table_form_confirm($form_state) {
  $desc = 'This action CAN NOT be undone.';
  // Tell the submit handler to process the form
  $form['process'] = array('#type' => 'hidden', '#value' => 'true');
  // Make sure the form redirects in the end
  if(arg(0) == 'admin'){
    $form['destination'] = array('#type' => 'hidden', '#value' => 'admin/content/importer/drop_table');
  }
  else {
    $form['destination'] = array('#type' => 'hidden', '#value' => 'importer/drop_table');
  }
  $form['table_to_drop'] = array('#type' => 'hidden', '#value' => $form_state['values']['table_to_drop']);
  if(arg(0) == 'admin'){
    return confirm_form($form,
                        t('Are you sure you want to drop the table %table?', array('%table' => $form_state['values']['table_to_drop'])),
                        'admin/content/importer/drop_table',
                        $desc,
                        'Drop',
                        'Return');
  }
  else{
    return confirm_form($form,
                        t('Are you sure you want to drop the table %table?', array('%table' => $form_state['values']['table_to_drop'])),
                        'importer/drop_table',
                        $desc,
                        'Drop',
                        'Return');
  }
}

function _importer_delete_file_form_confirm($form_state) {
  $desc = 'This action CAN NOT be undone.';
  // Tell the submit handler to process the form
  $form['process_files'] = array('#type' => 'hidden', '#value' => 'true');
  // Make sure the form redirects in the end
  if(arg(0) == 'admin'){
    $form['destination'] = array('#type' => 'hidden', '#value' => 'admin/content/importer/drop_table');
  }
  else {
    $form['destination'] = array('#type' => 'hidden', '#value' => 'importer/drop_table');
  }
  $form['filenames'] = array('#type' => 'hidden', '#value' => implode(',', $form_state['values']['filenames']));
  if(arg(0) == 'admin'){
    return confirm_form($form,
                        t('Are you sure you want to delete selected file(s)?'),
                        'admin/content/importer/drop_table',
                        $desc,
                        'Delete',
                        'Return');
  }
  else {
    return confirm_form($form,
                        t('Are you sure you want to delete selected file(s)?'),
                        'importer/drop_table',
                        $desc,
                        'Delete',
                        'Return');
  }
}

/**
 * Submit _drop_table form, or rebuild it if the
 * next step is a confirmation step
 *
 * @param  $form_id
 * @param  $form_state
 */
function _importer_drop_table_submit($form_id, &$form_state) {
  // If confirmation has been done, process the file
  if (isset($form_state['values']['process'])) {
    $result = array();
    db_drop_table($result, $form_state['values']['table_to_drop']);   
    if ($result[0]['success']) {
      drupal_set_message('The table ' . $form_state['values']['table_to_drop'] . ' was successfully dropped.');
      if (module_exists('vidi')) {
        if (!db_query("DELETE FROM {vidi_visualization_tables} WHERE tablename='%s'", $form_state['values']['table_to_drop'])) {
          drupal_set_message('The table ' . $form_state['values']['table_to_drop'] . ' failed to delete from VIDI handeling. Please do it manually.');
        }
      }      
    }
    else
      drupal_set_message('The table ' . $form_state['values']['table_to_drop'] . ' was NOT dropped.');
    return TRUE;
  }
  elseif (isset($form_state['values']['process_files'])) {
    $file_folder = file_directory_path() . '/delimited/';
    $filenames = explode(',', $form_state['values']['filenames']);

    foreach ( $filenames as $key => $value ) {
      $path = file_create_path($file_folder . $value);
      $sql = "DELETE FROM {files} WHERE filepath = '%s'";
      if (db_query($sql, $path))
        file_delete($path);
    }
    return TRUE;
  }

  $form_state['rebuild'] = TRUE;
}