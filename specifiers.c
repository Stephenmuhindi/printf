#include "hols.h"

/**
* printf_char - prints char
* @listed: list of arguments
* Return:amount of chars printed
*/

int printf_char(va_list listed)
{
	write_char(va_arg(listed, int));
	return (1);
}
/**
* printf_char - prints string
* @listed: list of arguments
* Return: amount of characters
*/
int printf_str(va_list listed)
{
	int t;
	char *v;

	v = va_arg(listed, char *);
	if (v == NULL)
		v = "(null)";
	for (t = 0; v[t] != '\0'; t++)
		write_char(v[t]);
	return (t);
}
/**
 * printf_cent - prints percent
 * @list: list of arguments
 * Return: amount of characters
 */
int printf_cent(__attribute__((unused))va_list listed)
{
	write_char('%');
	return (1);
}
/**
* printf_int - prints int
* @list: list of arguments
* Return: amount of characters
*/
int printf_int(va_list listed)
{
	int num_leng;

	num_leng = printf_num(listed);
	return (num_leng);
}
/**
* unsigned_int - prints unsigned int
* @list: list of arguments
* Return: count numbers
*/
int unsigned_int(va_list listed)
{
	unsigned int number;

	number = va_arg(listed, unsigned int);

	if (number == 0)
		return (printf_unsigned_num(number));
	if (number < 1)
		return (-1);
	return (printf_unsigned_num(number));
}
