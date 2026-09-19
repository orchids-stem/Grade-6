
#define MLa 8
#define MLb 9
#define MRa 10
#define MRb 11

#define L_sensor 2   // Left IR
#define R_sensor 3   // Right IR

#define TRIG 6
#define ECHO 7

// --------- SETUP ----------
void setup() {
  pinMode(MLa, OUTPUT);
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);

  pinMode(L_sensor, INPUT);
  pinMode(R_sensor, INPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  Serial.begin(9600);
  delay(1500);
  stopMotor();
}

// --------- ULTRASONIC ----------
long getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 30000);
  if (duration == 0) return 100;
  return duration * 0.034 / 2;
}

// --------- MOTOR CONTROL ----------
void stopMotor() {
  digitalWrite(MLa, LOW);
  digitalWrite(MLb, LOW);
  digitalWrite(MRa, LOW);
  digitalWrite(MRb, LOW);
}

void forward() {
  digitalWrite(MLa, LOW);
  digitalWrite(MLb, HIGH);
  digitalWrite(MRa, HIGH);
  digitalWrite(MRb, LOW);
}

void leftTurn() {
  digitalWrite(MLa, LOW);
  digitalWrite(MLb, LOW);
  digitalWrite(MRa, HIGH);
  digitalWrite(MRb, LOW);
}

void rightTurn() {
  digitalWrite(MLa, LOW);
  digitalWrite(MLb, HIGH);
  digitalWrite(MRa, LOW);
  digitalWrite(MRb, LOW);
}

// --------- LOOP ----------
void loop() {

  long distance = getDistance();
  int left  = digitalRead(L_sensor);
  int right = digitalRead(R_sensor);

  Serial.print("D:");
  Serial.print(distance);
  Serial.print("  L:");
  Serial.print(left);
  Serial.print("  R:");
  Serial.println(right);

  // ----- OBSTACLE STOP -----
  if (distance <= 10) {
    stopMotor();
    return;
  }

  // ----- LINE FOLLOW (BLACK = LOW) -----
  // Move ONLY when at least one sensor sees black

  if (left == LOW && right == LOW) {
    forward();
  }
  else if (left == HIGH && right == LOW) {
    leftTurn();
  }
  else if (left == LOW && right ==HIGH) {
    rightTurn();
  }
  else {
    stopMotor();   // BOTH HIGH → no black → STOP
  }

  delay(10);
}
