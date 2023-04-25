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
	char buffer[50];
	int i, r;
	char hex = (buffer[0] == 'A') ? 'A' : 'a';

	i = 0;
	(n == 0) && (buffer[i] = '0');
	i++;

	while (n > 0)
	{
		r = n % 2;

	if (r < 10)
	{
		buffer[i] = r + '0';
		i++;
	}
	else
	{
		buffer[i] = r - 10 + hex;
		i++;
	}

	n /= 2;
	}
	buffer[i] = '\0';
	reverse_str(buffer);
	return( _puts(buffer));
}
