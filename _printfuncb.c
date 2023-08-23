#include "main.h"

/**
 * print_unsigned - displays unsigned int.
 * @types: arguments
 * Return: amount chars.
 */

int print_unsigned(va_list types)
{
	unsigned long int num = va_arg(types, unsigned long int);
	char buffer[BUFF_SIZE];
	int q = BUFF_SIZE - 2;

    while (num > 0)
    {
	    buffer[q--] = (num % 10) + '0';
	    num /= 10;
    }

    q++;

    return (write_unsgnd(0, q, buffer, 0, 0, 0, 0));
}

/**
 * print_octal - displays unsigned int in octal.
 * @types: arguments
 * Return: amount of char.
 */

int print_octal(va_list types)
{
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;
	char buffer[BUFF_SIZE];
	int q = BUFF_SIZE - 2;

    while (num > 0)
    {
	    buffer[q--] = (num % 8) + '0';
	    num /= 8;
    }
    if (init_num == 0)
	    buffer[q--] = '0';
    q++;

    return (write_unsgnd(0, q, buffer, 0, 0, 0, 0));
}

/**
 * print_hexadecimal - displays unsigned int in hexadecimal.
 * @types: arguments
 * Return: amount of chars.
 */

int print_hexadecimal(va_list types)
{
    return (print_hexa(types, "0123456789abcdef", NULL, 0, 'x', 0, 0, 0));
}
