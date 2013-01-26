<script>
$(document).ready(function() {
  $('div.postCommentsBarMax').hide();
  $('div.postCommentsBarAddButton').hide();
  $('textarea.addComment').click(function() {
    $('div.postCommentsBarMax').fadeIn('10');
    $('div.postCommentsBarAddButton').fadeIn('10');
  });
});

$('textarea.addComment').keyup(function () {
    var left = 500 - $(this).val().length;
    if (left < 0) {
	left = 0;
    }
    $('#counter').text('Characters Left: ' + left);
});

$(document).ready(function() {
  $('div.postComments').hide();
  $('a#commentsShow').toggle(function() {
    $('div.postComments').slideDown('100');
    return false;
    },
    function() {
      $('div.postComments').slideUp('100');
      $('div.postCommentsBarMax').slideUp('10');
      $('div.postCommentsBarAddButton').slideUp('10');
      return false;
    });
});
</script>


<!-- a common post --> <!--
<div class="post">
    <div class="postTitle">
        <span class="postTitle"><strong>This is a Wonderful Title</strong></span>
        <div class="postDate"><i>9/17/2012</i></div>
    </div>
    <div class="postPadding">
        <div class="postImg"><a href="#"><img height="100px" width="100px" class="smallBorderShadow" src="/core/img/default.jpg" /></a>
        <div class="postUser">
        <a href="#">ExampleUser</a><br/><i class="small">Admin</i>
        </div></div>
        <div class="postText">
            <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
            <br/>
            Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
            <br/>
            <br/>
            Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
        </div>
        
        <div class="postComments">
          <div class="postCommentsBar">
            <div class="postCommentsUser">
             <img width="70px" src="/core/img/default.jpg" />
            </div>
            
            
            
            <div class="postCommentsBarAdd">
              <form><textarea class="addComment" maxlength="500" type="text"></textarea></form>
              <div class="postCommentsBarMax">
                <p id="counter">Characters Left: 500</p>
                
                
                
              </div>
              <div class="postCommentsBarAddButton">
                <button type="button" class="addComment">Add Comment</button>
              </div>
            </div>
            <div class="postCommentsBarNotice">
            <p>Comments</p>
            </div>
          </div>
          
          <div class="postCommentsComment">
            <div class="postCommentsCommentUser">
              <a href="/user"><strong>ExampleUser</strong></a> 
              <i class="small">Posted: 5 days ago</i>
              <span class="postCommentsCommentUserStatus"><i>Admin</i></span>
            </div>
            <div class="postCommentsCommentText">
              <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
            
              <button type="button" class="reply">Reply</button> <?php // when user click reply, add '@UserExample ' to  Textarea and focus it ?>
            </div>
          </div>
        </div>
        
        <div class="postCata">
            <a href="#">Blog and Events</a>
        </div>
        
        
        
        <div class="postCommentButton">
	  <a href="#" id="commentsShow" title="Click to show/hide comments">1 Comment</a> <?php //changes whith '1 Comment' and 2 Comments ?>
        </div>
    </div>
</div>-->
  <!-- common post end -->
  
  
  
  
  
  <!-- THIS IS AN EXAMPLE!!  ALSO AN 'OR' SO IF THE USER HAS A PROFILE IMAGE OR NOT-->
  
<!-- a common post -->
<div class="post">
    <div class="postTitle">
      <span class="post-user"><a href="">Brian Turnball</a> <i class="small">Admin</i></span>
        <span class="postTitle"><strong>Integrating Git with FRC Workbench</strong></span>
        <div class="postDate"><i>1/18/12</i></div>
    </div>
    <div class="postPadding">
        <!--<div class="postImg"><a href="#"><img height="100px" width="100px" class="smallBorderShadow" src="/core/img/default.jpg" /></a>
        <div class="postUser">
        <a href="#">Brian Turnbull</a><br/><i class="small">Admin</i>
        </div></div>-->
        <div class="postText">
            
