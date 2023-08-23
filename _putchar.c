#include <stdio.h>
#include "main.h"

#include <unistd.h>


/**
 * _putchar - displays c to stdout
 * @c: input
 * Return: On success 1. alternatively -1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
