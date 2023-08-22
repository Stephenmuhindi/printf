#include "main.h"
#include <stdio.h>
/**
* print_number - prints int
* @n: integer
* Return: no of int
*/ 

int print_number(int n)
{
    int count = 0;
    int digit;
    
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
        count++;
    }

    if (n / 10)
        count += print_number(n / 10);

    digit = (n % 10) + '0';
    write(1, &digit, 1);
    count++;

    return (count);
}

