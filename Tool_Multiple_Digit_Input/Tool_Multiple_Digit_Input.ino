char dat;
int val = 0;
void setup() {
    Serial.begin(115200);
}

void loop() {
  if(Serial.available() > 0){
    dat = Serial.read();
    if (dat == '0' || dat == '1' || dat == '2' || dat == '3' || dat == '4' || dat == '5' || dat == '6' || dat == '7' || dat == '8' || dat == '9' ){
      Serial.println("in: " + String(dat));
      val = val * 10 + dat - '0';
    }
    if (dat == 'A'){
      Serial.println("val: " + String(val));
      val = 0;
    }
  }
}
