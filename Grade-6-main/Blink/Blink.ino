const int ledPin = 4;  // Digital Input/Output pin

void setup() {
  pinMode(ledPin, OUTPUT);  // Set the LED pin as an output
  Serial.begin(9600);       // Initialize serial communication at 9600 baud rate
}

void loop() { 
    digitalWrite(ledPin, HIGH);  // Turn LED ON
    delay(1000);                 // Wait for 1 second (1000 milliseconds)
    digitalWrite(ledPin, LOW);   // Turn LED OFF
    delay(1000);                 // Wait for 1 second (1000 milliseconds)
}
