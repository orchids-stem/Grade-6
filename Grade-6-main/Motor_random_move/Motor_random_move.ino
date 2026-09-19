#define MLa 6  // Left motor 1st pin
#define MLb 9  // Left motor 2nd pin
#define MRa 10 // Right motor 1st pin
#define MRb 11 // Right motor 2nd pin

void setup() {
  // Set motor pins as output
  pinMode(MLa, OUTPUT);
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Move Forward
  digitalWrite(MLa, HIGH);
  digitalWrite(MLb, LOW);
  digitalWrite(MRa, HIGH);
  digitalWrite(MRb, LOW);
  Serial.println("Forward");
  delay(3000);

  // Move Backward
  digitalWrite(MLa, LOW);
  digitalWrite(MLb, HIGH);
  digitalWrite(MRa, LOW);
  digitalWrite(MRb, HIGH);
  Serial.println("Backward");
  delay(1500);

  // Turn Right
  digitalWrite(MLa, HIGH);
  digitalWrite(MLb, LOW);
  digitalWrite(MRa, LOW);
  digitalWrite(MRb, LOW);
  Serial.println("Right");
  delay(1000);

  // Turn Left
  digitalWrite(MLa, LOW);
  digitalWrite(MLb, LOW);
  digitalWrite(MRa, HIGH);
  digitalWrite(MRb, LOW);
  Serial.println("Left");
  delay(2000);

  // Stop
  digitalWrite(MLa, LOW);
  digitalWrite(MLb, LOW);
  digitalWrite(MRa, LOW);
  digitalWrite(MRb, LOW);
  Serial.println("Stop");
  delay(300);
}
