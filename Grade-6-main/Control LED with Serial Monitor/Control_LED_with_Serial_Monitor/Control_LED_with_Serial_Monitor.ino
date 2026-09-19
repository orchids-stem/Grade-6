void setup() {
  pinMode(4, OUTPUT);
  Serial.begin(9600); // Set baud rate to 9600
}

void loop() {
  if (Serial.available() > 0) {
    char state = Serial.read(); // Read as character

    if (state == '1') {
      digitalWrite(4, HIGH); // Turn ON pin 4
    }
    else if (state == '0') {
      digitalWrite(4, LOW);  // Turn OFF pin 4
    }
  }
}
