#include "main.h"
#include <stdarg.h>
#include <stdio.h>/* Include the necessary header for putchar*/

int _printf(const char *format, ...)
{
	unsigned int q;
	int counter = 0;/* Declare and initialize counter*/
	int counter_string = 0;/* Declare and initialize counter_string*/

	va_list arguments;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(arguments, format);

	for (q = 0; format[q] != '\0'; q++)
	{
		if (format[q] != '%')
		{
			putchar(format[q]);/* Use putchar to output a single character*/
		}
		else if (format[q + 1] == 'c')
		{
			putchar(va_arg(arguments, int));
			q++;
		}
		else if (format[q + 1] == 's')
		{
			char *str = va_arg(arguments, char *);

			puts(str);/* Use puts to output a string*/
			counter_string = strlen(str);
			counter += (counter_string - 1);
			q++;
		} else if (format[q + 1] == '%')
		{
			putchar('%');
			q++;
		}
		counter++;
	}
	va_end(arguments);

	return (counter);
}
