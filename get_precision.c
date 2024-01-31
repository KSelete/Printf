#include "main.h"

/**
 * calculate_precision - Calculate the precision for printing
 * @format: The format string
 * @index: The current index in the format string
 * @args: The list of arguments
 *
 * Return: The calculated precision
 */

int calculate_precision(const char *format, int *index, va_list args)
{
	int current_index = *index + 1;
	int precision = -1;

	if (format[current_index] != '.')
		return precision;

	precision = 0;

	for (current_index += 1; format[current_index] != '\0'; current_index++)
	{
		if (is_numeric_character(format[current_index]))
		{
			precision *= 10;
			precision += format[current_index] - '0';
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			precision = va_arg(args, int);
			break;
		}
		else
		{
			break;
		}
	}

	*index = current_index - 1;

	return precision;
}
