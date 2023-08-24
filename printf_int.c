#include "main.h"

/**
* print_int - prints int
* @args: arguments
* Return: number of characters
*/

int print_int(va_list args)
{
	int m = va_arg(args, int);
	int number, lt = m % 10, dig, p = 1;
	int e = 1;

	m = m / 10;
	number = m;

	if (lt < 0)
	{
		_putchar('-');
		number = -number;
		m = -m;
		lt = -lt;
		e++;
	}
	if (number > 0)
	{
		while (number / 10 != 0)
		{
			p = p * 10;
			number = number / 10;
		}
		number = m;
		while (p > 0)
		{
			dig = number / p;
			_putchar(dig + '0');
			number = number - (dig * p);
			p = p / 10;
			e++;
		}
	}
	_putchar(lt + '0');
	return (e);
}
/**
* print_deci - prints decimal
* @args: arguments
* Return: number of characters
*/
int print_deci(va_list args)
{
	int t = va_arg(args, int);
	int number, lt = t % 10, dig;
	int r = 1;
	int p = 1;

	t = t / 10;
	number = t;

	if (lt < 0)
	{
		_putchar('-');
		number = -number;
		t = -t;
		lt = -lt;
		r++;
	}
	if (number > 0)
	{
		while (number / 10 != 0)
		{
			dig = number / p;
			_putchar(dig + '0');
			number = number - (dig * p);
			p = p / 10;
			r++;
		}
	}
	_putchar(lt + '0');
	return (r);
}
