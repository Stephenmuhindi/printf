#include "main.h"

/**
* printf_deci - decimal printed
* @argumentz: arguments
* Return: number of chars printed
*/

int printf_deci(va_list argumentz)
{
	int r = va_args(argumentz, int);
	int number, lt = r % 10, dig;
	int b = 1;
	int g = 1;

	r = r / 10;
	number = r;
	if (lt < 0)
	{
		_putc('-');
		number = -number;
		r = -r;
		lt = -lt;
		b++;
	}
	if (number > 0)
	{
		while (number / 10 != 0)
		{
			g = g * 10;
			number = number / 10;
		}
		number = r;
		while (g > 0)
		{
			dig = number / g;
			_putc(dig + '0');
			number = number - (dig * g);
			g = g / 10;
			b++;
		}
	}
	_putc(lt + '0');
	return (b);
}

