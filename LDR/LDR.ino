const int LED = 9;

int val = 0;

void setup() {
  pinMode(LED, OUTPUT);

  /* Note: Analogue pins are automatically set as inputs */
}

void loop() {
  val = analogRead(0);  // read value from the sensor

  analogWrite(LED, val / 4);
  delay(10);
}
