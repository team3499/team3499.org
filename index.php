<?php
$title = ('<title>Team 3499 River\'s Edge Robotics</title>');
$meta = ('
<meta name="description" content="We are Team 3499, River\'s Edge Robotics part of Oyster River High School located in Hew Hampshire." />
<meta name="keywords" content="team 3499, rivers edge robotics, first, oyster river, 3499" />
<meta name="author" content="" />
');
include(getenv("DOCUMENT_ROOT")."/php/top.php");
?>
<!-- this head is here in case you want to put other stuff here pertaining to one document-->
</head>
<?php include(getenv("DOCUMENT_ROOT")."/php/topTwo.php"); ?>
<!-- enter stuff here -->


<!-- left column -->
<div class="left">
  <!-- home picture -->
  <a href="/"><img class="sitelogo" width="210px" src="/files/logo.png"/></a>
  <p>Resources</p>
  <ul>
     <li><a href="#">FRC Website</a></li>
     <ul>
         <li><a href="#">FRC Competition Manuals</a></li>
         <li><a href="#">FRC Q&A System</a></li>
     </ul>
     <li><a href="#">WPILib</a></li>
     <ul>
         <li><a href="#">WPILib Cookbook</a></li>
         <li><a href="#">WPILib Users Guide</a></li>
         <li><a href="#">WPILib C++ Getting Started Guide</a></li>
     </ul>
     <li><a href="#">Facebook Page</a></li>
     <li><a href="#">ORHS</a></li>
  </ul>
<p>Catagories</p>
  <ul>
     <li><a href="#">Blog and events</a></li>
     <li><a href="#">Competition</a></li>
     <li><a href="#">Events</a></li>
     <li><a href="#">Meetings</a></li>
     <li><a href="#">Programming</a></li>
     <li><a href="#">Robot</a></li>
     <li><a href="#">Sponsors</a></li>
  </ul>
<p>Important Dates</p>
	<ul>
     <li><a href="#">Example</a></li>
     <li><a href="#">Example</a></li>
     <li><a href="#">Example</a></li>
     <li><a href="#">Example</a></li>
     <li><a href="#">Example</a></li>
	</ul>
	
  <p class="sponsorsTitle"><strong>Sponsors</strong></p>
  <a href="#"><img src="/files/default.jpg" width="200px" /></a><br />
  <a href="#"><img src="/files/default.jpg" width="200px" /></a><br />
  <a href="#"><img src="/files/default.jpg" width="200px" /></a>
</div>

<!-- right column -->
<div class="right">

<?php
include(getenv("DOCUMENT_ROOT")."/php/navbar.php");
?>

<!-- a common post -->
  <div class="post">
    <div class="postTitle">
      <span class="postTitle"><strong>Title</strong></span>
      <div class="postDate">
      9/17/2012
      </div>
    </div>
    <div class="postPadding">
      <div class="postImg"><img height="100px" width="100px" src="/files/default.jpg" />
      </div>
      <div class="postText">
        <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.<br /><br />
        Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
      </div>
      <div class="postCata">
      <a href="#">Blog and Events</a>
      </div>
      <div class="postCommentButton">
      <a href="#"><img width="25px" src="/files/bubble.png" /></a>
        <div class="postCommentNum">
        <a href="#">5</a>
        </div>
      </div>
    </div>
  </div>
  <!-- common post end -->

    <!-- a common post -->
  <div class="post">
    <div class="postTitle">
      <span class="postTitle"><strong>Title</strong></span>
      <div class="postDate">
      9/17/2012
      </div>
    </div>
    <div class="postPadding">
      <div class="postImg"><img height="100px" width="100px" src="/files/default.jpg" />
      </div>
      <div class="postText">
        <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.<br /><br />
        Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.<br /><br />
        Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
      </div>
      <div class="postCata">
      <a href="#">Blog and Events</a>
      </div>
      <div class="postCommentButton">
      <a href="#"><img width="25px" src="/files/bubble.png" /></a>
        <div class="postCommentNum">
        <a href="#">10</a>
        </div>
      </div>
    </div>
  </div>
  <!-- common post end -->

</div>
<!-- end stuff here -->
<?php include(getenv("DOCUMENT_ROOT")."/php/bottom.php"); ?>