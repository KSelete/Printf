#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 *
 * Return: on success 1. on error, -1 is required
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
