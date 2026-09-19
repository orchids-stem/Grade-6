#include <IRremote.h>

int MLa = 6;  // Left motor 1st pin
int MLb = 9;  // Left motor 2nd pin
int MRa = 10; // Right motor 1st pin
int MRb = 11; // Right motor 2nd pin

int RECV_PIN = 4;  // IR receiver pin

void setup() {
  Serial.begin(9600);        // Start serial communication
  IrReceiver.begin(RECV_PIN); // Initialize IR receiver on pin 4
  pinMode(MLa, OUTPUT);      // Set motor pins as output
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {   // Check if an IR signal is received
    unsigned long data = IrReceiver.decodedIRData.decodedRawData;  // Store the decoded data
    Serial.println(data, HEX); // Print the received hex value

    // Move forward when "2" is pressed
    if (data == 0xE718FF00) {
      digitalWrite(MLa, HIGH);
      digitalWrite(MLb, LOW);
      digitalWrite(MRa, LOW);
      digitalWrite(MRb, HIGH);
      Serial.println("Moving Forward");
    }
    
    // Move backward when "8" is pressed
    else if (data == 0xAD52FF00) {
      digitalWrite(MLa, LOW);
      digitalWrite(MLb, HIGH);
      digitalWrite(MRa, HIGH);
      digitalWrite(MRb, LOW);
      Serial.println("Moving Backward");
    }

    // Turn right for 500ms when "6" is pressed
    else if (data == 0xA55AFF00) {
      digitalWrite(MLa, HIGH);
      digitalWrite(MLb, LOW);
      digitalWrite(MRa, HIGH);
      digitalWrite(MRb, LOW);
      Serial.println("Turning Right");
      delay(500); // Turn for 500ms
    }

    // Turn left for 500ms when "4" is pressed
    else if (data == 0xF708FF00) {
      digitalWrite(MLa, LOW);
      digitalWrite(MLb, HIGH);
      digitalWrite(MRa, LOW);
      digitalWrite(MRb, HIGH);
      Serial.println("Turning Left");
      delay(500); // Turn for 500ms
    }

    // Stop the robot when "5" is pressed
    else if (data == 0xE31CFF00) {
      digitalWrite(MLa, LOW);
      digitalWrite(MLb, LOW);
      digitalWrite(MRa, LOW);
      digitalWrite(MRb, LOW);
      Serial.println("Stopped");
    }

    IrReceiver.resume(); // Ready to receive the next code
  }
}
