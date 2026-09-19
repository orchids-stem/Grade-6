#include <IRremote.h>

void setup() {
  Serial.begin(9600);           // Start serial communication at 9600 baud
  IrReceiver.begin(4);          // Initialize IR receiver on pin 4
}

void loop() {
  if (IrReceiver.decode()) {    // Check if an IR signal is received
    Serial.print("Hex Value: ");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);  // Print the decoded data in hex format
    IrReceiver.resume();        // Resume receiving the next IR signal
  }
  delay(10);  // Short delay to prevent flooding the serial monitor
}
