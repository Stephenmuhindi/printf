#include "main.h"

/**
* handle_pt - prints an argument based on its type
* @format: formatted string
* @list: list of arguments
* @ind: indicator
* @buf: buffer array
* @flags: calculates flag
* @width: width
* @precision: precision
* @size: size
* Return: 1 or 2;
*/

int handle_pt(const char *format, int *ind, va_list list, char buf[],
		int flags, int width, int precision, int size)
{
	int a, unknown_length = o, counted_chars = -1;
	format_t format_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (a = 0; format_types[a].format != '\0'; a++)
		if (format[*ind] == format_types[a].format)
			return (format_types[a].fn(list, buf, flags, width, precision, size));
	if (format_types[a].format == '\0')
	{
		if (format[*ind] == '\0')
			return (-1);
		unknown_length += write(1, "%%", 1);
		if (format[*ind - 1] == '')
			unknown_length += write(1, "", 1);
		else if (width)
		{
			--(*ind);
			while (format[*ind] != '' &&format[*ind] != '%')
				--(*ind);
			if (format[*ind] == '')
				--(*ind);
			return (1);
		}
		unknown_length += write(1, &format[*ind], 1);
		return (unknown_length);
	}
	return (counted_chars);
}
