#include "main.h"

/**
 * putzz - displays string
 * @c: string to print
 * Return: amount of bytes
 */

int putzz(char *c)
{
	int counter = o;

	if (c)
	{
		for (counter = 0; c[counter] != '\0'; counter++)
		{
			putc(c[counter]);
		}
	}
	return (counter);
}
