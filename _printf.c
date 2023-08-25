#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h> /* Include the necessary header for putchar*/
/**
* _printf -displays sring.
* @format: specifiers
* Return: amount of bytes
*/

int _printf(const char *format, ...)
{
	unsigned int q;
	int count = 0;
	va_list args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	for (q = 0; format[q] != '\0'; q++)
	{
		if (format[q] != '%')
		{
			_putchar(format[q]); /* Use putchar to output a single character */
		}
		else if (format[q + 1] == 'c')
		{
			_putchar(va_arg(args, int));
			q++;
			count++;
		}
		else if (format[q + 1] == 's')
		{
			char *str = va_arg(args, char *);

			while (*str)
			{
				_putchar(*str);
				str++;
				count++;
			}
			q++;
		}
		else if (format[q + 1] == 'd' || format[q + 1] == 'i')
		{
			int num = va_arg(args, int);
			char my_str[20];

			printf(my_str, "%d", num);
			count += write(1, my_str, strlen(my_str));
			q++;
		}
		else if (format[q + 1] == '%')
		{
			_putchar('%');
			q++;
			count++;
		}
		count++;
	}
	va_end(args);
	return (count);
}
