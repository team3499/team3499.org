<div class="galleryYearContent">
  <table class="images"> <?php //add fade across when each image is loaded 1 by 1. ex: fade start on 1st img -> 2nd .... ?>
    <tr>
        <?php 
  $images = [ //NOTE: This is a start for having a database supply the data here.
            "/core/img/default.jpg",
            "/core/img/2012/IMG_3863.JPG",
            "/core/img/2012/IMG_3863.JPG",
            "/core/img/2012/IMG_3863.JPG",

            "/core/img/2012/IMG_3863.JPG",
            "/core/img/default.jpg",
            "/core/img/2012/IMG_3863.JPG",
            "/core/img/2012/IMG_3863.JPG",

            "/core/img/2012/IMG_3863.JPG",
            "/core/img/2012/IMG_3863.JPG",
            "/core/img/default.jpg",
            "/core/img/2012/IMG_3863.JPG",

            "/core/img/2012/IMG_3863.JPG",
            "/core/img/2012/IMG_3863.JPG",
            "/core/img/2012/IMG_3863.JPG",
            "/core/img/default.jpg"
            ];
      $count = 0;
      foreach($images as $imgname){
        echo "<td class=\"tooltip-td\" id=\"";
        echo $count++; 
        echo "\" img=\"". $imgname . "\"><span class=\"tooltip-span\">tooltip 1</span>";
        echo "<span class=\"tooltip-span-2\">tooltip 2</span></td>";
      }

    
    echo "
    </tr>
  </table>
  <script type=\"text/javascript\">
  //alert(''+$('.tooltip-td').attr('img'));
  var counter = 0;
  var totalCount =". $count .";"; // This will be one more than the highest id. All the id's need to be sequential.
                                 // Also, the id's should be changed to have more specific id's
  echo "
  while(counter < totalCount){
    $('td.tooltip-td#'+counter).css(\"background-image\", \"url('\" + $('td.tooltip-td#'+counter).attr('img') + \"')\");
    $('td.tooltip-td#'+counter).click(function(){
      window.open($('td.tooltip-td#'+counter).attr('img'));
    });
    ". // TODO: This gives an invalid page. Yea. work with charlie-api more
  "
  counter = counter + 1;
  } ";
echo "</script>";
?>
<script type="text/javascript">
  ;
    
</script>
</div>