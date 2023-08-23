#include "main.h"
#include "main.h"

/**
 * print_reverse - Prints a reversed string.
 * @types: List of arguments
 * Return: Number of characters printed.
 */

int print_reverse(va_list types)
{
	char *str = va_arg(types, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";
	for (int q = 0; str[q]; q++)
		count++;
	for (int q = count - 1; q >= 0; q--)
	{
		char ch = str[q];
		write(1, &ch, 1);
	}
	return (count);
}

/**
 * print_rot13string - displays str in ROT13.
 * @types: arguments
 * Return: amount of bytes.
 */

int print_rot13string(va_list types)
{
	char *str = va_arg(types, char *);
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	if (str == NULL)
		str = "(AHYY)";
	for (int q = 0; str[q]; q++)
	{
		char ch = str[q];
        int s;

        for (s = 0; in[s]; s++)
	{
		if (in[s] == ch)
		{
			ch = out[s];
			break;
		}
	}
	if (!in[s])
            ch = str[s];
	
	write(1, &ch, 1);
	count++;
	}

	return (count);
}
