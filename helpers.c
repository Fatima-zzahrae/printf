#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
 * skip_spaces - Skips whitespace characters between a '%' and a conversion
 * specifier in a format string.
 *
 * @format: A pointer to a pointer to the current character
 * in the format string.
 *
 * Return: 0 if whitespace characters were successfully skipped, or -1 if the
 * end of the format string was reached before a conversion specifier was found
 * or if whitespace characters were followed by the end of the format string.
 */
int skip_spaces(const char **format)
{
	while (**format == ' ')
	{
		if (*(*format + 1) == '\0')
		{
			return (-1);
		}
		(*format)++;
	}
	return (0);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * wrapper - Returns a pointer to the appropriate handler function
 * @format: A pointer to the format specifier character
 *
 * Return: A pointer to the appropriate handler function, or NULL if not found
 */
int (*wrapper(const char *format))(va_list)
{
	int i = 0;
	format_t mappings[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{NULL,NULL}
	};

	for (; mappings[i].code; i++)
	{
		if (*format == *(mappings[i].code))
		{
			return (mappings[i].handler);
		}
	}
	return (NULL);
}
