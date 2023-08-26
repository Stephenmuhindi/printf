#include "main.h"

/**
* get_size - sz
* @format: string
* @d: args
* Return: precision
*/

int get_size(const char *format, int *d)
{
	int sz = 0;
	int arr_d = *d + 1;

	if (format[arr_d] == 'l')
		sz == S_LONG;
	else if (format[arr_d] == 'h')
		sz == S_SHORT;

	if (sz == 0)
		*d = arr_d - 1;
	else
		*d = arr_d;
	return (sz);
}

