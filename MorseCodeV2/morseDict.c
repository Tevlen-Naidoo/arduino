#include <stddef.h>

#include "morseDict.h"

static const char *table[TABLESIZE]; /* pointer table */

static int getIndex(char c) {
  if (c == ' ')
    return SPACE_INDEX;
  if (c >= '0' && c <= '9')
    return c - '0';
  if (c >= 'A' && c <= 'Z')
    return c - 'A' + 10;
  if (c >= 'a' && c <= 'z')
    return c - 'a' + 10;

  return INVALID;
}

/* The values are string literals with static storage duration, so the table
   can hold the pointers directly instead of duplicating them onto the heap. */
void install(char key, const char *value) {
  int index = getIndex(key);

  if (index == INVALID)
    return;

  table[index] = value;
}

const char *lookup(char key) {
  int index = getIndex(key);

  if (index == INVALID)
    return NULL;

  return table[index];
}
