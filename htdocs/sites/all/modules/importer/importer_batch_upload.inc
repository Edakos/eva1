<?php
/**
 * @file The part of the module that handles the upload of files.
 */
 
 
/**
 * Form for uploading zip files
 *
 * @global $db_type
 * @param  $form_state
 */
function importer_batch_file_uploade_form($form_state) {
  global $db_type, $db_prefix;
  $file_dir = file_directory_path();
  $dirs = file_scan_directory($file_dir, '^(.)*_importer_files$', $nomask = array(
    '.',
    '..'
  ), 0, FALSE);
  $dirnames = array();
  foreach ($dirs as $dir) {
    $path = $file_dir . '/' . $dir->basename;
    if (file_check_directory($path)) {
      $dirnames[$dir->basename] = $dir->basename;
    }
  }
  $form['#attributes'] = array(
    'enctype' => "multipart/form-data"
  );
  $form['files'] = array(
    '#type' => 'fieldset',
    '#title' => t('Upload a .zip file'),
    '#collapsible' => FALSE
  );
  if (function_exists('zip_open')) {
    $render_tables = TRUE;
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
    $options = array(
      '--'
    );
    while ($row = db_fetch_array($result)) {
      foreach ($row as $tablename) {
        $unprefixed = schema_unprefix_table($tablename);
        $options[$unprefixed] = $unprefixed;
      }
    }
    $max_filesize = format_size(parse_size(file_upload_max_size()));

    if ($render_tables) {
      $form['files']['table'] = array(
        '#type' => 'fieldset',
        '#title' => t('Choose a table and a field to modify'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE
      );

      $form['files']['table']['existing_tables'] = array(
        '#title' => 'Existing database tables',
        '#type' => 'select',
        '#options' => $options,
        '#multiple' => FALSE,
        '#description' => t('Tables which are created via importer module.'),
        '#ahah' => array(
          'event' => 'change',
          'method' => 'replace',
          'path' => 'importer/js',
          'effect' => 'fade',
          'wrapper' => 'edit-table-fields-wrapper',
        ),
      );

      $form['files']['table']['table_fields'] = array(
        '#title' => 'Table fields',
        '#type' => 'select',
        '#options' => array(
          '--' => '--'
        ),
        '#multiple' => FALSE,
        '#description' => t('Choose a field of selected table that contains the file name.<br />The content of the field must be the same as filenames in the zip file.'),

        
      );
    }

    $form['files']['file_upload'] = array(
      '#type' => 'file',
      '#description' => t('Maximum Filesize: @max_filesize<br />Must be a ZIP file', array(
        '@max_filesize' => $max_filesize
      )),
      '#attributes' => array(
        'accept' => 'zip'
      ),
      '#title' => 'Zip file to upload'
    );

    $form['files']['directory'] = array(
      '#type' => 'textfield',
      '#size' => 50,
      '#maxlength' => 255,
      '#title' => 'Directory to store files in',
      '#description' => t('Creates a new directory in the \'files\' directory. \'_importer_files\' will be appended to directory name.'),

      
    );

    if (count($dirnames) != 0) {
      $form['files']['existing_dirs'] = array(
        '#title' => 'Existing directories',
        '#type' => 'radios',
        '#required' => FALSE,
        '#options' => $dirnames,
        '#description' => t('Only valid if the new directory field is empty, in witch case you must choose one of the existing directories to store files in.'),

        
      );
    }

    $form['files']['file_upload_button'] = array(
      '#type' => 'submit',
      '#value' => t('Upload')
    );

  }
  else {
    $form['files'] = array(
      '#value' => t('Your php instalation doesn\'t have zip manipulation capabilities. Prease install zlib php library to use this feature.'),

      
    );
  }
  return $form;
}

/**
 * Menu callback, referenced by the #ahah['path'] property
 */
function importer_js() {

  $form_state = array(
    'submitted' => FALSE
  );
  $form_build_id = $_POST['form_build_id'];

  if (!$form = form_get_cache($form_build_id, $form_state)) {
    exit();
  }
  $tablename = db_escape_table($_POST['existing_tables']);

  $options = array();
  if (db_table_exists($tablename)) {
    $results = db_query("show columns from {" . $tablename . "}");
    while ($result = db_fetch_object($results)) {
      if ($result->Key !== "PRI") {
        $options[$result->Field] = $result->Field;
      }
    }
  }
  else {
    $options[] = '--';
  }

  $form['files']['table']['table_fields']['#options'] = $options;

  form_set_cache($form_build_id, $form, $form_state);
  $form += array(
    '#post' => $_POST,
    '#programmed' => FALSE,

    
  );
  // Rebuild the form.
  $form = form_builder('importer_batch_file_uploade', $form, $form_state);

  // Render the new output.
  $output = theme('status_messages') . drupal_render($form['files']['table']['table_fields']);
  $var = array(
    'status' => TRUE,
    'data' => $output
  );
  //drupal_json(array('status' => TRUE, 'data' => $output));
  print drupal_to_js($var);
  exit;
}

/**
 * Validation method for the upload zip form
 *
 * @param  $form
 * @param  $form_state
 */
function importer_batch_file_uploade_form_validate(& $form, & $form_state) {
  if (!isset ($form_state['values']['directory']) || trim($form_state['values']['directory']) == '') {
    if (!isset ($form_state['values']['existing_dirs']) || trim($form_state['values']['existing_dirs']) == '') {
      form_set_error('directory', t('If none of the existing directories is chosen or no appropriate directory exists, one must be created.'));
    }
  }
}

/**
 * Submit the _batch_file_uploade form
 * @param $form
 * @param $form_state
 */
function importer_batch_file_uploade_form_submit($form, & $form_state) {
  $dir_name = ((isset($form_state['values']['directory']) && trim($form_state['values']['directory']) != '') ? $form_state['values']['directory'] . '_importer_files' : $form_state['values']['existing_dirs']);
  $file_dir = file_directory_path();
  $full_dir_path = $file_dir . '/' . $dir_name;

  if (!file_check_directory($full_dir_path, 1))
    watchdog('php', 'Directory %dir was NOT created.', array(
      '%dir' => $dir_name
    ), WATCHDOG_ERROR);

  $images = array();
  $validators = array(
    'file_validate_extensions' => array(
      'zip'
    ),
    'importer_valid_zip' => array(),

    
  );
  if ($file = file_save_upload('file_upload', $validators)) {
    $extracted = importer_zip_unpaker($file->filepath, $full_dir_path, $form_state);
    if ($file->fid) {
      db_query("DELETE FROM {files} WHERE fid = %d", $file->fid);
    }
    if (file_exists($file->filepath)) {
      unlink($file->filepath);
    }
  }
  drupal_set_message(t('Upload successful!'));
}

/**
 * Unpack the zip file, save the content, update the {files} table
 * and the import_* table, if one was selected on the form.
 *
 * @global $user
 * @param  $filepath. A peth to the zip file
 * @param  $save_filepath. Full path to the destination.
 * @param  $form_state
 */
function importer_zip_unpaker($filepath, $save_filepath, $form_state) {
  $extracted = array();
  global $user;

  if ($z = zip_open($filepath)) {
    $dest = file_destination(file_directory_temp() . '/' . basename($filepath, '.zip'), FILE_EXISTS_RENAME); //FILE_EXISTS_REPLACE);

    mkdir($dest, 0755);
    $msg_database = "";
    while ($entry = zip_read($z)) {

      if (zip_entry_open($z, $entry, 'r') && ($zip_entry_filesize = zip_entry_filesize($entry))) {
        $entry_name = zip_entry_name($entry);
        $data = zip_entry_read($entry, $zip_entry_filesize);

        if ($filepath = file_save_data($data, $save_filepath . '/' . drupal_strtolower($entry_name))) {
          $path_array = explode('/', $filepath);
          $file = new stdClass();
          $file->filepath = $filepath;
          $file->filename = $path_array[count($path_array) - 1];
          $file->filemime = file_get_mimetype($filepath);
          $file->filesize = filesize($filepath);
          $file->uid = $user->uid;
          $file->status = 1;
          $file->timestamp = time();
          drupal_write_record('files', $file);
          $sql = "SELECT filepath, filename FROM {files} WHERE fid = %d";

          if ($form_state['values']['existing_tables'] !== '--' && $form_state['values']['table_fields'] !== '--') {
            $sql = "SELECT COUNT(*) FROM {importer_change_log} WHERE table_name='%s' AND old_value='%s'";
            $managed_tables_count = db_result(db_query($sql, $form_state['values']['existing_tables'], drupal_strtolower($entry_name)));

            if ($managed_tables_count != 0) {
              $sql = "SELECT new_value FROM {importer_change_log} WHERE table_name='%s' AND old_value='%s' AND field_name='%s'";
              $current_imagefield_value = db_result(db_query_range($sql, $form_state['values']['existing_tables'], drupal_strtolower($entry_name), $form_state['values']['table_fields'], 0, 1));
              $sql = "UPDATE {%s} SET %s='%s' WHERE %s='%s'";
              db_query($sql, db_escape_table($form_state['values']['existing_tables']), db_escape_table($form_state['values']['table_fields']), $file->filepath, db_escape_table($form_state['values']['table_fields']), $current_imagefield_value);
              $sql = "UPDATE {importer_change_log} SET new_value='%s', old_value='%s' WHERE table_name='%s' AND old_value='%s' AND field_name='%s'";
              db_query($sql, $file->filepath, drupal_strtolower($entry_name), $form_state['values']['existing_tables'], drupal_strtolower($entry_name), $form_state['values']['table_fields']);
            }
            else {
              $sql = "SELECT * FROM {%s} WHERE %s='%s';";
              $results = db_query($sql, db_escape_table($form_state['values']['existing_tables']), db_escape_table($form_state['values']['table_fields']), $entry_name);

              while ($result = db_fetch_object($results)) {
                $log = new stdClass();
                $log->table_name = $form_state['values']['existing_tables'];
                $log->record_id = $result->ImporterID;
                $log->field_name = $form_state['values']['table_fields'];
                $log->old_value = drupal_strtolower($entry_name);
                $log->new_value = $file->filepath;
                drupal_write_record('importer_change_log', $log);
              }

              $sql = "UPDATE {%s} SET %s='%s' WHERE %s='%s'";
              db_query($sql, db_escape_table($form_state['values']['existing_tables']), db_escape_table($form_state['values']['table_fields']), $file->filepath, db_escape_table($form_state['values']['table_fields']), $entry_name);
            }

            $msg_database = t('Table @table was sucessfully updated!', array(
              '@table' => $form_state['values']['existing_tables']
            ));
          }

          $msg_file = t('File @file was succesfully saved in the directory @dir under the name %newfile', array(
            '@file' => $entry_name,
            '@dir' => $form_state['values']['directory'] ? $form_state['values']['directory'] : $form_state['values']['existing_dirs'],
            '%newfile' => $path_array[count($path_array) - 1]
          ));
          drupal_set_message($msg_file);
          $extracted[] = $file;
        }

        zip_entry_close($entry);
      }
    }

    if ($msg_database != "") {
      drupal_set_message($msg_database);
    }

    zip_close($z);
  }
  return $extracted;
}

/**
 * Is the uploaded file a valid zip file
 *
 * @param <type> $file
 */
function importer_valid_zip($file) {
  $errors = array();
  if ($z = zip_open($file->filepath)) {
    zip_close($z);
  }
  else {
    $errors[] = t('The file is not a valid zip file or may be corrupt.');
  }
  return $errors;
}