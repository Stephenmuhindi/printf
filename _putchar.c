#include <unistd.h>

/**
 * putc - displays c to stdout
 * @c: input
 * Return: On success 1. alternatively -1 
 */
int putc(char c)
{
	return (write(1, &c, 1));
}
