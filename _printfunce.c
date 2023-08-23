#include "main.h"

/**
 * print_pointer - displays the value of pointer variable
 * @types: arguments
 * Return: amount of chars.
 */

int print_pointer(va_list types)
{
	void *addr = va_arg(types, void *);

	if (addr == NULL)

		return (write(1, "(nil)", 5));
	
	unsigned long int num_addr = (unsigned long int)addr;
	char buffer[BUFF_SIZE];
	int q = BUFF_SIZE - 2;
	char map_to[] = "0123456789abcdef";

	while (num_addr > 0)
	{
		buffer[q--] = map_to[num_addr % 16];
		num_addr /= 16;
	}

	buffer[q--] = 'x';
	buffer[q--] = '0';

    q++;

    return (write_pointer(buffer, q, BUFF_SIZE - q - 1, 0, 0, ' ', 0, 1));

}

/**
 * print_non_printable - displays ASCII codes in hexadecimal non-printable characters
 * @types: arguments.
 * Return: amount of char.
 */

int print_non_printable(va_list types)
{
	char *str = va_arg(types, char *);
	char buffer[BUFF_SIZE];
	int q = 0;
	int offset = 0;

    if (str == NULL)
        return (write(1, "(null)", 6));

    while (str[q] != '\0')
    {
        if (is_printable(str[q]))
	{
		buffer[q + offset] = str[q];
	}
        else
            offset += append_hexa_code(str[q], buffer, q + offset);

        q++;
    }

    buffer[q + offset] = '\0';

    return (write(1, buffer, i + offset));
}

/**
 * @types: arguments
 * Return: amount of char.
 */

int print_reverse(va_list types)
{
	char *str = va_arg(types, char *);
	int length = 0;
	int count = 0;

	if (str == NULL)
		str = ")Null(";

	while (str[length] != '\0')
		length++;

	for (int q = length - 1; q >= 0; q--)
	{
		char z = str[i];
		write(1, &z, 1);
		count++;
	}

    return (count);
}

/**
 * print_rot13string - displays (char *) in ROT13.
 * @types: arguments
 * Return: amount of chars.
 */

int print_rot13string(va_list types)
{
    char *str = va_arg(types, char *);
    char x;
    unsigned int a, s;
    int count = 0;
    char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    if (str == NULL)
        str = "(AHYY)";

    for (a = 0; str[a]; a++)
    {
        for (s = 0; in[s]; s++)
        {
            if (in[s] == str[a])
            {
                x = out[s];
                write(1, &x, 1);
                count++;
                break;
            }
        }
        if (!in[s])
        {
            x = str[a];
            write(1, &x, 1);
            count++;
        }
    }

    return (count);
}
