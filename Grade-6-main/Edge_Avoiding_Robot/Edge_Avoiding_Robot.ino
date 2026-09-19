// ----------------------------
// Motor driver pin definitions
// ----------------------------
#define MLa 8   // Left motor 
#define MLb 9   // Left motor
#define MRa 10  // Right motor  
#define MRb 11  // Right motor 

// ----------------------------
// IR sensor pin
// ----------------------------
#define Sensor 2  // IR Sensor input pin

// ----------------------------
// Setup function - runs once
// ----------------------------
void setup()
{
  // Set motor control pins as OUTPUT
  pinMode(MLa, OUTPUT);
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);

  // Set sensor pin as INPUT
  pinMode(Sensor, INPUT);

  // Start Serial Monitor (for debugging sensor readings)
  Serial.begin(9600);
}

// ----------------------------
// Loop function - runs repeatedly
// ----------------------------
void loop()
{
  // Read IR sensor input
  // Many IR sensors give LOW when an object is detected
  int Sensorin = digitalRead(Sensor);

  // Print the sensor value to Serial Monitor
  Serial.println(Sensorin);
  delay(100);  // Delay just to slow down printing (easier to read)

  // ----------------------------
  // CASE 1: Object detected (Sensorin = LOW)
  // ----------------------------
  if (Sensorin == LOW) {
    // Move forward
    digitalWrite(MLa, LOW);   // Left motor forward
    digitalWrite(MLb, HIGH);
    digitalWrite(MRa, HIGH);  // Right motor forward
    digitalWrite(MRb, LOW);

  }
  // ----------------------------
  // CASE 2: No object detected (Sensorin = HIGH)
  // ----------------------------
  else {
    // Stop motors first
    digitalWrite(MLa, LOW);
    digitalWrite(MLb, LOW);
    digitalWrite(MRa, LOW);
    digitalWrite(MRb, LOW);
    delay(300);

    // Move backward
    digitalWrite(MLa, HIGH);  // Left motor backward
    digitalWrite(MLb, LOW);
    digitalWrite(MRa, LOW);   // Right motor backward
    digitalWrite(MRb, HIGH);
    delay(500);  // Reverse for 0.5 seconds

    // Stop motors again
    digitalWrite(MLa, LOW);
    digitalWrite(MLb, LOW);
    digitalWrite(MRa, LOW);
    digitalWrite(MRb, LOW);
    delay(300);

    // Turn right
    digitalWrite(MLa, LOW);   // Left motor forward
    digitalWrite(MLb, HIGH);
    digitalWrite(MRa, LOW);   // Right motor backward
    digitalWrite(MRb, HIGH);
    delay(300);  // Turning time
  }
}
