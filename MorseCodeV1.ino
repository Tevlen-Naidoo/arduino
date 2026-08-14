const int LED = 13;

enum { DOT = '.', DASH = '-', SPACE = ' ', SLASH = '/' };

const int UNIT = 100;

const int DIT = 1 * UNIT;
const int DAH = 3 * UNIT;
const int INTRA_CHAR_SPACE = 1 * UNIT;
const int INTER_CHAR_SPACE = 3 * UNIT;
const int INTER_WORD_SPACE = 7 * UNIT;

struct MorseMap {
  char key;
  int timing;
  int value;
};

const struct MorseMap mappings[] = {
  { DOT, DIT, HIGH },
  { DASH, DAH, HIGH },
  { SPACE, INTER_CHAR_SPACE, LOW },
  { SLASH, INTER_WORD_SPACE, LOW }
};

int mapSize = sizeof(mappings) / sizeof(mappings[0]);

struct MorseMap get(char c)
{
  for (int i = 0; i < mapSize; i++)
  {
    if (mappings[i].key == c) {
      return mappings[i];
    }
  }
  return (struct MorseMap){ DOT, DIT, LOW };
}

void beep(char c)
{
  struct MorseMap mm = get(c);

  digitalWrite(LED, mm.value);
  delay(mm.timing);

  digitalWrite(LED, LOW);
  delay(INTRA_CHAR_SPACE);
}

void parseMorseCode(char *message)
{
  for (; *message; message++)
  {
    beep(*message);
  }
}

void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  const char *message = ".... . .-.. .-.. --- / .-- --- .-. .-.. -..";

  parseMorseCode(message);

  // Ensuring there is enough time
  // between the last and first words

  digitalWrite(LED, LOW);
  delay(INTER_WORD_SPACE);
}
