<?php
    class Commands extends CommandBase {
        protected function home(){
            $out['pagetitle'] = SITE;
            $out['path'] = "/";
            $out['title'] = nows_file("home-title.php");
            $out['content'] = nows_file("home-content.php");
            return $out;
        }
        
        protected function help(){
            global $command_index;
            $command = $this->command;
            if(isset($command[1])){
                $help_query = $command;
                array_shift($help_query);
                $help_info = commandParser($help_query);
                if(is_array($help_info)){
                    $use = str_replace(["<", ">"], ["&lt;", "&gt;"], $help_info[3]);
                    $des = $help_info[4];
                    if(substr($help_info[5], -4) == ".php"){
                        ob_start();
                        include("help/".$help_info[5]);
                        $info = str_replace(["\n", "\t", "\r", "  "], "", ob_get_contents());
                        ob_clean();
                    }else{
                        $info = $help_info[5];
                    }
                    $name = "";
                    foreach($help_info[0] as $val){
                        $name .= " ".$val;
                    }
                    $name = substr($name, 1);
                    $content = '<span class="bold-bolder">'.$name."</span> ".$use." - ".$des."<br/>".$info;
                    $out['title'] = default_title($name." Help");
                    $out['content'] = default_content($content);
                }else{
                    $out['title'] = default_title("Bad Help");
                    $out['content'] = default_content("Unknown Command");
                }
            }else{
                $content = "";
                foreach($command_index as $length){
                    foreach($length as $entry){
                        if($_SESSION['perms'] >= $entry[6]){
                            $use = str_replace(["<", ">"], ["&lt;", "&gt;"], $entry[3]);
                            $des = $entry[4];
                            $name = "";
                            foreach($entry[0] as $name_val){
                                $name .= " ".$name_val;
                            }
                            $name = substr($name, 1);
                            $content .= '<span class="bold-bolder">'.$name."</span> ".$use." - ".$des."<br/>";
                        }
                    }
                }
                $out['title'] = default_title("Command Help");
                $out['content'] = default_content($content);
            }
            return $out;
        }
        
        protected function derp(){
            $out['title'] = default_title("DERP");
            $out['content'] = default_content("yay derp");
            return $out;
        }
        
        protected function herp(){
            $out['title'] = default_title("HERP");
            $out['content'] = default_content("yay herpy");
            return $out;
        }
        
        protected function search(){
            $command = $this->command;
            $i = 1;
            if(isset($command[$i]) == TRUE){
                $searchstr = "Search Text:";
                while(isset($command[$i]) != FALSE){
                    $searchstr .= " ".$command[$i];
                    $i++;
                }
                $out['content'] = default_content($searchstr);
            }else{
                $out['content'] = default_content("No search text!");
            }
            $out['title'] = default_title("SEARCH");
            return $out;
        }
        
        protected function add(){
            $command = $this->command;
            $i = 1;
            if(isset($command[$i]) == TRUE){
                $sum = 0;
                while(isset($command[$i]) != FALSE){
                    $sum += $command[$i];
                    $i++;
                }
                $out['content'] = default_content("Sum: ".$sum);
            }else{
                $out['content'] = default_content("No numbers to add!");
            }
            $out['title'] = default_title("ADDITION");
            return $out;
        }

        protected function upload(){
            $command = $this->command;
            //if($this->command[1] == "file" && check_session_commands(array(0 => "upload", 1 => ""), 2)){
            if(isset($command[1]) && $command[1] == "file"){
                $out['title'] = default_title("FILE UPLOAD SUCCESS");
                ob_start();
                print_r($_FILES);
                $filecont = ob_get_contents();
                ob_clean();
                $out['content'] = default_content("File <em>".$filecont."</em> uploaded");
            }else{
                $out['title'] = default_title("FILE UPLOAD");
                $out['content'] = nows_file("upload-content.php");
            }
            return $out;
        }
        
        protected function game(){
            $command = $this->command;
            if(isset($command[1])){
                switch(strtolower($command[1])){
                    case "target":
                        $out['title'] = default_title("TARGET GAME");
                        $out['content'] = parse_phpHtml_file("game/target/target.php", get_defined_vars());
                        $out['script'] = nows_file("game/target/target.js");
                        $out['style'] = nows_file("game/target/target.css");
                        break;
                    case "hilow":
                        $out['title'] = default_title("HIGH-LOW GAME");
                        $out['content'] = nows_file("game/hilow/hilow.php");
                        $out['script'] = nows_file("game/hilow/hilow.js");
                        $out['style'] = nows_file("game/hilow/hilow.css");
                        break;
                    default:
                        $out['title'] = default_title("GAME INCORRECT");
                        $out['content'] = default_content("Please Specify Correct Game");
                        break;
                }
            }else{
                $out['title'] = default_title("GAME");
                $out['content'] = default_content("Please Specify Game");
            }
            return $out;
        }
        
        protected function sherlock(){
            $out['pagetitle'] = SITE." - Sherlock Holmes";
            $out['title'] = default_title("Sherlock Holmes");
            $out['content'] = default_content("By golly Watson, you're right!");
            return $out;
        }

        protected function about(){
            $out['title'] = default_title("About ".SITE);
            global $command_index;
            $comnums = 0;
            $coms = [];
            foreach($command_index as $val){
                foreach($val as $subval){
                    if(!in_array($subval[1], $coms)){
                        $coms[count($coms)] = $subval[1];
                        $comnums++;
                    }
                }
            }
            if($_SESSION['user'] != null){
                $usernameid = "Logged in as: ".$_SESSION['user']."<br/>User ID: ".$_SESSION['id']."<br/>";
            }else{
                $usernameid = "Not Logged In<br/>";
            }
            $out['content'] = default_content(
                "Site: ".SITE."<br/>",
                "Version: ".VERSION."<br/>",
                "Author: ".AUTHOR."<br/>",
                "Number of Pages: ".$comnums."<br/>",
                "Last Updated: ".UPDATE."<br/>",
                $usernameid
            );
            return $out;
        }
        
        protected function projects(){
            $command = $this->command;
            $rawcommand = $this->rawcommand;
            if(isset($command[1])){
                if($_SESSION['perms'] >= 2 && strtolower($command[1]) == "add"){
                    $out['title'] = default_title("Add Project");
                    if(isset($command[2]) && isset($command[3]) && isset($command[4]) && isset($command[5]) && isset($command[6]) && isset($command[7]) && !isset($command[8])){
                        // <"project name"> <permission code> <"short deatil"> <"description"> <staus code> <"status detail">
                        $id = SELECT("id", "projects", "ORDER BY id DESC LIMIT 1", dbh())->fetchAll()[0]['id'] + 1;
                        INSERT("projects", "id, name, perms, details, description, status, status_detail", $id.", '".$command[2]."', ".$command[3].", '".$command[4]."', '".$command[5]."', ".$command[6].", '".$command[7]."'", dbh());
                        $out['content'] = default_content("Project ".$command[2]." Added");
                    }else{
                        $out['content'] = default_content("Invalid Synatx");
                    }
                }elseif($_SESSION['perms'] >= 2 && strtolower($command[1]) == "edit"){
                    $out['title'] = default_title("Edit Project");
                    if(isset($command[2]) && isset($command[3]) && isset($command[4]) && isset($command[5]) && isset($command[6]) && isset($command[7]) && !isset($command[8])){
                        $out['content'] = default_content("");
                    }else{
                        $out['content'] = default_content("Invalid Synatx");
                    }
                }else{
                    $out['title'] = default_title("Project Name");
                    $out['content'] = default_content($rawcommand);
                }
            }else{
                $out['title'] = default_title("Projects");
                $projects = SELECT("id, name, status, status_detail, details", "projects", "WHERE perms <= ".$_SESSION['perms'], dbh());
                if($projects != false){
                    $projects = $projects->fetchAll();
                    $content = "";
                    foreach($projects as $proj){
                        switch($proj['status']){
                            case 0:$col="red";break;    //0 - Stopped   - Red
                            case 1:$col="blue";break;   //1 - Done      - Blue
                            case 2:$col="green";break;  //2 - Active    - Green
                            case 3:$col="yellow";break; //3 - Suspended - Yellow
                            default:$col="gray";break;  //? - Unknown   - Gray
                        }
                        $icon = '<span class="bubble bubble-'.$col.'">'.$proj['status_detail'].'</span>';
                        $content .= '<p class="default-content">Project ID '.$proj['id'].' - '.$proj['name'].'</p>'.$icon.'<p class="default-content">'.$proj['details'].'</p><hr/>';
                    }
                    $content = substr($content, 0, -5);
                    $out['content'] = '<div class="default-wrapper">'.$content.'</div>';
                    ob_start();
                    //var_dump($projects);
                    //$out['content'] = default_content(str_replace(["\n", "  "], ["<br/>", "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"], ob_get_contents()));
                    ob_clean();
                }
            }
            return $out;
        }
    }
?>