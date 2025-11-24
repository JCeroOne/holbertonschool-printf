#include "main.h"
#include <stdio.h>
#include <stdlib.h>
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
					if (str == NULL)
					{
						write(1, "(null)", 6);
						printed += 6;
						break;
					}
					while (*str != '\0')
					{
						write(1, str, 1);
						printed++;
						str++;
					}
					break;
				}
				case 'd':
				{
					char *ptr = malloc(sizeof(char) * 100);
					double num = va_arg(args, double);
					int i;
					sprintf(ptr, "%d", num);
					for (i = 0; ptr[i] != '\0'; i++)
					{
						write(1, ptr + i, 1);
						printed++;
					}
					free(ptr);
					break;
				}
				case 'i':
				{
					char *ptr = malloc(sizeof(char) * 100);
					int num = va_arg(args, int);
					int i;
					sprintf(ptr, "%i", num);
					for (i = 0; ptr[i] != '\0'; i++)
					{
						write(1, ptr + i, 1);
						printed++;
					}
					free(ptr);
					break;

				}
				case '\0':
					break;
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
