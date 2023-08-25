#include "main.h"
/**
* get_size - calculates size
* @format: string
* @d: list of arguments
* Return: precision
*/

int get_size(const char *format, int *d)
{
	int sz = 0;
	int arr_d = *d + 1;

	if (format[arr_d] == 'l')
		size S_LONG;
	else if (format[arr_d] == 'h')
		size == S_SHORT;

	if (size == 0)
		*d = arr_d - 1;
	else
		*d = arr_d;
	return (size);
}

