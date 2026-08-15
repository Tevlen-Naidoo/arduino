#include <stdio.h>

enum { DOT = '.', DASH = '-', SPACE = ' ', SLASH = '/' };

const int UNIT = 100;

enum {
  DIT = 100,
  DAH = 300,
  INTRA_CHAR_SPACE = 100,
  INTER_CHAR_SPACE = 300,
  INTER_WORD_SPACE = 700
};

enum { HIGH = 1, LOW = 0 };

struct MorseMap {
  char type;
  int timing;
  int value;
  char *name;
};

const struct MorseMap mappings[] = {
    {DOT, DIT, HIGH, "DOT"},
    {DASH, DAH, HIGH, "DAH"},
    {SPACE, INTER_CHAR_SPACE, LOW, "SPACE"},
    {SLASH, INTER_WORD_SPACE, LOW, "SLASH"},
};

int mapSize = sizeof(mappings) / sizeof(mappings[0]);

struct MorseMap find(char c) {
  for (int i = 0; i < mapSize; i++) {
    if (mappings[i].type == c) {
      return mappings[i];
    }
  }
  return (struct MorseMap){DOT, DIT, LOW, "[EMPTY]"};
}

void beep(char c) {
  struct MorseMap mm = find(c);

  printf("%c\t%s\t%d\t%d\n", c, mm.name, mm.timing, mm.value);
}

int main() {
  char *message = ".... . .-.. .-.. --- / .-- --- .-. .-.. -..";

  printf("CHAR\tNAME\tTIMING\tVALUE\n");

  for (; *message; message++) {
    beep(*message);
  }

  return 0;
}
