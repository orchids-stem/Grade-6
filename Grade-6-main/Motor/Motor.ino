#define Ma 10  // Motor pin 1
#define Mb 11  // Motor pin 2

void setup() {
  pinMode(Ma, OUTPUT);  // Set motor pins as output
  pinMode(Mb, OUTPUT);
  Serial.begin(9600);   // Start Serial communication
}

void loop() {
  // Move forward
  digitalWrite(Ma, HIGH);
  digitalWrite(Mb, LOW);
  Serial.println("Forward");
  delay(3000);

  // Stop
  digitalWrite(Ma, LOW);
  digitalWrite(Mb, LOW);
  Serial.println("Stop");
  delay(500);

  // Move backward
  digitalWrite(Ma, LOW);
  digitalWrite(Mb, HIGH);
  Serial.println("Backward");
  delay(3000);
}
