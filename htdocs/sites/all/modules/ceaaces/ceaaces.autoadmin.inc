<?php
// $Id

/**
 * @file
 * Auto Admin schemas for ceaaces module.
 *
 * @tables {ev_tipo_ies}, {ev_ies}, {ev_variable}, {ev_valor}, {ev_tipo_dato}, {ev_valor_posible}, {ev_validacion}, {ev_formula}, {ev_indicador}, {ev_criterio}, {ev_hoja_calculo}, {ev_lugar}, {ev_parroquia}, {ev_canton}, {ev_provincia}, {ev_pais}, {ev_persona}, {ev_evaluador}, {ev_carrera}, {ev_alumno}, {ev_titulo}, {ev_cargo}, {ev_categoria}, {ev_relacion_trabajo}, {ev_profesor}, {ev_mec}, {ev_modalidad_carrera}, {ev_subarea_unesco}, {ev_unidad_academica}
 */

/**
 * Implementation of hook_autoadmin_schema().
 */
function ceaaces_autoadmin_schema() {
  // Auto Admin schema for {ev_tipo_ies} table
  $autoadmin_schema['ev_tipo_ies'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_tipo_ies',
    'title' => t('Ev Tipo Ies'),
    'title_plural' => t('Ev Tipo y'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
    ),
    'relations' => array(
      'ev_criterio' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_tipo_ies_id',
      ),
      'ev_evaluador' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_tipo_ies_id',
      ),
      'ev_hoja_calculo' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_tipo_ies_id',
      ),
      'ev_ies' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_tipo_ies_id',
      ),
      'ev_variable' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_tipo_ies_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_ies} table
  $autoadmin_schema['ev_ies'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_ies',
    'title' => t('Ev Ies'),
    'title_plural' => t('Ev y'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'ev_tipo_ies_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Tipo Ies'),
        'title_plural' => t('Ev Tipo y'),
      ),
      'codigo' => array(
        'autoadmin_type' => 'text',
        'title' => t('Codigo'),
        'title_plural' => t('Codigos'),
      ),
      'observaciones' => array(
        'autoadmin_type' => 'text',
        'title' => t('Observaciones'),
        'title_plural' => t('Observaciones'),
      ),
      'ev_lugar_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Lugar'),
        'title_plural' => t('Ev Lugars'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
    ),
    'relations' => array(
      'ev_tipo_ies' => array(
        'type' => 'has_one',
        'local_key' => 'ev_tipo_ies_id',
        'foreign_key' => 'id',
      ),
      'ev_lugar' => array(
        'type' => 'has_one',
        'local_key' => 'ev_lugar_id',
        'foreign_key' => 'id',
      ),
      'ev_carrera' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_ies_id',
      ),
      'ev_mec' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_ies_id',
      ),
      'ev_profesor' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_ies_id',
      ),
      'ev_unidad_academica' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_ies_id',
      ),
      'ev_valor' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_ies_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_variable} table
  $autoadmin_schema['ev_variable'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_variable',
    'title' => t('Ev Variable'),
    'title_plural' => t('Ev Variables'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'ev_tipo_dato_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Tipo Dato'),
        'title_plural' => t('Ev Tipo Datos'),
      ),
      'descripcion' => array(
        'autoadmin_type' => 'text',
        'title' => t('Descripcion'),
        'title_plural' => t('Descripcions'),
      ),
      'ev_tipo_ies_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Tipo Ies'),
        'title_plural' => t('Ev Tipo y'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'borrado' => array(
        'autoadmin_type' => 'int',
        'title' => t('Borrado'),
        'title_plural' => t('Borrados'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
      'coord' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Coord'),
        'title_plural' => t('Coords'),
      ),
      'ev_hoja_calculo_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Hoja Calculo'),
        'title_plural' => t('Ev Hoja Calculos'),
      ),
    ),
    'relations' => array(
      'ev_tipo_dato' => array(
        'type' => 'has_one',
        'local_key' => 'ev_tipo_dato_id',
        'foreign_key' => 'id',
      ),
      'ev_tipo_ies' => array(
        'type' => 'has_one',
        'local_key' => 'ev_tipo_ies_id',
        'foreign_key' => 'id',
      ),
      'ev_hoja_calculo' => array(
        'type' => 'has_one',
        'local_key' => 'ev_hoja_calculo_id',
        'foreign_key' => 'id',
      ),
      'ev_formula' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_variable_id',
      ),
      'ev_validacion' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_variable_id',
      ),
      'ev_valor' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_variable_id',
      ),
      'ev_valor_posible' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_variable_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_valor} table
  $autoadmin_schema['ev_valor'] = array(
    'alias' => 'id',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_valor',
    'title' => t('Ev Valor'),
    'title_plural' => t('Ev Valors'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'ev_variable_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Variable'),
        'title_plural' => t('Ev Variables'),
      ),
      'ev_ies_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Ies'),
        'title_plural' => t('Ev y'),
      ),
      'dato' => array(
        'autoadmin_type' => 'text',
        'title' => t('Dato'),
        'title_plural' => t('Datos'),
      ),
      'fecha_creacion' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Fecha Creacion'),
        'title_plural' => t('Fecha Creacions'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'borrado' => array(
        'autoadmin_type' => 'int',
        'title' => t('Borrado'),
        'title_plural' => t('Borrados'),
      ),
      'fuente' => array(
        'autoadmin_type' => 'text',
        'title' => t('Fuente'),
        'title_plural' => t('Fuentes'),
      ),
      'grupo' => array(
        'autoadmin_type' => 'text',
        'title' => t('Grupo'),
        'title_plural' => t('Grupos'),
      ),
      'ev_evaluador_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Evaluador'),
        'title_plural' => t('Ev Evaluadors'),
      ),
    ),
    'relations' => array(
      'ev_variable' => array(
        'type' => 'has_one',
        'local_key' => 'ev_variable_id',
        'foreign_key' => 'id',
      ),
      'ev_ies' => array(
        'type' => 'has_one',
        'local_key' => 'ev_ies_id',
        'foreign_key' => 'id',
      ),
      'ev_evaluador' => array(
        'type' => 'has_one',
        'local_key' => 'ev_evaluador_id',
        'foreign_key' => 'id',
      ),
    ),
  );

  // Auto Admin schema for {ev_tipo_dato} table
  $autoadmin_schema['ev_tipo_dato'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_tipo_dato',
    'title' => t('Ev Tipo Dato'),
    'title_plural' => t('Ev Tipo Datos'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
    ),
    'relations' => array(
      'ev_validacion' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_tipo_dato_id',
      ),
      'ev_variable' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_tipo_dato_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_valor_posible} table
  $autoadmin_schema['ev_valor_posible'] = array(
    'alias' => 'id',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_valor_posible',
    'title' => t('Ev Valor Posible'),
    'title_plural' => t('Ev Valor Posibles'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'ev_variable_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Variable'),
        'title_plural' => t('Ev Variables'),
      ),
      'dato' => array(
        'autoadmin_type' => 'text',
        'title' => t('Dato'),
        'title_plural' => t('Datos'),
      ),
      'descripcion' => array(
        'autoadmin_type' => 'text',
        'title' => t('Descripcion'),
        'title_plural' => t('Descripcions'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
    ),
    'relations' => array(
      'ev_variable' => array(
        'type' => 'has_one',
        'local_key' => 'ev_variable_id',
        'foreign_key' => 'id',
      ),
    ),
  );

  // Auto Admin schema for {ev_validacion} table
  $autoadmin_schema['ev_validacion'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_validacion',
    'title' => t('Ev Validacion'),
    'title_plural' => t('Ev Validacions'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'regexp' => array(
        'autoadmin_type' => 'text',
        'title' => t('Regexp'),
        'title_plural' => t('Regexps'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'ev_tipo_dato_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Tipo Dato'),
        'title_plural' => t('Ev Tipo Datos'),
      ),
      'ev_variable_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Variable'),
        'title_plural' => t('Ev Variables'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
    ),
    'relations' => array(
      'ev_tipo_dato' => array(
        'type' => 'has_one',
        'local_key' => 'ev_tipo_dato_id',
        'foreign_key' => 'id',
      ),
      'ev_variable' => array(
        'type' => 'has_one',
        'local_key' => 'ev_variable_id',
        'foreign_key' => 'id',
      ),
    ),
  );

  // Auto Admin schema for {ev_formula} table
  $autoadmin_schema['ev_formula'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_formula',
    'title' => t('Ev Formula'),
    'title_plural' => t('Ev Formulas'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'ev_indicador_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Indicador'),
        'title_plural' => t('Ev Indicadors'),
      ),
      'ev_variable_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Variable'),
        'title_plural' => t('Ev Variables'),
      ),
      'orden' => array(
        'autoadmin_type' => 'int',
        'title' => t('Orden'),
        'title_plural' => t('Ordens'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'postfijo' => array(
        'autoadmin_type' => 'text',
        'title' => t('Postfijo'),
        'title_plural' => t('Postfijos'),
      ),
      'prefijo' => array(
        'autoadmin_type' => 'text',
        'title' => t('Prefijo'),
        'title_plural' => t('Prefijos'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
    ),
    'relations' => array(
      'ev_indicador' => array(
        'type' => 'has_one',
        'local_key' => 'ev_indicador_id',
        'foreign_key' => 'id',
      ),
      'ev_variable' => array(
        'type' => 'has_one',
        'local_key' => 'ev_variable_id',
        'foreign_key' => 'id',
      ),
    ),
  );

  // Auto Admin schema for {ev_indicador} table
  $autoadmin_schema['ev_indicador'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_indicador',
    'title' => t('Ev Indicador'),
    'title_plural' => t('Ev Indicadors'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'ev_criterio_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Criterio'),
        'title_plural' => t('Ev Criterios'),
      ),
      'codigo' => array(
        'autoadmin_type' => 'text',
        'title' => t('Codigo'),
        'title_plural' => t('Codigos'),
      ),
      'descripcion' => array(
        'autoadmin_type' => 'text',
        'title' => t('Descripcion'),
        'title_plural' => t('Descripcions'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'orden' => array(
        'autoadmin_type' => 'int',
        'title' => t('Orden'),
        'title_plural' => t('Ordens'),
      ),
      'borrado' => array(
        'autoadmin_type' => 'int',
        'title' => t('Borrado'),
        'title_plural' => t('Borrados'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
    ),
    'relations' => array(
      'ev_criterio' => array(
        'type' => 'has_one',
        'local_key' => 'ev_criterio_id',
        'foreign_key' => 'id',
      ),
      'ev_formula' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_indicador_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_criterio} table
  $autoadmin_schema['ev_criterio'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_criterio',
    'title' => t('Ev Criterio'),
    'title_plural' => t('Ev Criterios'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'ev_criterio_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Criterio'),
        'title_plural' => t('Ev Criterios'),
      ),
      'codigo' => array(
        'autoadmin_type' => 'text',
        'title' => t('Codigo'),
        'title_plural' => t('Codigos'),
      ),
      'descripcion' => array(
        'autoadmin_type' => 'text',
        'title' => t('Descripcion'),
        'title_plural' => t('Descripcions'),
      ),
      'ev_tipo_ies_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Tipo Ies'),
        'title_plural' => t('Ev Tipo y'),
      ),
      'orden' => array(
        'autoadmin_type' => 'int',
        'title' => t('Orden'),
        'title_plural' => t('Ordens'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
    ),
    'relations' => array(
      'ev_criterio' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_criterio_id',
      ),
      'ev_tipo_ies' => array(
        'type' => 'has_one',
        'local_key' => 'ev_tipo_ies_id',
        'foreign_key' => 'id',
      ),
      'ev_indicador' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_criterio_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_hoja_calculo} table
  $autoadmin_schema['ev_hoja_calculo'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_hoja_calculo',
    'title' => t('Ev Hoja Calculo'),
    'title_plural' => t('Ev Hoja Calculos'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
      'notes' => array(
        'autoadmin_type' => 'text',
        'title' => t('Notes'),
        'title_plural' => t('Notes'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'ev_tipo_ies_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Tipo Ies'),
        'title_plural' => t('Ev Tipo y'),
      ),
    ),
    'relations' => array(
      'ev_tipo_ies' => array(
        'type' => 'has_one',
        'local_key' => 'ev_tipo_ies_id',
        'foreign_key' => 'id',
      ),
      'ev_variable' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_hoja_calculo_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_lugar} table
  $autoadmin_schema['ev_lugar'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_lugar',
    'title' => t('Ev Lugar'),
    'title_plural' => t('Ev Lugars'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'ev_parroquia_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Parroquia'),
        'title_plural' => t('Ev Parroquias'),
      ),
      'descripcion' => array(
        'autoadmin_type' => 'text',
        'title' => t('Descripcion'),
        'title_plural' => t('Descripcions'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
    ),
    'relations' => array(
      'ev_parroquia' => array(
        'type' => 'has_one',
        'local_key' => 'ev_parroquia_id',
        'foreign_key' => 'id',
      ),
      'ev_ies' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_lugar_id',
      ),
      'ev_persona' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_lugar_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_parroquia} table
  $autoadmin_schema['ev_parroquia'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_parroquia',
    'title' => t('Ev Parroquia'),
    'title_plural' => t('Ev Parroquias'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'ev_canton_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Canton'),
        'title_plural' => t('Ev Cantons'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
    ),
    'relations' => array(
      'ev_canton' => array(
        'type' => 'has_one',
        'local_key' => 'ev_canton_id',
        'foreign_key' => 'id',
      ),
      'ev_lugar' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_parroquia_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_canton} table
  $autoadmin_schema['ev_canton'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_canton',
    'title' => t('Ev Canton'),
    'title_plural' => t('Ev Cantons'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'ev_provincia_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Provincia'),
        'title_plural' => t('Ev Provincias'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
    ),
    'relations' => array(
      'ev_provincia' => array(
        'type' => 'has_one',
        'local_key' => 'ev_provincia_id',
        'foreign_key' => 'id',
      ),
      'ev_parroquia' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_canton_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_provincia} table
  $autoadmin_schema['ev_provincia'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_provincia',
    'title' => t('Ev Provincia'),
    'title_plural' => t('Ev Provincias'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'ev_pais_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Pais'),
        'title_plural' => t('Ev Pais'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
    ),
    'relations' => array(
      'ev_pais' => array(
        'type' => 'has_one',
        'local_key' => 'ev_pais_id',
        'foreign_key' => 'id',
      ),
      'ev_canton' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_provincia_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_pais} table
  $autoadmin_schema['ev_pais'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_pais',
    'title' => t('Ev Pais'),
    'title_plural' => t('Ev Pais'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'nacionalidad' => array(
        'autoadmin_type' => 'text',
        'title' => t('Nacionalidad'),
        'title_plural' => t('Nacionalidads'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
    ),
    'relations' => array(
      'ev_carrera' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_pais_id',
      ),
      'ev_persona' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_pais_id',
      ),
      'ev_provincia' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_pais_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_persona} table
  $autoadmin_schema['ev_persona'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_persona',
    'title' => t('Ev Persona'),
    'title_plural' => t('Ev Personas'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'prefijo' => array(
        'autoadmin_type' => 'text',
        'title' => t('Prefijo'),
        'title_plural' => t('Prefijos'),
      ),
      'nombres' => array(
        'autoadmin_type' => 'text',
        'title' => t('Nombres'),
        'title_plural' => t('Nombres'),
      ),
      'apellido_paterno' => array(
        'autoadmin_type' => 'text',
        'title' => t('Apellido Paterno'),
        'title_plural' => t('Apellido Paternos'),
      ),
      'apellido_materno' => array(
        'autoadmin_type' => 'text',
        'title' => t('Apellido Materno'),
        'title_plural' => t('Apellido Maternos'),
      ),
      'subfijo' => array(
        'autoadmin_type' => 'text',
        'title' => t('Subfijo'),
        'title_plural' => t('Subfijos'),
      ),
      'cedula' => array(
        'autoadmin_type' => 'text',
        'title' => t('Cedula'),
        'title_plural' => t('Cedulas'),
      ),
      'telefono_fijo' => array(
        'autoadmin_type' => 'text',
        'title' => t('Telefono Fijo'),
        'title_plural' => t('Telefono Fijos'),
      ),
      'telefono_movil' => array(
        'autoadmin_type' => 'text',
        'title' => t('Telefono Movil'),
        'title_plural' => t('Telefono Movils'),
      ),
      'direccion_domiciliaria' => array(
        'autoadmin_type' => 'text',
        'title' => t('Direccion Domiciliaria'),
        'title_plural' => t('Direccion Domiciliarias'),
      ),
      'email' => array(
        'autoadmin_type' => 'text',
        'title' => t('Email'),
        'title_plural' => t('Emails'),
      ),
      'fecha_nacimiento' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Fecha Nacimiento'),
        'title_plural' => t('Fecha Nacimientos'),
      ),
      'ev_lugar_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Lugar'),
        'title_plural' => t('Ev Lugars'),
      ),
      'es_mujer' => array(
        'autoadmin_type' => 'int',
        'title' => t('Es Mujer'),
        'title_plural' => t('Es Mujers'),
      ),
      'ev_pais_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Pais'),
        'title_plural' => t('Ev Pais'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
    ),
    'relations' => array(
      'ev_lugar' => array(
        'type' => 'has_one',
        'local_key' => 'ev_lugar_id',
        'foreign_key' => 'id',
      ),
      'ev_pais' => array(
        'type' => 'has_one',
        'local_key' => 'ev_pais_id',
        'foreign_key' => 'id',
      ),
      'ev_alumno' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_persona_id',
      ),
      'ev_evaluador' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_persona_id',
      ),
      'ev_profesor' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_persona_id',
      ),
      'ev_titulo' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_persona_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_evaluador} table
  $autoadmin_schema['ev_evaluador'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_evaluador',
    'title' => t('Ev Evaluador'),
    'title_plural' => t('Ev Evaluadors'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
      'notes' => array(
        'autoadmin_type' => 'text',
        'title' => t('Notes'),
        'title_plural' => t('Notes'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'ev_tipo_ies_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Tipo Ies'),
        'title_plural' => t('Ev Tipo y'),
      ),
      'ev_persona_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Persona'),
        'title_plural' => t('Ev Personas'),
      ),
    ),
    'relations' => array(
      'ev_tipo_ies' => array(
        'type' => 'has_one',
        'local_key' => 'ev_tipo_ies_id',
        'foreign_key' => 'id',
      ),
      'ev_persona' => array(
        'type' => 'has_one',
        'local_key' => 'ev_persona_id',
        'foreign_key' => 'id',
      ),
      'ev_valor' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_evaluador_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_carrera} table
  $autoadmin_schema['ev_carrera'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_carrera',
    'title' => t('Ev Carrera'),
    'title_plural' => t('Ev Carreras'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'ev_subarea_unesco_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Subarea Unesco'),
        'title_plural' => t('Ev Subarea Unescos'),
      ),
      'nivel' => array(
        'autoadmin_type' => 'int',
        'title' => t('Nivel'),
        'title_plural' => t('Nivels'),
      ),
      'ev_ies_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Ies'),
        'title_plural' => t('Ev y'),
      ),
      'ev_pais_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Pais'),
        'title_plural' => t('Ev Pais'),
      ),
      'ev_modalidad_carrera_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Modalidad Carrera'),
        'title_plural' => t('Ev Modalidad Carreras'),
      ),
      'num_creditos' => array(
        'autoadmin_type' => 'int',
        'title' => t('Num Creditos'),
        'title_plural' => t('Num Creditos'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
    ),
    'relations' => array(
      'ev_subarea_unesco' => array(
        'type' => 'has_one',
        'local_key' => 'ev_subarea_unesco_id',
        'foreign_key' => 'id',
      ),
      'ev_ies' => array(
        'type' => 'has_one',
        'local_key' => 'ev_ies_id',
        'foreign_key' => 'id',
      ),
      'ev_pais' => array(
        'type' => 'has_one',
        'local_key' => 'ev_pais_id',
        'foreign_key' => 'id',
      ),
      'ev_modalidad_carrera' => array(
        'type' => 'has_one',
        'local_key' => 'ev_modalidad_carrera_id',
        'foreign_key' => 'id',
      ),
      'ev_alumno' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_carrera_id',
      ),
      'ev_titulo' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_carrera_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_alumno} table
  $autoadmin_schema['ev_alumno'] = array(
    'alias' => 'id',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_alumno',
    'title' => t('Ev Alumno'),
    'title_plural' => t('Ev Alumnos'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'ev_persona_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Persona'),
        'title_plural' => t('Ev Personas'),
      ),
      'ev_carrera_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Carrera'),
        'title_plural' => t('Ev Carreras'),
      ),
      'num_matricula' => array(
        'autoadmin_type' => 'text',
        'title' => t('Num Matricula'),
        'title_plural' => t('Num Matriculas'),
      ),
      'observaciones' => array(
        'autoadmin_type' => 'text',
        'title' => t('Observaciones'),
        'title_plural' => t('Observaciones'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
    ),
    'relations' => array(
      'ev_persona' => array(
        'type' => 'has_one',
        'local_key' => 'ev_persona_id',
        'foreign_key' => 'id',
      ),
      'ev_carrera' => array(
        'type' => 'has_one',
        'local_key' => 'ev_carrera_id',
        'foreign_key' => 'id',
      ),
    ),
  );

  // Auto Admin schema for {ev_titulo} table
  $autoadmin_schema['ev_titulo'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_titulo',
    'title' => t('Ev Titulo'),
    'title_plural' => t('Ev Titulos'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'descripcion' => array(
        'autoadmin_type' => 'text',
        'title' => t('Descripcion'),
        'title_plural' => t('Descripcions'),
      ),
      'registro_senescyt' => array(
        'autoadmin_type' => 'text',
        'title' => t('Registro Senescyt'),
        'title_plural' => t('Registro Senescyts'),
      ),
      'ev_carrera_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Carrera'),
        'title_plural' => t('Ev Carreras'),
      ),
      'ev_persona_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Persona'),
        'title_plural' => t('Ev Personas'),
      ),
      'fecha_inicio_estudios' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Fecha Inicio Estudios'),
        'title_plural' => t('Fecha Inicio Estudios'),
      ),
      'fecha_fin_estudios' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Fecha Fin Estudios'),
        'title_plural' => t('Fecha Fin Estudios'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
    ),
    'relations' => array(
      'ev_carrera' => array(
        'type' => 'has_one',
        'local_key' => 'ev_carrera_id',
        'foreign_key' => 'id',
      ),
      'ev_persona' => array(
        'type' => 'has_one',
        'local_key' => 'ev_persona_id',
        'foreign_key' => 'id',
      ),
    ),
  );

  // Auto Admin schema for {ev_cargo} table
  $autoadmin_schema['ev_cargo'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_cargo',
    'title' => t('Ev Cargo'),
    'title_plural' => t('Ev Cargos'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
    ),
    'relations' => array(
      'ev_profesor' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_cargo_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_categoria} table
  $autoadmin_schema['ev_categoria'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_categoria',
    'title' => t('Ev Categoria'),
    'title_plural' => t('Ev Categorias'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
    ),
    'relations' => array(
      'ev_profesor' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_categoria_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_relacion_trabajo} table
  $autoadmin_schema['ev_relacion_trabajo'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_relacion_trabajo',
    'title' => t('Ev Relacion Trabajo'),
    'title_plural' => t('Ev Relacion Trabajos'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
    ),
    'relations' => array(
      'ev_profesor' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_relacion_trabajo_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_profesor} table
  $autoadmin_schema['ev_profesor'] = array(
    'alias' => 'id',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_profesor',
    'title' => t('Ev Profesor'),
    'title_plural' => t('Ev Profesors'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'ev_persona_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Persona'),
        'title_plural' => t('Ev Personas'),
      ),
      'ev_ies_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Ies'),
        'title_plural' => t('Ev y'),
      ),
      'fecha_ingreso' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Fecha Ingreso'),
        'title_plural' => t('Fecha Ingresos'),
      ),
      'ev_relacion_trabajo_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Relacion Trabajo'),
        'title_plural' => t('Ev Relacion Trabajos'),
      ),
      'ev_cargo_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Cargo'),
        'title_plural' => t('Ev Cargos'),
      ),
      'ev_categoria_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Categoria'),
        'title_plural' => t('Ev Categorias'),
      ),
      'sueldo' => array(
        'autoadmin_type' => 'int',
        'title' => t('Sueldo'),
        'title_plural' => t('Sueldos'),
      ),
      'dedicacion' => array(
        'autoadmin_type' => 'int',
        'title' => t('Dedicacion'),
        'title_plural' => t('Dedicacions'),
      ),
      'ev_unidad_academica_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Unidad Academica'),
        'title_plural' => t('Ev Unidad Academicas'),
      ),
      'email' => array(
        'autoadmin_type' => 'text',
        'title' => t('Email'),
        'title_plural' => t('Emails'),
      ),
      'observaciones' => array(
        'autoadmin_type' => 'text',
        'title' => t('Observaciones'),
        'title_plural' => t('Observaciones'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
    ),
    'relations' => array(
      'ev_persona' => array(
        'type' => 'has_one',
        'local_key' => 'ev_persona_id',
        'foreign_key' => 'id',
      ),
      'ev_ies' => array(
        'type' => 'has_one',
        'local_key' => 'ev_ies_id',
        'foreign_key' => 'id',
      ),
      'ev_relacion_trabajo' => array(
        'type' => 'has_one',
        'local_key' => 'ev_relacion_trabajo_id',
        'foreign_key' => 'id',
      ),
      'ev_cargo' => array(
        'type' => 'has_one',
        'local_key' => 'ev_cargo_id',
        'foreign_key' => 'id',
      ),
      'ev_categoria' => array(
        'type' => 'has_one',
        'local_key' => 'ev_categoria_id',
        'foreign_key' => 'id',
      ),
      'ev_unidad_academica' => array(
        'type' => 'has_one',
        'local_key' => 'ev_unidad_academica_id',
        'foreign_key' => 'id',
      ),
    ),
  );

  // Auto Admin schema for {ev_mec} table
  $autoadmin_schema['ev_mec'] = array(
    'alias' => 'id',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_mec',
    'title' => t('Ev Mec'),
    'title_plural' => t('Ev Mecs'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'ev_ies_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Ies'),
        'title_plural' => t('Ev y'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
    ),
    'relations' => array(
      'ev_ies' => array(
        'type' => 'has_one',
        'local_key' => 'ev_ies_id',
        'foreign_key' => 'id',
      ),
    ),
  );

  // Auto Admin schema for {ev_modalidad_carrera} table
  $autoadmin_schema['ev_modalidad_carrera'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_modalidad_carrera',
    'title' => t('Ev Modalidad Carrera'),
    'title_plural' => t('Ev Modalidad Carreras'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
    ),
    'relations' => array(
      'ev_carrera' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_modalidad_carrera_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_subarea_unesco} table
  $autoadmin_schema['ev_subarea_unesco'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_subarea_unesco',
    'title' => t('Ev Subarea Unesco'),
    'title_plural' => t('Ev Subarea Unescos'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
    ),
    'relations' => array(
      'ev_carrera' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_subarea_unesco_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_unidad_academica} table
  $autoadmin_schema['ev_unidad_academica'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_unidad_academica',
    'title' => t('Ev Unidad Academica'),
    'title_plural' => t('Ev Unidad Academicas'),
    'fields' => array(
      'id' => array(
        'autoadmin_type' => 'primary_key',
        'title' => t('Id'),
        'title_plural' => t('Ids'),
      ),
      'ev_ies_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Ies'),
        'title_plural' => t('Ev y'),
      ),
      'created' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Created'),
        'title_plural' => t('Createds'),
      ),
      'modified' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Modified'),
        'title_plural' => t('Modifieds'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
    ),
    'relations' => array(
      'ev_ies' => array(
        'type' => 'has_one',
        'local_key' => 'ev_ies_id',
        'foreign_key' => 'id',
      ),
      'ev_profesor' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_unidad_academica_id',
      ),
    ),
  );

  return $autoadmin_schema;
}