#include "main.h"

/**
 * _printf - Custom printf function selects appropriate formatting
 * function based on conversion specifiers.
 * @format: The format string with conversion specifiers.
 * Return: amount of characters printed.
 */

int _printf(const char * const format, ...)
{
	convert_match m[] = {
		{"%c", printf_char},
		{"%s", printf_string},
		{"%%", printf_percent},
		{"%d", printf_int},
		{"%i", printf_int}
	};

	va_list args;

	int q = 0, w, len = 0;

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[q] != '\0')
	{
		w = 4;

	while (w >= 0)
	{
		if (format[q] == '%' && format[q + 1] == m[w].id[1])
		{
			len += m[w].f(args);
			q += 2;

			goto Here;
		}
		w--;
	}
	putc(format[q]);
	len++;
	q++;
	}

	va_end(args);
	return (len);
}
