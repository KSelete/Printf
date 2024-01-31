#include "main.h"

int _printint(int num)
{
	int count = 0;

	if (num < 0)
	{
		_putchar('_');
		num = -num;
		count++:
	}

	if(num / 10)
		count += _printint(num / 10);

	_putchar((num % 10) + '0');
	count++;

	return count;
}
