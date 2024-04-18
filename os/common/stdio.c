#include "stdio.h"

#include "kernel/prototypes.h"
#include "types.h"

char *itoa(int num, char *str, int base) {
  int i = 0;
  unsigned int unum = (unsigned int)num;

  if (unum == 0) {
    str[i++] = '0';
    str[i] = '\0';
    return str;
  }

  while (unum != 0) {
    int rem = unum % base;
    str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
    unum = unum / base;
  }

  str[i] = '\0';

  int start = 0;
  int end = i - 1;
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
  return str;
}

void *memset(void *b, int c, size_t len) {
  size_t i;
  unsigned char *str;

  str = (unsigned char *)b;
  i = 0;
  while (i < len) {
    str[i] = (unsigned char)c;
    i++;
  }
  return (b);
}

int putchar(int c) { return kernel_putchar(c); }

int printf(const char *fmt, ...) {
  int count = 0;
  va_list ap;

  if (!fmt) {
    PANIC("fmt is NULL");
  }

  va_start(ap, fmt);
  const char *s;
  while (*fmt) {
    if (*fmt != '%') {
      if (putchar(*fmt) == EOF) {
        return EOF;
      }
      count++;
    } else {
      fmt++;
      switch (*fmt) {
        case '%':
          if (putchar('%') == EOF) {
            return EOF;
          }
          count++;
          break;
        case 'd': {
          char buf[12];
          itoa(va_arg(ap, int), buf, 10);
          s = buf;
          while (*s) {
            if (putchar(*s++) == EOF) {
              return EOF;
            }
            count++;
          }
          break;
        }
        case 's':
          s = va_arg(ap, const char *);
          while (*s) {
            if (putchar(*s++) == EOF) {
              return EOF;
            }
            count++;
          }
          break;
        case 'x': {
          char buf[9];
          itoa(va_arg(ap, int), buf, 16);
          s = buf;
          while (*s) {
            if (putchar(*s++) == EOF) {
              return EOF;
            }
            count++;
          }
          break;
        }
        default:
          if (putchar('%') == EOF) {
            return EOF;
          }
          count++;
          break;
      }
    }
    fmt++;
  }
  va_end(ap);

  return count;
}
