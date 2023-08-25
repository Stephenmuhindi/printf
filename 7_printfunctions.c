#include "main.h"

/**
* is_prints - checks if it can be displayed
* @g: charactet
* Return: 1 if g is displayed, else 0
*/

int is_prints(char g)
{
	if (g >= 32 && g < 127)
		return (1);
	return (0);
}
/**
 * append_hex_code - ongeza Ascci in hex
 * @buf: char array
 * @y: index
 * @ascii_code: ASSCI
 * Return: 3
 */

int append_hex_code(char ascii_code, char buf[], int y)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;
	buf[y++] = '\\';
	buf[y++] = 'X';
	buf[y++] = map_to[ascii_code / 16];
	buf[y] = map_to[ascii_code % 16];
	return (3);
}
/**
* is_dig - verifies if char is a digit
* @k: char to be verified
* Return: 1 if k is a digit else 0
*/
int is_dig(char k)
{
	if (k >= '0' && k <= '9')
		return (1);
	return (0);
}
/**
* vert_size_no - casts a number to specified size
* @number: number
* @size: size
* Return: casted value
*/
long int vert_size_no(long int number, int size)
{
	if (size == S_LONG)
		return (number);
	else if (size == S_SHORT)
		return ((short)number);
	return ((int)number);
}
/**
* vert_size_unsigned - casts a number to a specified size
* @number: number to be casted
* @size: size
* Return: casted value
*/
long int vert_size_unsigned(unsigned long int number, int size)
{
	if (size == S_LONG)
		return (number);
	else if (size == S_SHORT)
		return ((unsigned short)number);
	return ((unsigned int)number);
}
