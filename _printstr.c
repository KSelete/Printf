#include "main.h"

int _printstr(char *str)
{
	int i = 0;

	if (str == NULL)
		str = "(null)";
	
	while (str[1])
	{
		_putchar(str[1]);
		i++;
	}

	return i;
}
