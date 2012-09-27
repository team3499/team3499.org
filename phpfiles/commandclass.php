<?php
    abstract class CommandBase {
        protected $command = array();
        protected $rawcommand = "";
        protected $out = array();
        protected $command_info = array();
        protected $pushsettings = false;
        
        function __construct($command, $out, $rawcommand, $command_info, $pushsettings){
            $this->command = $command;
            $this->rawcommand = $rawcommand;
            $this->out = $out;
            $this->command_info = $command_info;
            $this->pushsettings = $pushsettings;
        }
        
        protected function unknowncommand(){
            $out['title'] = default_title("Unrecognized Command: ".$this->rawcommand);
            $out['content'] = default_content("NOPE");
            $out['shell'] = "Unknown Command: ".$this->rawcommand."<br/>";
            return $out;
        }
        
        public function resolveCommand(){
            $command = $this->command;
            $command_info = $this->command_info;
            if(is_array($command_info)){
                $return = call_user_func([$this, $command_info[1]]);
            }else{
                $return = $this->unknowncommand();
            }
            $out = array_merge($this->out, $return);
            return $out;
        }
    }
?>