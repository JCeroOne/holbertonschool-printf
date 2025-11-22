#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>

/**
 * _printf - Prints a formatted string to the console, equivalent to printf.
 * @format: The string to print.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed = 0;
	int isFormat = 0;

	va_start(args, format);
	while (*format != '\0')
	{
		if (isFormat == 0)
		{
			if (*format == '%')
				isFormat = 1;
			else
			{
				write(1, format, 1);
				printed++;
			}
		}
		else
		{
			isFormat = 0;
			switch(*format)
			{
				case 'c':
				{
					int ch = va_arg(args, int);
					write(1, &ch, 1);
					printed++;	
					break;
				}
				case 's':
				{
					char *str = va_arg(args, char*);
					while (*str != '\0')
					{
						if (*str == NULL)
							write(1, '\0', 1);
						else
							write(1, str, 1);
						printed++;
						str++;
					}
					break;
				}
				default:
				{
					write(1, format, 1);
					printed++;
				}
			}
		}
		format++;
	}

	va_end(args);

	return (printed);
}
