void setup() {
  Serial.begin(115200);
}

void loop() {
 voltageMeasure();
  delay(100);
}

void voltageMeasure(){
  pinMode(A5, INPUT);
  float voltage = analogRead(A5) * (6.13/880);
  Serial.print("volt= "); Serial.println(voltage);
}

//--------------------v1.0-------------------//
/*
  float data = analogRead(A0);
  float calcdata = map(data, 0, 880, 0, 1023);
  Serial.println(data);
  Serial.print("calc= "); Serial.println(calcdata);
  float voltage = calcdata * (6.13/1023);
  Serial.print("volt= "); Serial.println(voltage);
  delay(100);
//--------------------v1.1-------------------//
  float data = analogRead(A5);
  float voltage = data * (6.13/880);
  Serial.print("volt= "); Serial.println(voltage);
 */
