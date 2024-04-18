#pragma once

#include "types.h"

#define va_arg __builtin_va_arg
#define va_end __builtin_va_end
#define va_list __builtin_va_list
#define va_start __builtin_va_start

#define PANIC(fmt, ...)                                                   \
  do {                                                                    \
    printf("PANIC: %s:%d: " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__); \
    while (1) {                                                           \
    }                                                                     \
  } while (0)

char *itoa(int num, char *str, int base);
void *memset(void *b, int c, size_t len);
int printf(const char *fmt, ...);
int putchar(int c);
