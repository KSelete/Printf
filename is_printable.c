#include "main.h"

/**
 * is_character_printable - Determines if a character is printable
 * @character: The character to be evaluated
 *
 * Return: 1 if the character is printable, 0 otherwise
 */
int is_character_printable(char character)
{
	if (character >= 32 && character < 127)
		return 1;

	return 0;
}

/**
 * append_hexadecimal_code - Appends ASCII in hexadecimal code to buffer
 *  @buffer: Array of characters
 *  @index: Index at which to start appending
 *  @ascii_code: ASCII code
 *
 *  Return: Always returns 3
 */
int append_hexadecimal_code(char ascii_code, char buffer[], int index)
{
	char hex_map[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[index++] = '\\';
	buffer[index++] = 'x';
	buffer[index++] = hex_map[ascii_code / 16];
	buffer[index] = hex_map[ascii_code % 16];

	return 3;
}

/**
 * is_character_digit - Checks if a character is a digit
 * @ch: The character to check
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */
int is_character_digit(char ch)
{
	return (ch >= '0' && ch <= '9');
}

/**
 * cast_number_with_size - Casts a number to the specified size
 * @num: The number to cast
 * @size: The size indicating the type to cast to
 *
 * Return: The casted value of num
 */
long int cast_number_with_size(long int num, int size)
{
	if (size == SIZE_LONG)
		return num;
	else if (size == SIZE_SHORT)
		return (short)num;

	return (int)num;
}

/**
 * cast_unsigned_number_with_size - Casts an unsigned number to the specified size
 * @num: The number to cast
 * @size: The size indicating the type to cast to
 * Return: The casted value of num
 */
unsigned long int cast_unsigned_number_with_size(unsigned long int num, int size)
{
	if (size == SIZE_LONG)
		return num;
	else if (size == SIZE_SHORT)
		return (unsigned short)num;

	return (unsigned int)num;
}
