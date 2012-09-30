<?php
// note: commands are in alphabetical order, first by the file they are in, then by their name

    //  --USAGE:--
    // [
    //      length => [
    //        "base of command" => [["command parts", ...], "function", "child class file",
    //        "usage", 
    //        "description", 
    //        "information", 
    //        security],
    //          ...
    //      ],
    //      ...
    //    ]
    
    $command_index = [
        4 => [
            "home" => [["home"], "home", "commands.php", 
                "", 
                "Goes Home", 
                "", 
                0],
            "help" => [["help"], "help", "commands.php", 
                "<command>", 
                "Command Help (this command)", 
                "", 
                0],
            "derp" => [["derp"], "derp", "commands.php", 
                "", 
                "DERP!", 
                "", 
                0],
            "herp" => [["herp"], "herp", "commands.php", 
                "", 
                "HERP!", 
                "", 
                0],
            "dump" => [["dump"], "dump", "dev-commands.php", 
                "", 
                "Dumps variables for session debugging", 
                "", 
                0],
            "echo" => [["echo"], "echo_com", "dev-commands.php", 
                "<command>", 
                "Displays parsed command", 
                "", 
                0],
            "user" => [["user"], "user", "user-commands.php", 
                "", 
                "User-properties!", 
                "Opens a page for user properties", 
                0],
            "gallery" => [["gallery"], "gallery", "commands.php",
                "", 
                "Gallery Index", 
                "", 
                0],
        ],
        5 => [
            "login" => [["login"], "login", "user-commands.php", 
                "<username> <password>", 
                "Login", 
                "Logs the Specified User In", 
                0],
            "about" => [["about"], "about", "commands.php", 
                "", 
                "Information", 
                "Gives Information About the Website", 
                0],
            "blank" => [["blank"], "blank", "dev-commands.php", 
                "", 
                "Blank White Page", 
                "", 
                0],
        ],
        6 => [
            "logout" => [["logout"], "logout", "user-commands.php", 
                "", 
                "Logout", 
                "Logs the Current User Out", 
                0],
        ],
        8 => [
            "settings" => [["settings"], "settings", "user-commands.php", 
                "[\"name of setting\"=value]", 
                "User Interface Settings", 
                "Changes settings for the curently logged in user, or if no user is logged in, only for the current session.", 
                0],
        ],
    ];
?>