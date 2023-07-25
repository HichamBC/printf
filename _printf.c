#include<unistd.h>
#include<stdarg.h>
#include"main.h"
/**
 * _printf - print anything and return number of caraters
 * @format: caracter to be printed
 * Return: number of caracters printed
 *
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i = 0;
	int numb_char = 0;
	char c;
	int j = 0;
	char *s;

	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			i++;
			c = va_arg(list, int);
			write(1, &c, 1);
		} else if (format[i] == '%' && format[i + 1] == 's')
		{
			i++;
			s = va_arg(list, char *);
			while (s[j] != '\0')
			{
				j++;
			}
			write(1, s, j);
		} else if (format[i] == '%' && format[i + 1] == '%')
		{
			i++;
			write(1, "%", 1);
		} else
		{
			write(1, &format[i], 1);
		}
		numb_char++;
		i++;
	}
	return (numb_char - 1);
}

