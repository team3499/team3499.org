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
});

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