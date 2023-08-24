#include "main.h"

/**
 * _printf -displays sring.
 * @format: specifiers
 * Return: amount of bytes
 */

void print_buffer(char buffer[], int *buff_ind);

int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;

	va_list list;

	char buffer[BUFF_SIZE];
/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 * Return: amount of bytes
 */
int _printf(const char *format, ...)
{
	int q = 0;

	va_list(args);

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
			}
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			i++;
			printed = handle_print(format, &i, list, buffer,
					flags, width, precision, size);
			if (printed == -1)
			{
				va_end(list);
				return (-1);
			}
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);

	va_end(list);

    return (printed_chars);
}

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, &buffer[0], *buff_ind);
	}

	*buff_ind = 
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			q++;
			format++;
		} else
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				char my_str[20];

				sprintf(my_str, "%d", num);
				q += write(1, my_str, strlen(my_str));
			}
			format++;
		}
	}
	va_end(args);
	return (q);
}
