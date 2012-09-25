<style type="text/css">

</style>
<script>
    $(document).ready(function(){
        function getsett(name){
            return " "+name+' "'+$('input[name="'+name+'"]').val()+'"';
        }
        preset();
        $('#submit-settings').click(function(){
			var subsett = "settings";
			subsett += getsett("hide-shell-on-send");
			subsett += getsett("shell-background-color");
            sendCommand(subsett);
        });
    });
</script>
<div class="default-wrapper">
    Hide Shell on Command Send:
	<input type="radio" name="hide-shell-on-send" value="1" />Yes
    <input type="radio" name="hide-shell-on-send" value="0" />No
    <br/>
    <br/>
    Shell Background Color:
    <input type="text" name="shell-background-color" />
    <br/>
    <br/>
    <button id="submit-settings">Submit Settings</button>
</div>