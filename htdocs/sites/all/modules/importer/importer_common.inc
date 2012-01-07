<?php
/**
 * @file Utility functions.
 */
 
/**
 * Upload a single file containing data for the database.
 *
 * @param $form_state
 */
function importer_file_uploader(&$form, &$form_state) {
  $dir = file_directory_path() . '/delimited';
  file_check_directory($dir, 1);

  $file = file_save_upload('file_upload', array(), file_directory_path() . '/delimited', FILE_EXISTS_ERROR);

  if (!$file) {
    drupal_set_message('ERROR downloading the file to ' . $dir);
  }
  else {
    drupal_set_message('The file: <strong>"' . $file->filename . '"</strong> is successfully uploaded');
    file_set_status($file,  FILE_STATUS_PERMANENT);
  }

  $form_state['storage']['return_link'] = $form_state['values']['return_link'];
}

/**
 * Lists existing files in files/delimited directory
 *
 */
function importer_list_files($link = TRUE) {
    $sql = "SELECT * FROM {files} WHERE filepath LIKE '" . file_directory_path() . '/delimited' . "/%'";
    $results = db_query($sql);
    $allfiles = array();
    while ($file = db_fetch_object($results)) {
      if ($link)
        $allfiles[$file->filename] = t($file->filename . '......' . l('Download/View', $file->filepath, array('attributes' => array('target' => '_blank'))));
      else
        $allfiles[$file->filename] = t($file->filename);
    }
  return $allfiles;
}

/**
 * Open a specific file for reading and find delimiters for the data
 *
 * @param $filepath
 */
function importer_find_delimiter($filepath) {
  $filepath = file_directory_path() . '/delimited/' . $filepath;
  $handle = fopen($filepath, 'r');
  if ($handle === FALSE) {
    drupal_set_message(t('Could not open !filename', array(
      '!filename' => $filepath
    )));
    return FALSE;
  }

  $sample = fgets($handle);
  $separator = 'colon';
  if (strpos($sample, "|") === FALSE) {
    if (strpos($sample, "\t") === FALSE) {
      if (strpos($sample, ",") === FALSE)
        if (strpos($sample, ";") === FALSE)
          $separator = 'space';
        else
          $separator = 'semicolon';
      else
        $separator = 'comma';
    }
    else {
      $separator = 'tab';
    }
  }
  else {
    $separator = 'pipe';
  }
  fclose($handle);
  return $separator;
}

/**
 * Recognize columns of data in the file (all except xls)
 *
 * @staticvar $size
 * @param $filepath
 * @param $separator
 */
