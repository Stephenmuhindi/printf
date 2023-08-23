#ifndef HOLS_H
#define HOLS_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
* struct vert - defines a structure
* @u: operator
* @f: function
*/

struct vert
{
	char *u;
	int(*f)(va_list);
};
typedef struct vert vert_same;

int pass(const char *format, vert_same p[], va_list argumentz);
int _printf(const char *format, ...);
int write_char(char);
int printf_char(va_list);
int printf_str(va_list);
int printf_cent(va_list);
int printf_int(va_list);
int printf_num(va_list);
int printf_bina(va_list);
int printf_rev(va_list argumentz);
int rot_thirteen(va_list);
int unsigned_int(va_list);
int printf_oct(va_list listed);
int printf_hex(va_list listed);
int printf_Hex(va_list listed);

unsigned int base_length(unsigned int, int);
char *rev_string(char *);
void write_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int m);
int printf_unsigned_num(unsigned int);

#endif
