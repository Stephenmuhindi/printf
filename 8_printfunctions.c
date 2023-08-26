#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - displays what if done
 * @format: format.
 * Return: characters.
 */
int _printf(const char *format, ...)
{
	int q, printed = 0, counter = 0;
	int flags, width, precision, sz, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (q = 0; format && format[q] != '\0'; q++)
	{
		if (format[q] != '%')
		{
			buffer[buff_ind++] = format[q];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			counter++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &q);
			width = get_width(format, &q, list);
			precision = get_precision(format, &q, list);
			sz = get_size(format, &q);
			++q;
			printed = handle_print(format, &q, list, buffer,
				flags, width, precision, sz);

			if (printed == -1)
				return (-1);
			counter += printed;
		}
	}
	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (counter);
}

/**
 * print_buffer - displays content
 * @buffer: buff array
 * @buff_ind: Index
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