<p>
For team members working on the robot source code, coordination and collaboration on source code changes can be managed using version control. We’re using <a href="#">Git</a> as our version control system.
</p>
<br/>
<p><strong>Installing on Windows</strong></p>
<br/>
<p>
<a href="#">GitHub has terrific</a> <a href="#">installation instructions for Git on Windows</a>. Follow these using the installation defaults.
</p>
<br/>
<p class="indent">
NOTE! — Since we manage our own repository, you can skip the steps for integration with GitHub (Step 4 under “Setup SSH Keys” and Step 2 under “Setup Your Info”)
</p>
<br/><p>
During the installation, you will have generated an SSH key-pair. Send the public key file to Brian Turnbull to be granted access to our upstream repository. The public key will be stored in the .ssh directory of your home directory — typically at <code>c:/Documents </code>and<code> Settings/USERNAME/.ssh/id_rsa.pub</code>.</p>
<br/>
<p>
<strong>Integration with FRC WorkBench</strong></p>
<br/><p>
Integrating Git with WorkBench is accomplished by installing the <a href="#">EGit Eclipse plugin</a>. Installation is similar to the FRC Downloader and is done in WorkBench:</p>
<br/>
<ul>
 <li>   Open the Install New Software dialog via Help > Install New Software …</li>
 <li>   Add <a href="#">http://download.eclipse.org/egit/updates</a> with a name of “EGit” as a new repository for Eclipse plugins.</li>
 <li>   Select “EGit” in the “Work with:” drop down select box.</li>
 <li>   Check the “Eclipse Git Team Provider” and then remove the “EGit Mylyn” option.</li>
 <li>   Continue the installation, accepting license agreements, restarting, etc. </li>
</ul>
<br/>
<p>
You are now ready to set up individual projects in WorkBench — we’ll do this together at the next team meeting.</p>


        </div>
        
        <div class="postComments">
        <p style="font-size:20px;color:#666;text-align:center;">Comments are currently disabled <i class="small" title="Comment system has not been implemented correctly yet." style="color:rgb(17, 109, 204);cursor:help;">why?</i></p>
        <!--
          <div class="postCommentsBar">
            <div class="postCommentsUser">
             <img width="70px" src="/core/img/default.jpg" />
            </div>
            
            <script>
            $(document).ready(function() {
	      $('div.postCommentsBarMax').hide();
	      $('div.postCommentsBarAddButton').hide();
	      $('textarea.addComment').click(function() {
		$('div.postCommentsBarMax').fadeIn('10');
		$('div.postCommentsBarAddButton').fadeIn('10');
	      });
            });
            </script>
            
            <div class="postCommentsBarAdd">
              <form><textarea class="addComment" maxlength="500" type="text"></textarea></form>
              <div class="postCommentsBarMax">
                <p id="counter">Characters Left: 500</p>
                
                <script>
		$('textarea.addComment').keyup(function () {
		    var left = 500 - $(this).val().length;
		    if (left < 0) {
			left = 0;
		    }
		    $('#counter').text('Characters Left: ' + left);
		});
		</script>
                
              </div>
              <div class="postCommentsBarAddButton">
                <button type="button" class="addComment">Add Comment</button>
              </div>
            </div>
            <div class="postCommentsBarNotice">
            <p>Comments</p>
            </div>
          </div>
          
          <div class="postCommentsComment">
            <div class="postCommentsCommentUser">
              <a href="/user"><strong>ExampleUser</strong></a> 
              <i class="small">Posted: 5 days ago</i>
              <span class="postCommentsCommentUserStatus"><i>Admin</i></span>
            </div>
            <div class="postCommentsCommentText">
              <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
            
              <button type="button" class="reply">Reply</button> <?php // when user click reply, add '@UserExample ' to  Textarea and focus it ?>
            </div>
          </div>-->
        </div>
        
        <div class="postCata">
            <a href="#">Programming</a>
        </div>
        <!--
        <script>
        $(document).ready(function() {
	  $('div.postComments').hide();
	  $('a#commentsShow').toggle(function() {
	    $('div.postComments').slideDown('100');
	    return false;
	   },
	    function() {
	      $('div.postComments').slideUp('100');
	      $('div.postCommentsBarMax').slideUp('10');
	      $('div.postCommentsBarAddButton').slideUp('10');
	      return false;
	    });
        });
        </script>
        -->
        <div class="postCommentButton">
	  <a href="#" id="commentsShow" title="Click to show/hide comments">0 Comments</a> <?php //changes whith '1 Comment' and 2 Comments ?>
        </div>
    </div>
</div>
  <!-- common post end -->
  
  <!-- a common post -->
<div class="post">
    <div class="postTitle">
      <span class="post-user"><a href="">Brian Turnball</a> <i class="small">Admin</i></span>
        <span class="postTitle"><strong>Integrating Git with FRC Workbench</strong></span>
        <div class="postDate"><i>1/18/12</i></div>
    </div>
    <div class="postPadding">
        <!--<div class="postImg"><a href="#"><img height="100px" width="100px" class="smallBorderShadow" src="/core/img/default.jpg" /></a>
        <div class="postUser">
        <a href="#">Brian Turnbull</a><br/><i class="small">Admin</i>
        </div></div>-->
        <div class="postText">
            
