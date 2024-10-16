uint8_t button[15] = {33, 32, 23, 19, 4, 15, 13, 12, 25, 26, 27, 14, 16, 17, 2}; // "L3", "R3", "L2", "L1", "UP", "LEFT", "DOWN", "RIGHT", "SQUARE", "CROSS", "ROUND", "TRIANGLE", "R2", "R1"
bool buttonStat[15];

void setup() {
  Serial.begin(115200);
  for(uint8_t i = 0; i < 15; i++){
    pinMode(button[i], INPUT_PULLUP);
  }
  pinMode(18, OUTPUT);
  pinMode(5, OUTPUT);

}

void loop() {
  for(uint8_t i = 0; i < 15; i++){
    buttonStat[i] = digitalRead(button[i]);
    
    Serial.print(" -- ");
    Serial.print(button[i]);
    Serial.print(" = ");
    Serial.print(buttonStat[i]);
    Serial.print(", ");
  }
  Serial.println();

  digitalWrite(18, !digitalRead(18));
  digitalWrite(5, !digitalRead(18));
  
  delay(500);

}
