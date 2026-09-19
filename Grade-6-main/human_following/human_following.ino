#define MLa 6  // Left motor 1st pin
#define MLb 9  // Left motor 2nd pin
#define MRa 10 // Right motor 1st pin
#define MRb 11 // Right motor 2nd pin

int IR_Left = 3;  // Left IR sensor pin
int IR_Right = 4; // Right IR sensor pin

// Function to move forward
void moveForward() {
  digitalWrite(MLa, HIGH);
  digitalWrite(MLb, LOW);
  digitalWrite(MRa, HIGH);
  digitalWrite(MRb, LOW);
}

// Function to move left
void moveLeft() {
  digitalWrite(MLa, LOW);
  digitalWrite(MLb, LOW);
  digitalWrite(MRa, HIGH);
  digitalWrite(MRb, LOW);
}

// Function to move right
void moveRight() {
  digitalWrite(MLa, HIGH);
  digitalWrite(MLb, LOW);
  digitalWrite(MRa, LOW);
  digitalWrite(MRb, LOW);
}

// Function to stop the robot
void stopMotors() {
  digitalWrite(MLa, LOW);
  digitalWrite(MLb, LOW);
  digitalWrite(MRa, LOW);
  digitalWrite(MRb, LOW);
}

void setup() {
  // Set IR sensor pins as input
  pinMode(IR_Left, INPUT);
  pinMode(IR_Right, INPUT);

  // Set motor pins as output
  pinMode(MLa, OUTPUT);
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);

  // Initialize motors to stop
  stopMotors();
}

void loop() {
  // Read the IR sensor values
  int leftSensor = digitalRead(IR_Left);
  int rightSensor = digitalRead(IR_Right);

  if (leftSensor == HIGH && rightSensor == HIGH) {
    // Stop the robot if both sensors are HIGH
    stopMotors();
  } 
  else if (leftSensor == LOW && rightSensor == HIGH) {
    // Move left when left sensor is LOW and right sensor is HIGH
    moveLeft();
  } 
  else if (leftSensor == HIGH && rightSensor == LOW) {
    // Move right when left sensor is HIGH and right sensor is LOW
    moveRight();
  } 
  else if (leftSensor == LOW && rightSensor == LOW) {
    // Move forward when both sensors are LOW
    moveForward();
  }

  // Add a small delay to avoid rapid switching between states
  delay(100); 
}
