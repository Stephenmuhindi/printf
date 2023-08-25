#include "main.h"
/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 * Return: amount of bytes
 */
int _printf(const char *format, ...)
{
        int q = 0;

        va_list(args);

        if (format == NULL)
                return (-1);

        va_start(args, format);

        while (*format != '\0')
        {
                if (*format != '%')
                {
                        write(1, format, 1);
                        q++;
                        format++;
                } else
                {
                        format++;
                        if (*format == 'd' || *format == 'i')
                        {
                                int num = va_arg(args, int);
                                char my_str[20];

                                sprintf(my_str, "%d", num);
                                q += write(1, my_str, strlen(my_str));
                        }
                        format++;
                }
        }
        va_end(args);
        return (q);
}
