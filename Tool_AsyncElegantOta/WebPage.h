char webpage[] PROGMEM = R"=====(

<!DOCTYPE html>
<html>
  <meta name='viewport' content='width=device-width, initial-scale=1'>
  <head>
    <title>webpage sederhana</title>
    <style>
    button {
      margin: 3px 1px 3px 1px;
      display: inline-block; cursor: pointer; box-shadow: 1px 1px 2px 0 rgba(0,0,0,0.2);
      font: normal normal bold 17px/normal "Times New Roman", Times, serif;
      text-shadow:0px 1px 0px #b23e35; color: rgba(255,255,255,1); background: #e06666;
      border-radius:28px; border:1px solid #ffffff; padding:16px 31px;
    }
    hr {
      margin: 47px 10px 47px 10px; border: 2px solid #eee;
    }
    .key { 
      background-color:#ffffff; border-radius:15px; color:#000000; font-size:14px; padding:75px 15px;
    }
    </style>  
<script>

var connection = new WebSocket('ws://'+location.hostname+':81/');

var PlayerData = 0;
var MusikData = 0;

function Player(playermode)
{
  PlayerData = playermode; 
  console.log("player - " '+playermode+');
  send_data();
}

function Musik(musikmode)
{
  MusikData = musikmode;
console.log("musik - " '+musikmode+');
send_data();
}

function send_data()
{
  var full_data = '{"PLAYER" :'+PlayerData+',"MUSIK":'+MusikData+'}';
  connection.send(full_data);
}


</script>
<body style="background-color:DodgerBlue;">

<center>
<h1>esp8266 WebServer</h1>
<hr/>
<h3> Player </h3>
<div>
    <button onclick= "Player(1)" >On</button>
    <button onclick="Player(2)" >Random</button>
    <button onclick="Player(3)" >Off</button>
</div>
<hr/>
<h3> Musik </h3>
<div>
    <button onclick="Musik(1)">satu</button>
    <button onclick="Musik(2)">dua</button>
    <button onclick="Musik(3)">tiga</button>
    <button onclick="Musik(4)">empat</button>
    <button onclick="musikmode(5)">Lima</button>
    <button onclick="musikmode(6)">enam</button>
</div>
<hr/>
<h3>Update Software</h3>
<button class="tombol" onclick="window.location = 'http://'+location.hostname+'/update'">Update</button>


</center>
</body>
</html>

)=====";
