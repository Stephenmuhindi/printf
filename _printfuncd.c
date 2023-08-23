#include "main.h"

/**
 * print_hexa_upper - displays unsigned int in upper hexadecimal.
 * @types: arguments
 * Return: amount of chars.
 */

int print_hexa_upper(va_list types)
{
    return (print_hexa(types, "0123456789ABCDEF", NULL, 0, 'X', 0, 0, 0));
}

/**
 * print_hexa - displays hexadecimal int in lower or upper case.
 * @types: arguments
 * Return: amount of chars.
 */

int print_hexa(va_list types)
{
	char buffer[BUFF_SIZE];
	int q = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;
	char map_to[] = "0123456789abcdef";

	while (num > 0)
	{
		buffer[q--] = map_to[num % 16];
		num /= 16;
	}

	if (init_num == 0)
		buffer[q--] = '0';
	q++;

	return (write_unsgnd(0, q, buffer, 0, 0, 0, 0);
}
