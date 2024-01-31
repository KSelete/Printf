#include "main.h"

/**
 * determine_argument_size - Determines the size to cast the argument
 * @format: The format string
 * @index: The current index in the format string
 *
 * Return: The argument size
 */
int determine_argument_size(const char *format, int *index)
{
	int current_index = *index + 1;
	int size = 0;

	if (format[current_index] == 'l')
	{
		size = ARGUMENT_SIZE_LONG;
	}
	else if (format[current_index] == 'h')
	{
		size = ARGUMENT_SIZE_SHORT;
	}

	if (size == 0)
	{
		*index = current_index - 1;
	}
	else
	{
		*index = current_index;
	}

	return size;
}