<p>
For team members working on the robot source code, coordination and collaboration on source code changes can be managed using version control. We’re using <a href="#">Git</a> as our version control system.
</p>
<br/>
<p><strong>Installing on Windows</strong></p>
<br/>
<p>
<a href="#">GitHub has terrific</a> <a href="#">installation instructions for Git on Windows</a>. Follow these using the installation defaults.
</p>
<br/>
<p class="indent">
NOTE! — Since we manage our own repository, you can skip the steps for integration with GitHub (Step 4 under “Setup SSH Keys” and Step 2 under “Setup Your Info”)
</p>
<br/><p>
During the installation, you will have generated an SSH key-pair. Send the public key file to Brian Turnbull to be granted access to our upstream repository. The public key will be stored in the .ssh directory of your home directory — typically at <code>c:/Documents </code>and<code> Settings/USERNAME/.ssh/id_rsa.pub</code>.</p>
<br/>
<p>
<strong>Integration with FRC WorkBench</strong></p>
<br/><p>
Integrating Git with WorkBench is accomplished by installing the <a href="#">EGit Eclipse plugin</a>. Installation is similar to the FRC Downloader and is done in WorkBench:</p>
<br/>
<ul>
 <li>   Open the Install New Software dialog via Help > Install New Software …</li>
 <li>   Add <a href="#">http://download.eclipse.org/egit/updates</a> with a name of “EGit” as a new repository for Eclipse plugins.</li>
 <li>   Select “EGit” in the “Work with:” drop down select box.</li>
 <li>   Check the “Eclipse Git Team Provider” and then remove the “EGit Mylyn” option.</li>
 <li>   Continue the installation, accepting license agreements, restarting, etc. </li>
</ul>
<br/>
<p>
You are now ready to set up individual projects in WorkBench — we’ll do this together at the next team meeting.</p>


        </div>
        
        <div class="postComments">
        <p style="font-size:20px;color:#666;text-align:center;">Comments are currently disabled <i class="small" title="Comment system has not been implemented correctly yet." style="color:rgb(17, 109, 204);cursor:help;">why?</i></p>
        <!--
          <div class="postCommentsBar">
            <div class="postCommentsUser">
             <img width="70px" src="/core/img/default.jpg" />
            </div>
            
            <script>
            $(document).ready(function() {
	      $('div.postCommentsBarMax').hide();
	      $('div.postCommentsBarAddButton').hide();
	      $('textarea.addComment').click(function() {
		$('div.postCommentsBarMax').fadeIn('10');
		$('div.postCommentsBarAddButton').fadeIn('10');
	      });
            });
            </script>
            
            <div class="postCommentsBarAdd">
              <form><textarea class="addComment" maxlength="500" type="text"></textarea></form>
              <div class="postCommentsBarMax">
                <p id="counter">Characters Left: 500</p>
                
                <script>
		$('textarea.addComment').keyup(function () {
		    var left = 500 - $(this).val().length;
		    if (left < 0) {
			left = 0;
		    }
		    $('#counter').text('Characters Left: ' + left);
		});
		</script>
                
              </div>
              <div class="postCommentsBarAddButton">
                <button type="button" class="addComment">Add Comment</button>
              </div>
            </div>
            <div class="postCommentsBarNotice">
            <p>Comments</p>
            </div>
          </div>
          
          <div class="postCommentsComment">
            <div class="postCommentsCommentUser">
              <a href="/user"><strong>ExampleUser</strong></a> 
              <i class="small">Posted: 5 days ago</i>
              <span class="postCommentsCommentUserStatus"><i>Admin</i></span>
            </div>
            <div class="postCommentsCommentText">
              <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
            
              <button type="button" class="reply">Reply</button> <?php // when user click reply, add '@UserExample ' to  Textarea and focus it ?>
            </div>
          </div>-->
        </div>
        
        <div class="postCata">
            <a href="#">Programming</a>
        </div>
        <!--
        <script>
        $(document).ready(function() {
	  $('div.postComments').hide();
	  $('a#commentsShow').toggle(function() {
	    $('div.postComments').slideDown('100');
	    return false;
	   },
	    function() {
	      $('div.postComments').slideUp('100');
	      $('div.postCommentsBarMax').slideUp('10');
	      $('div.postCommentsBarAddButton').slideUp('10');
	      return false;
	    });
        });
        </script>
        -->
        <div class="postCommentButton">
	  <a href="#" id="commentsShow" title="Click to show/hide comments">0 Comments</a> <?php //changes whith '1 Comment' and 2 Comments ?>
        </div>
    </div>
</div>
  <!-- common post end -->
