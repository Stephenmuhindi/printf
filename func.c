#include "hols.h"
#include <stdio.h>

/**
* rev_string - prints reverse string
* @s: string
* Returns: pointer
*/
char *rev_string(char *s)
{
	int length;
	int hd;
	char temp;
	char *dest;

	for (length = 0; s[length] != '\0'; length++)
	{}
	dest = malloc(sizeof(char) * length + 1);
	if (dest == NULL)
		return (NULL);
	_memcpy(dest, s, length);
	for (hd = 0; hd < length; hd++, length--)
	{
		temp = dest[length - 1];
		dest[length - 1] = dest[hd];
		dest[hd] = temp;
	}
	return (dest);
}
/**
* write_base - sends chard to std output
* @str: string
*/
void write_base(char *str)
{
	int y;

	for (y = 0; str[y] != '\0'; y++)
		write_char(str[y]);
}
/**
 * base_length - calculates length for an octal no
 * @number: number
 * @bas: base
 * Return: int
 */
unsigned int base_length(unsigned int number, int bas)
{
	unsigned int k;

	for (k = 0; number > 0; k++)
	{
		number = number / bas;
	}
	return (k);
}
/**
* _memcpy: copy memory area
* @dest: destination
* @src: source
* @m: no of bytes
* Return: pointer to dest
*/
char *_memcpy(char *dest, char *src, unsigned int m)
{
	unsigned int j;

	for (j = 0; j < m; j++)
		dest[j] = src[j];
	dest[j] = '\0';
	return (dest);
}

