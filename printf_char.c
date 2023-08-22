#include <stdio.h>
#include "main.h"

/**
* print_character - prints chars
* @c: char
* Return: no of chars
*/

int print_character(char c)
{
    write(1, &c, 1);
    return (1);
}

