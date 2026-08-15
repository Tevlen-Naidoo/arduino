#include "arduinoSim.h"
#include "morse.h"

static void setup(void) {
  pinMode(LED, OUTPUT);
  loadMorseTable();
}

static void loop(void) {
  const char *message = "Hello World";

  translateToMorse(message);

  /* Ensuring there is enough time
     between the last and first words */

  digitalWrite(LED, LOW);
  delay(INTER_WORD_SPACE - INTER_CHAR_SPACE);
}

int main(void) {
  setup();
  loop();

  return 0;
}
