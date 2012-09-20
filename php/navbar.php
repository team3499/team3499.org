<div class="navbar">
  <div class="linksbox">
    <span class="links"><a href="/">Home</a></span>
    <span class="links"><a href="#">About</a></span>
    <span class="links"><a href="#">Images</a></span>
    <span class="links"><a href="#">Task List</a></span>
    <span class="links"><a href="#">Link 12345</a></span>
    <span class="linksDonate"><a href="#">Donate</a></span>
    <div class="head">
     <div class="headImageBox">
      <div class="headImages">
      <a href="#"><img height="150px" src="/files/text.jpg"></a>
      <a href="#"><img height="150px" src="/files/text.jpg"></a>
      <a href="#"><img height="150px" src="/files/text.jpg"></a>
      </div>
     </div>
    <div class="headTitle"><p><strong>River's Edge Robotics</strong><p>
    </div>
    <script>
    $(document).ready(function() {
      $('input[type="search"]').addClass("headSearch");
      $('input[type="search"]').focus(function() {
        if (this.value == this.defaultValue){
          this.value = '';  
        }
        if(this.value != this.defaultValue){
          this.select();
        }
      });
      $('input[type="search"]').blur(function() {  
        if ($.trim(this.value == '')){
          this.value = (this.defaultValue ? this.defaultValue : '');
        }
      });
    });
    </script>
    </div>
  </div>
  <br style="clear:both;">
</div>