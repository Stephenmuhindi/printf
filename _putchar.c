<<<<<<< HEAD
#include <stdio.h>
#include "hols.h"

/**
 * write_char - displays c to stdout
=======
#include <unistd.h>
#include <stdio.h>

/**
 * _putchar - displays c to stdout
>>>>>>> 19bf3b09ef125fb62bfd1a850e89f40c3f0085bf
 * @c: input
 * Return: On success 1. alternatively -1
 */
<<<<<<< HEAD
int write_char(char c)
=======

int _putchar(char c)
>>>>>>> 19bf3b09ef125fb62bfd1a850e89f40c3f0085bf
{
	return (write(1, &c, 1));
}
