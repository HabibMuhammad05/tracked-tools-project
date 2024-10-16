//mac-address
#include "WiFi.h"
//#include <ESP8266WiFi.h>


void setup(){
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());
}

void loop(){

}
