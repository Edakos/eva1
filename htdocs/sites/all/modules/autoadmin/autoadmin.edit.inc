<?php
// $Id: autoadmin.edit.inc,v 1.4 2011/01/25 10:48:27 rune Exp $

/**
 * @file
 * Handles the edit page.
 *
 * @ingroup autoadmin
 * @author Rune Kaagaard rune@prescriba.com
 */

// Constants.
define('AUTOADMIN_EDIT_VARCHAR_MAX_SIZE', 60);

/**
 * Returns edit form.
 *
 * @ingroup forms
 * @see autoadmin_edit_form_submit()
 * @param array $form
 * @param array $schema
 * @param int/FALSE $primary_value
 *   Primary value of row being edited or FALSE for new item.
 * @return array
 */
function autoadmin_edit_form(&$form_state, $table, $primary_value) {
  $schema = autoadmin_init_page($table);
  // Get current record or empty array.
  $row = _autoadmin_edit_form_get_row($schema, $primary_value);
  $weight = 0;
  // Create form from schema. Change weight by reference.
  $form = _autoadmin_edit_build_form($row, $schema, $weight);
  // Store schema in form.
  $form['schema'] = array('#type' => 'value', '#value' => $schema);
  // Buttons.
  $form['submit'] = array('#type' => 'submit', '#value' => t('Save'), '#weight' => ++$weight);
  if ($primary_value) {
    $form['delete'] = array(
      '#type' => 'button',
      '#value' => t('Delete'),
      '#attributes' => _autoadmin_edit_redirect_button_attributes($schema['path'] . '/' . $primary_value . '/delete'),
      '#submit' => FALSE,
      '#weight' => ++$weight,
    );
  }
  $form['cancel'] = array(
    '#value' => t('Cancel'),
    '#type' => 'button',
    '#attributes' => _autoadmin_edit_redirect_button_attributes($schema['path'] . '/list'),
    '#submit' => FALSE,
    '#weight' => ++$weight,
  );
  return $form;
}

/**
 * Fetch data for the form.
 *
 * @param array $schema
 * @param int/FALSE $primary_value
 * @return array
 */
function _autoadmin_edit_form_get_row($schema, $primary_value) {
  if (!$primary_value) {
    return array();
  }
  $query = autoadmin_query_get_query($schema, $primary_value);
  return db_fetch_array(db_query($query['sql'], $query['placeholders']));
}

/**
 * Assemble form from schema fields.
 *
 * @param array $row fetched from db
 * @param array $schema
 * @param int $weight set by referenced
 * @return array
 */
function _autoadmin_edit_build_form($row, $schema, &$weight) {
  $form = array();
  $metadata = autoadmin_get_metadata();
  foreach ($schema['fields'] as $field_key => $field) {
    if (!in_array($field_key, $metadata)) {
      $form[$field_key] = _autoadmin_edit_build_field($schema, $field, $row, &$weight);
    }
  }
  return $form;
}

function _autoadmin_edit_build_field($schema, $field, $row, &$weight) {
  $callback = autoadmin_get_callback_function('_autoadmin_edit_field_', $schema, $field);
  $form_field = call_user_func($callback, $row, $field, $schema, $weight);
  // Overwrite with form settings from hook_autoadmin().
  if (!empty($field['#form'])) {
    $form_field = array_merge($form_field, $field['#form']);
  }
  ++$weight;
  return $form_field;
}

/**
 * Updates/inserts row.
 *
 * @todo Break into smaller functions.
 * @param array $form
 * @param array $form_state
 */