function importer_find_columns($filepath, $separator) {
  static $size = 10000;
  $filepath = file_directory_path() . '/delimited/' . $filepath;
  $handle = fopen($filepath, 'r');
  if ($handle === FALSE) {
    drupal_set_message(t('Could not open !filename', array(
      '!filename' => $filepath
    )));
    return FALSE;
  }

  $separator1 = ' ';
  switch ($separator) {
    case "tab" :
      $separator1 = "\t";
      break;
    case "semicolon" :
      $separator1 = ";";
      break;
    case "comma" :
      $separator1 = ",";
      break;
    case "colon" :
      $separator1 = ":";
      break;
    case "pipe" :
      $separator1 = "|";
      break;
    default :
      $separator1 = " ";
  }

  $result['cnames'] = fgetcsv($handle, $size, $separator1);
  $result['data'] = array();
  $colcount = count($result['cnames']);
  $rowcount = 0;
  while (($data = fgetcsv($handle, $size, $separator1)) !== FALSE) {
    $result['data'][] = $data;
    $rowcount++;
  }
  fclose($handle);

  for ($j = 0; $j < $colcount; $j++) {
    //$result['type'][$j] = 'text';
    $type_counter = array(
        'int' => 0,
        'datetime' => 0, 'datetime1' => 0, 'datetime2' => 0, 'datetime3' => 0, 'datetime4' => 0, 'datetime5' => 0, 'datetime6' => 0,
        'date' => 0, 'date1' => 0, 'date2' => 0, 'date3' => 0, 'date4' => 0, 'date5' => 0, 'date6' => 0,
        'float' => 0, 'floatUS' => 0, 'floatEU' => 0,
        'text' => 0,
    );
    for ($i = 0; $i < $rowcount; $i++) {
      if ($result['data'][$i][$j] == '') continue;
      if (preg_match('/^-?\d+$/', $result['data'][$i][$j])) {
        $result['type'][$j] = 'int';
        $type_counter['int']++;
      }
      elseif (preg_match('/^-?(?:\d+(?:\.\d*)?|\.\d+)$/', trim($result['data'][$i][$j])) || preg_match('/^([+-]?)(?=\d|\.\d)\d*(\.\d*)?([Ee]([+-]?\d+))?$/', trim($result['data'][$i][$j]))) {
          $result['type'][$j] = 'float';
          $type_counter['float']++;
      }
      elseif (preg_match("/\d{4}\-\d{2}\-\d{2} \d{2}:\d{2}:\d{2}/", trim($result['data'][$i][$j])) || preg_match("/\d{2}\-\d{2}\-\d{4} \d{2}:\d{2}:\d{2}/", trim($result['data'][$i][$j])) || preg_match("/\d{4}\-\d{2}\-\d{2} \d{2}:\d{2}/", trim($result['data'][$i][$j])) || preg_match("/\d{2}\-\d{2}\-\d{4} \d{2}:\d{2}/", trim($result['data'][$i][$j])) || preg_match("/\d{4}\/\d{2}\/\d{2} \d{2}:\d{2}:\d{2}/", trim($result['data'][$i][$j])) || preg_match("/\d{2}\/\d{2}\/\d{4} \d{2}:\d{2}:\d{2}/", trim($result['data'][$i][$j])) || preg_match("/\d{4}\/\d{2}\/\d{2} \d{2}:\d{2}/", trim($result['data'][$i][$j])) || preg_match("/\d{2}\/\d{2}\/\d{4} \d{2}:\d{2}/", trim($result['data'][$i][$j])) || preg_match("/\d{4}\.\d{2}\.\d{2} \d{2}:\d{2}:\d{2}/", trim($result['data'][$i][$j])) || preg_match("/\d{2}\.\d{2}\.\d{4} \d{2}:\d{2}:\d{2}/", trim($result['data'][$i][$j])) || preg_match("/\d{4}\.\d{2}\.\d{2} \d{2}:\d{2}/", trim($result['data'][$i][$j])) || preg_match("/\d{2}\.\d{2}\.\d{4} \d{2}:\d{2}/", trim($result['data'][$i][$j]))) {
        $result['type'][$j] = 'datetime';
        $type_counter['datetime']++;
        if (preg_match("/\d{4}\-\d{2}\-\d{2} \d{2}:\d{2}/", trim($result['data'][$i][$j])) || preg_match("/\d{4}\-\d{2}\-\d{2} \d{2}:\d{2}:\d{2}/", trim($result['data'][$i][$j]))) {
          $result['type'][$j] = 'datetime1';
          $type_counter['datetime1']++;
        }
        if (preg_match("/\d{2}\-\d{2}\-\d{4} \d{2}:\d{2}/", trim($result['data'][$i][$j])) || preg_match("/\d{2}\-\d{2}\-\d{4} \d{2}:\d{2}:\d{2}/", trim($result['data'][$i][$j]))) {
          $result['type'][$j] = 'datetime2';
          $type_counter['datetime2']++;
        }
        if (preg_match("/\d{4}\/\d{2}\/\d{2} \d{2}:\d{2}/", trim($result['data'][$i][$j])) || preg_match("/\d{4}\/\d{2}\/\d{2} \d{2}:\d{2}:\d{2}/", trim($result['data'][$i][$j]))) {
          $result['type'][$j] = 'datetime3';
          $type_counter['datetime3']++;
        }
        if (preg_match("/\d{2}\/\d{2}\/\d{4} \d{2}:\d{2}/", trim($result['data'][$i][$j])) || preg_match("/\d{2}\/\d{2}\/\d{4} \d{2}:\d{2}:\d{2}/", trim($result['data'][$i][$j]))) {
          $result['type'][$j] = 'datetime4';
          $type_counter['datetime4']++;
        }
        if (preg_match("/\d{4}\.\d{2}\.\d{2} \d{2}:\d{2}/", trim($result['data'][$i][$j])) || preg_match("/\d{4}\.\d{2}\.\d{2} \d{2}:\d{2}:\d{2}/", trim($result['data'][$i][$j]))) {
          $result['type'][$j] = 'datetime5';
          $type_counter['datetime5']++;
        }
        if (preg_match("/\d{2}\.\d{2}\.\d{4} \d{2}:\d{2}/", trim($result['data'][$i][$j])) || preg_match("/\d{2}\.\d{2}\.\d{4} \d{2}:\d{2}:\d{2}/", trim($result['data'][$i][$j]))) {
          $result['type'][$j] = 'datetime6';
          $type_counter['datetime6']++;
        }
      }
      elseif (preg_match("/\d{4}\-\d{2}\-\d{2}/", trim($result['data'][$i][$j])) || preg_match("/\d{2}\-\d{2}\-\d{4}/", trim($result['data'][$i][$j])) || preg_match("/\d{4}\/\d{2}\/\d{2}/", trim($result['data'][$i][$j])) || preg_match("/\d{2}\/\d{2}\/\d{4}/", trim($result['data'][$i][$j])) || preg_match("/\d{4}\.\d{2}\.\d{2}/", trim($result['data'][$i][$j])) || preg_match("/\d{2}\.\d{2}\.\d{4}/", trim($result['data'][$i][$j]))) {
        $result['type'][$j] = 'date';
        $type_counter['date']++;
        if (preg_match("/\d{4}\-\d{2}\-\d{2}/", trim($result['data'][$i][$j]))) {
          $result['type'][$j] = 'date1';
          $type_counter['date1']++;
        }
        if (preg_match("/\d{2}\-\d{2}\-\d{4}/", trim($result['data'][$i][$j]))) {
          $result['type'][$j] = 'date2';
          $type_counter['date2']++;
        }
        if (preg_match("/\d{4}\/\d{2}\/\d{2}/", trim($result['data'][$i][$j]))) {
          $result['type'][$j] = 'date3';
          $type_counter['date3']++;
        }
        if (preg_match("/\d{2}\/\d{2}\/\d{4}/", trim($result['data'][$i][$j]))) {
          $result['type'][$j] = 'date4';
          $type_counter['date4']++;
        }
        if (preg_match("/\d{4}\.\d{2}\.\d{2}/", trim($result['data'][$i][$j]))) {
          $result['type'][$j] = 'date5';
          $type_counter['date5']++;
        }
        if (preg_match("/\d{2}\.\d{2}\.\d{4}/", trim($result['data'][$i][$j]))) {
          $result['type'][$j] = 'date6';
          $type_counter['date6']++;
        }
      }
      else
        if (preg_match('/^[+-]?' . '(((([0-9]+)|([0-9]{1,4}(,[0-9]{3,4})+)))?(\\.[0-9])?([0-9]*))' . '(e[0-9]+)?' . '$/', trim($result['data'][$i][$j]))) {
          $result['type'][$j] = 'floatUS';
          $type_counter['floatUS']++;
        }
        else
          if (preg_match('/^[+-]?' . '(((([0-9]+)|([0-9]{1,4}(\\.[0-9]{3,4})+)))?(,[0-9])?([0-9]*))' . '(e[0-9]+)?' . '$/', trim($result['data'][$i][$j]))) {
            $result['type'][$j] = 'floatEU';
            $type_counter['floatEU']++;
          }
          else{
            $result['type'][$j] = 'text';
            $type_counter['text']++;
          }
    }
    $max = max($type_counter);
    if ($max == 0) 
      $result['type'][$j] = 'empty';
    else{
      foreach ($type_counter as $key => $value) {
        if ($value == $max)
          $result['type'][$j] = $key;
      }
    }
  }
  return $result;
}

