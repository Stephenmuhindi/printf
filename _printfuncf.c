#include "main.h"

/**
 * print_pointer - displays the value of pointer variable
 * @types: arguments
 * Return: amount of chars.
 */

int print_pointer(va_list types)
{
	void *addrs = va_arg(types, void *);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	unsigned long int num_addrs = (unsigned long int)addrs;
	char buffer[BUFF_SIZE];
	int q = BUFF_SIZE - 2;
	char map_to[] = "0123456789abcdef";
	
	while (num_addrs > 0)
	{
		buffer[i--] = map_to[num_addrs % 16];
		num_addrs /= 16;
	}

	buffer[q--] = 'x';
	buffer[q--] = '0';
	q++;

	return (write_pointer(buffer, q, BUFF_SIZE - q - 1, 0, 0, ' ', 0, 1));
}

/**
 * print_non_printable - displays ASCII in hexadecimal.
 * @types: arguments
 * Return: amount of char.
 */

int print_non_printable(va_list types)
{
	char *str = va_arg(types, char *);
	char buffer[BUFF_SIZE];
	int q = 0;
	int offset = 0;

	if (str == NULL)
        return (write(1, "(null)", 6));

	while (str[q] != '\0')
	{
		if (is_printable(str[q]))
			buffer[q + offset] = str[q];
		else
			offset += append_hexa_code(str[q], buffer, q + offset);
		q++;
	}

	buffer[q + offset] = '\0';

	return (write(1, buffer, i + offset));
}