function autoadmin_edit_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $form_state['values']['pk'] = NULL;
  $data = array();
  foreach ($values['schema']['fields'] as $field['key'] => $field) {
    $data[$field['key']] = $values[$field['key']];
  }
  $pk_name = $values['schema']['primary key'][0];
  $text_vars = array(
    '!title' => strtolower($values['schema']['title']),
  );
  if (empty($values[$pk_name])) {
    unset($data[$pk_name]);
    $status = drupal_write_record($values['schema']['table'], $data);
    if ($status) {
      $text_vars['!pk'] = $data[$pk_name];
      $form_state['values']['pk'] = $data[$pk_name];
      drupal_set_message(t('A new !title with id !pk was created.', $text_vars));
    }
    else {
      drupal_set_message(t('Failed to create a new !title.', $text_vars), 'error');
    }
  }
  else {
    if (array_key_exists('modified', $data)) { 
      //if there is the 'modified' audit-purpose field 
      // then put the current time
      // (isset function is not used because it returns false if the value is null)
      $data['modified'] = 'now()';
    }
    $status = drupal_write_record($values['schema']['table'], $data, $pk_name);
    if ($status) {
      $text_vars['!pk'] = $data[$pk_name];
      $form_state['values']['pk'] = $data[$pk_name];
      drupal_set_message(t('Updated !title with id !pk.', $text_vars));
    }
    else {
      drupal_set_message(t('Failed to update !title.', $text_vars), 'error');
    }
  }
  $form_state['redirect'] = $values['schema']['path'] . '/list';
}

/**
 * Returns appropriate value for the form field.
 *
 * @param array $row db row being edited
 * @param array $field field from schema/hook_autoadmin()
 * @param array $schema current schema
 * @param array $default default to this value if not set'
 *
 * @return mixed
 */
function _autoadmin_edit_field_get_value($row, $field, $schema, $default = '') {
  if (isset($row[$field['key']])) {
    return $row[$field['key']];
  }
  if (autoadmin_session_get_field_param($schema, $field)) {
    return autoadmin_session_get_field_param($schema, $field);
  }
  return $default;
}

/**
 * Creates onclick javascript for redirect buttons.
 * 
 * @param string $path
 * @return array
 */
function _autoadmin_edit_redirect_button_attributes($path) {
  return array('onclick' => "window.location='". base_path() . $path . "'; return false;");
}

/**
 * Form field generators. Each function maps to a type of field in the schema.
 *
 * @param array $row
 *   The row being edited.
 * @param array $field
 *   The field from schema/hook_autoadmin().
 * @param array $schema
 *   Current schema.
 * @param int $weight
 * @return array
 *   Form item.
 */

function _autoadmin_edit_field_primary_key($row, $field, $schema, $weight) {
  return array(
    '#type' => 'value',
    '#value' => _autoadmin_edit_field_get_value($row, $field, $schema, FALSE),
  );
}

function _autoadmin_edit_field_serial($row, $field, $schema, $weight) {
  autoadmin_int_field_lengths($field, $size, $maxlength);
  return array(
    '#type' => 'textfield',
    '#title' => $field['title'],
    '#description' => !empty($field['description']) ? $field['description'] : '',
    '#default_value' => _autoadmin_edit_field_get_value($row, $field, $schema),
    '#size' => $size,
    '#maxlength' => $maxlength,
    '#required' => TRUE,
    '#weight' => $weight,
    '#element_validate' => array('autoadmin_validate_int'),
  );
}

function _autoadmin_edit_field_int($row, $field, $schema, $weight) {
  autoadmin_int_field_lengths($field, $size, $maxlength);
  return array(
    '#type' => 'textfield',
    '#title' => $field['title'],
    '#description' => !empty($field['description']) ? $field['description'] : '',
    '#default_value' => _autoadmin_edit_field_get_value($row, $field, $schema),
    '#size' => $size,
    '#maxlength' => $maxlength,
    '#required' => TRUE,
    '#weight' => $weight,
    '#element_validate' => array('autoadmin_validate_int'),
  );
}

function _autoadmin_edit_field_varchar($row, $field, $schema, $weight) {
  return array(
    '#type' => 'textfield',
    '#title' => $field['title'],
    '#description' => !empty($field['description']) ? $field['description'] : '',
    '#default_value' => _autoadmin_edit_field_get_value($row, $field, $schema),
    '#size' => ($field['length'] > AUTOADMIN_EDIT_VARCHAR_MAX_SIZE) ? AUTOADMIN_EDIT_VARCHAR_MAX_SIZE : $field['length'],
    '#maxlength' => $field['length'],
    '#required' => TRUE,
    '#weight' => $weight,
  );
}

