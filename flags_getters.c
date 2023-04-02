#include "main.h"

/**
 * get_flags - starts flags
 * @format: Formatted string in which to print the arguments
 * @i: input
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;
	int flags = 0;
	const char C_FLAGS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int ARR_FLAGS[] = {MINUS_FLAG, PLUS_FLAG, ZERO_FLAG,
				 HASH_FLAG, SPACE_FLAG, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; C_FLAGS[j] != '\0'; j++)
			if (format[curr_i] == C_FLAGS[j])
			{
				flags |= ARR_FLAGS[j];
				break;
			}

		if (C_FLAGS[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}
