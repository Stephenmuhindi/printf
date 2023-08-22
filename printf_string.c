#include "main.h"
#include <stdio.h>

/**
* print_string - prints string
* @str: string
* Returns: no of strings
*/

int print_string(const char *str)
{
    int count = 0;

    while (*str)
    {
        write(1, str, 1);
        str++;
        count++;
    }

    return (count);
}
