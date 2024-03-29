#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * my_print_char - Prints a character
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int my_print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	 return (my_handle_write_char(c, buffer, flags, width, precision, size));
}

/************************* CUSTOMIZED PRINT A STRING *************************/

/**
 * my_print_string - Prints a string
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int my_print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}


/************************* CUSTOMIZED PRINT PERCENT SIGN *************************/

/**
 * my_print_percent - Prints a percent sign
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int my_print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}

/************************* CUSTOMIZED PRINT INT *************************/

/**
 * my_print_int - Print an integer
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int my_print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	 n = my_convert_size_number(n, size);

	 if (n == 0)
            buffer[i--] = '0';

         buffer[BUFF_SIZE - 1] = '\0';
         num = (unsigned long int)n;

	 if (n < 0)
	 {
		 num = (unsigned long int)((-1) * n);
		 is_negative = 1;
	 }

	 while (num > 0)
	 {
		 buffer[i--] = (num % 10) + '0';
		 num /= 10;}

	 i++;

	 return (my_write_number(is_negative, i, buffer, flags, width, precision, size));
}
/************************* CUSTOMIZED PRINT BINARY *************************/

/**
 * my_print_binary - Prints a binary number
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int my_print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	 n = va_arg(types, unsigned int);
	 m = 2147483648; /* (2 ^ 31) */
	 a[0] = n / m;
	 for (i = 1; i < 32; i++)
	 {
		 m /= 2;
		 a[i] = (n / m) % 2;
	 }
	 for (i = 0, sum = 0, count = 0; i < 32
