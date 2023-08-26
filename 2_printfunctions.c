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
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_adrs;
	char map_to[] = "0123456789abcdef";
	void *adrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);
	if (adrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_adrs = (unsigned long)adrs;

	while (num_adrs > 0)
	{
		buffer[ind--] = map_to[num_adrs % 16];
		num_adrs /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;
	ind++;
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
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
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int q = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[q] != '\0')
	{
		if (is_printable(str[q]))
			buffer[q + offset] = str[q];
		else
			offset += append_hexa_code(str[q], buffer, q + offset);

		q++;
	}
	buffer[q + offset] = '\0';
	return (write(1, buffer, q + offset));
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
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str;
	int q, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);
		str = ")Null(";
	}
	for (q = 0; str[q]; q++)
	for (q = q - 1; q >= 0; q--)
	{
		char z = str[q];

		write(1, &z, 1);
		count++;
	}
	return (count);
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

int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int q, m;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (q = 0; str[q]; q++)
	{
		for (m = 0; in[m]; m++)
		{
			if (in[m] == str[q])
			{
				x = out[m];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[m])
		{
			x = str[q];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