function _autoadmin_edit_field_text($row, $field, $schema, $weight) {
  return array(
    '#type' => 'textarea',
    '#title' => $field['title'],
    '#description' => !empty($field['description']) ? $field['description'] : '',
    '#default_value' => _autoadmin_edit_field_get_value($row, $field, $schema),
    '#required' => TRUE,
    '#weight' => $weight,
  );
}

function _autoadmin_edit_field_bool($row, $field, $schema, $weight) {
  return array(
    '#type' => 'checkbox',
    '#title' => $field['title'],
    '#description' => !empty($field['description']) ? $field['description'] : '',
    '#default_value' => _autoadmin_edit_field_get_value($row, $field, $schema),
    '#required' => TRUE,
    '#weight' => $weight,
  );
}

function _autoadmin_edit_field_weight($row, $field, $schema, $weight) {
  return array(
    '#type' => 'weight',
    '#title' => t('Weight'),
    '#default_value' => _autoadmin_edit_field_get_value($row, $field, $schema, 0),
    '#delta' => 50,
    '#description' => (!empty($field['description'])) ?
      $field['description'] :
      t('The heavier items will sink and the lighter items will be positioned nearer the top.'),
    '#weight' => $weight,
  );
}

function _autoadmin_edit_field_has_one($row, $field, $schema, $weight) {
  $options = autoadmin_db_fetch_options($schema, $field);
  return array(
    '#type' => 'select',
    '#title' => $field['title'],
    '#default_value' => _autoadmin_edit_field_get_value($row, $field, $schema, 0, $options),
    '#options' => $options,
    '#description' => !empty($field['description']) ? $field['description'] : '',
  );
}

function _autoadmin_edit_field_datetime($row, $field, $schema, $weight) {
  return array(
    '#type' => 'date_popup',
    '#title' => $field['title'],
    '#description' => !empty($field['description']) ? $field['description'] : '',
    '#default_value' => _autoadmin_edit_field_get_value($row, $field, $schema),
//    '#size' => ($field['length'] > AUTOADMIN_EDIT_VARCHAR_MAX_SIZE) ? AUTOADMIN_EDIT_VARCHAR_MAX_SIZE : $field['length'],
//    '#maxlength' => $field['length'],
    '#required' => TRUE,
    '#weight' => $weight,
//    '#date_format' => 'Y-m-d',
    '#date_year_range' => '-100:+20',
  );
}

function _autoadmin_edit_field_date($row, $field, $schema, $weight) {
  return array(
    '#type' => 'date_popup',
    '#title' => $field['title'],
    '#description' => !empty($field['description']) ? $field['description'] : '',
    '#default_value' => _autoadmin_edit_field_get_value($row, $field, $schema),
//    '#size' => ($field['length'] > AUTOADMIN_EDIT_VARCHAR_MAX_SIZE) ? AUTOADMIN_EDIT_VARCHAR_MAX_SIZE : $field['length'],
//    '#maxlength' => $field['length'],
    '#required' => TRUE,
    '#weight' => $weight,
//    '#date_format' => 'Y-m-d',
    '#date_year_range' => '-100:+20',
  );
}

function _autoadmin_edit_field_numeric($row, $field, $schema, $weight) {
  autoadmin_numeric_field_lengths($field, $size, $maxlength);
  return array(
    '#type' => 'textfield',
    '#title' => $field['title'],
    '#description' => !empty($field['description']) ? $field['description'] : '',
    '#default_value' => _autoadmin_edit_field_get_value($row, $field, $schema),
    '#size' => $size,
    '#maxlength' => $maxlength,
    '#required' => TRUE,
    '#weight' => $weight,
    '#element_validate' => array('autoadmin_validate_numeric'),
  );
}

/* end form field generators */
