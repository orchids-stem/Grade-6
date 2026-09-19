#define IR 2  // Pin connected to the IR sensor

void setup() {
  Serial.begin(9600);       // Start serial communication at 9600 baud rate
  pinMode(IR, INPUT_PULLUP); // Set IR sensor pin as input with internal pull-up resistor
}

void loop() {
  int IR_read = digitalRead(IR);  // Read the state of the IR sensor
  
  // Print the value of IR sensor
  Serial.println(IR_read);

  // Check if object is detected
  if (IR_read == LOW) {
    Serial.println("Object detected");
  } else {
    Serial.println("Object not detected");
  }
  
  delay(500);  // Add a small delay to avoid spamming the serial output
}
