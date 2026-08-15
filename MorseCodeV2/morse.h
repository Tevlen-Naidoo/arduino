#ifndef MORSE_H
#define MORSE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "morseDict.h"
#include "symbolMap.h"

#define UNIT 100 /* milliseconds */
#define LED 13

enum {
  DIT = UNIT,
  DAH = 3 * UNIT,
  INTRA_CHAR_SPACE = UNIT,
  INTER_CHAR_SPACE = 3 * UNIT,
  INTER_WORD_SPACE = 7 * UNIT
};

enum { DOT = '.', DASH = '-', SPACE = ' ', SLASH = '/' };

extern const struct SymbolMap mappings[];

void loadMorseTable();

struct SymbolMap get(char c);

void beep(char c);

void parseSequence(const char *sequence);

void translateToMorse(const char *message);

#ifdef __cplusplus
}
#endif

#endif
