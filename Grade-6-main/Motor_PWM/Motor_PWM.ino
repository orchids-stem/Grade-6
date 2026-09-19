#define MLa 6  // Left motor 1st pin
#define MLb 9  // Left motor 2nd pin
#define MRa 10 // Right motor 1st pin
#define MRb 11 // Right motor 2nd pin

void setup() {
  pinMode(MLa, OUTPUT);  // Declare motors pins as output
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Forward
  analogWrite(MLa, 150);  // Motor speed at 150
  analogWrite(MLb, 0);
  analogWrite(MRa, 150);
  analogWrite(MRb, 0);
  Serial.println("Forward");
  delay(3000);

  // Backward
  analogWrite(MLa, 0);
  analogWrite(MLb, 150);
  analogWrite(MRa, 0);
  analogWrite(MRb, 150);
  Serial.println("Backward");
  delay(1500);

  // Right turn
  analogWrite(MLa, 150);
  analogWrite(MLb, 0);
  analogWrite(MRa, 0);
  analogWrite(MRb, 0);
  Serial.println("Right");
  delay(1000);

  // Left turn
  analogWrite(MLa, 0);
  analogWrite(MLb, 0);
  analogWrite(MRa, 150);
  analogWrite(MRb, 0);
  Serial.println("Left");
  delay(2000);

  // Stop
  analogWrite(MLa, 0);
  analogWrite(MLb, 0);
  analogWrite(MRa, 0);
  analogWrite(MRb, 0);
  Serial.println("Stop");
  delay(1000);
}
