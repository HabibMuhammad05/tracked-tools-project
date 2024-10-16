// Define the pin connected to the buzzer
const int buzzerPin = 11;

// Define the frequency of the tone in Hz
const int toneFrequency = 1000;

// Define the duration of each tone in milliseconds
const int toneDuration = 1000;

void setup() {
  // Set the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Generate the tone
  generateTone(buzzerPin, toneFrequency, toneDuration);
  
  // Wait before generating the next tone
  delay(1000);
}

void generateTone(int pin, int frequency, int duration) {
  // Calculate the period of one cycle in microseconds
  int period = 1000000 / frequency;
  
  // Calculate the half period for the duty cycle
  int halfPeriod = period / 2;

  // Calculate the number of cycles for the given duration
  long cycles = frequency * duration / 1000;

  // Generate the tone by toggling the buzzer pin on and off
  for (long i = 0; i < cycles; i++) {
    digitalWrite(pin, HIGH); // Turn the buzzer on
    delayMicroseconds(halfPeriod); // Wait for half the period
    digitalWrite(pin, LOW); // Turn the buzzer off
    delayMicroseconds(halfPeriod); // Wait for the other half of the period
  }
}
