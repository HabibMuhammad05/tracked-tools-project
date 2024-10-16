// ipaddress/led1/on
//ipaddress/led1/off

// ipaddress/led2/on
//ipaddress/led2/off

char webpage[] PROGMEM = R"=====(

<!DOCTYPE html>
<html>
<body>

<center>
<h1>My Home Automation</h1>

<h3> LED 1 </h3>
<button onclick="window.location = 'http://'+location.hostname+'/led1/on'">On</button><button onclick="window.location = 'http://'+location.hostname+'/led1/off'">Off</button>
<h3> LED 2 </h3>
<button onclick="window.location = 'http://'+location.hostname+'/led2/on'">On</button><button onclick="window.location = 'http://'+location.hostname+'/led2/off'">Off</button>

</center>
</body>
</html>

)=====";
