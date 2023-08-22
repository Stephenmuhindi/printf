#include "main.h"
/**
* _printf - output produced according to format
* @format: character string
* Return: characters printed
*/
int _printf(const char *format, ...)
{
	vert_same q[] = {
		{"%s", printf_str}, {"%c", printf_char},
		{"%%", printf_cent},
		{"%i", printf_int}, {"%d", printf_deci}, {"%r", printf_srev},
		{"%R", printf_rot13}, {"%b", printf_b}, {"%u", printf_unsigned},
		{"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
		{"%S", printf_exs_str}, {"%p", printf_pot}
	};
	va_list argumentz;
	int z = 0, l, length = 0;

	va_start(argumentz, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
Here:
	while (format[z] != '\0')
	{
		l = 13;
		while (l >= 0)
		{
			if (q[l].id[0] == format[z] && q[l].id[1] == format[z + 1])
			{
				length += q[l].f(argumentz);
				z = z + 2;
				goto Here;
			}
			l--;
		}
		_putc(format[z]);
		length++;
		z++;
	}
	va_end(argumentz);
	return (length);
}
