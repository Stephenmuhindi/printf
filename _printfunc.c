#include "main.h"

/**
 * print_char - Prints a char
 * @types: arguments
 * Return: amount of chars.
 */

int print_char(va_list types)
{
    char c = va_arg(types, int);
    putchar(c);
    return 1;
}

/*
 * print_string - displays char *.
 * @types: List arguments.
 * Return: amount of chars.
 */

int print_string(va_list types)
{
    char *str = va_arg(types, char *);
    if (str == NULL)
        str = "(null)";
    printf("%s", str);
    return strlen(str);
}

/**
 * print_percent - displays percent.
 * @types: arguments.
 * Return: amount of chars.
 */

int print_percent(va_list types)
{
    UNUSED(types);
    putchar('%');
    return 1;
}

/*
 * print_int - displays an integer
 * @types: arguments.
 * Return: amount of chars.
 */

int print_int(va_list types)
{
    int n = va_arg(types, int);
    printf("%d", n);
    return num_digits(n);
}

