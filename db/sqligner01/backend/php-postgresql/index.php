<?php

// ---------------------------------------------------------------------
// Postgresql server backend for wwwsqldesigner
// version 0.1 beta
// Based on the mysql server backend provided with wwwsqldesigner 2.3.2
// 
// 
// 
// Issues relating to using wwwsqldesigner with postgresl:
//  * Request dialog for a database name is not needed. Enter anything when
//    requested.
//  * There can be user-defined types in Postgresql which is not found in
//    '../../db/postgresql/datatypes.xml'.
//  * There is no auto increment column in Postgresql. Ignore the checkbox,
//    use the serial type when building your tables; if importing, you should
//    see an Integer type and a default value of something similar to
//    nextval('"someSequenceName"'::regclass).
// ---------------------------------------------------------------------


// Parameters for the database you want to import in the application
    function setup_live_database() {
        Define("HOST_ADDR", "localhost");   // if the database cluster is on the same server as this application use 'localhost' otherwise the appropriate address (192.168.0.2 for example).
        Define("PORT_NO", "5432");          // default port is 5432. If you have or had more than one db cluster at the same time, consider ports 5433,... etc.
        Define("DATABASE_NAME", "ceaaces");   // the database you want to import
        Define("USER_NAME", "ceaaces");    // role having rights to read the database
        Define("PASSWORD", "c344c35");       // password for role
    }
    

