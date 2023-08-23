#include "main.h"

/**
 * get_size - Calculates size.
 * @format: Formatted string.
 * @i: Pointer to the current position.
 * Return: Size constant (S_LONG or S_SHORT)
 * 0 if specifier is not found.
 */

int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
	{
		size = S_LONG;
		curr_i++;
	}
	else if (format[curr_i] == 'h')
	{
		size = S_SHORT;
		curr_i++;
	}

	*i = curr_i;

	return (size);
}
