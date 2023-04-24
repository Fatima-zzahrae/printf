#include "main.h"

/**
 * print_string - Prints a string to stdout.
 *
 * @args: A va_list containing the string to print.
 *
 * Return: The number of characters printed (excluding the null byte used
 *         to end output to strings).
 */
int print_string(va_list args)
{
	int count = 0, i = 0;
	char *value = va_arg(args, char *);

	if (!value)
	{
		value = "(nil)";
	}

	while (value[i] != '\0')
	{
		_putchar(value[i]);
		count++;
		i++;
	}

	return (count);
}

/**
 * print_percent - Prints the conversion specifier '%'
 * @ap: A pointer to the list of arguments
 *
 * Return: The number of characters printed
 */
int print_percent(va_list ap)
{
	(void) (ap);
	return (_putchar('%'));
}

/**
 * print_char - Prints the conversion specifier 'c'
 * @ap: A pointer to the list of arguments
 *
 * Return: The number of characters printed
 */
int print_char(va_list ap)
{
	int c = va_arg(ap, int);

	return (_putchar(c));
}
