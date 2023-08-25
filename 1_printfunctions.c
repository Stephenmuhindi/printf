#include "main.h"

/**
 * print_char - displays characters.
 * @types: args
 * @buffer: Buff array
 * @flags:  flags
 * @width: WIdth.
 * @precision: Precision
 * @size: Size
 * Return: amount of bytes
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int q = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = vert_size_unsigned(num, size);

	if (num == 0)
		buffer[q--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[q--] = (num % 10) + '0';
		num /= 10;
	}
	q++;
	return (write_unsgnd(0, q, buffer, flags, width, precision, size));
}
/**
 * print_char - displays characters.
 * @types: args
 * @buffer: Buff array
 * @flags:  flags
 * @width: WIdth.
 * @precision: Precision
 * @size: Size
 * Return: amount of bytes
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int q = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = vert_size_unsigned(num, size);
	if (num == 0)
		buffer[q--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[q--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[q--] = '0';

	q++;
	return (write_unsgnd(0, q, buffer, flags, width, precision, size));
}

/**
 * print_char - displays characters.
 * @types: args
 * @buffer: Buff array
 * @flags:  flags
 * @width: WIdth.
 * @precision: Precision
 * @size: Size
 * Return: amount of bytes
 */
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}
/**
 * print_char - displays characters.
 * @types: args
 * @buffer: Buff array
 * @flags:  flags
 * @width: WIdth.
 * @precision: Precision
 * @size: Size
 * Return: amount of bytes
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}
/**
 * print_char - displays characters.
 * @types: args
 * @buffer: Buff array
 * @flags:  flags
 * @width: WIdth.
 * @precision: Precision
 * @size: Size
 * Return: amount of bytes
 */
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int q = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = vert_size_unsigned(num, size);

	if (num == 0)
		buffer[q--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[q--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[q--] = flag_ch;
		buffer[q--] = '0';
	}
	q++;
	return (write_unsgnd(0, q, buffer, flags, width, precision, size));
}
