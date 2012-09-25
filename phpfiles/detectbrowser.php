<?php
    header('Content-type: text/html; charset=utf-8');
    $usag = $_SERVER['HTTP_USER_AGENT'];
    preg_match_all('/\((?:\\\\.|[^\\\\"])*\)|\S+/', $usag, $uag);
    $ua = $uag[0];
    foreach($ua as $val){
        echo $val."<br/>";
    }
    foreach($ua as $val=>$key){
        $prop = strstr($val, "/", true);
    }
?>