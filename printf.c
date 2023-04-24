#include <unistd.h>
#include "main.h"

/**
 * _printf - Prints formatted output to stdout
 *
 * @format: A pointer to a string containing format specifiers
 * @...: Optional arguments for the format specifiers
 *
 * Return: The number of characters printed (excluding the null byte used to
 *         end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int (*handler_func)(va_list);
	int chars_printed = 0;

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	while (*format != '\0' && format != NULL)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);

			if (skip_spaces(&format) == -1)
				return (-1);

			handler_func = wrapper(format);
			if (handler_func != NULL)
			{
				chars_printed += handler_func(ap);
			}
			else
			{
				chars_printed += _putchar('%');
				chars_printed += _putchar(*format);
			}
		}
		else
		{
			chars_printed += _putchar(*format);
		}
		format++;
	}
	va_end(ap);
	return (chars_printed);
}
