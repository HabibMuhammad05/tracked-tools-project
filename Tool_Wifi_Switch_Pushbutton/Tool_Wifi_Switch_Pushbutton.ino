#include <ESP8266WiFi.h>
bool prev;
bool state = true;
unsigned long waktu1=0;

#include "OneButton.h"
OneButton pb(13, true, true);  //(Pb_Pin;  true = ActiveLow;  true = button PullUp)
void setup() {
  Serial.begin(115200);
//  pinMode(13, INPUT_PULLUP);
  pb.attachLongPressStop(tekanLama);
}

void loop() {
  pb.tick();
  Serial.println("mentah =" + String(digitalRead(13)));
  delay(100);
  
  if(state){
    Serial.println("truw");
    WiFi.mode(WIFI_AP);
    WiFi.softAP("NodeMcu_OTA", "1qazmlp0");
  }else{
    Serial.println("not truw");
    WiFi.mode(WIFI_OFF);
  }
}

void tekanLama(){
  Serial.println("Single Press Detected!");
    state = !state;
} 
  
//void keyMode(){
//    Serial.println("keyMode");
//    int val = analogRead(A0);
//    for (int i = 0; i < 16; i++){
//      if( abs(val - thresholds[i]) < 5){
//        Serial.println(val);
//        Serial.println(key[i]);
//        stateCheck();
//        while(analogRead(A0) < 1000) {delay(10);}
//      }
//    }
//}
//void wifiMode(){
//    Serial.println("WifiMode");
//    cek();
//}
