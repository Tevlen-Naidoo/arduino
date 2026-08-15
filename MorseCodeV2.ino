#include "morse_ino.h"

void setup()
{
  pinMode(LED, OUTPUT);
  loadMorseTable();
}

void loop()
{
  const char *message = "Hello World";

  translateToMorse(message);

  // Ensuring there is enough time
  // between the last and first words

  digitalWrite(LED, LOW);
  delay(INTER_WORD_SPACE - INTER_CHAR_SPACE);
}

