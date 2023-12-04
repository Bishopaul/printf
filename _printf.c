#include "main.h"

/**
 * _printf - function that produces output according to a format
 *
 * @format: format specified
 *
 * Return: int - number of characters printed
 */

int _printf(const char *format, ...)
{
	unsigned int a, string_count, b = 0;

	va_list args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);

	for (a = 0; format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			bputchar(format[a]);
		}
		else if (format[a] == '%' && format[a + 1] == 'c')
		{
			bputchar(va_arg(args, int));
			a++;
		}
		else if (format[a + 1] == 's')
		{
			string_count = putts(va_arg(args, char *));
			a++;
			b += (string_count - 1);
		}
		else if (format[a + 1] == '%')
		{
			bputchar('%');
		}
		
		b += 1;
	}
	va_end(args);
	return (b);
}
