<?php
    include("functions.php");
    
    if(isset($_POST['c'])){
        $rawcommand = $_POST['c'];
        //$command = explode(" ", $rawcommand);
        if($rawcommand == ""){
            $command[0] = "home";
        }else{
            preg_match_all('/"(?:\\\\.|[^\\\\"])*"|\S+/', $rawcommand, $rawoutput);
            $command = $rawoutput[0];
            foreach($rawoutput[0] as $key=>$val){
                if(strstr($val, " ")){
                    $command[$key] = substr($val, 1, -1);
                }else{
                    $command[$key] = $val;
                }
            }
        }
        
        //foreach($rawoutput[0] as $key => $val){
        //    if(substr($val, 0, 1) == '"' && substr($val, -1) == '"'){
        //        
        //    }
        //}
        //var_dump($rawoutput);
        
        if(isset($_COOKIE['PHPSESSID']) && $_COOKIE['PHPSESSID'] != ""){
            session_id($_COOKIE['PHPSESSID']);
            //session_save_path(getenv("DOCUMENT_ROOT")."/../phpfiles/sessions");
            session_start();
        } else {
            session_start();
            //$expire = time()+60*60*24;
            //setcookie("session", session_id(), $expire);
            $_SESSION['commands'][0] = "*session starts*";
            $_SESSION['calls'] = 0;
            reset_user_info();
        }
        $_SESSION['commands'][count($_SESSION['commands'])] = $command;
        $_SESSION['calls']++;
    } else {
        header("Location: /");
    }
    if(isset($_POST['ps']) && $_POST['ps'] == 1){
        $pushsettings = true;
    }else{
        $pushsettings = false;
    }
    
    const VERSION = "v0.1";
    const SITE = "Team 3499";
    const AUTHOR = "Chaos, Theyy, DerpyDragon";
    const UPDATE = "Never";
    include("commandindex.php");
    
    function commandParser($command){
        global $command_index;
        $cm = strtolower($command[0]);
        $comlen = strlen($command[0]);
        if(isset($command[1])){
            $cm1 = strtolower($command[1]);
        }else{
            $cm1 = null;
        }
        foreach($command as $key => $val){
            $command_lower[$key] = strtolower($val);
        }
        if(isset($command_index[$comlen][$cm])){
            if(array_intersect_assoc($command_lower, $command_index[$comlen][$cm][0]) == $command_index[$comlen][$cm][0] && $_SESSION['perms'] >= $command_index[$comlen][$cm][6]){
                return $command_index[$comlen][$cm];
            }else{
                return "unknowncommand";
            }
        }else{
            return "unknowncommand";
        }
    }
    $command_info = commandParser($command);
    $out = array('pagetitle' => NULL, 'path' => NULL, 'content' => NULL, 'script' => NULL, 'style' => NULL, 'pushsettings' => false);
    
    include("commandclass.php");
    if(is_array($command_info)){
        include("commands/".$command_info[2]);
    } else {
        class Commands extends CommandBase {}
        $command_info = [[], "unknowncommand", "", "", "", "", 0];
    }
    foreach($command as $val){
        $out['path'] .= "/".$val;
    }
    $out['pagetitle'] = SITE." - ".$command[0];
    
    $comclass = new Commands($command, $out, $rawcommand, $command_info, $pushsettings);
    $classout = $comclass->resolveCommand();
    
    $mergeout = array_merge($out, $classout);
    
    if($pushsettings || $mergeout['pushsettings']){
        $mergeout['script'] .= set_js_settings();
    }
    $pageout = [
        'pagetitle' => $mergeout['pagetitle'],
        'path' => $mergeout['path'],
        'content' => $mergeout['content'],
        'script' => '<script>'.$mergeout['script']."</script>",
        'style' => '<style>'.$mergeout['style']."</style>",
    ];
    echo json_encode($pageout);
?>