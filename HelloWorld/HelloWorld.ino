// Hello World Morse Code

// .... . .-.. .-.. --- / .-- --- .-. .-.. -..

const int LED = 13;

const int UNIT = 100;

const int SHORT = 1 * UNIT;
const int LONG = 3 * UNIT;

const int IN_LETTER = 1 * UNIT;
const int IN_BETWEEN_LETTERS = 3 * UNIT;
const int IN_BETWEEN_WORDS = 7 * UNIT;

void dot() {
  digitalWrite(LED, HIGH);
  delay(SHORT);
}

void dash() {
  digitalWrite(LED, HIGH);
  delay(LONG);
}

void spaceInLetter() {
  digitalWrite(LED, LOW);
  delay(IN_LETTER);
}

void spaceBetweenLetter() {
  digitalWrite(LED, LOW);
  delay(IN_BETWEEN_LETTERS);
}

void spaceBetweenWord() {
  digitalWrite(LED, LOW);
  delay(IN_BETWEEN_WORDS);
}

void setup() {
  pinMode(LED, OUTPUT);
}

// .... . .-.. .-.. --- / .-- --- .-. .-.. -..

void loop() {
  // H
  dot();
  spaceInLetter();
  dot();
  spaceInLetter();
  dot();
  spaceInLetter();
  dot();
  spaceBetweenLetter();

  // e
  dot();
  spaceBetweenLetter();

  // l
  dot();
  spaceInLetter();
  dash();
  spaceInLetter();
  dot();
  spaceInLetter();
  dot();
  spaceBetweenLetter();

  // l
  dot();
  spaceInLetter();
  dash();
  spaceInLetter();
  dot();
  spaceInLetter();
  dot();
  spaceBetweenLetter();

  // o
  dash();
  spaceInLetter();
  dash();
  spaceInLetter();
  dash();

  spaceBetweenWord();

  // W
  dot();
  spaceInLetter();
  dash();
  spaceInLetter();
  dash();
  spaceBetweenLetter();

  // o
  dash();
  spaceInLetter();
  dash();
  spaceInLetter();
  dash();

  // r
  dot();
  spaceInLetter();
  dash();
  spaceInLetter();
  dot();
  spaceBetweenLetter();

  // l
  dot();
  spaceInLetter();
  dash();
  spaceInLetter();
  dot();
  spaceInLetter();
  dot();
  spaceBetweenLetter();

  // d
  dash();
  spaceInLetter();
  dot();
  spaceInLetter();
  dot();
  spaceBetweenWord();
}
