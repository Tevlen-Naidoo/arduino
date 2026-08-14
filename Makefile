CC = gcc

CFLAGS = -Wall -Wextra -pedantic -g


TARGET = morse

all: morseCode.c
	$(CC) $(CFLAGS) -o $(TARGET) morseCode.c

clean:
	rm -f $(TARGET)
