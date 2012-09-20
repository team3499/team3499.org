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
