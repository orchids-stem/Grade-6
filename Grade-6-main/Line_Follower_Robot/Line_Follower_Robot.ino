#define MLa 8    // Left motor IN1
#define MLb 9    // Left motor IN2
#define MRa 10   // Right motor IN3
#define MRb 11   // Right motor IN4


#define L_sensor 3  // Left IR sensor
#define R_sensor 4  // Right IR sensor


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
  int left = digitalRead(L_sensor);
  int right = digitalRead(R_sensor);


  // Debugging - print sensor states
  Serial.print("L: ");
  Serial.print(left);
  Serial.print("  R: ");
  Serial.println(right);


  if (left == LOW && right == LOW) {
    // Both sensors detect line → move forward
    digitalWrite(MLa, LOW);
    digitalWrite(MLb, HIGH);  // Left motor forward
    digitalWrite(MRa, HIGH);
    digitalWrite(MRb, LOW);   // Right motor forward
  }
  else if (left == LOW && right == HIGH) {
    // Right sensor off line → turn right
    digitalWrite(MLa, LOW);
    digitalWrite(MLb, HIGH);  // Left motor forward
    digitalWrite(MRa, LOW);
    digitalWrite(MRb, HIGH);  // Right motor backward
  }
  else if (left == HIGH && right == LOW) {
    // Left sensor off line → turn left
    digitalWrite(MLa, HIGH);
    digitalWrite(MLb, LOW);   // Left motor backward
    digitalWrite(MRa, HIGH);
    digitalWrite(MRb, LOW);   // Right motor forward
  }
  else {
    // Both sensors off line → stop
    digitalWrite(MLa, LOW);
    digitalWrite(MLb, LOW);
    digitalWrite(MRa, LOW);
    digitalWrite(MRb, LOW);
  }


  delay(10); // Small delay to stabilize readings
}
