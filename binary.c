#include "main.h"
#include <stdio.h>

/**
 * to_binary_string - prints a binary representation of an unsigned int
 *
 * @ap: va_list of integers to be printed
 *
 * Return: number of printed characters
 */
int to_binary_string(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	static char buffer[sizeof(unsigned int) * 8 + 1];
	int i = sizeof(unsigned int) * 8 - 1;
	
	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	if (n < 1)
		return (-1);

	buffer[i--] = '\0';
	while (n != 0)
	{
		buffer[i--] = n % 2 + '0';
		n >>= 1;
	}

	return (_puts(&buffer[i + 1]));
}
