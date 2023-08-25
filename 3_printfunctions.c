#include "main.h"

/**
 * get_flags - disp. Flags
 * @format: Args display
 * @i: parameter.
 * Return: flags:
 */
int get_flags(const char *format, int *q)
{
	int m, curr_q;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_q = *q + 1; format[curr_q] != '\0'; curr_q++)
	{
		for (m = 0; FLAGS_CH[m] != '\0'; m++)
			if (format[curr_q] == FLAGS_CH[m])
			{
				flags |= FLAGS_ARR[m];
				break;
			}
		if (FLAGS_CH[m] == 0)
			break;
	}
	*q = curr_q - 1;
	return (flags);
}
