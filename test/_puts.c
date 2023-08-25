#include "main.h"

/**
 * _puts - displays the string
 * @c: string
 * Return: amount of amount
 */
int _puts(char *c)
{
        int count = 0;

        if (c)
        {
                for (count = 0; c[count] != '\0'; count++)
                {
                        _putchar(c[count]);
                }
        }
        return (count);
}
