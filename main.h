#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
 * struct format_mapping - maps conversion specifiers to handler functions
 *
 * @code: the conversion specifier string
 * @handler: the handler function for the conversion specifier
 */
typedef struct format_mapping
{
	char *code;
	int (*handler)(va_list);
} format_t;

int _printf(const char *format, ...);

int _putchar(char c);
int skip_spaces(const char **format);
int (*wrapper(const char *))(va_list);

int print_string(va_list args);
int print_percent(va_list ap);
int print_char(va_list ap);
int _div(int d, unsigned int num);
int print_int(va_list args);

#endif
