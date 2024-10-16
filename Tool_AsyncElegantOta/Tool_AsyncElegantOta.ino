#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WebSocketsServer.h>

#include <ArduinoJson.h>
#include "WebPage.h"


#define LED1 13
#define LED2 12



// ipaddress/led1/on
//ipaddress/led1/off

// ipaddress/led2/on
//ipaddress/led2/off
#include <ESPAsyncTCP.h>
#include <AsyncElegantOTA.h>
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80); // server port 80
WebSocketsServer websockets(81);

void notFound(AsyncWebServerRequest *request)
{
  request->send(404, "text/plain", "Page Not found");
}


void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {

  switch (type) 
  {
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", num);
      break;
    case WStype_CONNECTED: {
        IPAddress ip = websockets.remoteIP(num);
        Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);

        // send message to client
        websockets.sendTXT(num, "Connected from server");
      }
      break;
    case WStype_TEXT:
      Serial.printf("[%u] get Text: %s\n", num, payload);
      String message = String((char*)( payload));
      Serial.println(message);

      
     DynamicJsonDocument doc(200);
    // deserialize the data
    DeserializationError error = deserializeJson(doc, message);
    // parse the parameters we expect to receive (TO-DO: error handling)
      // Test if parsing succeeds.
  if (error) {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.c_str());
    return;
  }

  int LED1_status = doc["LED1"];
  int LED2_status = doc["LED2"];
  digitalWrite(LED1,LED1_status);
  digitalWrite(LED2,LED2_status);




  }
}

void setup(void)
{
  
  Serial.begin(115200);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  
  WiFi.softAP("techiesms", "");
  Serial.println("softap");
  Serial.println("");
  Serial.println(WiFi.softAPIP());


  if (MDNS.begin("ESP")) { //esp.local/
    Serial.println("MDNS responder started");
  }



  server.on("/", [](AsyncWebServerRequest * request)
  { 
   
  request->send_P(200, "text/html", webpage);
  });

   server.on("/led1/on", HTTP_GET, [](AsyncWebServerRequest * request)
  { 
    digitalWrite(LED1,HIGH);
  request->send_P(200, "text/html", webpage);
  });

  server.onNotFound(notFound);

  AsyncElegantOTA.begin(&server);    // Start AsyncElegantOTA
  server.begin();  // it will start webserver
  websockets.begin();
  websockets.onEvent(webSocketEvent);

}


void loop(void)
{
  AsyncElegantOTA.loop();
 websockets.loop();
}
