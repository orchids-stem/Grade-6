#include <IRremote.h>

#define IR_RECEIVE_PIN 2

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.println("IR Receiver Initialized. Press any button on the remote...");
}

void loop() {
  if (IrReceiver.decode()) {
    unsigned long code = IrReceiver.decodedIRData.decodedRawData;

    if (code != 0x0) {   // Ignore repeat signal sent on button release
      Serial.print("Button Pressed - HEX Code: 0x");
      Serial.println(code, HEX);
    }

    IrReceiver.resume();
  }
}