// Motor control pins
const int M1_ip_A = 10;   // Motor direction pin A
const int M1_ip_B = 9;    // Motor direction pin B
const int M1_pwm  = 3;    // PWM pin for motor speed control

void setup() {
  // Set motor control and PWM pins as outputs
  pinMode(M1_ip_A, OUTPUT);
  pinMode(M1_ip_B, OUTPUT);
  pinMode(M1_pwm, OUTPUT);
}

void loop() {
  // Set motor speed (0 - 255)
  analogWrite(M1_pwm, 200);  // ~80% of max speed

  // Rotate motor Clockwise
  digitalWrite(M1_ip_A, HIGH);
  digitalWrite(M1_ip_B, LOW);
  delay(3000); // Run for 3 seconds

  // Apply Brake (both HIGH)
  digitalWrite(M1_ip_A, HIGH);
  digitalWrite(M1_ip_B, HIGH);
  delay(1000); // Brake for 1 second

  // Rotate motor Anti-Clockwise
  digitalWrite(M1_ip_A, LOW);
  digitalWrite(M1_ip_B, HIGH);
  delay(3000); // Run for 3 seconds

  // Brake again
  digitalWrite(M1_ip_A, HIGH);
  digitalWrite(M1_ip_B, HIGH);
  delay(1000);
}
