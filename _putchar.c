#include <stdio.h>
#include "hols.h"

/**
 * write_char - displays c to stdout
 * @c: char
 * Return: 1
 */
#include <unistd.h>
/*#include <stdio.h>*/

/**
 * _putchar - displays c to stdout
 * @c: input
 * Return: On success 1. alternatively -1
 */

int write_char(char c)/*int _putchar(char c)*/
{
	return (write(1, &c, 1));
}
