#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int voltagePin = 34; // ADC pin on ESP32
const float voltageDividerFactor = 47.0 / (100.0 + 47.0);
const float calibrationFactor = 1.066; // Adjust this for better accuracy if needed

const float minVoltage = 6.0; // Minimum voltage for 0%
const float maxVoltage = 8.4; // Maximum voltage for 1

unsigned long previousMillis = 0;
const long interval = 2000; // 2 seconds interval
bool showVoltage = true;

void setup() {
  Serial.begin(115200);
  lcd.begin();
  lcd.backlight();
}

void loop() {
  // Calculate elapsed time
  unsigned long currentMillis = millis();
  
  // Read voltage from the battery
  float vOut = (analogRead(voltagePin) / 4095.0) * 3.3; // 12-bit ADC, 3.3V reference
  float batteryVoltage = (vOut / voltageDividerFactor) * calibrationFactor;
  
  // Calculate battery percentage
  float batteryPercentage = (batteryVoltage - minVoltage) / (maxVoltage - minVoltage) * 100;
  
  // Clamp the percentage between 0% and 100%
  batteryPercentage = constrain(batteryPercentage, 0, 100);
  
  // Print to Serial Monitor
  Serial.print("Battery Voltage: ");
  Serial.print(batteryVoltage, 2); // Print with 2 decimal places
  Serial.print(" V, Percentage: ");
  Serial.print(batteryPercentage, 0); // Print without decimals
  Serial.println(" %");

  // Check if it's time to update the display
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    lcd.clear();
    
    if (showVoltage) {
      // Display battery voltage
      lcd.setCursor(1, 0);
      lcd.print("Hello, world!");
      lcd.setCursor(1, 1);
      lcd.print("Baterai: ");
      lcd.print(batteryVoltage, 2);
      lcd.print("V");
    } else {
      // Display battery percentage
      lcd.setCursor(1, 0);
      lcd.print("Hello, world!");
      lcd.setCursor(2, 1);
      lcd.print("persen: ");
      lcd.print((int)batteryPercentage); // Cast to int for whole number
      lcd.print("%");
    }

    // Toggle the display mode
    showVoltage = !showVoltage;
  }

  delay(100); // Reduce flickering and CPU usage
}

//------------------------------------------------V1.0---------------------------------------------//
//#include <Wire.h> 
//#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x27, 16, 2);
//
//const int voltagePin = 34; // ADC pin on ESP32
//const float voltageDividerFactor = 47.0 / (100.0 + 47.0);
//const float calibrationFactor = 1.066; // Adjust this for better accuracy if needed
//
//
//void setup() {
//  Serial.begin(115200);
//  lcd.begin();
//  lcd.backlight();
//}
//
//void loop() {
//  float vOut = (analogRead(voltagePin) / 4095.0) * 3.3; // 12-bit ADC, 3.3V reference
//  float batteryVoltage = (vOut / voltageDividerFactor) * calibrationFactor;
//
//  Serial.print("Battery Voltage: ");
//  Serial.print(batteryVoltage, 2); // Print with 2 decimal places
//  Serial.println(" V");
//  
//  lcd.setCursor(1, 0);
//  lcd.print("Hello, world!");
//  lcd.setCursor(1, 1);
//  lcd.print("Baterai: ");
//  lcd.print(batteryVoltage);
//  lcd.print("V");
//  
//  delay(500); // Update every second
//}
