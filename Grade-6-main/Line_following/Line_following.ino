#define MLa 5 // Left motor 1st pin (PWM)
#define MLb 6 // Left motor 2nd pin (PWM)
#define MRa 9 // Right motor 1st pin (PWM)
#define MRb 10 // Right motor 2nd pin (PWM)
#define L_sensor 3 // Left IR sensor pin
#define R_sensor 4 // Right IR sensor pin

int motorSpeed = 135; // Set motor speed to 135 (PWM value)

void setup() {
  pinMode(MLa, OUTPUT);
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);
  pinMode(L_sensor, INPUT);
  pinMode(R_sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  if ((digitalRead(L_sensor) == LOW) && (digitalRead(R_sensor) == LOW)) {
    Serial.println("Left and Right sensors are detecting");
    analogWrite(MLa, motorSpeed);  // Left motor forward
    analogWrite(MLb, 0);           // No reverse for left motor
    analogWrite(MRa, motorSpeed);  // Right motor forward
    analogWrite(MRb, 0);           // No reverse for right motor
  }
  else if ((digitalRead(L_sensor) == LOW) && (digitalRead(R_sensor) == HIGH)) {
    Serial.println("Left detecting");
    analogWrite(MLa, 0);           // Stop left motor
    analogWrite(MLb, 0);           // No reverse for left motor
    analogWrite(MRa, motorSpeed);  // Right motor forward
    analogWrite(MRb, 0);           // No reverse for right motor
  }
  else if ((digitalRead(L_sensor) == HIGH) && (digitalRead(R_sensor) == LOW)) {
    Serial.println("Right detecting");
    analogWrite(MLa, motorSpeed);  // Left motor forward
    analogWrite(MLb, 0);           // No reverse for left motor
    analogWrite(MRa, 0);           // Stop right motor
    analogWrite(MRb, 0);           // No reverse for right motor
  }
  else {
    Serial.println("No sensors detecting");
    analogWrite(MLa, 0);           // Stop left motor
    analogWrite(MLb, 0);           // No reverse for left motor
    analogWrite(MRa, 0);           // Stop right motor
    analogWrite(MRb, 0);           // No reverse for right motor
  }
  delay(50); // Small delay to stabilize motor response
}
