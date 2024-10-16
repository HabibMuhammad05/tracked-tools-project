#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>

#include <ESPAsyncTCP.h>
#include <AsyncElegantOTA.h>
#include <ESPAsyncWebServer.h>
AsyncWebServer server(80); // server port 80

#include "Webpage.h"

void notFound(AsyncWebServerRequest *request){
  request->send(404, "text/plain", "Page Not found");
}

#define LED1 15
#define LED2 12

//-----------------------------Void Setup------------------------------//
void setup(void){
  Serial.begin(115200);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  
//-----------------------------WiFi Setup------------------------------//
  WiFi.softAP("NodeMcu_AP", "1qazmlp0");
  Serial.println("softap");
  Serial.println("");
  Serial.println(WiFi.softAPIP());
  
//------------------------------MDNS Setup-----------------------------//
  if (MDNS.begin("ESP")) { //esp.local/
    Serial.println("MDNS responder started");
  }
  
//------------------------Homepage setup--------------------------------//
  server.on("/", [](AsyncWebServerRequest * request){ 
   request->send_P(200, "text/html", webpage);
  });
  
//---------------------------led1 on------------------------------------//
   server.on("/led1/on", HTTP_GET, [](AsyncWebServerRequest * request){ 
    digitalWrite(LED1,HIGH);
    request->send_P(200, "text/html", webpage);
  });
  
//-----------------------------end--------------------------------------//
  server.onNotFound(notFound);
  AsyncElegantOTA.begin(&server);    // Start AsyncElegantOTA
  server.begin();  // it will start webserver
}

void loop(void){
  AsyncElegantOTA.loop();
}
