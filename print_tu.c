#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
* _printf - prints in a certain format
* @format: argument
* Return: number of chars
*/ 
int _printf(const char *format, ...)
{
	va_list args;
    int printed_chars = 0;
    char *str;
    int num;
    char c;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    c = va_arg(args, int);
                    printed_chars += print_character(c);
                    break;
                case 's':
                    str = va_arg(args, char *);
                    printed_chars += print_string(str);
                    break;
                case 'd':
                case 'i':
                    num = va_arg(args, int);
                    printed_chars += print_number(num);
                    break;
                case '%':
                    printed_chars += print_character('%');
                    break;
                case 'r':
                    str = va_arg(args, char *);
                    printed_chars += print_reverse(str);
                    break;
            }
        }
        else
        {
            printed_chars += print_character(*format);
        }

        format++;
    }

    va_end(args);

    return printed_chars;
}
