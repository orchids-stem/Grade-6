const int ledPin = 6;  // LED pin connected to pin 6

void setup() {
  pinMode(ledPin, OUTPUT);  // Set the LED pin as an output
}

void loop() {
  // Fade in
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPin, brightness);  // Set LED brightness using PWM
    delay(10);  // Wait for 10 milliseconds for smooth transition
  }

  // Fade out
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPin, brightness);  // Set LED brightness using PWM
    delay(10);  // Wait for 10 milliseconds for smooth transition
  }
}
