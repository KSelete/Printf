#include "main.h"
#include <stdarg.h>

/**
 * _printf - Produces output according to a format.
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_cgars = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					_putchar(va_arg(args, int));
					printed_chars++;
					break;
				case 's':
					printed_chars += _printstr(va_arg(args, char *));
					break;
				case '%':
					_putchar('%');
					_putchar(*format);
					printed_chars += 2;
					break;
			}
		}
		else
		{
			_putchar(*format);
			printed_chars++;
		}

		format++;
	}
	
	va_end(args);

	return printed_chars;
}

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _printstr(char *str)
{
	int printed_chars = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		_putchar(*str);
		printed_chars++;
		str++
	}

	return printed_chars;
}
