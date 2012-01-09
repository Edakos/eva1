var CONFIG = {
	AVAILABLE_DBS:["mysql","sqlite","web2py","mssql","postgresql"],
	DEFAULT_DB:"postgresql",

	AVAILABLE_LOCALES:["en","fr","de","cs","pl","pt_BR","es", "ru","eo"],
	DEFAULT_LOCALE:"en",
	
	//AVAILABLE_BACKENDS:["php-mysql","php-blank","php-file","php-sqlite","php-postgresql"],
  AVAILABLE_BACKENDS:["php-file", "php-postgresql", "php-mysql", "php-sqlite", "php-blank"],
	DEFAULT_BACKEND:["php-file"],

	RELATION_THICKNESS:2,
	RELATION_SPACING:15,
	
	STATIC_PATH: "",
	XHR_PATH: "",

  AUTOSAVE_WAIT_TIME:30
}
