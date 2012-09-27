<?php
    class Commands extends CommandBase {
        protected function login(){
            $command = $this->command;
            $out['title'] = default_title("Login");
            $out['pagetitle'] = SITE." - ".$command[0];
            $out['path'] = "/login";
            if(isset($command[1])){
                $user = $command[1];
                $pass = SELECT("password", "users", "WHERE user = '".$user."'", dbh());
                if(isset($command[2])){
                    if($pass != false){
                        $pass = $pass->fetchAll();
                        
                        if($command[2] == $pass[0]['password']){
                            $info = SELECT("id, name, perms, settings", "users", "WHERE user = '".$user."'", dbh())->fetchAll();
                            $_SESSION['user'] = $info[0]['name'];
                            $_SESSION['perms'] = (int)$info[0]['perms'];
                            $_SESSION['id'] = (int)$info[0]['id'];
                            $_SESSION['settings'] = json_decode($info[0]['settings'], true);
                            $out['content'] = default_content("Logged in as User ".$_SESSION['id'].", ".$_SESSION['user']);
                            $out['pushsettings'] = true;
                        }else{
                            $out['content'] = default_content("Invalid Login - Incorrect Password");
                        }
                    }else{
                        $out['content'] = default_content("Invalid Login - DB Error");
                    }
                }else{
                    $out['content'] = default_content("Invalid Login - Password Not Specified");
                }
            }else{
                $out['content'] = default_content("No User Specified");
            }
            return $out;
        }
        protected function logout(){
            $out['title'] = default_title("Logout");
            if($_SESSION['user'] != null){
                reset_user_info();
                $out['content'] = default_content("Logged Out");
                $out['pushsettings'] = true;
            }else{
                $out['content'] = default_content("No User Logged In");
            }
            return $out;
        }
        protected function settings(){
            $command = $this->command;
            $err = false;
            $errc = "Bad Synatx";
            $good = false;
            $setting_names = [
                "hide-shell-on-send",
                "shell-background-color"
            ];
			if(isset($command[1])){
				if($command[1] == "list" && !isset($command[2])){
					$list = "";
					foreach($setting_names as $val){
						$list .= $val."<br/>";
					}
					$out['title'] = default_title("Settings List");
					$out['content'] = default_content($list);
				}else{
					array_shift($command);
					foreach($command as $key=>$val){
						if(in_array($val, $setting_names)){
							$good = true;
							if(isset($command[$key+1])){
								if(!in_array($command[$key+1], $setting_names)){
									$sett[$val] = $command[$key+1];
								}else{
									$err = true;
									$errc .= " - Setting Value Not Declared Before Next Setting";
								}
							}else{
								$err = true;
								$errc .= " - Setting Value Undeclared";
							}
						}else{
							if(!isset($command[$key-1]) || !in_array($command[$key-1], $setting_names)){
								$err = true;
								$errc .= ' - Bad Setting Name "'.$val.'"';
							}
						}
					}
					$out['title'] = default_title("Set Settings");
					if(!$err){
						ob_start();
						var_dump($sett);
						$out['content'] = default_content(ob_get_contents());
						ob_clean();
					}else{
						$out['content'] = default_content($errc);
					}
				}
			}else{
				$out['title'] = default_title("Settings");
				$out['content'] = '<script>'."function preset(){".
                    '$(\'input[name="hide-shell-on-send"][value="'.$_SESSION['settings']['hide-shell-on-send'].'"]\').attr("checked", "checked");'.
                    '$(\'input[name="shell-background-color"]\').attr("value", "'.$_SESSION['settings']['shell-background-color'].'");'.
                "}"."</script>".nows_file("settings-content.php");
			}
			return $out;
        }


        protected function user(){
            $out['title'] = "Title Goes Here!";
            $out['content'] = nows_file("user-content.php");
            return $out;
        }
    }
?>