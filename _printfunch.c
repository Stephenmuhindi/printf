#include "main.h"

/**
 * get_flags - active flags.
 * @format: string in which to display the arguments.
 * @i: Pointer to current index format string.
 * Return: Flags:
 */

int get_flags(const char *format, int *i)
{
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	int flags = 0;
	int curr_i = *i + 1;

	while (format[curr_i] != '\0')
	{
		int s;
        for (s = 0; FLAGS_CH[s] != '\0'; s++)
        {
            if (format[curr_i] == FLAGS_CH[s])
            {
		    flags |= FLAGS_ARR[s];
		    break;
	    }
	}

	if (FLAGS_CH[s] == '\0')
		break;
	curr_i++;
	}

	*i = curr_i - 1;

	return (flags);
}