/**
 * Recognize columns of data in the xls file
 *
 * @param <type> $filepath
 */
function importer_find_columns_xls($filepath) {
  $result = array();
  $filepath = file_directory_path() . '/delimited/' . $filepath;
  $data = new Spreadsheet_Excel_Reader($filepath);
  $data->read($filepath);
  $sheet = 0;
  for ($j = 1; $j <= $data->colcount(0); $j++) {
    $result['cnames'][$j -1] = $data->val(1, $j, 0);
    $typea = $data->val(2, $j, 0);
    $result['type'][$j -1] = 'text';
    if (preg_match('/^-?\d+$/', $typea))
      $result['type'][$j -1] = 'int';
    else
      if (preg_match('/^-?(?:\d+(?:\.\d*)?|\.\d+)$/', $typea) || preg_match('/^([+-]?)(?=\d|\.\d)\d*(\.\d*)?([Ee]([+-]?\d+))?$/', trim($typea)))
        $result['type'][$j -1] = 'float';
    elseif (preg_match("/\d{4}\-\d{2}\-\d{2} \d{2}:\d{2}:\d{2}/", trim($typea)) || preg_match("/\d{2}\-\d{2}\-\d{4} \d{2}:\d{2}:\d{2}/", trim($typea)) || preg_match("/\d{4}\-\d{2}\-\d{2} \d{2}:\d{2}/", trim($typea)) || preg_match("/\d{2}\-\d{2}\-\d{4} \d{2}:\d{2}/", trim($typea)) || preg_match("/\d{4}\/\d{2}\/\d{2} \d{2}:\d{2}:\d{2}/", trim($typea)) || preg_match("/\d{2}\/\d{2}\/\d{4} \d{2}:\d{2}:\d{2}/", trim($typea)) || preg_match("/\d{4}\/\d{2}\/\d{2} \d{2}:\d{2}/", trim($typea)) || preg_match("/\d{2}\/\d{2}\/\d{4} \d{2}:\d{2}/", trim($typea)) || preg_match("/\d{4}\.\d{2}\.\d{2} \d{2}:\d{2}:\d{2}/", trim($typea)) || preg_match("/\d{2}\.\d{2}\.\d{4} \d{2}:\d{2}:\d{2}/", trim($typea)) || preg_match("/\d{4}\.\d{2}\.\d{2} \d{2}:\d{2}/", trim($typea)) || preg_match("/\d{2}\.\d{2}\.\d{4} \d{2}:\d{2}/", trim($typea))) {
      $result['type'][$j -1] = 'datetime';
      if (preg_match("/\d{4}\-\d{2}\-\d{2} \d{2}:\d{2}/", trim($typea)) || preg_match("/\d{4}\-\d{2}\-\d{2} \d{2}:\d{2}:\d{2}/", trim($typea)))
        $result['type'][$j -1] = 'datetime1';
      if (preg_match("/\d{2}\-\d{2}\-\d{4} \d{2}:\d{2}/", trim($typea)) || preg_match("/\d{2}\-\d{2}\-\d{4} \d{2}:\d{2}:\d{2}/", trim($typea)))
        $result['type'][$j -1] = 'datetime2';
      if (preg_match("/\d{4}\/\d{2}\/\d{2} \d{2}:\d{2}/", trim($typea)) || preg_match("/\d{4}\/\d{2}\/\d{2} \d{2}:\d{2}:\d{2}/", trim($typea)))
        $result['type'][$j -1] = 'datetime3';
      if (preg_match("/\d{2}\/\d{2}\/\d{4} \d{2}:\d{2}/", trim($typea)) || preg_match("/\d{2}\/\d{2}\/\d{4} \d{2}:\d{2}:\d{2}/", trim($typea)))
        $result['type'][$j -1] = 'datetime4';
      if (preg_match("/\d{4}\.\d{2}\.\d{2} \d{2}:\d{2}/", trim($typea)) || preg_match("/\d{4}\.\d{2}\.\d{2} \d{2}:\d{2}:\d{2}/", trim($typea)))
        $result['type'][$j -1] = 'datetime5';
      if (preg_match("/\d{2}\.\d{2}\.\d{4} \d{2}:\d{2}/", trim($typea)) || preg_match("/\d{2}\.\d{2}\.\d{4} \d{2}:\d{2}:\d{2}/", trim($typea)))
        $result['type'][$j -1] = 'datetime6';
    }
    elseif (preg_match("/\d{4}\-\d{2}\-\d{2}/", trim($typea)) || preg_match("/\d{2}\-\d{2}\-\d{4}/", trim($typea)) || preg_match("/\d{4}\/\d{2}\/\d{2}/", trim($typea)) || preg_match("/\d{2}\/\d{2}\/\d{4}/", trim($typea)) || preg_match("/\d{4}\.\d{2}\.\d{2}/", trim($typea)) || preg_match("/\d{2}\.\d{2}\.\d{4}/", trim($typea))) {
      $result['type'][$j -1] = 'date';
      if (preg_match("/\d{4}\-\d{2}\-\d{2}/", trim($typea)))
        $result['type'][$j -1] = 'date1';
      if (preg_match("/\d{2}\-\d{2}\-\d{4}/", trim($typea)))
        $result['type'][$j -1] = 'date2';
      if (preg_match("/\d{4}\/\d{2}\/\d{2}/", trim($typea)))
        $result['type'][$j -1] = 'date3';
      if (preg_match("/\d{2}\/\d{2}\/\d{4}/", trim($typea)))
        $result['type'][$j -1] = 'date4';
      if (preg_match("/\d{4}\.\d{2}\.\d{2}/", trim($typea)))
        $result['type'][$j -1] = 'date5';
      if (preg_match("/\d{2}\.\d{2}\.\d{4}/", trim($typea)))
        $result['type'][$j -1] = 'date6';
    }
    elseif (preg_match('/^[+-]?' . '(((([0-9]+)|([0-9]{1,4}(,[0-9]{3,4})+)))?(\\.[0-9])?([0-9]*))' . '(e[0-9]+)?' . '$/', trim($typea))) $result['type'][$j -1] = 'floatUS';
    elseif (preg_match('/^[+-]?' . '(((([0-9]+)|([0-9]{1,4}(\\.[0-9]{3,4})+)))?(,[0-9])?([0-9]*))' . '(e[0-9]+)?' . '$/', trim($typea))) $result['type'][$j -1] = 'floatEU';
    else
      $result['type'][$j -1] = 'text';
  }

  for ($i = 2; $i <= $data->rowcount(0); $i++)
    for ($j = 1; $j <= $data->colcount(0); $j++) {
      $result['data'][$i -2][$j -1] = $data->val($i, $j, 0);
    }
  return $result;
}

