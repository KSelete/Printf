#include "my_custom_header.h"

/************************* PRINT UNSIGNED NUMBER *************************/

/**
 * my_print_unsigned - Prints an unsigned number
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int my_print_unsigned(va_list types, char buffer[],
                      int flags, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);

    num = my_convert_size_unsgnd(num, size);

    if (num == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer[i--] = (num % 10) + '0';
        num /= 10;
    }

    i++;

    return (my_write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/****************** PRINT UNSIGNED NUMBER IN OCTAL ******************/

/**
 * my_print_octal - Prints an unsigned number in octal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int my_print_octal(va_list types, char buffer[],
                   int flags, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);
    unsigned long int init_num = num;

    UNUSED(width);

    num = my_convert_size_unsgnd(num, size);

    if (num == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer[i--] = (num % 8) + '0';
        num /= 8;
    }

    if (flags & F_HASH && init_num != 0)
        buffer[i--] = '0';

    i++;

    return (my_write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/***************** PRINT UNSIGNED NUMBER IN HEXADECIMAL ******************/

/**
 * my_print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int my_print_hexadecimal(va_list types, char buffer[],
                         int flags, int width, int precision, int size)
{
    return (my_print_hexa(types, "0123456789abcdef", buffer,
                          flags, 'x', width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL ***************/

/**
 * my_print_hexa_upper - Prints an unsigned number in uppercase hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int my_print_hexa_upper(va_list types, char buffer[],
                        int flags, int width, int precision, int size)
{
    return (my_print_hexa(types, "0123456789ABCDEF", buffer,
                          flags, 'X', width, precision, size));
}

/************* PRINT HEXADECIMAL NUMBER IN LOWER OR UPPER **************/

/**
 * my_print_hexa - Prints a hexadecimal number in lower or uppercase
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @flag_ch: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int my_print_hexa(va_list types, char map_to[], char buffer[],
                  int flags, char flag_ch, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);
    unsigned long int init_num = num;

    UNUSED(width);

    num = my_convert_size_unsgnd(num, size);

    if (num == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer[i--] = map_to[num % 16];
        num /= 16;
    }

    if (flags & F_HASH && init_num != 0)
    {
        buffer[i--] = flag_ch;
        buffer[i--] = '0';
    }

    i++;

    return (my_write_unsgnd(0, i, buffer, flags, width, precision, size));
}

