#pragma once

#include <stdint.h>
#include <stdio.h>

#define HIGH 0x1
#define LOW 0x0

#define INPUT 0x0
#define OUTPUT 0x1

static inline void pinMode(uint8_t pin, uint8_t mode) {
  printf("pinMode(%u, %s);\n", pin, mode == OUTPUT ? "OUTPUT" : "INPUT");
}

static inline void digitalWrite(uint8_t pin, uint8_t value) {
  printf("digitalWrite(%u, %s);\n", pin, value ? "HIGH" : "LOW");
}

static inline void delay(unsigned long ms) { printf("  delay(%lu);\n", ms); }
