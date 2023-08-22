#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> /* used by variadic function*/
#include <unistd.h> /* used by putchar*/
#include <limits.h>
/**
* format - match conversion identifiers
* @id: pointer
* @f: pointer
*/
typedef struct format
{
	char *id;
	int (*f)();
} vert_same;

int _printf(const char *format, ...);
int _putc(char c);
int printf_rot13(va_list argumentz);
int printf_bin(va_list value);
int printf_unsigned(va_list argumentz);
int printf_oct(va_list value);
int printf_hex(va_list value);
int printf_HEX(va_list value);
int printf_exs_str(va_list value);
int printf_pot(va_list value);
int printf_cent(void);
int printf_str(va_list value);
int printf_char(va_list value);
int printf_int(va_list argumentz);
int printf_deci(va_list argumentz);
int printf_srev(va_list argumentz);
int _strlen(char *s);

#endif /*end of thei main.h */
