#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_number(int n);
int print_character(char c);
int print_reverse(const char *string);
int print_string(const char *string);
int _printf(const char *format, ...);
int printf_char(va_list args);
int printf_string(va_list args);
int printf_percent(va_list args);
int printf_int(va_list args);


#endif
