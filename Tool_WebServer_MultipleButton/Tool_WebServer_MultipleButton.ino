#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <AsyncElegantOTA.h>
#include <ArduinoJson.h>

#include "WebPage.h"
#include "SoundLib.h"
#include "ToneDef.h"

#include <ESPAsyncWebServer.h>
AsyncWebServer server(80); // server port 80

void notFound(AsyncWebServerRequest *request){
  request->send(404, "text/plain", "Page Not found");
}

void setup(void){
  
  Serial.begin(115200);
  pinMode(LED_BUILTIN,OUTPUT);
  
  WiFi.softAP("techiesms", "");
  Serial.println("softap");
  Serial.println("");
  Serial.println(WiFi.softAPIP());


  if (MDNS.begin("ESP")) { //esp.local/
    Serial.println("MDNS responder started");
  }
  
//-----------------------------------------------------------------------//
  server.on("/", [](AsyncWebServerRequest * request) { request->send_P(200, "text/html", webpage); });

//-----------------------------------manual not-----------------------------------//
  server.on("/do", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(LED_BUILTIN, LOW);
    request->send(200, "text/plain", "ok");
  });
  server.on("/re", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(LED_BUILTIN, LOW);
    request->send(200, "text/plain", "ok");
  });
  server.on("/mi", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(LED_BUILTIN, LOW);
    request->send(200, "text/plain", "ok");
  });
  server.on("/fa", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(LED_BUILTIN, LOW);
    request->send(200, "text/plain", "ok");
  });
  server.on("/sol", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(LED_BUILTIN, LOW);
    request->send(200, "text/plain", "ok");
  });
  server.on("/la", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(LED_BUILTIN, LOW);
    request->send(200, "text/plain", "ok");
  });
  server.on("/si", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(LED_BUILTIN, LOW);
    request->send(200, "text/plain", "ok");
  });
  server.on("/do2", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(LED_BUILTIN, LOW);
    request->send(200, "text/plain", "ok");
  });
  server.on("/Noteoff", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(LED_BUILTIN, HIGH);
    request->send(200, "text/plain", "ok");
  });
//-----------------------------------song select-----------------------------------//
  server.on("/1", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(LED_BUILTIN, HIGH);
    request->send(200, "text/plain", "ok");
  });
  server.on("/2", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(LED_BUILTIN, HIGH);
    request->send(200, "text/plain", "ok");
  });
  server.on("/3", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(LED_BUILTIN, HIGH);
    request->send(200, "text/plain", "ok");
  });
  server.on("/4", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(LED_BUILTIN, HIGH);
    request->send(200, "text/plain", "ok");
  });
  server.on("/5", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(LED_BUILTIN, HIGH);
    request->send(200, "text/plain", "ok");
  });
  server.on("/6", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(LED_BUILTIN, HIGH);
    request->send(200, "text/plain", "ok");
  });  
  server.on("/Songoff", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(LED_BUILTIN, HIGH);
    request->send(200, "text/plain", "ok");
  });
  
  server.onNotFound(notFound);
  AsyncElegantOTA.begin(&server);    // Start AsyncElegantOTA
  server.begin();  // it will start webserver

}


void loop(void)
{
  
}
