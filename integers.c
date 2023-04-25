#include "main.h"
#include <stdio.h>

unsigned int _strlen(char *s);
void reverse_str(char s[]);
void _itoa(long n, char s[]);

/**
 * print_int - Prints an integer.
 *
 * @args: A va_list containing the string to print.
 *
 * Return: The number of characters printed.
 *
 */
int print_int(va_list args)
{
	int count = 0, i = 0;

	int value = va_arg(args, int);
	char text[50];

	_itoa(value, text);

	while (text[i] != '\0')
	{
		_putchar(text[i]);
		count++;
		i++;
	}
	return (count);
}

/**
 * _strlen - length of a given string
 * @s: the string
 * Return: the length of given string
 */

unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * reverse_str - reverses a given string
 *
 * @s: the string to be reversed
 */

void reverse_str(char s[])
{
	unsigned int i = 0, len = 0;
	char temp;

	len = _strlen(s);

	for (; i < len / 2; i++)
	{
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
}

/**
 * _itoa - Converts a long integer to a string
 *
 * @n: The long integer to convert
 *
 * @s: The character array to store the converted string in
 */

void _itoa(long n, char s[])
{
	long sign = n;
	unsigned int i = 0;

	if (sign < 0)
		n = -n;
	do
		s[i++] = n % 10 + '0';
	while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse_str(s);
}
