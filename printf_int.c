#include "main.h"

/**
* printf_int - integer printed
* @argumentz: arguments
* Return: number of char printed
*/
int printf_int(va_list argumentz)
{
	int m = va_args(argumentz, int);
	int number, lt = m % 10, dig, p = 1;
	int a = 1;

	m = m / 10;
	number = m;
	if (last < 0)
	{
		_putc('-');
		number = -number;
		m = -m;
		lt = -lt;
		a++;
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
			_putc(dig + '0');
			number = number - (dig * p);
			p = p / 10;
			a++;
		}
	}
	_putc(last + '0');
	return (a);
}
