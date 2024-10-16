char webpage[] PROGMEM = R"=====(

<!DOCTYPE HTML><html>
  <head>
    <title>ESP Web Server</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
      body { font-family: Arial; text-align: center; margin:0px auto; padding-top: 30px; background-color: dodgerblue;}
      button {
        padding: 10px 20px;
        font-size: 24px;
        text-align: center;
        outline: none;
        color: #fff;
        background-color: #2f4468;
        border: none;
        border-radius: 5px;
        box-shadow: 0 6px #999;
        cursor: pointer;
        -webkit-touch-callout: none;
        -webkit-user-select: none;
        -khtml-user-select: none;
        -moz-user-select: none;
        -ms-user-select: none;
        user-select: none;
        -webkit-tap-highlight-color: rgba(0,0,0,0);
      }  
      button:hover {background-color: #1f2e45}
      button:active {
        background-color: #1f2e45;
        box-shadow: 0 4px #666;
        transform: translateY(2px);
      }
      .key { 
       border-radius:15px; color:#ffffff; font-size:14px; padding:75px 15px;
    }
      .tombol { padding: 10px 15px; font-size: 14px;}
    hr {
    margin: 30px 10px 30px 10px; border: 2px solid #eee;
  }
    </style>
  </head>
  <body>
    <h1>ESP Pushbutton Web Server</h1>
    <br/>
    <hr>
    <div>
      <h3>Manual Control</h3>
      <button class="key" onmousedown="toggleCheckbox('do');" ontouchstart="toggleCheckbox('1');" onmouseup="toggleCheckbox('Noteoff');" ontouchend="toggleCheckbox('Noteoff');">1</button>
      <button class="key" onmousedown="toggleCheckbox('re');" ontouchstart="toggleCheckbox('2');" onmouseup="toggleCheckbox('Noteoff');" ontouchend="toggleCheckbox('Noteoff');">2</button>
      <button class="key" onmousedown="toggleCheckbox('mi');" ontouchstart="toggleCheckbox('3');" onmouseup="toggleCheckbox('Noteoff');" ontouchend="toggleCheckbox('Noteoff');">3</button>
      <button class="key" onmousedown="toggleCheckbox('fa');" ontouchstart="toggleCheckbox('4');" onmouseup="toggleCheckbox('Noteoff');" ontouchend="toggleCheckbox('Noteoff');">4</button>
      <button class="key" onmousedown="toggleCheckbox('sol');" ontouchstart="toggleCheckbox('5');" onmouseup="toggleCheckbox('Noteoff');" ontouchend="toggleCheckbox('Noteoff');">5</button>
      <button class="key" onmousedown="toggleCheckbox('la');" ontouchstart="toggleCheckbox('6');" onmouseup="toggleCheckbox('Noteoff');" ontouchend="toggleCheckbox('Noteoff');">6</button>
      <button class="key" onmousedown="toggleCheckbox('si');" ontouchstart="toggleCheckbox('7');" onmouseup="toggleCheckbox('Noteoff');" ontouchend="toggleCheckbox('Noteoff');">7</button>
      <button class="key" onmousedown="toggleCheckbox('do2');" ontouchstart="toggleCheckbox('8');" onmouseup="toggleCheckbox('Noteoff');" ontouchend="toggleCheckbox('Noteoff');">8</button>
      
    </div>
    <br>
    <hr>
    <h3>Music Select</h3>
    <div>
      <button class="tombol" onclick="toggleCheckbox('1')">satu</button>
      <button class="tombol" onclick="toggleCheckbox('2')">dua</button>
      <button class="tombol" onclick="toggleCheckbox('3')">tiga</button>
      <button class="tombol" onclick="toggleCheckbox('4')">empat</button>
      <button class="tombol" onclick="toggleCheckbox('5')">lima</button>
      <button class="tombol" onclick="toggleCheckbox('6')">enam</button>
    </div>
    <br>
    <hr>
    <h3>Software Update</h3>
      <button onclick="window.location = 'http://'+location.hostname+'/update'">UPDATE</button>
   <br>
   <br>
   <script>
   function toggleCheckbox(x) {
     var xhr = new XMLHttpRequest();
     xhr.open("GET", "/" + x, true);
     xhr.send();
   }
  </script>
  </body>
</html>

)=====";
