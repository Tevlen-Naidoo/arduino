CC = gcc

INCLUDES = -Iutils -IMorseCodeV2

CFLAGS = -Wall -Wextra -pedantic -Werror=implicit-function-declaration -g $(INCLUDES)

TARGET = morse

SRCS = MorseCodeV2/MorseCodeV2.c MorseCodeV2/morse.c MorseCodeV2/morseDict.c

all: morse-v2

morse-v2: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all morse-v2 clean
