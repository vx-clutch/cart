#ifndef UTIL_H
#define UTIL_H

#include <stdarg.h>
#include <stdio.h>

static const char *RESET = "[0m";
static const char *RED = "[1;91m";
static const char *YELLOW = "[0;33m";
static const char *GREEN = "[1;32m";
static const char *PURPLE = "[0;95m";
static const char *WHITE = "[0;97m";

typedef enum {
  ok,
  error,
  warn,
  info,
  fatal,
} level_t;

#define cart_case(message, level_color)                                        \
  case message:                                                                \
    printf("%scart%s: %s" #message "%s: ", WHITE, RESET, level_color, RESET);  \
    break;

static int cprintf(level_t level, char *src, ...) {
  va_list args;
  va_start(args, src);
  switch (level) {
    cart_case(ok, GREEN);
    cart_case(error, RED);
    cart_case(warn, YELLOW);
    cart_case(info, PURPLE);
    cart_case(fatal, RED);
  }
  vprintf(src, args);
  printf("\n");
  va_end(args);
  return 0;
}

#endif
