#include "main.h"

/**
* get_size - sz
* @format: string
* @d: args
* Return: precision
*/
int get_size(const char *format, int *q)
{
	int curr_q = *q + 1;
	int sz = 0;

	if (format[curr_q] == 'l')
		sz = S_LONG;
	else if (format[curr_q] == 'h')
		sz = S_SHORT;

	if (sz == 0)
		*q = curr_q - 1;
	else
		*q = curr_q;
	return (sz);
}
