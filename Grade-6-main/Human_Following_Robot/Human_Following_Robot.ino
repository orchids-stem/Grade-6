// ----------------------------
// ----------------------------
// Motor driver pin definitions
// ----------------------------
#define MLa 8   // Left motor pin 1
#define MLb 9   // Left motor pin 2
#define MRa 10  // Right motor pin 1
#define MRb 11  // Right motor pin 2


// ----------------------------
// IR sensor pin definitions
// ----------------------------
int IR_Left = 3;   // Left IR sensor
int IR_Right = 4;  // Right IR sensor


void setup() {
  // Set IR sensor pins as input
  pinMode(IR_Left, INPUT);
  pinMode(IR_Right, INPUT);


  // Set motor driver pins as output
  pinMode(MLa, OUTPUT);
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);
}


void loop() {
  int leftVal = digitalRead(IR_Left);
  int rightVal = digitalRead(IR_Right);


  if (leftVal == HIGH && rightVal == HIGH) {
    // Case 1: No human detected → Stop
    digitalWrite(MLa, LOW);
    digitalWrite(MLb, LOW);
    digitalWrite(MRa, LOW);
    digitalWrite(MRb, LOW);
  }
  else if (leftVal == LOW && rightVal == HIGH) {
    // Case 2: Human detected on LEFT → Turn Left
    digitalWrite(MLa, LOW);   // Left motor OFF
    digitalWrite(MLb, LOW);
    digitalWrite(MRa, HIGH);  // Right motor ON
    digitalWrite(MRb, LOW);
  }
  else if (leftVal == HIGH && rightVal == LOW) {
    // Case 3: Human detected on RIGHT → Turn Right
    digitalWrite(MLa, LOW);   // Left motor ON
    digitalWrite(MLb, HIGH);
    digitalWrite(MRa, LOW);   // Right motor OFF
    digitalWrite(MRb, LOW);
  }
  else if (leftVal == LOW && rightVal == LOW) {
    // Case 4: Human detected in CENTER → Move Forward
    digitalWrite(MLa, LOW);   // Left motor forward
    digitalWrite(MLb, HIGH);
    digitalWrite(MRa, HIGH);  // Right motor forward
    digitalWrite(MRb, LOW);
  }


  delay(50);  // Small delay to stabilize motor response
}
