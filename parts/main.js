comindex = 0;
var comarray = new Array();
var wip = false;
var response;
var pagecont = "";
comarray[0] = loadonload;
var history = new Array();
var historyid = 0;
var settings = new Array();
settings['hide-shell-on-send'] = 1;
settings['shell-background-color'] = "#000";
var cleanload = 1;

$(document).ready(function(){
    $('#shellout').click(function(){
        $('#shelline').focus();
    });
    $('#shellline').focus(function(){
        $('#shellin').css("box-shadow", "0 0 10px "+settings['shell-background-color']);
        $('#shellout').css("visibility", "visible");
        if($('#shellline').val() == "Awaiting Command..."){
            $('#shellline').val("");
        }
        $('#shellblink').html('> '.blink());
    });
    $('#shellline').blur(function(){
        $('#shellin').css("box-shadow", "none");
        $('#shellout').css("visibility", "hidden");
        //var str = $('#shelline').val();
        //var num = str.replace(/\s/g, '').length;
        //alert(num);
        if(!$('#shellline').val().replace(/\s/g, '').length){
            $('#shellline').val("Awaiting Command...");
        }
        $('#shellblink').html('> ');
    });
    /*$(document).on("click", function(){
    });*/
    $('#shellline').keydown(function(event){
        var value = this.value;
        if(event.which === 13){ /*ENTER*/
            if(/\S/.test(value)){
                if(settings['hide-shell-on-send']){
                    $('#shellout').css("visibility", "hidden");
                }
                sendCommand(value);
                comarray[comarray.length] = value;
                comindex = comarray.length;
                this.value = '';
            } else {
                this.value = '';
            }
        }else if(event.which == 27){ /*ESCAPE*/
            $('#shellout').css("visibility", "hidden");
        }else if(event.which == 38 && comindex > 0){ /*UP*/
            if(/\S/.test(value)){
                comindex--;
                this.value = comarray[comindex];
            } else {
                this.value = comarray[comindex];
            }
        }else if(event.which == 40){ /*DOWN*/
            if(comindex < (comarray.length-1)){ /*In middle of array*/
                comindex++;
                this.value = comarray[comindex];
            } else { /*at end of array*/
                this.value = '';
            }
        }
        /*updateStatus(value);*/
    });
    /*window.onpopstate = function(e) {
        alert(e.state.id);
        sendCommand(history[e.state.id]);
        sendCommand(e.state.com);
    };*/
    $(window).resize(function(){
        $('#shellline').css("width", ($('#shellin').width() - $('#shellblink').width())+"px");
    });
    $(window).resize();
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
    /*historyid++;
    history[historyid] = value;*/
    xmlhttp.onreadystatechange = function(){
        if(xmlhttp.readyState == 4 /*&& xmlhttp.status == 200*/){
            cleanload = 0;
            /*DEBUG*/console.log("  ::PLAIN::  " + xmlhttp.responseText);
            response = JSON.parse(xmlhttp.responseText);
            /*if(history.pushState && history.replaceState) {
                push current id, title and url
                history.pushState({"id":100}, document.title, location.href);*/
                window.History.pushState({id:101},"",response.path);
            /*}*/
            document.title = response.pagetitle;
            $('#contstyle').html(response.style);
            $('#pagecontent').html(response.content);
            $('#contscript').html(response.script);
            $('#shellcont').append(response.shell);
            if(settings['shell-background-color'] != "#000"){
                $('#shellin, #shellout').css("background-color", settings['shell-background-color']);
                $('#shellout').css("box-shadow", "0 0 15px "+settings['shell-background-color']);
            }
            $(window).resize();
            $('#pagecontent').fadeIn(500);
        }
    };
    var c = "a="+value;
    if(cleanload){
        c += "&ps="+cleanload;
        /*DEBUG*/console.log("  ::PS::  " + cleanload);
    }
    xmlhttp.open("POST", "/", true);
    xmlhttp.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xmlhttp.setRequestHeader("Content-Length", c.length);
    xmlhttp.setRequestHeader("Connection", "close");
    xmlhttp.send(c);
}
