#include "main.h"

/**
* get_width - calculates width
* @format: string
* @j: list of arguments to be printed
* @list: list of arguments
* Return: width
*/

int get_width(const char *format, int *j, va_list list)
{
	int arr_j;
	int width = 0;

	for (arr_j = *j + 1; format[arr_j] != '\0'; arr_j++)
	{
		if (is_dig(format[arr_j]))
		{
			width *= 10;
			width += format[arr_j] - '0';
		}
		else if (format[arr_j] == '*')
		{
			arr_j++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*j = arr_j - 1;
	return (width);
}

