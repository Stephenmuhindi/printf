#include "main.h"

/**
 * print_binary - displays unsigned int in binary
 * @types: arguments
 * Return: amount of chars.
 */

int print_binary(va_list types)
{
	unsigned int n = va_arg(types, unsigned int);
	unsigned int m = 2147483648;
	unsigned int a[32];
	int count = 0;

	a[0] = n / m;
	for (int i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}

	int sum = 0;

	for (int i = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			putchar('0' + a[i]);
			count++;
		}
	}
	return (count);
}
