<div class="galleryYearContent">
  <table class="images"> <?php //add fade across when each image is loaded 1 by 1. ex: fade start on 1st img -> 2nd .... ?>
    <tr>
      <td class="tooltip-td" id="0" img="url('/core/img/2012/IMG_3863.JPG')"><span class="tooltip-span">tooltip test</span></a></td>
      <td class="tooltip-td" id="1" img="url('/core/img/2012/IMG_3868.JPG')"><span class="tooltip-span">tooltip test</span></a></td>
      <td class="tooltip-td" id="2" img="url('/core/img/2012/IMG_3893.JPG')"><span class="tooltip-span">tooltip test</span></td>
      <td class="tooltip-td" id="3" img="url('/core/img/default.jpg')"><span class="tooltip-span">tooltip test</span></td>
    </tr>
    <tr>
      <td><a href="#" class="tooltip"><img src="/core/img/2012/IMG_3863.JPG"/><span>tooltip test</span></a></td>
      <td><a href="#" class="tooltip"><img src="/core/img/2012/IMG_3868.JPG"/><span>tooltip test</span></a></td>
      <td><a href="#" class="tooltip"><img src="/core/img/2012/IMG_3893.JPG"/><span>tooltip test</span></a></td>
      <td><a href="#" class="tooltip"><img src="/core/img/2012/IMG_3874.JPG"/><span>tooltip test</span></a></td>
    </tr>
    <tr>
      <td><a href="#" class="tooltip"><img src="/core/img/2012/IMG_3863.JPG"/><span>tooltip test</span></a></td>
      <td><a href="#" class="tooltip"><img src="/core/img/2012/IMG_3868.JPG"/><span>tooltip test</span></a></td>
      <td><a href="#" class="tooltip"><img src="/core/img/2012/IMG_3893.JPG"/><span>tooltip test</span></a></td>
      <td><a href="#" class="tooltip"><img src="/core/img/2012/IMG_3874.JPG"/><span>tooltip test</span></a></td>
    </tr>
    <tr>
      <td><a href="#" class="tooltip"><img src="/core/img/2012/IMG_3863.JPG"/><span>tooltip test</span></a></td>
      <td><a href="#" class="tooltip"><img src="/core/img/2012/IMG_3868.JPG"/><span>tooltip test</span></a></td>
      <td><a href="#" class="tooltip"><img src="/core/img/2012/IMG_3893.JPG"/><span>tooltip test</span></a></td>
      <td><a href="#" class="tooltip"><img src="/core/img/2012/IMG_3874.JPG"/><span>tooltip test</span></a></td>
    </tr>
  </table>
  <script type="text/javascript">
  //alert(''+$('.tooltip-td').attr('img'));
  var count = 0;
  while($('td.tooltip-td#'+count)){
    $('td.tooltip-td#'+count).css("background-image",$('td.tooltip-td#'+count).attr('img'));
    count = count + 1;
  }
</script>
</div>