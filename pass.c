#include "hols.h"

/**
* pass- receives string
* @format: character string
* @p: list of functions
* @argumentz: argumentz
* Return: count of characters
*/

int pass(const char *format, vert_same p[], va_list argumentz)
{
	int a, b, r_value, counted_chars;

	counted_chars = 0;
	for (a = 0; format[a] != '\0'; a++)
	{
		if (format[a] == '%')
		{
			for (b = 0; p[b].u != NULL; b++)
			{
				if (format[a + 1] == p[b].u[0])
				{
					r_value = p[b].f(argumentz);
					if (r_value == -1)
						return (-1);
					counted_chars += r_value;
					break;
				}
			}
			if (p[b].u == NULL && format[a + 1] != ' ')
			{
				if (format[a + 1] != '\0')
				{
					write_char(format[a]);
					write_char(format[a + 1]);
					counted_chars = counted_chars + 2;
				}
				else
					return (-1);
			}
				a = a + 1;
		}
		else
		{
			write_char(format[a]);
			counted_chars++;
		}
	}
	return (counted_chars);
}
