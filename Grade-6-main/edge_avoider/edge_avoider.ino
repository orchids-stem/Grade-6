#define MLa 6  // Left motor 1st pin
#define MLb 9  // Left motor 2nd pin
#define MRa 10 // Right motor 1st pin
#define MRb 11 // Right motor 2nd pin
#define Sensor 2 // Sensor pin

void setup() {
  // Set motor pins as output
  pinMode(MLa, OUTPUT);
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);

  // Set sensor pin as input
  pinMode(Sensor, INPUT);

  // Begin serial communication for debugging
  Serial.begin(9600);
}

// Function to move forward
void forward() {
  analogWrite(MLb, 255);  // Left motor full speed
  digitalWrite(MLa, LOW); // Left motor direction
  analogWrite(MRa, 255);  // Right motor full speed
  digitalWrite(MRb, LOW); // Right motor direction
  Serial.println("Forward");
}

// Function to stop the robot
void stopMotors() {
  digitalWrite(MLa, LOW);
  digitalWrite(MLb, LOW);
  digitalWrite(MRa, LOW);
  digitalWrite(MRb, LOW);
  Serial.println("Stop");
}

// Function to move backward
void backward() {
  digitalWrite(MLa, LOW);  // Left motor direction
  digitalWrite(MLb, HIGH); // Left motor reverse
  digitalWrite(MRa, LOW);  // Right motor direction
  digitalWrite(MRb, HIGH); // Right motor reverse
  Serial.println("Backward");
}

// Function to turn right
void rightTurn() {
  digitalWrite(MLa, HIGH);  // Left motor forward
  digitalWrite(MLb, LOW);   // Left motor forward
  digitalWrite(MRa, LOW);   // Right motor stop
  digitalWrite(MRb, LOW);   // Right motor stop
  Serial.println("Right Turn");
}

void loop() {
  // Read the sensor value
  int Sensorin = digitalRead(Sensor);
  Serial.println(Sensorin);  // Print sensor value for debugging
  delay(100);  // Small delay for sensor stability

  if (Sensorin == LOW) {
    // If sensor detects object (LOW), move forward
    forward();
  } else {
    // If no object detected (HIGH), stop, move backward, stop, and turn right
    stopMotors();
    delay(500);  // Stop for 500ms
    backward();
    delay(700);  // Move backward for 700ms
    stopMotors();
    delay(300);  // Stop for 300ms
    rightTurn();
    delay(600);  // Turn right for 600ms
  }
}
