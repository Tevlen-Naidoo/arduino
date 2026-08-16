// PWM Practice

const int LED = 9;    // the pin for the LED
const int BUTTON = 7; // input pin of the pushbutton

int val = 0;          // stores the state of the pin
int old_val = 0;      // stores the previous value of `val`

int state = 0;        // 0 = LED off; 1 = LED on

int brightness =  128;        // stores the brightness value
unsigned long startTime = 0;  // when did we begin pressing the button

void setup() {
  pinMode(LED, OUTPUT);   // tell Arduino LED is an output
  pinMode(BUTTON, INPUT); // and BUTTON is an input
}

void loop() {
  val = digitalRead(BUTTON);  // read input value and store it

  if ((val == HIGH) && (old_val == LOW)) {
    state = 1 - state;    // change the state from off to on or vice-verse

    startTime = millis(); // millis() is the Arduino clock. It returns how many milliseconds have passed since the board has been reset.

    delay(10);            // wait a bit so that we can see the effect
  }

  // check whether the button is being pressed down
  if ((val == HIGH) && (old_val == HIGH)) {
    // if the button is held for more than 500ms
    if (state == 1 && (millis() - startTime) > 500) {
      brightness++; // increment brightness by one
      delay(10);    // delay to avoid the brightness going up too fast

      if (brightness > 255) // 255 is the max brightness
        brightness = 0;     // if we go over 255, we go back to 0
    }
  }

  old_val = val;  // val is now old, lets store it

  if (state == 1)
    analogWrite(LED, brightness); // turn LED on at the current brightness level
  else
    analogWrite(LED, 0);          // turn LED off
}
