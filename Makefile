CC = gcc

CFLAGS = -Wall -Wextra -pedantic -Werror=implicit-function-declaration -g

TARGET = morse

SRCS = MorseCodeV2.c morse.c morseDict.c

all: morse-v2

morse-v2: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all morse-v2 clean
