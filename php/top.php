<!DOCTYPE html>
<head>
<?php
echo $title;
echo $meta;
echo '<meta name="viewport" content="width=400;" />
<meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
<link rel="stylesheet" href="/fouc.css" media="all" />
<link rel="stylesheet" href="/style.css" media="all" />
<link rel="icon" href="/files/favicon.ico" type="image/x-icon" />
<link rel="shortcut icon" href="/files/favicon.ico" type="image/x-icon" />';
include(getenv("DOCUMENT_ROOT")."/php/headExtra.php");
?>

<script src="/js/jquery172.js" type="text/javascript"></script>
<script>
	addEventListener('load', function() {
		setTimeout(hideAddressBar, 0);
	}, false);
	function hideAddressBar() {
		window,scrollTo(0, 1);
	}
</script>

<!-- this is to hide/show the links -->
<!-- please make this (slide) smoother -->
<script>

function showHideId(id){
	var x = document.getElementById(id);
	if (x.currentStyle)
		var y = x.currentStyle['display'];
	else if (window.getComputedStyle)
		var y = document.defaultView.getComputedStyle(x,null).getPropertyValue('display');
	if(y == 'none'){
    showId(id);
  } else {
    hideId(id);
  }
}


function hideId(id) {
	//safe function to hide an element with a specified id
	if (document.getElementById) { // DOM3 = IE5, NS6
		document.getElementById(id).style.display = 'none';
	}
	else {
		if (document.layers) { // Netscape 4
			document.id.display = 'none';
		}
		else { // IE 4
			document.all.id.style.display = 'none';
		}
	}
}

function showId(id) {
	//safe function to show an element with a specified id
		  
	if (document.getElementById) { // DOM3 = IE5, NS6
		document.getElementById(id).style.display = 'block';
	}
	else {
		if (document.layers) { // Netscape 4
			document.id.display = 'block';
		}
		else { // IE 4
			document.all.id.style.display = 'block';
		}
	}
}
</script>