#include "main.h"

/**
 * calculate_flags - Calculates active flags
 * @format: Formatted string
 * @index: Current index in the format string
 * Return: Flags
 */
int calculate_flags(const char *format, int *index)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, current_index;
	int flags = 0;
	const char FLAGS_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_VALUES[] = {FLAG_MINUS, FLAG_PLUS, FLAG_ZERO, FLAG_HASH, FLAG_SPACE, 0};

	for (current_index = *index + 1; format[current_index] != '\0'; current_index++)
	{
		for (j = 0; FLAGS_CHARS[j] != '\0'; j++)
		{
			if (format[current_index] == FLAGS_CHARS[j])
			{
				flags |= FLAGS_VALUES[j];
				break;
			}
		}

		if (FLAGS_CHARS[j] == 0)
		{
			break;
		}
	}

	*index = current_index - 1;

	return flags;
}
