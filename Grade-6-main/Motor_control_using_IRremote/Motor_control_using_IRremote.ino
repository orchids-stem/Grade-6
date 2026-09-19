#include <IRremote.h>  // Include the IRremote library

void setup() {
  Serial.begin(115200);         // Optional: helpful for debugging
  IrReceiver.begin(2);          // IR receiver on pin 2
  pinMode(3, OUTPUT);           // Pin 3 as output
  pinMode(4, OUTPUT);           // Pin 4 as output
  digitalWrite(3, LOW);         // Initialize outputs
  digitalWrite(4, LOW);
  Serial.println("IR Receiver Initialized");
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.print("Received Command: 0x");
    Serial.println(IrReceiver.decodedIRData.command, HEX);

    // Action based on command
    if (IrReceiver.decodedIRData.command == 0x2) {
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
    }
    else if (IrReceiver.decodedIRData.command == 0x3) {
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
    }
    else {
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
    }

    IrReceiver.resume(); // Ready for next signal
    delay(200); // Slight delay to debounce input
  }
}
