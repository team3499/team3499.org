<?php
    class Commands extends CommandBase {
        protected function test_text(){
            $out['title'] = default_title("TEST");
            $out['content'] = default_file("test1.txt");
            $out['shell'] = file_get_contents(getenv("DOCUMENT_ROOT")."/core/files/test1.txt")."<br/>";
            return $out;
        }
        protected function test_text2(){
            $out['title'] = default_title("TEST2");
            $out['content'] = default_file("test2.txt");
            return $out;
        }
        protected function dump(){
            $out['title'] = default_title("Session Variable Dump");
            ob_start();
            echo session_id();
            echo "<br/>";
            var_dump($_SESSION);
            $session .= str_replace(["\n", "  "], ["<br/>", "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"], ob_get_contents());
            ob_clean();
            $out['content'] = default_content($session);
            return $out;
        }
		protected function echo_com(){
			$command = $this->command;
			$rawcommand = $this->rawcommand;
			$out['title'] = default_title("Echo");
			$cont = $rawcommand."<br/>";
			ob_start();
			var_dump($command);
			$cont .= ob_get_contents();
			ob_clean();
			$out['content'] = default_content($cont);
			return $out;
		}
        protected function blank(){
            $out['defaultpage'] = false;
            $out['content'] = '<div class="white"></div>';
            $out['style'] = '
                body{
                    background-color:#666;
                }
                div.white{
                    height:800px;
                    background-color:#fff;
                }';
            return $out;
        }
    }
?>