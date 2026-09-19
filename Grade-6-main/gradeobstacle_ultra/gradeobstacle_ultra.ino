#define MLa 8      // left motor 1st pin
#define MLb 9      // left motor 2nd pin
#define MRa 10     // right motor 1st pin
#define MRb 11     // right motor 2nd pin

#define TRIG 6     // Ultrasonic trigger
#define ECHO 7     // Ultrasonic echo

void setup() {
  pinMode(MLa, OUTPUT);
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  Serial.begin(9600);
}

long getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);
  return duration * 0.034 / 2;   // convert to cm
}

void loop() {

  long distance = getDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Obstacle very close
  if (distance <= 10) {
    // STOP
    digitalWrite(MLa, LOW);
    digitalWrite(MLb, LOW);
    digitalWrite(MRa, LOW);
    digitalWrite(MRb, LOW);
    delay(1000);

    // BACKWARD
    digitalWrite(MLa, HIGH);
    digitalWrite(MLb, LOW);
    digitalWrite(MRa, LOW);
    digitalWrite(MRb, HIGH);
    delay(800);

    // TURN RIGHT
    digitalWrite(MLa, LOW);
    digitalWrite(MLb, HIGH);
    digitalWrite(MRa, LOW);
    digitalWrite(MRb, HIGH);
    delay(700);
  }

  else {
    // MOVE FORWARD
    digitalWrite(MLa, LOW);
    digitalWrite(MLb, HIGH);
    digitalWrite(MRa, HIGH);
    digitalWrite(MRb, LOW);
  }

  delay(50);
}
