#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int printf_char(va_list args);
int printf_string(va_list args);
int printf_percent(va_list args);
int printf_int(va_list args);
int putc(char c);

#endif
