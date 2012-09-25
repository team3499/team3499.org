

$(document).ready(function() {
    $('#resources').hide();
    $('#categories').hide();
    $('#important-dates').hide();
    setTimeout(hideAddressBar, 0);
    setTimeout(toggleImg, 0);
	$('input[type="search"]').addClass("headSearch");
	$('input[type="search"]').focus(function() {
        if(this.value == this.defaultValue){
          this.value = '';  
        }
        if(this.value != this.defaultValue){
          this.select();
        }
	});
	$('input[type="search"]').blur(function(){
		if($.trim(this.value == '')){
			this.value = (this.defaultValue ? this.defaultValue : '');
		}
	});
    $('#resources-title').click(function(){
        $('#resources').toggle();
        $('#categories').hide();
        $('#important-dates').hide();
    });
    $('#categories-title').click(function(){
        $('#categories').toggle();
        $('#resources').hide();
        $('#important-dates').hide();
    });
    $('#important-dates-title').click(function(){
        $('#important-dates').toggle();
        $('#categories').hide();
        $('#resources').hide();
    });
    
    loadContent(loadonload);
});

function sendCommand(value){
    $('#pagecontent').fadeOut(500, function(){
        loadContent(value);
    });
    return false;
}
function loadContent(value){
    /*DEBUG*/console.log("  ::COMMAND::  \"" + value +'"');
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.onreadystatechange = function(){
        if(xmlhttp.readyState == 4 && xmlhttp.status == 200){
            cleanload = 0;
            /*DEBUG*/console.log("  ::PLAIN::  " + xmlhttp.responseText);
            response = JSON.parse(xmlhttp.responseText);
            //if(history.pushState && history.replaceState) {
                //push current id, title and url
                //history.pushState({"id":100}, document.title, location.href);
                window.History.pushState({id:101},"",response.path);
            //}
            document.title = response.pagetitle;
            $('#contstyle').html(response.style);
            $('#pagecontent').html(response.content);
			$('#contscript').html(response.script);
            $('#shellcont').append(response.shell);
            /*if(settings['shell-background-color'] != "#000"){
                $('#shellin, #shellout').css("background-color", settings['shell-background-color']);
                $('#shellout').css("box-shadow", "0 0 15px "+settings['shell-background-color']);
            }*/
            $(window).resize();
			$('#pagecontent').fadeIn(500);
        }
    };
	var c = "c="+value;
    if(cleanload){
        c += "&ps="+cleanload;
		/*DEBUG*/console.log("  ::PS::  " + cleanload);
    }
	xmlhttp.open("POST", "/core/index.php", true);
	xmlhttp.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
	xmlhttp.setRequestHeader("Content-Length", c.length);
	xmlhttp.setRequestHeader("Connection", "close");
    xmlhttp.send(c);
}

function hideAddressBar(){
	window,scrollTo(0, 1);
}
function sleep(delay){
	var start = new Date().getTime();
	while (new Date().getTime() < start + delay);
}
function toggleImg(){
    $('#sponsor-img-2').fadeIn(1000);
    $('#sponsor-img-1').fadeOut(1000, function(){
        setTimeout(toggleImg2, 5000);
    });
}
function toggleImg2(){
    $('#sponsor-img-1').fadeIn(1000);
    $('#sponsor-img-2').fadeOut(1000, function(){
        setTimeout(toggleImg, 5000);
    });
}