#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
* _printf - displays according to a format
* @format: character string
* @...: variable arguments
* Return: number of characters printed
*/

int _printf(const char *format, ...)
{
int count = 0;

va_list arguments;

va_start(arguments, format);

while (*format)
{
if (*format != '%')
{
write(1, format, 1);
count++;
}
else
{
format++;

switch (*format)
{
case 'c':
{
char c = (char)va_arg(arguments, int);
write(1, &c, 1);
count++;
break;
}
case 's':
{
const char *strng = va_arg(arguments, const char *);
while (*strng)
{
write(1, strng, 1);
strng++;
count++;
}
break;
}
case '%':
{
write(1, format, 1);
count++;
break;
}
default:
break;
}
}

format++;
}

va_end(arguments);

return (count);
}
