<?php
// $Id

/**
 * @file
 * Auto Admin schemas for ceaaces module.
 *
 * @tables {ev_hoja_calculo}, {ev_criterio}, {ev_indicador}, {ev_formula}, {ev_tipo_dato}, {ev_valor}, {ev_tipo_ies}, {ev_provincia}, {ev_canton}, {ev_valor_posible}, {ev_variable}, {ev_validacion}, {ev_relacion_trabajo}, {ev_cargo}, {ev_profesor}, {ev_categoria}, {ev_estudiante}, {ev_unidad_academica}, {ev_persona}, {ev_lugar}, {ev_parroquia}, {ev_titulo}, {ev_subarea_unesco}, {ev_evaluador}, {ev_pais}, {ev_carrera}, {ev_modalidad_estudio}, {ev_sede}, {ev_nivel_carrera}, {ev_tipo_sede}, {ev_organizacion_malla}, {ev_estado_carrera}, {ev_jornada}, {ev_archivo}, {ev_form_mtn}, {ev_ies}, {ev_tipo_archivo}, {ev_log}, {ev_ies_comentario}, {ev_ies_tipo_comentario}
 */

/**
 * Implementation of hook_autoadmin_schema().
 */
function ceaaces_autoadmin_schema() {
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
      'region' => array(
        'autoadmin_type' => 'int',
        'title' => t('Region'),
        'title_plural' => t('Regions'),
      ),
      'codigo' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Codigo'),
        'title_plural' => t('Codigos'),
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
      'ev_estudiante' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_provincia_id',
      ),
      'ev_form_mtn' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_provincia_id',
      ),
      'ev_persona' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_provincia_id',
      ),
      'ev_sede' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_provincia_id',
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
      'codigo' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Codigo'),
        'title_plural' => t('Codigos'),
      ),
    ),
    'relations' => array(
      'ev_provincia' => array(
        'type' => 'has_one',
        'local_key' => 'ev_provincia_id',
        'foreign_key' => 'id',
      ),
      'ev_estudiante' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_canton_id',
      ),
      'ev_form_mtn' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_canton_id',
      ),
      'ev_parroquia' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_canton_id',
      ),
      'ev_persona' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_canton_id',
      ),
      'ev_sede' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_canton_id',
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

  // Auto Admin schema for {ev_estudiante} table
  $autoadmin_schema['ev_estudiante'] = array(
    'alias' => 'modalidad',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_estudiante',
    'title' => t('Ev Estudiante'),
    'title_plural' => t('Ev Estudiantes'),
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
      'num_cred' => array(
        'autoadmin_type' => 'int',
        'title' => t('Num Cred'),
        'title_plural' => t('Num Creds'),
      ),
      'fecha_inicio_estudios' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Fecha Inicio Estudios'),
        'title_plural' => t('Fecha Inicio Estudios'),
      ),
      'modalidad' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Modalidad'),
        'title_plural' => t('Modalidads'),
      ),
      'nivel' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Nivel'),
        'title_plural' => t('Nivels'),
      ),
      'beneficio_beca_c' => array(
        'autoadmin_type' => 'int',
        'title' => t('Beneficio Beca C'),
        'title_plural' => t('Beneficio Beca Cs'),
      ),
      'beneficio_beca_p' => array(
        'autoadmin_type' => 'int',
        'title' => t('Beneficio Beca P'),
        'title_plural' => t('Beneficio Beca Ps'),
      ),
      'beneficio_ay_finan' => array(
        'autoadmin_type' => 'int',
        'title' => t('Beneficio Ay Finan'),
        'title_plural' => t('Beneficio Ay Finans'),
      ),
      'beneficio_credito_iece' => array(
        'autoadmin_type' => 'int',
        'title' => t('Beneficio Credito Iece'),
        'title_plural' => t('Beneficio Credito Ieces'),
      ),
      'beneficio_credito_ies' => array(
        'autoadmin_type' => 'int',
        'title' => t('Beneficio Credito Ies'),
        'title_plural' => t('Beneficio Credito y'),
      ),
      'pasantias' => array(
        'autoadmin_type' => 'int',
        'title' => t('Pasantias'),
        'title_plural' => t('Pasantias'),
      ),
      'n' => array(
        'autoadmin_type' => 'int',
        'title' => t('N'),
        'title_plural' => t('Ns'),
      ),
      'carrera' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Carrera'),
        'title_plural' => t('Carreras'),
      ),
      'institucion' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Institucion'),
        'title_plural' => t('Institucions'),
      ),
      'cedula' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Cedula'),
        'title_plural' => t('Cedulas'),
      ),
      'provincia' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Provincia'),
        'title_plural' => t('Provincias'),
      ),
      'canton' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Canton'),
        'title_plural' => t('Cantons'),
      ),
      'ev_parroquia_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Parroquia'),
        'title_plural' => t('Ev Parroquias'),
      ),
      'ev_canton_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Canton'),
        'title_plural' => t('Ev Cantons'),
      ),
      'ev_provincia_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Provincia'),
        'title_plural' => t('Ev Provincias'),
      ),
      'ev_ies_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Ies'),
        'title_plural' => t('Ev y'),
      ),
      'sede' => array(
        'autoadmin_type' => 'text',
        'title' => t('Sede'),
        'title_plural' => t('Sedes'),
      ),
      'direccion' => array(
        'autoadmin_type' => 'text',
        'title' => t('Direccion'),
        'title_plural' => t('Direccions'),
      ),
      'lugar' => array(
        'autoadmin_type' => 'text',
        'title' => t('Lugar'),
        'title_plural' => t('Lugars'),
      ),
      'parroquia' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Parroquia'),
        'title_plural' => t('Parroquias'),
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
      'ev_parroquia' => array(
        'type' => 'has_one',
        'local_key' => 'ev_parroquia_id',
        'foreign_key' => 'id',
      ),
      'ev_canton' => array(
        'type' => 'has_one',
        'local_key' => 'ev_canton_id',
        'foreign_key' => 'id',
      ),
      'ev_provincia' => array(
        'type' => 'has_one',
        'local_key' => 'ev_provincia_id',
        'foreign_key' => 'id',
      ),
      'ev_ies' => array(
        'type' => 'has_one',
        'local_key' => 'ev_ies_id',
        'foreign_key' => 'id',
      ),
      'ev_form_mtn' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_estudiante_id',
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
      'fecha_nac' => array(
        'autoadmin_type' => 'datetime',
        'title' => t('Fecha Nac'),
        'title_plural' => t('Fecha Nacs'),
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
      'ev_canton_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Canton'),
        'title_plural' => t('Ev Cantons'),
      ),
      'provincia_nac' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Provincia Nac'),
        'title_plural' => t('Provincia Nacs'),
      ),
      'ev_provincia_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Provincia'),
        'title_plural' => t('Ev Provincias'),
      ),
      'canton_nac' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Canton Nac'),
        'title_plural' => t('Canton Nacs'),
      ),
      'sexo' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Sexo'),
        'title_plural' => t('Sexos'),
      ),
      'nacionalidad' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Nacionalidad'),
        'title_plural' => t('Nacionalidads'),
      ),
    ),
    'relations' => array(
      'ev_pais' => array(
        'type' => 'has_one',
        'local_key' => 'ev_pais_id',
        'foreign_key' => 'id',
      ),
      'ev_canton' => array(
        'type' => 'has_one',
        'local_key' => 'ev_canton_id',
        'foreign_key' => 'id',
      ),
      'ev_provincia' => array(
        'type' => 'has_one',
        'local_key' => 'ev_provincia_id',
        'foreign_key' => 'id',
      ),
      'ev_estudiante' => array(
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
      'codigo' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Codigo'),
        'title_plural' => t('Codigos'),
      ),
    ),
    'relations' => array(
      'ev_canton' => array(
        'type' => 'has_one',
        'local_key' => 'ev_canton_id',
        'foreign_key' => 'id',
      ),
      'ev_estudiante' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_parroquia_id',
      ),
      'ev_form_mtn' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_parroquia_id',
      ),
      'ev_ies' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_parroquia_id',
      ),
      'ev_lugar' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_parroquia_id',
      ),
      'ev_sede' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_parroquia_id',
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
      'area_unesco' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Area Unesco'),
        'title_plural' => t('Area Unescos'),
      ),
      'codigo' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Codigo'),
        'title_plural' => t('Codigos'),
      ),
      'descripcion' => array(
        'autoadmin_type' => 'text',
        'title' => t('Descripcion'),
        'title_plural' => t('Descripcions'),
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
      'ev_ies_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Ies'),
        'title_plural' => t('Ev y'),
      ),
      'ev_modalidad_estudio_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Modalidad Estudio'),
        'title_plural' => t('Ev Modalidad Estudios'),
      ),
      'num_creditos_st' => array(
        'autoadmin_type' => 'int',
        'title' => t('Num Creditos St'),
        'title_plural' => t('Num Creditos Sts'),
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
      'ev_nivel_carrera_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Nivel Carrera'),
        'title_plural' => t('Ev Nivel Carreras'),
      ),
      'ev_organizacion_malla_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Organizacion Malla'),
        'title_plural' => t('Ev Organizacion Mallas'),
      ),
      'facultad' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Facultad'),
        'title_plural' => t('Facultads'),
      ),
      'escuela' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Escuela'),
        'title_plural' => t('Escuelas'),
      ),
      'departamento' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Departamento'),
        'title_plural' => t('Departamentos'),
      ),
      'centro_apoyo' => array(
        'autoadmin_type' => 'int',
        'title' => t('Centro Apoyo'),
        'title_plural' => t('Centro Apoyos'),
      ),
      'lugar' => array(
        'autoadmin_type' => 'text',
        'title' => t('Lugar'),
        'title_plural' => t('Lugars'),
      ),
      'carrera_convenio' => array(
        'autoadmin_type' => 'int',
        'title' => t('Carrera Convenio'),
        'title_plural' => t('Carrera Convenios'),
      ),
      'instit_convenio' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Instit Convenio'),
        'title_plural' => t('Instit Convenios'),
      ),
      'ev_jornada_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Jornada'),
        'title_plural' => t('Ev Jornadas'),
      ),
      'num_creditos_ct' => array(
        'autoadmin_type' => 'int',
        'title' => t('Num Creditos Ct'),
        'title_plural' => t('Num Creditos Cts'),
      ),
      'ev_estado_carrera_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Estado Carrera'),
        'title_plural' => t('Ev Estado Carreras'),
      ),
      'observaciones' => array(
        'autoadmin_type' => 'text',
        'title' => t('Observaciones'),
        'title_plural' => t('Observaciones'),
      ),
      'titulo' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Titulo'),
        'title_plural' => t('Titulos'),
      ),
      'ev_sede_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Sede'),
        'title_plural' => t('Ev Sedes'),
      ),
      'duracion_sin_tesis' => array(
        'autoadmin_type' => 'numeric',
        'title' => t('Duracion Sin Tesis'),
        'title_plural' => t('Duracion Sin Teses'),
      ),
      'duracion_con_tesis' => array(
        'autoadmin_type' => 'numeric',
        'title' => t('Duracion Con Tesis'),
        'title_plural' => t('Duracion Con Teses'),
      ),
      'costo_anual_est' => array(
        'autoadmin_type' => 'numeric',
        'title' => t('Costo Anual Est'),
        'title_plural' => t('Costo Anual Ests'),
      ),
      'n' => array(
        'autoadmin_type' => 'int',
        'title' => t('N'),
        'title_plural' => t('Ns'),
      ),
      'provincia' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Provincia'),
        'title_plural' => t('Provincias'),
      ),
      'canton' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Canton'),
        'title_plural' => t('Cantons'),
      ),
      'parroquia' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Parroquia'),
        'title_plural' => t('Parroquias'),
      ),
      'institucion' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Institucion'),
        'title_plural' => t('Institucions'),
      ),
      'sede' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Sede'),
        'title_plural' => t('Sedes'),
      ),
      'nivel' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Nivel'),
        'title_plural' => t('Nivels'),
      ),
      'modalidad' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Modalidad'),
        'title_plural' => t('Modalidads'),
      ),
      'jornada' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Jornada'),
        'title_plural' => t('Jornadas'),
      ),
      'organiz_cp' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Organiz Cp'),
        'title_plural' => t('Organiz Cps'),
      ),
      'subarea' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Subarea'),
        'title_plural' => t('Subareas'),
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
      'ev_modalidad_estudio' => array(
        'type' => 'has_one',
        'local_key' => 'ev_modalidad_estudio_id',
        'foreign_key' => 'id',
      ),
      'ev_nivel_carrera' => array(
        'type' => 'has_one',
        'local_key' => 'ev_nivel_carrera_id',
        'foreign_key' => 'id',
      ),
      'ev_organizacion_malla' => array(
        'type' => 'has_one',
        'local_key' => 'ev_organizacion_malla_id',
        'foreign_key' => 'id',
      ),
      'ev_jornada' => array(
        'type' => 'has_one',
        'local_key' => 'ev_jornada_id',
        'foreign_key' => 'id',
      ),
      'ev_estado_carrera' => array(
        'type' => 'has_one',
        'local_key' => 'ev_estado_carrera_id',
        'foreign_key' => 'id',
      ),
      'ev_sede' => array(
        'type' => 'has_one',
        'local_key' => 'ev_sede_id',
        'foreign_key' => 'id',
      ),
      'ev_estudiante' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_carrera_id',
      ),
      'ev_form_mtn' => array(
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

  // Auto Admin schema for {ev_modalidad_estudio} table
  $autoadmin_schema['ev_modalidad_estudio'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_modalidad_estudio',
    'title' => t('Ev Modalidad Estudio'),
    'title_plural' => t('Ev Modalidad Estudios'),
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
        'foreign_key' => 'ev_modalidad_estudio_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_sede} table
  $autoadmin_schema['ev_sede'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_sede',
    'title' => t('Ev Sede'),
    'title_plural' => t('Ev Sedes'),
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
      'ev_parroquia_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Parroquia'),
        'title_plural' => t('Ev Parroquias'),
      ),
      'lugar' => array(
        'autoadmin_type' => 'text',
        'title' => t('Lugar'),
        'title_plural' => t('Lugars'),
      ),
      'name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Name'),
        'title_plural' => t('Names'),
      ),
      'ev_tipo_sede_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Tipo Sede'),
        'title_plural' => t('Ev Tipo Sedes'),
      ),
      'ev_canton_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Canton'),
        'title_plural' => t('Ev Cantons'),
      ),
      'ev_provincia_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Provincia'),
        'title_plural' => t('Ev Provincias'),
      ),
      'parroquia' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Parroquia'),
        'title_plural' => t('Parroquias'),
      ),
      'canton' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Canton'),
        'title_plural' => t('Cantons'),
      ),
      'provincia' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Provincia'),
        'title_plural' => t('Provincias'),
      ),
    ),
    'relations' => array(
      'ev_ies' => array(
        'type' => 'has_one',
        'local_key' => 'ev_ies_id',
        'foreign_key' => 'id',
      ),
      'ev_parroquia' => array(
        'type' => 'has_one',
        'local_key' => 'ev_parroquia_id',
        'foreign_key' => 'id',
      ),
      'ev_tipo_sede' => array(
        'type' => 'has_one',
        'local_key' => 'ev_tipo_sede_id',
        'foreign_key' => 'id',
      ),
      'ev_canton' => array(
        'type' => 'has_one',
        'local_key' => 'ev_canton_id',
        'foreign_key' => 'id',
      ),
      'ev_provincia' => array(
        'type' => 'has_one',
        'local_key' => 'ev_provincia_id',
        'foreign_key' => 'id',
      ),
      'ev_carrera' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_sede_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_nivel_carrera} table
  $autoadmin_schema['ev_nivel_carrera'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_nivel_carrera',
    'title' => t('Ev Nivel Carrera'),
    'title_plural' => t('Ev Nivel Carreras'),
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
      'ev_carrera' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_nivel_carrera_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_tipo_sede} table
  $autoadmin_schema['ev_tipo_sede'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_tipo_sede',
    'title' => t('Ev Tipo Sede'),
    'title_plural' => t('Ev Tipo Sedes'),
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
    ),
    'relations' => array(
      'ev_sede' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_tipo_sede_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_organizacion_malla} table
  $autoadmin_schema['ev_organizacion_malla'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_organizacion_malla',
    'title' => t('Ev Organizacion Malla'),
    'title_plural' => t('Ev Organizacion Mallas'),
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
    ),
    'relations' => array(
      'ev_carrera' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_organizacion_malla_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_estado_carrera} table
  $autoadmin_schema['ev_estado_carrera'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_estado_carrera',
    'title' => t('Ev Estado Carrera'),
    'title_plural' => t('Ev Estado Carreras'),
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
    ),
    'relations' => array(
      'ev_carrera' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_estado_carrera_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_jornada} table
  $autoadmin_schema['ev_jornada'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_jornada',
    'title' => t('Ev Jornada'),
    'title_plural' => t('Ev Jornadas'),
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
    ),
    'relations' => array(
      'ev_carrera' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_jornada_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_archivo} table
  $autoadmin_schema['ev_archivo'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_archivo',
    'title' => t('Ev Archivo'),
    'title_plural' => t('Ev Archivos'),
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
      'ev_tipo_archivo_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Tipo Archivo'),
        'title_plural' => t('Ev Tipo Archivos'),
      ),
      'path' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Path'),
        'title_plural' => t('Paths'),
      ),
      'extension' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Extension'),
        'title_plural' => t('Extensions'),
      ),
      'md5' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Md5'),
        'title_plural' => t('Md5s'),
      ),
      'ies_name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Ies Name'),
        'title_plural' => t('Ies Names'),
      ),
      'orig_name' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Orig Name'),
        'title_plural' => t('Orig Names'),
      ),
    ),
    'relations' => array(
      'ev_tipo_archivo' => array(
        'type' => 'has_one',
        'local_key' => 'ev_tipo_archivo_id',
        'foreign_key' => 'id',
      ),
    ),
  );

  // Auto Admin schema for {ev_form_mtn} table
  $autoadmin_schema['ev_form_mtn'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_form_mtn',
    'title' => t('Ev Form Mtn'),
    'title_plural' => t('Ev Form Mtns'),
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
      'ev_parroquia_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Parroquia'),
        'title_plural' => t('Ev Parroquias'),
      ),
      'ev_canton_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Canton'),
        'title_plural' => t('Ev Cantons'),
      ),
      'ev_provincia_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Provincia'),
        'title_plural' => t('Ev Provincias'),
      ),
      'cedula' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Cedula'),
        'title_plural' => t('Cedulas'),
      ),
      'telefono_fijo' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Telefono Fijo'),
        'title_plural' => t('Telefono Fijos'),
      ),
      'telefono_movil' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Telefono Movil'),
        'title_plural' => t('Telefono Movils'),
      ),
      'direccion' => array(
        'autoadmin_type' => 'text',
        'title' => t('Direccion'),
        'title_plural' => t('Direccions'),
      ),
      'email' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Email'),
        'title_plural' => t('Emails'),
      ),
      'apellido_paterno' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Apellido Paterno'),
        'title_plural' => t('Apellido Paternos'),
      ),
      'apellido_materno' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Apellido Materno'),
        'title_plural' => t('Apellido Maternos'),
      ),
      'nombres' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Nombres'),
        'title_plural' => t('Nombres'),
      ),
      'n' => array(
        'autoadmin_type' => 'int',
        'title' => t('N'),
        'title_plural' => t('Ns'),
      ),
      'ev_estudiante_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Estudiante'),
        'title_plural' => t('Ev Estudiantes'),
      ),
      'ev_carrera_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Carrera'),
        'title_plural' => t('Ev Carreras'),
      ),
      'num_cred' => array(
        'autoadmin_type' => 'int',
        'title' => t('Num Cred'),
        'title_plural' => t('Num Creds'),
      ),
      'num_cred_tot' => array(
        'autoadmin_type' => 'int',
        'title' => t('Num Cred Tot'),
        'title_plural' => t('Num Cred Tots'),
      ),
      'provincia' => array(
        'autoadmin_type' => 'text',
        'title' => t('Provincia'),
        'title_plural' => t('Provincias'),
      ),
      'canton' => array(
        'autoadmin_type' => 'text',
        'title' => t('Canton'),
        'title_plural' => t('Cantons'),
      ),
      'parroquia' => array(
        'autoadmin_type' => 'text',
        'title' => t('Parroquia'),
        'title_plural' => t('Parroquias'),
      ),
      'registro_origen_id' => array(
        'autoadmin_type' => 'int',
        'title' => t('Registro Origen'),
        'title_plural' => t('Registro Origens'),
      ),
      'registro_origen_n' => array(
        'autoadmin_type' => 'int',
        'title' => t('Registro Origen N'),
        'title_plural' => t('Registro Origen Ns'),
      ),
    ),
    'relations' => array(
      'ev_parroquia' => array(
        'type' => 'has_one',
        'local_key' => 'ev_parroquia_id',
        'foreign_key' => 'id',
      ),
      'ev_canton' => array(
        'type' => 'has_one',
        'local_key' => 'ev_canton_id',
        'foreign_key' => 'id',
      ),
      'ev_provincia' => array(
        'type' => 'has_one',
        'local_key' => 'ev_provincia_id',
        'foreign_key' => 'id',
      ),
      'ev_estudiante' => array(
        'type' => 'has_one',
        'local_key' => 'ev_estudiante_id',
        'foreign_key' => 'id',
      ),
      'ev_carrera' => array(
        'type' => 'has_one',
        'local_key' => 'ev_carrera_id',
        'foreign_key' => 'id',
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
      'ev_parroquia_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Parroquia'),
        'title_plural' => t('Ev Parroquias'),
      ),
      'provincia' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Provincia'),
        'title_plural' => t('Provincias'),
      ),
      'uid' => array(
        'autoadmin_type' => 'int',
        'title' => t('Uid'),
        'title_plural' => t('Uids'),
      ),
      'cedula_contacto' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Cedula Contacto'),
        'title_plural' => t('Cedula Contactos'),
      ),
      'email_contacto' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Email Contacto'),
        'title_plural' => t('Email Contactos'),
      ),
      'nombre_contacto' => array(
        'autoadmin_type' => 'text',
        'title' => t('Nombre Contacto'),
        'title_plural' => t('Nombre Contactos'),
      ),
    ),
    'relations' => array(
      'ev_tipo_ies' => array(
        'type' => 'has_one',
        'local_key' => 'ev_tipo_ies_id',
        'foreign_key' => 'id',
      ),
      'ev_parroquia' => array(
        'type' => 'has_one',
        'local_key' => 'ev_parroquia_id',
        'foreign_key' => 'id',
      ),
      'ev_carrera' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_ies_id',
      ),
      'ev_estudiante' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_ies_id',
      ),
      'ev_ies_comentario' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_ies_id',
      ),
      'ev_profesor' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_ies_id',
      ),
      'ev_sede' => array(
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

  // Auto Admin schema for {ev_tipo_archivo} table
  $autoadmin_schema['ev_tipo_archivo'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_tipo_archivo',
    'title' => t('Ev Tipo Archivo'),
    'title_plural' => t('Ev Tipo Archivos'),
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
    ),
    'relations' => array(
      'ev_archivo' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_tipo_archivo_id',
      ),
    ),
  );

  // Auto Admin schema for {ev_log} table
  $autoadmin_schema['ev_log'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_log',
    'title' => t('Ev Log'),
    'title_plural' => t('Ev Logs'),
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
      'description' => array(
        'autoadmin_type' => 'text',
        'title' => t('Description'),
        'title_plural' => t('Descriptions'),
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
      'uid' => array(
        'autoadmin_type' => 'int',
        'title' => t('Uid'),
        'title_plural' => t('Uids'),
      ),
      'tipo' => array(
        'autoadmin_type' => 'int',
        'title' => t('Tipo'),
        'title_plural' => t('Tipos'),
      ),
    ),
    'relations' => array(),
  );

  // Auto Admin schema for {ev_ies_comentario} table
  $autoadmin_schema['ev_ies_comentario'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_ies_comentario',
    'title' => t('Ev Ies Comentario'),
    'title_plural' => t('Ev Ies Comentarios'),
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
      'description' => array(
        'autoadmin_type' => 'text',
        'title' => t('Description'),
        'title_plural' => t('Descriptions'),
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
      'ev_ies_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Ies'),
        'title_plural' => t('Ev y'),
      ),
      'ev_ies_tipo_comentario_id' => array(
        'autoadmin_type' => 'has_one',
        'title' => t('Ev Ies Tipo Comentario'),
        'title_plural' => t('Ev Ies Tipo Comentarios'),
      ),
      'uid' => array(
        'autoadmin_type' => 'int',
        'title' => t('Uid'),
        'title_plural' => t('Uids'),
      ),
      'usuario' => array(
        'autoadmin_type' => 'varchar',
        'title' => t('Usuario'),
        'title_plural' => t('Usuarios'),
      ),
    ),
    'relations' => array(
      'ev_ies' => array(
        'type' => 'has_one',
        'local_key' => 'ev_ies_id',
        'foreign_key' => 'id',
      ),
      'ev_ies_tipo_comentario' => array(
        'type' => 'has_one',
        'local_key' => 'ev_ies_tipo_comentario_id',
        'foreign_key' => 'id',
      ),
    ),
  );

  // Auto Admin schema for {ev_ies_tipo_comentario} table
  $autoadmin_schema['ev_ies_tipo_comentario'] = array(
    'alias' => 'name',
    'inline_filter' => FALSE,
    'path' => 'admin/content/ev_ies_tipo_comentario',
    'title' => t('Ev Ies Tipo Comentario'),
    'title_plural' => t('Ev Ies Tipo Comentarios'),
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
    ),
    'relations' => array(
      'ev_ies_comentario' => array(
        'type' => 'has_many',
        'local_key' => 'id',
        'foreign_key' => 'ev_ies_tipo_comentario_id',
      ),
    ),
  );

  return $autoadmin_schema;
}