uint8_t button[14] = {32, 33, 25, 26, 27, 14, 12, 13, 18, 15, 5, 4, 17, 16  }; // "L3", "R3", "L2", "L1", "UP", "LEFT", "DOWN", "RIGHT", "SQUARE", "CROSS", "ROUND", "TRIANGLE", "R2", "R1"
uint8_t joystick[4] = {36, 39, 34, 35};
String nama[14] = {"L3", "R3", "L2", "L1", "UP", "LEFT", "DOWN", "RIGHT", "SQUARE", "CROSS", "ROUND", "TRIANGLE", "R2", "R1"};
unsigned long previousMillis = 0;        // will store last time LED was updated

void setup() {
  Serial.begin(115200);
  for(uint8_t i = 0; i < 14; i++){
    pinMode(button[i], INPUT);
  }
  for(uint8_t i = 0; i < 4; i++){
    pinMode(joystick[i], INPUT);
  }
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  for(uint8_t i = 0; i < 14; i++){
    Serial.print(digitalRead(button[i]));
    Serial.print(", ");
  }
  Serial.print("------");
  for(uint8_t i = 0; i < 4; i++){
    Serial.print(analogRead(joystick[i]));
    Serial.print(", ");
  }
  Serial.println();

  
  if (millis() - previousMillis >= 1000) {
    previousMillis = millis();

    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }
//  Serial.println(String(analogRead(A0)) + " - " + String(analogRead(A1)) + " - " +  String(analogRead(A2)) + " - " +  String(analogRead(A3)));
  delay(100);

}
