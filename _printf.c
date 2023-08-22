#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
* _printf - displays according to format.
* @format: char *.
* @...: variable arguments
* Return: amount of chars printed
*/

int _printf(const char *format, ...)
{
	va_list arguments;
	int counted_chars = 0;

	va_start(arguments, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(arguments, int);

				write(1, &c, 1);
				counted_chars++;
			}
			else if (*format == 's')
			{
				char *string = va_arg(arguments, char *);

				while (*string)
				{
					write(1, string, 1);
					string++;
					counted_chars++;
				}
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				counted_chars++;
			}
		}
		else
		{
			write(1, format, 1);
			counted_chars++;
		}
		format++;
	}
	va_end(arguments);
	return (counted_chars);
}
