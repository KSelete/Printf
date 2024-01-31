#include "main.h"

/**
 * my_print_argument - Prints an argument based on its type
 * @fmt: The format string
 * @ind: The index in the format string
 * @list: The list of arguments to be printed
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of characters printed, or -1 on error
 */
int my_print_argument(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, printed_chars = -1;
	 fmt_t fmt_types[] = {
		 {'c', my_print_char}, {'s', my_print_string}, {'%', my_print_percent},
		 {'i', my_print_int}, {'d', my_print_int}, {'b', my_print_binary},
		 {'u', my_print_unsigned}, {'o', my_print_octal}, {'x', my_print_hexadecimal},
		 {'X', my_print_hex_upper}, {'p', my_print_pointer}, {'S', my_print_non_printable},
		 {'r', my_print_reverse}, {'R', my_print_rot13string}, {'\0', NULL}
	 };

	 for (i = 0; fmt_types[i].fmt != '\0'; i++)
	 {
		 if (fmt[*ind] == fmt_types[i].fmt)
		 {
			 return fmt_types[i].fn(list, buffer, flags, width, precision, size);
		 }
	 }

	 if (fmt_types[i].fmt == '\0')
	 {
		 if (fmt[*ind] == '\0')
		 {
			 return -1;
		 }

		 unknown_len += write(1, "%%", 1);

		 if (fmt[*ind - 1] == ' ')
		 {
			 unknown_len += write(1, " ", 1);
		 }
		 else if (width)
		 {
			 (*ind)--;
			 while (fmt[*ind] != ' ' && fmt[*ind] != '%')
			 {
				 (*ind)--;
			 }

			 if (fmt[*ind] == ' ')
			 {
				 (*ind)--;
			 }

			 return 1;
		 }
		  unknown_len += write(1, &fmt[*ind], 1);
		  return unknown_len;
	 }
	 return printed_chars;
}
