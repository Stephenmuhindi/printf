#include "main.h"

/**
* printf_str - string is printed
* @value: argument
* Return: length
*/

int printf_str(va_list value)
{
	char *t;
	int n, length;

	t = va_arg(value, char *);
	if (t == NULL)
	{
		t = "(null)";
		length = _strlen(t);
		for (n = 0; n < length; n++)
			_putc(t[n]);
		return (length);
	}
	else
	{
		length = _strlen(t);
		for (n = 0; n < length; n++)
			_putc(t[n]);
		return (length);
	}
}