// Parameters for the application database
    function setup_saveloadlist() {
        Define("HOST_ADDR", "localhost");           // if the database cluster is on the same server as this application use 'localhost' otherwise the appropriate address (192.168.0.2 for example).
        Define("PORT_NO", "5432");                  // default port is 5432. If you have or had more than one db cluster at the same time, consider ports 5433,... etc.
        Define("DATABASE_NAME", "edgarval_wwwsqldesigner");  // leave as is
        Define("USER_NAME", "edgarval_ev");        // leave as is
        Define("PASSWORD", "PNorte2015");                 // leave as is
        Define("TABLE", "wwwsqldesigner");          // leave as is
    }

    function connect() {
        $str="host=".HOST_ADDR." port=".PORT_NO." dbname=".DATABASE_NAME." user=".USER_NAME." password=".PASSWORD;
        $conn = pg_connect($str);
        if (!$conn){
            header("HTTP/1.0 503 Service Unavailable");
            break;
        }
        return $conn;
    }

    function import($conn) {
    //  $db = (isset($_GET["database"]) ? $_GET["database"] : "information_schema");
    //  $db = pg_escape_string($conn, $db);
        $xml = "";
        $arr = array();
        @ $datatypes = file("../../db/postgresql/datatypes.xml");
        $arr[] = $datatypes[0];
        $arr[] = '<sql db="postgresql">';
        for ($i=1;$i<count($datatypes);$i++) {
            $arr[] = $datatypes[$i];
        }

        // in Postgresql comments are not stored in the ANSI information_schema (compliant to the standard);
        // so we will need to access the pg_catalog and may as well get the table names at the same time.
        $qstr = "
                SELECT  relname as table_name, 
                        c.oid as table_oid,
                        (SELECT pg_catalog.obj_description(c.oid, 'pg_class')) as comment
                FROM pg_catalog.pg_class c 
                WHERE c.relname !~ '^(pg_|sql_)' AND relkind = 'r'
        ;";

        $result = pg_query($conn, $qstr);
        while ($row = pg_fetch_array($result)) {
            $table = $row["table_name"];
            $table_oid = $row["table_oid"];
            $xml .= '<table name="'.$table.'">';
            $comment = (isset($row["comment"]) ? $row["comment"] : "");
            if ($comment) { $xml .= '<comment>'.$comment.'</comment>'; }
            $qstr = "
                SELECT *, col_description(".$table_oid.",ordinal_position) as column_comment 
                FROM information_schema.columns 
                WHERE table_name = '".$table."'
            ;";
            $result2 = pg_query($conn, $qstr);
            while ($row = pg_fetch_array($result2)) {
                $name  = $row["column_name"];
                $type  = $row["data_type"];     // maybe use "udt_name" instead to consider user types
                $comment = (isset($row["column_comment"]) ? $row["column_comment"] : "");
                $null = ($row["is_nullable"] == "YES" ? "1" : "0");
                $def = $row["column_default"];
                // $ai:autoincrement... Not in postgresql, Ignore
                $ai = "0";
                if ($def == "NULL") { $def = ""; }
                $xml .= '<row name="'.$name.'" null="'.$null.'" autoincrement="'.$ai.'">';
                $xml .= '<datatype>'.strtoupper($type).'</datatype>';
                $xml .= '<default>'.$def.'</default>';
                if ($comment) { $xml .= '<comment>'.$comment.'</comment>'; }

                /* fk constraints */
                $qstr = "
                    SELECT  kku.column_name,
                            ccu.table_name AS references_table,
                            ccu.column_name AS references_field
                    FROM information_schema.table_constraints tc
                    LEFT JOIN information_schema.constraint_column_usage ccu
                        ON tc.constraint_name = ccu.constraint_name
                    LEFT JOIN information_schema.key_column_usage kku
                        ON kku.constraint_name = ccu.constraint_name
                    WHERE constraint_type = 'FOREIGN KEY' 
                        AND kku.table_name = '".$table."' 
                        AND kku.column_name = '".$name."'
                ;";

                $result3 = pg_query($conn, $qstr);

                while ($row = pg_fetch_array($result3)) {
                    $xml .= '<relation table="'.$row["references_table"].'" row="'.$row["references_field"].'" />';
                }

                $xml .= '</row>';
            }
            
            // keys 
            $qstr = "
                SELECT  tc.constraint_name,
                        tc.constraint_type,
                        kcu.column_name
                FROM information_schema.table_constraints tc 
                LEFT JOIN information_schema.key_column_usage kcu 
                    ON tc.constraint_catalog = kcu.constraint_catalog 
                    AND tc.constraint_schema = kcu.constraint_schema 
                    AND tc.constraint_name = kcu.constraint_name 
                WHERE tc.table_name = '".$table."' AND constraint_type != 'FOREIGN KEY' 
                ORDER BY tc.constraint_name
            ;";
            $result2 = pg_query($conn, $qstr);
            $keyname1 = "";
            while ($row2 = pg_fetch_array($result2)){
                $keyname = $row2["constraint_name"];
                if ($keyname != $keyname1) {
                    if ($keyname1 != "") { $xml .= '</key>'; }
                    $xml .= '<key name="'.$keyname.'" type="'.$row2["constraint_type"].'">';
                    $xml .= isset($row2["column_name"]) ? '<part>'.$row2["column_name"].'</part>' : "";
                } else {
                    $xml .= isset($row2["column_name"]) ? '<part>'.$row2["column_name"].'</part>' : "";
                }
                $keyname1 = $keyname;
            }
            $xml .= '</key>';
            $xml .= "</table>";

        }
        $arr[] = $xml;
        $arr[] = '</sql>';
        return implode("\n",$arr);
    }

    $a = (isset($_GET["action"]) ? $_GET["action"] : false);
    switch ($a) {
        case "list":
            setup_saveloadlist();
            $conn = connect();
            $qstr = "SELECT keyword FROM ".TABLE." ORDER BY dt DESC";
            $result = pg_query($conn, $qstr);
            while ($row = pg_fetch_assoc($result)) {
                echo $row["keyword"]."\n";
            }
        break;
        case "save":
            setup_saveloadlist();
            $conn = connect();
            $keyword = (isset($_GET["keyword"]) ? $_GET["keyword"] : "");
            $keyword = pg_escape_string($conn,$keyword);
            $data = file_get_contents("php://input");
            if (get_magic_quotes_gpc() || get_magic_quotes_runtime()) {
               $data = stripslashes($data);
            }
            $data = pg_escape_string($conn,$data);
            $qstr = "SELECT * FROM ".TABLE." WHERE keyword = '".$keyword."'";
            $r = pg_query($conn, $qstr);
            if (pg_num_rows($r) > 0) {
                $qstr = "UPDATE ".TABLE." SET xmldata = '".$data."' WHERE keyword = '".$keyword."'";
                $res = pg_query($conn, $qstr);
            } else {
                $qstr = "INSERT INTO ".TABLE." (keyword, xmldata) VALUES ('".$keyword."', '".$data."')";
                $res = pg_query($conn, $qstr);
            }
            if (!$res) {
                header("HTTP/1.0 500 Internal Server Error");
            } else {
                header("HTTP/1.0 201 Created");
            }
        break;
        case "load":
            setup_saveloadlist();
            $conn = connect();
            $keyword = (isset($_GET["keyword"]) ? $_GET["keyword"] : "");
            $keyword = pg_escape_string($conn, $keyword);
            $qstr = "SELECT xmldata FROM ".TABLE." WHERE keyword = '".$keyword."'";
            $result = pg_query($conn, $qstr);
            $row = pg_fetch_assoc($result);
            if (!$row) {
                header("HTTP/1.0 404 Not Found");
            } else {
                header("Content-type: text/xml");
                echo $row["xmldata"];
            }
        break;
        case "import":
            setup_live_database();
            $conn = connect();
            header("Content-type: text/xml");
            echo import($conn);
        break;
        
        case "execute":
            $sql = (isset($_GET["sql"]) ? urldecode($_GET["sql"]) : '');
            $sql = str_replace('\"', '"', $sql);
            $sql = str_replace("\'", "'", $sql);
            if ($sql != '') {
                setup_live_database();
                $conn = connect();
                
                if (!pg_connection_busy($conn)) {
                    pg_send_query($conn, $sql);
                }

                $result = pg_get_result($conn);
                $error = pg_result_error($result);
                
                //$result = pg_query($conn, $sql);
                
                if ($error != '') {
                    header("HTTP/1.0 500 Internal Server Error");
                } else {
                    header("HTTP/1.0 201 Created");
                }
                
                pg_free_result($result);
                
                $count = (isset($_GET["count"]) ? $_GET["count"] : 0);
                $count += 1;
                echo $count . '|||' . $sql . '|||' . $error;
            } else {
                header("HTTP/1.0 404 Not Found");
            }
        break;
        
        case 'singularize':
            require_once('inflector.php');
            $inflector = new Inflector();
            $word = (isset($_GET["word"]) ? urldecode($_GET["word"]) : '');
            
            if ($word != '') {
                header("HTTP/1.0 201 Created");
                echo $inflector->singularize($word);
            } else {
                header("HTTP/1.0 404 Not Found");
            }
        break;
        
        default: header("HTTP/1.0 501 Not Implemented");
    }


    /*
        list: 501/200
        load: 501/200/404
        save: 501/201
        import: 501/200
    */
?>
