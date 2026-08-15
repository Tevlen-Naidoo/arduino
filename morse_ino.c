#include <Arduino.h>
#include <stddef.h>

#include "morse_ino.h"

void loadMorseTable() {
  install('A', ".-");
  install('B', "-...");
  install('C', "-.-.");
  install('D', "-..");
  install('E', ".");
  install('F', "..-.");
  install('G', "--.");
  install('H', "....");
  install('I', "..");
  install('J', ".---");
  install('K', "-.-");
  install('L', ".-..");
  install('M', "--");
  install('N', "-.");
  install('O', "---");
  install('P', ".--.");
  install('Q', "--.-");
  install('R', ".-.");
  install('S', "...");
  install('T', "-");
  install('U', "..-");
  install('V', "...-");
  install('W', ".--");
  install('X', "-..-");
  install('Y', "-.--");
  install('Z', "--..");
  install('1', ".----");
  install('2', "..---");
  install('3', "...--");
  install('4', "....-");
  install('5', ".....");
  install('6', "-....");
  install('7', "--...");
  install('8', "---..");
  install('9', "----.");
  install('0', "-----");
}

const struct SymbolMap mappings[] = {
    {DOT, DIT, HIGH},
    {DASH, DAH, HIGH},
    {SPACE, INTER_CHAR_SPACE, LOW},
    {SLASH, INTER_WORD_SPACE, LOW},
};

const int mapSize = sizeof(mappings) / sizeof(mappings[0]);

struct SymbolMap get(char c) {
  for (int i = 0; i < mapSize; i++)
    if (mappings[i].type == c)
      return mappings[i];

  return (struct SymbolMap){'\0', INVALID, INVALID};
}

void beep(char c) {
  struct SymbolMap mapping = get(c);

  if (mapping.type != '\0') {
    digitalWrite(LED, mapping.value);
    delay(mapping.timing);

    digitalWrite(LED, LOW);
    delay(INTRA_CHAR_SPACE);
  }
}

void parseSequence(const char *sequence) {
  for (; *sequence; sequence++) {
    beep(*sequence);
  }
  
  delay(INTER_CHAR_SPACE - INTRA_CHAR_SPACE);
}

void translateToMorse(const char *message) {
  for (; *message; message++) {

    if (*message == ' ') {
      delay(INTER_WORD_SPACE - INTER_CHAR_SPACE);
      continue;
    }

    const char *sequence = lookup(*message);
    if (sequence != NULL && sequence[0] != '\0') {
      parseSequence(sequence);
    }

  }
}

