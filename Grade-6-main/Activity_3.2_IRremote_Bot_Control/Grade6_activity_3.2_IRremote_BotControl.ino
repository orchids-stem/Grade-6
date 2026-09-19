#include <IRremote.h>

#define IR_RECEIVE_PIN 2

// Motor driver pins
#define MLa 8
#define MLb 9
#define MRa 10
#define MRb 11

// IR Remote HEX codes (use the values you recorded in Activity 3.1)
#define FORWARD_CODE   0xE41B7F80   // 2
#define BACKWARD_CODE  0xF00F7F80   // 8
#define LEFT_CODE      0xF30C7F80   // 4
#define RIGHT_CODE     0xF10E7F80   // 6

void setup() {
  pinMode(MLa, OUTPUT);
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);

  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  stopMotor();
}

void loop() {
  if (IrReceiver.decode()) {
    unsigned long code = IrReceiver.decodedIRData.decodedRawData;

    Serial.print("HEX Code: 0x");
    Serial.println(code, HEX);

    if (code == 0x0) {
      IrReceiver.resume();
      return;
    }

    if (code == FORWARD_CODE) forward();
    else if (code == BACKWARD_CODE) backward();
    else if (code == LEFT_CODE) left();
    else if (code == RIGHT_CODE) right();
    else stopMotor();

    IrReceiver.resume();
  }
}

// ---------- Motor Functions ----------
void forward() {
  digitalWrite(MLa, HIGH); digitalWrite(MLb, LOW);
  digitalWrite(MRa, HIGH); digitalWrite(MRb, LOW);
}

void backward() {
  digitalWrite(MLa, LOW); digitalWrite(MLb, HIGH);
  digitalWrite(MRa, LOW); digitalWrite(MRb, HIGH);
}

void left() {
  digitalWrite(MLa, HIGH); digitalWrite(MLb, LOW);
  digitalWrite(MRa, LOW); digitalWrite(MRb, HIGH);
}

void right() {
  digitalWrite(MLa, LOW); digitalWrite(MLb, HIGH);
  digitalWrite(MRa, HIGH); digitalWrite(MRb, LOW);
}

void stopMotor() {
  digitalWrite(MLa, LOW); digitalWrite(MLb, LOW);
  digitalWrite(MRa, LOW); digitalWrite(MRb, LOW);
}