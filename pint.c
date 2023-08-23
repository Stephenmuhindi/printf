#include "hols.h"

/**
* _printf - produces output according to a format.
* @format: character string
* Return: number of characters printed
*/

int _printf(const char *format, ...)
{
	int counted_chars;

	vert_same p[] = {
		{"c", printf_char},
		{"s", printf_str},
		{"%", printf_cent},
		{"d", printf_int},
		{"i", printf_int},
		{"r", printf_rev},
		/*{"R", rot_thirteen},*/
		{"u", unsigned_int},
		/*{"o", printf_oct},*/
		/*{"x", printf_hex},*/
		/*{"X", printf_Hex},*/
		{NULL, NULL}
	};
	va_list argumentz;
	if (format == NULL)
		return (-1);
	va_start(argumentz, format);

	counted_chars = pass(format, p, argumentz);
	va_end(argumentz);
	return (counted_chars);
}
