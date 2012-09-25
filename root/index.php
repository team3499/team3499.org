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
	
	require_once("../phpfiles/browser_check.php");
?>
<!DOCTYPE html>
<html>
<head>
<title>Team 3499 River's Edge Robotics</title>
<meta name="description" content="We are Team 3499, River\'s Edge Robotics part of Oyster River High School located in Hew Hampshire." />
<meta name="keywords" content="team 3499, rivers edge robotics, first, oyster river, 3499" />
<meta name="viewport" content="width=400;" />
<meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
<link rel="stylesheet" href="/core/style.css" media="all" />
<link rel="icon" href="/core/favicon.ico" type="image/x-icon" />
<link rel="shortcut icon" href="/core/favicon.ico" type="image/x-icon" />

<script src="/core/jquery172.js"></script>
<script src="/core/jquery.history.js"></script>
<script src="/core/main.js"></script>
<script>
	var loadonload = "<?php if($initcall){echo $initcommand;} ?>";
</script>
</head>
<body>
<br/>
<br/>
<div class="header">
  <div class="float-right" width="30%">
    <div class="headSearch">
          <input class="searchBar" type="search" name="search" value="Search..."/>
    </div>
    <div class="headIcons">
    <a href="#"><img width="25px" src="/core/img/facebook.png" class="head-icons"/></a>
    <a href="#"><img width="24px" src="/core/img/rss.png" class="head-icons"/></a>
    </div>
  </div>
  <div class="float-left" style="width:300px">
    <a href="/"><img class="sitelogo" height="25px" src="/core/img/logo.png"/></a>
    <p>River's Edge Robotics</p>
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
<div class="left">
    <br/>
    <div class="user">
        <p>Logged in as:<br/>&nbsp;&nbsp;&nbsp;User<a href="<!-- edit user account settings -->"><i style="float:right;margin-right:15px;">edit</i></a></p>
    <!-- we should also have a guest account -->
    </div>
    <br/>
    <div class="link-box">
		<p id="resources-title">>Resources</p>
		<ul id="resources">
			<li><a href="#">>FRC Website</a></li>
			<ul>
				 <li><a href="#">FRC Competition Manuals</a></li>
				 <li><a href="#">FRC Q&A System</a></li>
			</ul>
			<li><a href="#">>WPILib</a></li>
			<ul>
				<li><a href="#">WPILib Cookbook</a></li>
				<li><a href="#">WPILib Users Guide</a></li>
				<li><a href="#">WPILib C++ Getting Started Guide</a></li>
			</ul>
			<li><a href="#">Facebook Page</a></li>
			<li><a href="#">ORHS</a></li>
		</ul>
		<p id="categories-title">>Categories</p>
		<ul id="categories">
			<li><a href="#">Blog and events</a></li>
			<li><a href="#">Competition</a></li>
			<li><a href="#">Events</a></li>
			<li><a href="#">Meetings</a></li>
			<li><a href="#">Programming</a></li>
			<li><a href="#">Robot</a></li>
			<li><a href="#">Sponsors</a></li>
		</ul>
		<p id="important-dates-title">>Important Dates</p>
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
        <a href="http://www.google.com" id="sponsor-img-1"><img src="/core/img/default.jpg" width="200px" class="sponsor"/></a>
        <a href="http://www.yahoo.com" id="sponsor-img-2"><img src="/core/img/default2.jpg" width="200px" class="sponsor"/></a>
    </div>
  <!-- Here, cycle through images, starting with a random one, and change the link that they go to when they change -->
</div>

<!-- right column -->
<div class="right">

    <div class="navbar">
        <div class="linksbox">
            <span class="links"><a href="/">Home</a></span>
            <span class="links"><a href="#">About</a></span>
            <span class="links"><a href="#">Images</a></span>
            <span class="links"><a href="#">Task List</a></span>
            <span class="links"><a href="#">Link 12345</a></span>
            <span class="linksDonate"><a href="#">Donate</a></span>
            <div class="head">
                <div class="headTitle"><p><strong>River's Edge Robotics</strong><p></div>
            </div>
        </div>
        <br style="clear:both;" />
    </div>

    <div id="content">

    </div>
</div>
<!-- end stuff here -->
</div>
</body>
</html>