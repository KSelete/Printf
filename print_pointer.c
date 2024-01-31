#include "my_custom_header.h"

/****************** CUSTOMIZED PRINT POINTER ******************/

/**
 * my_print_pointer - Prints the value of a pointer variable
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int my_print_pointer(va_list types, char buffer[],
                     int flags, int width, int precision, int size)
{
    char extra_char = 0, padding_char = ' ';
    int ind = BUFF_SIZE - 2, length = 2, padding_start = 1; /* length=2, for '0x' */
    unsigned long int num_addresses;
    char map_to[] = "0123456789abcdef";
    void *addresses = va_arg(types, void *);

    UNUSED(width);
    UNUSED(size);

    if (addresses == NULL)
        return (write(1, "(nil)", 5));

    buffer[BUFF_SIZE - 1] = '\0';
    UNUSED(precision);

    num_addresses = (unsigned long int)addresses;

    while (num_addresses > 0)
    {
        buffer[ind--] = map_to[num_addresses % 16];
        num_addresses /= 16;
        length++;
    }

    if ((flags & F_ZERO) && !(flags & F_MINUS))
        padding_char = '0';
    if (flags & F_PLUS)
        extra_char = '+', length++;
    else if (flags & F_SPACE)
        extra_char = ' ', length++;

    ind++;

    return (write_pointer(buffer, ind, length,
                          width, flags, padding_char, extra_char, padding_start));
}

/************************* CUSTOMIZED PRINT NON PRINTABLE *************************/

/**
 * my_print_non_printable - Prints ASCII codes in hexadecimal of non-printable characters
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characte

