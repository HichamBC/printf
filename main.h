#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
/**
 * struct print - has the format specifier and function pointer as members.
 * @type: format specifier.
 * @fn: function pointer to a print function.
 */

typedef struct print
{
	char type;
	int (*fn)(va_list);
} print_t;

int print_char(va_list arg);
int print_string(va_list arg);
int print_percent(va_list arg);
int print_integer(va_list arg);
int (*print_func(char format))(va_list);

#endif
