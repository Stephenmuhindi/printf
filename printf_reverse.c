#include "main.h"
/**
* print_reverse - prints in reverse
* @str: string
* Return: reverse strinh
*/

int print_reverse(const char *str)
{
    int len = 0;
    int g;

    while (str[len])
        len++;

    g = len - 1; 

    while (g >= 0)
    {
        write(1, &str[g], 1);
        g--;
    }

    return (len);
}

