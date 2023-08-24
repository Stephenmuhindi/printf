#include "main.h"

/**
 * _printf - displays string
 * @format: string
 * Return: amount of bytes
 */
int _printf(const char *format, ...)
{
	int q = 0;

	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			q++;
			format++;
		}
		else
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				int numb = va_arg(args, int);
				char our_string[30];

				sprintf(our_string, "%d", numb);
				q += write(1, our_string, strlen(our_string));
			}
			format++;
		}
	}
	va_end(args);
	return (q);
}
