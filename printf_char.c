#include "main.h"

/**
* printf_char - character printed
* @value: argument
* Return: 1
*/

int printf_char(va_list value)
{
	char g;

	g = va_arg(value, int);
	_putc(g);
	return (1);
}
