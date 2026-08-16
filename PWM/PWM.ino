// PWM Practice

const int LED = 9;    // the pin for the LED
int i = 0;            // we'll use this to count up and down

void setup() {
  pinMode(LED, OUTPUT);   // tell Arduino LED is an output
}

void loop() {
  for (i = 0; i < 255; i++) {
    analogWrite(LED, i);  // set the LED brightness
    delay(10);            // wait 10ms because analogWrite is instantaneous and we would not see the change with no delay
  }

  for (i = 255; i > 0; i--) {
    analogWrite(LED, i);  // set the LED brightness
    delay(10);            // wait 10ms
  }
}
