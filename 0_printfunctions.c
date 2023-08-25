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
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);
	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/**
 * print_string - displays str.
 * @types: args.
 * @buffer: Buff array
 * @flags:  Flags
 * @width: WIdth.
 * @precision: Precision.
 * @size: Size
 * Return: amount of bytes.
 */
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0, q;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	} while (str[length] != '\0')
		length++;

		if (precision >= 0 && precision < length)
			length = precision;
		if (width > length)
		{
			if (flags & F_MINUS)
			{
				write(1, &str[0], length);
				for (q = width - length; q > 0; q--)
					write(1, " ", 1);
				return (width);
			}
			else
			{
				for (q = width - length; q > 0; q--)
					write(1, " ", 1);
				write(1, &str[0], length);
				return (width);
			}
		}
		return (write(1, str, length));
}
/**
 * print_percent - displays percent
 * @types: args
 * @buffer: Buff array
 * @flags:  Flags
 * @width: WIdth.
 * @precision: Precision
 * @size: Size
 * Return: Amount of bytes
 */
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/**
 * print_int - displays a number
 * @types: args
 * @buffer: Buffarray
 * @flags:  Flags
 * @width: WIdth.
 * @precision: Precision
 * @size: Size
 * Return: amount of bytes
 */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int t = BUFF_SIZE - 2;
	int is_negative = 0;
	long int t = va_arg(types, long int);
	unsigned long int num;

	t = convert_size_number(t, size);

	if (t == 0)
		buffer[q--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)t;

	if (t < 0)
	{
		num = (unsigned long int)((-1) * t);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	q++;
	return (write_number(is_negative, q, buffer, flags, width, precision, size));
}
/**
 * print_binary - displays unsigned int
 * @types: args
 * @buffer: Buff array
 * @flags:  Flags
 * @width: WIdth.
 * @precision: Precision
 * @size: Size
 * Return: amount of bytes.
 */
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int t, v, q, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	t = va_arg(types, unsigned int);
	v = 2147483648; /* (2 ^ 31) */
	a[0] = t / v;
	for (q = 1; q < 32; q++)
	{
		v /= 2;
		a[q] = (t / v) % 2;
	}
	for (q = 0, sum = 0, count = 0; q < 32; q++)
	{
		sum += a[q];
		if (sum || q == 31)
		{
			char z = '0' + a[q];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
