#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
/**
 */

typedef struct print
{
	char type;
	int (*fn)(va_list);
} print_t;

int print_char(va_list arg);
int print_string(va_list arg);
int print_percent(va_list arg);
int (*print_func(char format))(va_list);

#endif
