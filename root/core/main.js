<?php header('Content-type: text/javascript'); ?>
var cleanload = true;

$(document).ready(function() {
    $('#resources').hide();
    $('#categories').hide();
    $('#important-dates').hide();
    $('#user-info-box').hide();
    
    //var totalSponsorImages = 2;
    // start = rand() % totalSponsorImages;
    // but for now:
    //start = 1;
    //var sponsors = new Array();
    //sponsors[1] = toggleImg;
    //sponsors[2] = toggleImg2;
    //setTimeout(sponsors[Math.floor(Math.random()*sponsors.length)], 5000);
    /*for( i = 1; i <= totalSponsorImages; i++){
        if( start != i){
            $('#sponsor-img-'+i).hide();
        }
        setTimeout(toggleImg, 5000); // need to make this pick a random... it cant pick a new random one without a switch with each function
    }*/
    setTimeout(toggleImg, 5000);
    setTimeout(hideAddressBar, 0);
    
	$('input[type="search"]').addClass("headSearch");
	$('input[type="search"]').focus(function() {
        if(this.value == this.defaultValue){
          this.value = '';  
        }
        if(this.value != this.defaultValue){
          this.select();
        }
        this.style.width = 200;
	});
	$('input[type="search"]').blur(function(){
		if($.trim(this.value == '')){
			this.value = (this.defaultValue ? this.defaultValue : '');
		}
	});
    $('#resources-title').click(function(){
        $('#categories').fadeOut(function () { $('#important-dates').fadeOut(function () { $('#resources').fadeToggle(); }) });
    });
    $('#categories-title').click(function(){
        $('#resources').fadeOut(function () { $('#important-dates').fadeOut(function () { $('#categories').fadeToggle(); }) });
    });
    $('#important-dates-title').click(function(){
        $('#categories').fadeOut(function () { $('#resources').fadeOut(function () { $('#important-dates').fadeToggle(); }) });
    });
    
    $('#user-span').click(function(){
        $('#user-info-box').fadeToggle();
    });
    
    $('.link-image').click(function(){
      window.open($(this).attr('href'));
    });
    
    $('.link').click(function(){
        sendCommand($(this).attr('command'));
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
            cleanload = false;
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
<?php //echo"alert('PHP WORKS');" ?>

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