#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: character string.
 *
 * Return: number of characters printed or -1 if fail.
 */

int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;
	int (*print_f)(va_list);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			print_f = print_func(*format);

			if (print_f != NULL)
				len += print_f(args);
			else
			{
				write(1, "%", 1);
				write(1, format, 1);
				len += 2;
			}
		}
		else
		{
			write(1, format, 1);
			len += 1;
		}
		format++;
	}

	va_end(args);
	return (len);
}
