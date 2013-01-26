<?php
    header("Cache-Control: no-cache");
    header("Pragma: no-cache");
    $command = explode("/", $_SERVER['REQUEST_URI']);
    array_shift($command);
	$initcall = false;
	$initcommand = "";
	foreach($command as $val){
		$initcommand .= " ".$val;
	}
	if($initcommand != ""){
        $initcommand = substr($initcommand, 1);
		$initcall = true;
	}
	
	//require_once("browser_check.php");
?>
<!DOCTYPE html>
<html>
<head>
<title>Team 3499</title>
<meta name="description" content="We are Team 3499, River\'s Edge Robotics part of Oyster River High School located in Hew Hampshire." />
<meta name="keywords" content="team 3499, rivers edge robotics, first, oyster river, 3499" />
<meta name="viewport" content="width=400;" />
<meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
<link rel="stylesheet" href="/core/style.css" media="all" />
<link rel="icon" href="/core/img/favicon.ico" type="image/x-icon" />
<link rel="shortcut icon" href="/core/img/favicon.ico" type="image/x-icon" />
<link rel="apple-touch-icon" href="/core/img/favicon.ico" />

<script src="/core/jquery172.js"></script>
<script src="/core/jquery.history.js"></script>
<script src="/core/main.js"></script>
<script>
	var loadonload = "<?php if($initcall){echo $initcommand;} ?>";
</script>
<div id="contscript"></div>
<div id="contstyle"></div>
</head>
<body>
<br/>
<br/>
<div class="header">
  <div class="float-right" width="30%">
    <div class="headSearch">
          <input class="searchBar" maxlength="200" type="textarea" name="search" value="Search..."/>
    </div>
    <div class="headIcons">
    <img width="25px" src="/core/img/facebook.png" class="head-icons link-image" href="http://www.facebook.com/groups/137871619595813/"/>
    <img width="24px" src="/core/img/rss.png" class="head-icons link-image" href="http://www.google.com"/>
    </div>
  </div>
  <div class="float-left" style="width:600px">
    <a href="/"><img class="sitelogo" height="25px" src="/core/img/logoSmall.png"/></a>
    <p>River's Edge Robotics Team 3499 <i class="small">Our robot goes [--this--] fast.</i></p>
  </div>
<!-- </div>
<div class="header header-left"> -->
  <!-- home picture -->
</div>
<div class="left-shadow">
</div>
<div class="right-shadow">
</div>
<div class="container">
<!-- enter stuff here -->

<!-- left column -->
<div class="leftWrapper">
<div class="left">
  <a href="/"><img width="100%" src="/core/img/logo.png"/></a> <?php //get rid of if you don't like it where it is. I do think we should have a large logo somewhere though ?>
    <div class="user">
        <p>Logged in as:<br/>&nbsp;&nbsp;&nbsp;<span id="user-span">User</span><span id="user-edit" class="link" command="user"><i>edit</i></span></p>
        <div id="user-info-box">
        <p>Content goes here</p>
        <p>Username</p>
        <p>Something</p>
        </div>
    <!-- we should also have a guest account -->
    </div>
    <br/>
    <div class="link-box">
        <p><span id="resources-title-span">> Resources</span></p>
        <ul id="resources">
        <li><a href="http://www.usfirst.org/roboticsprograms/frc" target="_blank">FRC Website</a></li>
            <ul>
                <li><a href="http://www.usfirst.org/roboticsprograms/frc/competition-manual-and-related-documents" target="_blank">FRC Competition Manuals</a></li>
                <li><a href="http://www.usfirst.org/roboticsprograms/frc/game-q-and-a" target="_blank">FRC Q&A System</a></li>
            </ul>
                <li><a href="http://firstforge.wpi.edu/sf/projects/wpilib" target="_blank">WPILib</a></li>
            <ul>
                <li><a href="http://firstforge.wpi.edu/sf/go/doc1297?nav=1" target="_blank">WPILib Cookbook</a></li>
                <li><a href="http://firstforge.wpi.edu/sf/go/doc1196?nav=1" target="_blank">WPILib Users Guide</a></li>
                <li><a href="http://firstforge.wpi.edu/sf/go/doc1197?nav=1" target="_blank">WPILib C++ Getting Started Guide</a></li>
            </ul>
        <li><a href="http://www.facebook.com/groups/137871619595813/" target="_blank">Facebook Page</a></li>
            <li><a href="http://orcsd.org/school/orhs" target="_blank">ORHS</a></li>
        </ul>
        <p><span id="categories-title-span">> Categories</span></p>
        <ul id="categories">
            <li><a href="#">Blog and events</a></li>
            <li><a href="#">Competition</a></li>
            <li><a href="#">Events</a></li>
            <li><a href="#">Meetings</a></li>
            <li><a href="#">Programming</a></li>
            <li><a href="#">Robot</a></li>
            <li><a href="#">Sponsors</a></li>
        </ul>
        <p><span id="important-dates-title-span">> Important Dates</span></p>
        <ul id="important-dates">
            <li><a href="#">Example</a></li>
            <li><a href="#">Example</a></li>
            <li><a href="#">Example</a></li>
            <li><a href="#">Example</a></li>
            <li><a href="#">Example</a></li>
        </ul>
    </div>
    <br/>
    <p class="sponsorsTitle"><strong>Sponsors</strong></p>
    <div>
<img src="/core/img/default.jpg" class="sponsor link-image" id="sponsor-img-1" href="http://www.yahoo.com"/>
<img src="/core/img/default2.jpg" class="sponsor link-image" id="sponsor-img-2" href="http://www.google.com"/>
    </div>
</div>
</div>

<!-- right column -->
<div class="right">

    <div class="navbar">
        <div class="linksbox">
            <span class="link tab-links" command="home">Home</span>
            <span class="link tab-links" command="about">About</span>
            <span class="link tab-links" command="gallery">Gallery</span>
            <span class="link tab-links" command="task-schedule">Task Schedule</span> <!-- calender! -->
            <span class="link tab-links">FIRST</span>
            <span class="tab-links linkDonate">Donate</span>
            <div class="head">
                <div class="headTitle"><p><strong>River's Edge Robotics </strong><p></div>
                <span style="float:right;">#######TWITTER FEED</span> <!-- charlie or ethan plz -->
            </div>
        </div>
        <br style="clear:both;" />
    </div>

    <div id="pagecontent">

    </div>
    <div id="scroll-padding">
    Easter Egg!
    </div>
</div>
<!-- end stuff here -->
</div>
<div class="footer">
Copyright &copy; 2012,<a href="/">Team3499.org</a>
</div>
</body>
</html>