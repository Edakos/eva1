<?php
	$a = (isset($_GET["action"]) ? $_GET["action"] : false);

    $svn_start = '/usr/bin/svn';
    $svn_add = 'add';
    $svn_update = 'update';
    $svn_commit = 'commit /var/www/sql';
    $svn_login = '--username wwwsqldesigner --password wwwsqldesigner';
    function svn_msg($msg) {return '-m "[WWWSQLDESIGNER] ' . $msg . '"';}
    $svn_end = "--non-interactive 2>&1";

	switch ($a) {
		case "list":
			$files = glob("data/*");
			foreach ($files as $file) {
				$name = basename($file);
				echo $name."\n";
			}
		break;
		case "save":
			$keyword = (isset($_GET["keyword"]) ? $_GET["keyword"] : "");
			$keyword = "data/".basename($keyword);
			$f = fopen($keyword, "w");
			$data = file_get_contents("php://input");
			if (get_magic_quotes_gpc() || get_magic_quotes_runtime()) {
			   $data = stripslashes($data);
			}
			fwrite($f, $data);
			fclose($f);
            $resultado = array();

            exec("$svn_start commit $svn_login " . svn_msg('model save') . " $svn_end", $resultado, $returnStatus);

            //save log
            if (count($resultado) == 0) {$resultado = array("Saved!");}
            $f = fopen($keyword . '-log', "a");
            fwrite($f, "\n SVN COMMIT - " . date('l jS \of F Y h:i:s A') . ":\n" . implode("\n", $resultado) . "\n---\n\n");
			fclose($f);
            exec("$svn_start $svn_add " . $keyword . "-log $svn_end");
            exec("$svn_start $svn_commit $svn_login " . svn_msg('log save') . " $svn_end");

			header("HTTP/1.0 201 Created");
		break;
		case "load":
			$keyword = (isset($_GET["keyword"]) ? $_GET["keyword"] : "");
			$keyword = "data/".basename($keyword);

            exec("$svn_start $svn_update $svn_end", $resultado, $returnStatus);
            
            //save log 
            if (count($resultado) == 0) {$resultado = array("Updated!");}
            $f = fopen($keyword . '-log', "a");
            fwrite($f, "\n SVN UPDATE - " . date('l jS \of F Y h:i:s A') . ":\n" . implode("\n", $resultado) . "\n---\n\n");
		    fclose($f);
            exec("$svn_start $svn_add " . $keyword . "-log $svn_end");
            exec("$svn_start $svn_commit $svn_login " . svn_msg('log save') . " $svn_end");

			if (!file_exists($keyword)) {
				header("HTTP/1.0 404 Not Found");
			} else {
				header("Content-type: text/xml");
				echo file_get_contents($keyword);
			}
		break;
		default: header("HTTP/1.0 501 Not Implemented");
	}
?>
