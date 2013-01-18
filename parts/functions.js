function getScrollBarWidth() {
    var inner = document.createElement('p');
    inner.style.width = "100%";
    inner.style.height = "200px";

    var outer = document.createElement('div');
    outer.style.position = "absolute";
    outer.style.top = "0px";
    outer.style.left = "0px";
    outer.style.visibility = "hidden";
    outer.style.width = "200px";
    outer.style.height = "150px";
    outer.style.overflow = "hidden";
    outer.appendChild(inner);

    document.body.appendChild(outer);
    var w1 = inner.offsetWidth;
    outer.style.overflow = 'scroll';
    var w2 = inner.offsetWidth;
    if (w1 == w2) w2 = outer.clientWidth;

    document.body.removeChild(outer);

    return (w1 - w2);
}

function updateStatus(value){
    var fullarray;
    fullarray = ("<b>comarray[0]is</b>=>"+comarray[0]+"<br/>");
    for(var i = 1;i<comarray.length;i++){
        fullarray += ("<b>comarray["+i+"]is</b>=>"+comarray[i]+"<br/>");
    }
    //$('#status').html(comarray.length+" "+comindex+" \""+value+'" "'+comarray[comindex]+'"' + "<br/>" + fullarray);
    //document.getElementById('status').innerHTML = "Array Length: "+comarray.length+"</br>Current Index: "+comindex+'</br>"'+value+'" "'+comarray[comindex]+'"' + "<br/>" + fullarray;
}
