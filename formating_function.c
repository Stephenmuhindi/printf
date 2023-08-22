#include "main.h"
#include <stdio.h>

/**
 * printf_char - Format and display character.
 * @args: va_list of arguments.
 * Return: amount of char.
 */

int printf_char(va_list args)
{
	char c = va_arg(args, int);

	putc(c);
	return (1);
}

/**
 * printf_string - Format and display str.
 * @args: va_list of arguments.
 * Return: amount of char.
 */

int printf_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	if (str == NULL)
		str = "(null)";
	while (str[len])
	{
		putc(str[len]);
		len++;
	}

	return (len);
}

/**
 * printf_percent - Format and display percent.
 * @args: va_list of arguments.
 * Return: amount of char.
 */

int printf_percent(va_list args)
{
	(void)args;
	putc('%');

	return (1);
}

/**
 * printf_int - Format and displays int.
 * @args: va_list of arguments.
 * Return: amount of char.
 */

int printf_int(va_list args)
{
	int num = va_arg(args, int);
	int len = 0;

	if (num < 0)
	{
		putc('-');
		len++;
		num = -num;
	}

	len += printf_int(num);

	return (len);
}
