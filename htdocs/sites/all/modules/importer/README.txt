
DESCRIPTION
-------------------------------------
  Importer module provides an easy way for creating database tables from various files.
All variants of delimited text files are supports, and with an external class .xls files are
also supported.

  With this module the user can also insert new data into the existing table, provided that
the number of non-PK columns in the table match the number of columns in the file. If
the ordering of the columns is not matched, the user can alter the ordering in witch the
data is inserted. Types of the appropriate columns in the table and the file are
displayed as means of ensuring that no sql error is generated (unintentionally).

  If the user has a field in the data that should serve as a link to files on file system,
the procedure is as follows:
   
        - upload the data to the database ensuring that the appropriate field contains
          the file name <name.ext> of the file to witch it should point

        - zip all the files that are relevant to the table

        - upload the files to the server using "Batch file upload" feature of the module,
          making sure that appropriate table and field is selected

  After this, the data in the chosen field should be updated with the relative path to the
uploaded files on the server. The uploaded files are put in the directory of user choice
under the files/ directory (it has to be created by this module).
  The original file names are stored in the utility table, so if the user wants to make a 
change, all that is necessary is that the new file that is packed and uploaded has the
same name as the old one.

REQUIRED MUDULES
-------------------------------------

    - Schema
  To access imported tables through Views you need to install Table Wizard and add created 
  tables (to the table list)

  Finally, there is an option to drop the table previously created by this module or delete
  previously uploaded files.

This module is part of a package of modules being developed by Jefferson Institute. These
modules are meant to serve as tools for data visualization:

Timelinemap:
	http://drupal.org/project/timelinemap

KML content type:
	http://drupal.org/project/ct_gearth

Google Visualization API
	http://drupal.org/project/gvs

Tagmap
	http://drupal.org/project/tagmap





REQUIREMENTS
-------------------------------------
- Drupal 6.x

INSTALLATION AND CONFIGURATION
-------------------------------------
  Just copy the module to sites/.../modules directory and enable it.

EXCEL READER
-------------------------------------
  To enable this module to work with .xls files, you should download the class excel_reader2.php
from

    http://code.google.com/p/php-excel-reader/

change the extension from .php to .inc and put it in the modules/importer directory