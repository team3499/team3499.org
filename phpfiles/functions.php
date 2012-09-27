<?php
	function check_session_commands($search, $count){
		$i = count($_SESSION['commands']) - 1;
		while($i >= 0){
			$j = 0;
			$match = false;
			
			while($j < $count){
				if($_SESSION['commands'][$i][$j] = $search[$j]){
					$match = true;
				} else {
					$match = false;
				}
				$j++;
			}
			
			if($match == true){
				return $_SESSION['commands'][$i];
			} else {
				$i--;
			}
		}
	}
	
	function default_title($str){
		return '<p class="default-title">'.$str.'</p>';
	}
	function default_content(){
		$str = "";
		foreach(func_get_args() as $val){
			$str .= $val;
		}
		return '<p class="default-content">'.$str.'</p>';
	}
	function default_file($file){
		return '<p class="default-content">'.file_get_contents(getenv("DOCUMENT_ROOT")."/core/files/".$file).'</p>';
	}
	function nows_file($file){ //no-white-space_file
        return str_replace(["\n", "\t", "  "], "", file_get_contents($file, true));
	}
    function php_js_css_files($path, $name){
        $name = strtolower($name);
        return '<script type="text/javascript">'.nows_file($path."/".$name."/".$name.".js").'</script><style type="text/css">'.nows_file($path."/".$name."/".$name.".css").'</style>'.nows_file($path."/".$name."/".$name.".php");
    }
    function parse_phpHtml_file($path, $var){
		$html = "";
        $file = file_get_contents($path, true);
		$count1 = substr_count($file, "<?php");
		$count2 = substr_count($file, "?>");
		if($count1 == $count2){
			for($i=0;$i<$count1;$i++){
				$output = "";
				$htmp = strstr($file, "<?php", true);
				$output .= $htmp;
				$file = substr($file, strlen($htmp)+5);
				$ptmp = strstr($file, "?>", true);
				$file = substr($file, strlen($ptmp)+2);
				ob_start();
				eval($ptmp);
				$output .= ob_get_contents();
				ob_clean();
				$html .= $output;
			}
			$html .= $file;
			return $html;
		}else{
			return "Mismatch in Number of PHP tags.";
		}
    }
    function dbh(){
        $hostdb =   "mysql:host=localhost;".
                    "dbname=web;";
        $host = "localhost";
        $db = "web";
        $user = "web";
        $pass = "GuCFGLX4nH7zq69f";
        $options = [PDO::MYSQL_ATTR_INIT_COMMAND => "SET NAMES utf8"];
        $dbh = new PDO($hostdb, $user, $pass, $options);
        //$dbh = mysql_connect($host, $user, $pass);
        //mysql_select_db($db, $dbh);
        return $dbh;
    }
    function SELECT($fields, $table, $condition, $dbh){
        return $dbh->query("SELECT ".$fields." FROM ".$table." ".$condition);
        //return mysql_query("SELECT ".$fields." FROM ".$table." ".$condition, $dbh);
    }
    function INSERT($table, $fields, $values, $dbh){
        return $dbh->query("INSERT INTO ".$table." (".$fields.") VALUES (".$values.")");
        //return mysql_query("INSERT INTO ".$table." (".$fields.") VALUES (".$values.")", $dbh);
    }
    
    function reset_user_info(){
        $_SESSION['user'] = null;
        $_SESSION['perms'] = 0;
        $_SESSION['id'] = null;
        $_SESSION['settings'] = [
            "hide-shell-on-send" => 1,
            "shell-background-color" => "#000",
        ];
    }
    function set_js_settings(){
        return
		"$(document).ready(function(){".
            "settings['hide-shell-on-send'] = ".$_SESSION['settings']['hide-shell-on-send'].";".
            "settings['shell-background-color'] = '".$_SESSION['settings']['shell-background-color']."';".
		"});";
    }
?>