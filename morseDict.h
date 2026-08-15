#pragma once

#define TABLESIZE 37
#define SPACE_INDEX 36
#define INVALID -1

void install(char key, const char *value);

const char *lookup(char key);
