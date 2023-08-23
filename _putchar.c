#include <stdio.h>
#include "hols.h"

/**
 * write_char - displays c to stdout
 * @c: input
 * Return: On success 1. alternatively -1 
 */
int write_char(char c)
{
	return (write(1, &c, 1));
}