function importer_preview_table_js() {
  $form_state = array('storage' => NULL, 'submitted' => FALSE);
  $form_build_id = $_POST['form_build_id'];

  $form = form_get_cache($form_build_id, $form_state);

  $args = $form['#parameters'];
  $form_id = array_shift($args);
  $form_state['post'] = $form['#post'] = $_POST;
  $form['#programmed'] = $form['#redirect'] = FALSE;

  drupal_process_form($form_id, $form, $form_state);
  $form = drupal_rebuild_form($form_id, $form_state, $args, $form_build_id); 
  $tabledata = array('delimiters' => $form['delimiters']['#value']);
  foreach ($form['variabletable'] as $key => $value) {
    if (strpos($key, 'olnames') || strpos($key, 'atatypes'))
      $tabledata[$key] = $value['#value'];
  }

  $form['preview']['ahah_wrapper']['options']['#value'] = '<span>aaaaaaaaaaaaaaa</span>';
  $output = theme('status_messages') . drupal_render($form['preview']['ahah_wrapper']['options']);

  drupal_json(array('status' => TRUE, 'data' => $output));    
}

function _importer_generate_sql($no_of_rows, $no_of_cols, $coltypes, $rezultat, $tablename, $colnames1) {
  $sql_query = array(); 
  for ($ii = 0; $ii < $no_of_rows; $ii++) {
    for ($jj = 0; $jj < $no_of_cols; $jj++)
      switch ($coltypes[$jj]) {
    case 'int' :
          if ($rezultat['data'][$ii][$jj] == '')
            $rezultat['data'][$ii][$jj] = 'NULL';
          else {
            $rezultat['data'][$ii][$jj] = (int) (str_replace('.', '', $rezultat['data'][$ii][$jj]));
            $rezultat['data'][$ii][$jj] = (int) (str_replace(',', '', $rezultat['data'][$ii][$jj]));
          }
          break;
    case 'float' :
          if ($rezultat['data'][$ii][$jj] == '')
            $rezultat['data'][$ii][$jj] = 'NULL';
          else
            $rezultat['data'][$ii][$jj] = (float) (str_replace(',', '', $rezultat['data'][$ii][$jj]));
          break;
    case 'floatUS' :
          if ($rezultat['data'][$ii][$jj] == '')
            $rezultat['data'][$ii][$jj] = 'NULL';
          else
            $rezultat['data'][$ii][$jj] = (float) (str_replace(',', '', $rezultat['data'][$ii][$jj]));
          break;
    case 'floatEU' :
          if ($rezultat['data'][$ii][$jj] == '')
            $rezultat['data'][$ii][$jj] = 'NULL';
          else {
            $rezultat['data'][$ii][$jj] = str_replace('.', '', $rezultat['data'][$ii][$jj]);
            $rezultat['data'][$ii][$jj] = (float) (str_replace(',', '.', $rezultat['data'][$ii][$jj]));
          }
          break;
    case 'date' : //dd-mm-yyyy
          $stari = $rezultat['data'][$ii][$jj];
          $str = explode('/', $rezultat['data'][$ii][$jj]);
          $day = $str[0];
          $month = $str[1];
          $year = $str[2];
          if (checkdate($month, $day, $year)) {
            //$new_date = date("'Y-m-d H:i:s'",strtotime($str[2]."-".$str[1]."-".$str[0]." 00:00:00"));
            $new_date = "'" . $year . "-" . $month . "-" . $day . " 00:00:00" . "'";
            $rezultat['data'][$ii][$jj] = $new_date;
          }
          else
            $rezultat['data'][$ii][$jj] = 'NULL';
          break;
    case 'date1' : //yyyy-mm-dd
          $str = explode('-', $rezultat['data'][$ii][$jj]);
          $day = $str[2];
          $month = $str[1];
          $year = $str[0];
          if (checkdate($month, $day, $year)) {
            $new_date = "'" . $year . "-" . $month . "-" . $day . " 00:00:00" . "'";
            $rezultat['data'][$ii][$jj] = $new_date;
          }
          else
            $rezultat['data'][$ii][$jj] = 'NULL';
          break;
    case 'date2' : //dd-mm-yyyy
          $stari = $rezultat['data'][$ii][$jj];
          $str = explode('-', $rezultat['data'][$ii][$jj]);
          $day = $str[0];
          $month = $str[1];
          $year = $str[2];
          if (checkdate($month, $day, $year)) {
            $new_date = "'" . $year . "-" . $month . "-" . $day . " 00:00:00" . "'";
            $rezultat['data'][$ii][$jj] = $new_date;
          }
          else
            $rezultat['data'][$ii][$jj] = 'NULL';
          break;
    case 'date21' : //mm-dd-yyyy
          $str = explode('-', $rezultat['data'][$ii][$jj]);
          $day = $str[1];
          $month = $str[0];
          $year = $str[2];
          if (checkdate($month, $day, $year)) {
            $new_date = "'" . $year . "-" . $month . "-" . $day . " 00:00:00" . "'";
            $rezultat['data'][$ii][$jj] = $new_date;
          }
          else
            $rezultat['data'][$ii][$jj] = 'NULL';
          break;
    case 'date3' : //yyyy/mm/dd
          $str = explode('/', $rezultat['data'][$ii][$jj]);
          $day = $str[2];
          $month = $str[1];
          $year = $str[0];
          if (checkdate($month, $day, $year)) {
            $new_date = "'" . $year . "-" . $month . "-" . $day . " 00:00:00" . "'";
            $rezultat['data'][$ii][$jj] = $new_date;
          }
          else
            $rezultat['data'][$ii][$jj] = 'NULL';
          break;
    case 'date4' : //dd/mm/yyyy
          $str = explode('/', $rezultat['data'][$ii][$jj]);
          $day = $str[0];
          $month = $str[1];
          $year = $str[2];
          if (checkdate($month, $day, $year)) {
            $new_date = "'" . $year . "-" . $month . "-" . $day . " 00:00:00" . "'";
            $rezultat['data'][$ii][$jj] = $new_date;
          }
          else
            $rezultat['data'][$ii][$jj] = 'NULL';
          break;
    case 'date41' : //mm/dd/yyyy
          $str = explode('/', $rezultat['data'][$ii][$jj]);
          $day = $str[1];
          $month = $str[0];
          $year = $str[2];
          if (checkdate($month, $day, $year)) {
            $new_date = "'" . $year . "-" . $month . "-" . $day . " 00:00:00" . "'";
            $rezultat['data'][$ii][$jj] = $new_date;
          }
          else
            $rezultat['data'][$ii][$jj] = 'NULL';
          break;
    case 'date5' : //yyyy.mm.dd
          $str = explode('.', $rezultat['data'][$ii][$jj]);
          $day = $str[2];
          $month = $str[1];
          $year = $str[0];
          if (checkdate($month, $day, $year)) {
            $new_date = "'" . $year . "-" . $month . "-" . $day . " 00:00:00" . "'";
            $rezultat['data'][$ii][$jj] = $new_date;
          }
          else
            $rezultat['data'][$ii][$jj] = 'NULL';
          break;
    case 'date6' : //dd.mm.yyyy
          $str = explode('.', $rezultat['data'][$ii][$jj]);
          $day = $str[0];
          $month = $str[1];
          $year = $str[2];
          if (checkdate($month, $day, $year)) {
            $new_date = date("'Y-m-d H:i:s'", strtotime($str[2] . "-" . $str[1] . "-" . $str[0] . " 00:00:00"));
            $rezultat['data'][$ii][$jj] = $new_date;
          }
          else
            $rezultat['data'][$ii][$jj] = 'NULL';
          break;
    case 'date61' : //mm.dd.yyyy
          $str = explode('.', $rezultat['data'][$ii][$jj]);
          $day = $str[1];
          $month = $str[0];
          $year = $str[2];
          if (checkdate($month, $day, $year)) {
            $new_date = "'" . $year . "-" . $month . "-" . $day . " 00:00:00" . "'";
            $rezultat['data'][$ii][$jj] = $new_date;
          }
          else
            $rezultat['data'][$ii][$jj] = 'NULL';
          break;
    case 'datetime1' : //yyyy-mm-dd hh:mm
          if (preg_match("/(\d{4})\-(\d{2})\-(\d{2}) (\d{2}):(\d{2}):(\d{2})/", $rezultat['data'][$ii][$jj], $matches)) {
            if (checkdate($matches[2], $matches[3], $matches[1]))
              $rezultat['data'][$ii][$jj] = date("'Y-m-d H:i:s'", strtotime($matches[1] . "-" . $matches[2] . "-" . $matches[3] . " " . $matches[4] . ":" . $matches[5] . ":" . $matches[6]));
            else
              $rezultat['data'][$ii][$jj] = 'NULL';
          }
          elseif (preg_match("/(\d{4})\-(\d{2})\-(\d{2}) (\d{2}):(\d{2})/", $rezultat['data'][$ii][$jj], $matches)) {
            if (checkdate($matches[2], $matches[3], $matches[1]))
              $rezultat['data'][$ii][$jj] = date("'Y-m-d H:i:s'", strtotime($matches[1] . "-" . $matches[2] . "-" . $matches[3] . " " . $matches[4] . " " . $matches[5] . ":00"));
            else
              $rezultat['data'][$ii][$jj] = 'NULL';
          }
          else
            $rezultat['data'][$ii][$jj] = 'NULL';
          break;
    case 'datetime2' : //dd-mm-yyyy hh:mm
          if (preg_match("/^(\d{2})-(\d{2})-(\d{4}) ([01][0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9])$/", $rezultat['data'][$ii][$jj], $matches)) {
            if (checkdate($matches[2], $matches[1], $matches[3]))
              $rezultat['data'][$ii][$jj] = date("'Y-m-d H:i:s'", strtotime($matches[3] . "-" . $matches[2] . "-" . $matches[1] . " " . $matches[4] . ":" . $matches[5] . ":" . $matches[6]));
            else
              $rezultat['data'][$ii][$jj] = 'NULL';
          }
          else {
            if (preg_match("/^(\d{2})-(\d{2})-(\d{4}) ([01][0-9]|2[0-3]):([0-5][0-9])$/", trim($rezultat['data'][$ii][$jj]), $matches)) {
              if (checkdate($matches[2], $matches[1], $matches[3]))
                $rezultat['data'][$ii][$jj] = date("'Y-m-d H:i:s'", strtotime($matches[3] . "-" . $matches[2] . "-" . $matches[1] . " " . $matches[4] . ":" . $matches[5] . ":00"));
              else
                $rezultat['data'][$ii][$jj] = 'NULL';
            }
            else
              $rezultat['data'][$ii][$jj] = 'NULL';
          }
          break;
    case 'datetime21' : //mm-dd-yyyy hh:mm
          if (preg_match("/^(\d{2})-(\d{2})-(\d{4}) ([01][0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9])$/", $rezultat['data'][$ii][$jj], $matches)) {
            if (checkdate($matches[1], $matches[2], $matches[3]))
              $rezultat['data'][$ii][$jj] = date("'Y-m-d H:i:s'", strtotime($matches[3] . "-" . $matches[1] . "-" . $matches[2] . " " . $matches[4] . ":" . $matches[5] . ":" . $matches[6]));
            else
              $rezultat['data'][$ii][$jj] = 'NULL';
          }
          elseif (preg_match("/^(\d{2})-(\d{2})-(\d{4}) ([01][0-9]|2[0-3]):([0-5][0-9])$/", $rezultat['data'][$ii][$jj], $matches)) {
            if (checkdate($matches[1], $matches[2], $matches[3]))
              $rezultat['data'][$ii][$jj] = date("'Y-m-d H:i:s'", strtotime($matches[3] . "-" . $matches[1] . "-" . $matches[2] . " " . $matches[4] . ":" . $matches[5] . ":00"));
            else
              $rezultat['data'][$ii][$jj] = 'NULL';
          }
          else
            $rezultat['data'][$ii][$jj] = 'NULL';
          break;
    case 'datetime3' : //yyyy/mm/dd hh:mm
          if (preg_match("/^(\d{4})/(\d{2})/(\d{2}) ([01][0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9])$/", $rezultat['data'][$ii][$jj], $matches)) {
            if (checkdate($matches[2], $matches[3], $matches[1]))
              $rezultat['data'][$ii][$jj] = date("'Y-m-d H:i:s'", strtotime($matches[1] . "-" . $matches[2] . "-" . $matches[3] . " " . $matches[4] . ":" . $matches[5] . ":" . $matches[6]));
            else
              $rezultat['data'][$ii][$jj] = 'NULL';
          }
          elseif (preg_match("/^(\d{4})/(\d{2})/(\d{2}) ([01][0-9]|2[0-3]):([0-5][0-9])$/", $rezultat['data'][$ii][$jj], $matches)) {
            if (checkdate($matches[2], $matches[3], $matches[1]))
              $rezultat['data'][$ii][$jj] = date("'Y-m-d H:i:s'", strtotime($matches[1] . "-" . $matches[2] . "-" . $matches[3] . " " . $matches[4] . ":" . $matches[5] . ":00"));
            else
              $rezultat['data'][$ii][$jj] = 'NULL';
          }
          else
            $rezultat['data'][$ii][$jj] = 'NULL';
          break;
    case 'datetime4' : //dd/mm/yyyy hh:mm
          if (preg_match("/^(\d{2})/(\d{2})/(\d{4}) ([01][0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9])$/", $rezultat['data'][$ii][$jj], $matches)) {
            if (checkdate($matches[2], $matches[1], $matches[3]))
              $rezultat['data'][$ii][$jj] = date("'Y-m-d H:i:s'", strtotime($matches[3] . "-" . $matches[2] . "-" . $matches[1] . " " . $matches[4] . ":" . $matches[5] . ":" . $matches[6]));
            else
              $rezultat['data'][$ii][$jj] = 'NULL';
          }
          elseif (preg_match("/^(\d{2})/(\d{2})/(\d{4}) ([01][0-9]|2[0-3]):([0-5][0-9])$/", $rezultat['data'][$ii][$jj], $matches)) {
            if (checkdate($matches[2], $matches[1], $matches[3]))
              $rezultat['data'][$ii][$jj] = date("'Y-m-d H:i:s'", strtotime($matches[3] . "-" . $matches[2] . "-" . $matches[1] . " " . $matches[4] . ":" . $matches[5] . ":00"));
            else
              $rezultat['data'][$ii][$jj] = 'NULL';
          }
          else
            $rezultat['data'][$ii][$jj] = 'NULL';
          break;
    case 'datetime41' : //mm/dd/yyyy hh:mm
          if (preg_match("/^(\d{2})/(\d{2})/(\d{4}) ([01][0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9])$/", $rezultat['data'][$ii][$jj], $matches)) {
            if (checkdate($matches[1], $matches[2], $matches[3]))
              $rezultat['data'][$ii][$jj] = date("'Y-m-d H:i:s'", strtotime($matches[3] . "-" . $matches[1] . "-" . $matches[2] . " " . $matches[4] . ":" . $matches[5] . ":" . $matches[6]));
            else
              $rezultat['data'][$ii][$jj] = 'NULL';
          }
          elseif (preg_match("/^(\d{2})/(\d{2})/(\d{4}) ([01][0-9]|2[0-3]):([0-5][0-9])$/", $rezultat['data'][$ii][$jj], $matches)) {
            if (checkdate($matches[1], $matches[2], $matches[3]))
              $rezultat['data'][$ii][$jj] = date("'Y-m-d H:i:s'", strtotime($matches[3] . "-" . $matches[1] . "-" . $matches[2] . " " . $matches[4] . ":" . $matches[5] . ":00"));
            else
              $rezultat['data'][$ii][$jj] = 'NULL';
          }
          else
            $rezultat['data'][$ii][$jj] = 'NULL';
          break;
    case 'datetime5' : //yyyy.mm.dd hh:mm
          if (preg_match("/^(\d{4}).(\d{2}).(\d{2}) ([01][0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9])$/", $rezultat['data'][$ii][$jj], $matches)) {
            if (checkdate($matches[2], $matches[3], $matches[1]))
              $rezultat['data'][$ii][$jj] = date("'Y-m-d H:i:s'", strtotime($matches[1] . "-" . $matches[2] . "-" . $matches[3] . " " . $matches[4] . ":" . $matches[5] . ":" . $matches[6]));
            else
              $rezultat['data'][$ii][$jj] = 'NULL';
          }
          elseif (preg_match("/^(\d{4}).(\d{2}).(\d{2}) ([01][0-9]|2[0-3]):([0-5][0-9])$/", $rezultat['data'][$ii][$jj], $matches)) {
            if (checkdate($matches[2], $matches[3], $matches[1]))
              $rezultat['data'][$ii][$jj] = date("'Y-m-d H:i:s'", strtotime($matches[1] . "-" . $matches[2] . "-" . $matches[3] . " " . $matches[4] . ":" . $matches[5] . ":00"));
            else
              $rezultat['data'][$ii][$jj] = 'NULL';
          }
          else
            $rezultat['data'][$ii][$jj] = 'NULL';
          break;
    case 'datetime6' : //dd.mm.yyyy hh:mm
          if (preg_match("/^(\d{2}).(\d{2}).(\d{4}) ([01][0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9])$/", $rezultat['data'][$ii][$jj], $matches)) {
            if (checkdate($matches[2], $matches[1], $matches[3]))
              $rezultat['data'][$ii][$jj] = date("'Y-m-d H:i:s'", strtotime($matches[3] . "-" . $matches[2] . "-" . $matches[1] . " " . $matches[4] . ":" . $matches[5] . ":" . $matches[6]));
            else
              $rezultat['data'][$ii][$jj] = 'NULL';
          }
          elseif (preg_match("/^(\d{2}).(\d{2}).(\d{4}) ([01][0-9]|2[0-3]):([0-5][0-9])$/", $rezultat['data'][$ii][$jj], $matches)) {
            if (checkdate($matches[2], $matches[1], $matches[3]))
              $rezultat['data'][$ii][$jj] = date("'Y-m-d H:i:s'", strtotime($matches[3] . "-" . $matches[2] . "-" . $matches[1] . " " . $matches[4] . ":" . $matches[5] . ":00"));
            else
              $rezultat['data'][$ii][$jj] = 'NULL';
          }
          else
            $rezultat['data'][$ii][$jj] = 'NULL';
          break;
    case 'datetime61' : //mm.dd.yyyy hh:mm
          if (preg_match("/^(\d{2}).(\d{2}).(\d{4}) ([01][0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9])$/", $rezultat['data'][$ii][$jj], $matches)) {
            if (checkdate($matches[1], $matches[2], $matches[3]))
              $rezultat['data'][$ii][$jj] = date("'Y-m-d H:i:s'", strtotime($matches[3] . "-" . $matches[1] . "-" . $matches[2] . " " . $matches[4] . ":" . $matches[5] . ":" . $matches[6]));
            else
              $rezultat['data'][$ii][$jj] = 'NULL';
          }
          elseif (preg_match("/^(\d{2}).(\d{2}).(\d{4}) ([01][0-9]|2[0-3]):([0-5][0-9])$/", $rezultat['data'][$ii][$jj], $matches)) {
            if (checkdate($matches[1], $matches[2], $matches[3]))
              $rezultat['data'][$ii][$jj] = date("'Y-m-d H:i:s'", strtotime($matches[3] . "-" . $matches[1] . "-" . $matches[2] . " " . $matches[4] . ":" . $matches[5] . ":00"));
            else
              $rezultat['data'][$ii][$jj] = 'NULL';
          }
          else
            $rezultat['data'][$ii][$jj] = 'NULL';
          break;
    case 'text' :
          if ($rezultat['data'][$ii][$jj] == '')
            $rezultat['data'][$ii][$jj] = 'NULL';
          else
            $rezultat['data'][$ii][$jj] = "'" . utf8_encode(addslashes($rezultat['data'][$ii][$jj])) . "'";
          break;
    default:
          $rezultat['data'][$ii][$jj] = 'NULL';
      }

    $sql = 'INSERT INTO {' . $tablename . '} (' . implode(', ', $colnames1) . ') VALUES(' . implode(',', $rezultat['data'][$ii]) . ');';
    $msg = t('SQL command !digits:', array(
      '!digits' => $ii +1
    ));
    $sql_query[] = $sql;
  }
  
  return  $sql_query;
}