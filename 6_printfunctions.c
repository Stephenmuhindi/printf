#include "main.h"
/**
 * handle_print - displays agrs according to type
 * @fmt: str.
 * @list: args
 * @ind: index.
 * @buffer: Buff array
 * @flags: Flags
 * @width: WIdth.
 * @precision: Precision
 * @sz: Size
 * Return: 1 or 2;
 */
int handle_pt(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int sz)
{
	int q, unknown_length = 0, counted_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (q = 0; fmt_types[q].fmt != '\0'; q++)
		if (fmt[*ind] == fmt_types[q].fmt)
			return (fmt_types[q].fn(list, buffer, flags, width, precision, sz));
	if (fmt_types[q].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknown_length += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknown_length += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_length += write(1, &fmt[*ind], 1);
		return (unknown_length);
	}
	return (counted_chars);
}
