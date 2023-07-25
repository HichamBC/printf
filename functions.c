#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_char - prints a character.
 * @arg: character to print.
 *
 * Return: always 1.
 */

int print_char(va_list arg)
{
	char c = va_arg(arg, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - prints a string of characters.
 * @arg: the string to be printed.
 *
 * Return: length of the string.
 */

int print_string(va_list arg)
{
	char *s = va_arg(arg, char *);
	int len = 0;

	if (s == NULL)
		s = "(null)";

	while (*s != '\0')
	{
		write(1, s, 1);
		len += 1;
		s++;
	}

	return (len);
}

/**
 * print_percent - prints a percentage symbole.
 * @arg: unused.
 *
 * Return: Always 1.
 */

int print_percent(va_list arg)
{
	(void) arg;

	write(1, "%", 1);
	return (1);
}

/**
 * print_func - links the compatible print function with its specifier.
 * @format: the format specifier.
 *
 * Return: NULL or the print function of the specified format.
 */

int (*print_func(char format))(va_list)
{
	print_t pf[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}
	};

	print_t *ptr = pf;

	while (ptr->type != '\0')
	{
		if (ptr->type == format)
			return (ptr->fn);
		ptr++;
	}
	return (NULL);
}
