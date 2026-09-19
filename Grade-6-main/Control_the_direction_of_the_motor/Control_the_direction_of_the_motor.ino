// Define the control pins for the motor
const int M1_ip_A = 10; // Motor control pin A
const int M1_ip_B = 9;  // Motor control pin B

void setup() {
  // Set motor control pins as output
  pinMode(M1_ip_A, OUTPUT);
  pinMode(M1_ip_B, OUTPUT);
}

void loop() {
  // Rotate motor Clockwise
  digitalWrite(M1_ip_A, HIGH);
  digitalWrite(M1_ip_B, LOW);
  delay(3000); // Run for 3 seconds

  // Brake (both pins HIGH)
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
  delay(1000); // Brake for 1 second
}
