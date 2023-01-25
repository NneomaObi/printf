#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
* _printf - a function that produces output according to a format.
* @ format - to produce output
* Returns: the number of characters printed
*/
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	va_start(args, format);

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
				    putchar(va_arg(args, int));
				    count++;
				    break;
				case 's':
				    fputs(va_arg(args, char*), stdout);
				    count += strlen(va_arg(args, char*));
				    break;
				case '%':
				    putchar('%');
				    count++;
				    break;
				default:
				    break;
			}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
	}
	va_end(args);
	return count;
}
