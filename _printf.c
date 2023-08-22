#include "main.h"
#include <stdarg.h>

/**
 * _printf - displays the string to handle
 * @format: specifiers
 * Retuns: number of bytes or string
 */

int _printf(const char *format, ...)
{
	unsigned int q, counter = 0, counter_string = 0;

	va_list(arguments);

	if
		(!format || (format[0] == '%' && format[1] == '\0'))
	return (-1);

	va_start(arguments, format);

	for (q = 0; format[q] != '\0'; q++)
	{
		if (format[q] != "%")
		{
			putc(format[q]);
		}
		else if (format[q] == '%' && format[q + 1] ==  'c')
		{
			putc(va_arg(arguments, int);
					q++;
		}
		else if (format[q] == '%' && format[q + 1] ==  'd')
		{
		putc(va_arg(arguments, int);
				q++;
		}
		else if (format[q] == '%' && format[q + 1] == 's')
		{
		counter_string = (va_args(arguments, char *);
				counter += (counter_string - 1);
		}
		else if (format[q] == '%' && format[q + 1] == '%')
		{
		putc('%');
		}
		else if (format[q] == '%' && format[q + 1] ==  'i')
		{
		putc(va_arg(arguments, int);
		q++;
		}
		counter++;

		va_end(arguments);

		return (counter);
}
