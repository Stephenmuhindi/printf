#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Custom display function
 * @format: Format str.
 * Return: amount of displayed characters.
 */

int _printf(const char *format, ...)
{
	if (format == NULL)
		return -1;

	va_list arguments;
	va_start(args, format);

	int printed_chars = 0;
	int buff_ind = 0;
	char buffer[BUFF_SIZE];

	for (int q = 0; format[q] != '\0'; q++)
	{
		if (format[q] != '%')
		{
			buffer[buff_ind++] = format[q];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
				printed_chars++;
			}
		}
		else
		{
            print_buffer(buffer, &buff_ind);
            q++; /* Move past '%'*/


	    int flags = get_flags(format, &i);
	    int width = get_width(format, &i, arguments);
	    int precision = get_precision(format, &i, arguments);
	    int size = get_size(format, &i);
	    int printed = handle_print(format, &i, arguments, buffer,
			    flags, width, precision, size);
	    if (printed == -1)
	    {
                va_end(arguments);
		return (-1);
	    }
	    printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);

	va_end(arguments);

	return (printed_chars);
}
