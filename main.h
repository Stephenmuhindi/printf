#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int _printf(const char *format, ...);
int _puts(char *c);
int _putchar(char c);
int print_int(va_list args);
int print_deci(va_list args);
#endif/*end of main.h*/
