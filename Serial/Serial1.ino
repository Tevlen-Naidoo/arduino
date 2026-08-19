const int SERIAL = 0;

int val = 0;

void setup() {
  Serial.begin(9600);   // open the serial port to send data back to the computer at 9600 bits per second
}

void loop() {
  val = analogRead(SENSOR); // read value from the sensor

  Serial.println(val);      // print the value to the serial port

  delay(100);               // wait 100ms between each send
}
