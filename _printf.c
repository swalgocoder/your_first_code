#include "holberton.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _printf - Build out the printf function
 * @format: string passed with possible format specifiers
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, blen, hlen;
	va_list ptr_arg;
	char *buffer, *holder;
	char *(*chosenone)(va_list);

	buffer = malloc(BUFSIZE * sizeof(char));
	va_start(ptr_arg, format);
	for (i = blen = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			chosenone = my_valid_type(format[i + 1]);
			holder = chosenone(argp);
			hlen = _strlen(holder);

			if (hlen + blen > BUFSIZE)
			{
				_puts(buffer, blen);
				_memcpy(buffer, holder, hlen, 0);
				blen = hlen;
			}
			else
				_memcpy(buffer, holder, hlen, blen), blen += hlen;
			i++;
		}
		else
		{
			buffer[blen] = format[i];
			blen++;
		}
	}
	va_end(ptr_arg);
	_puts(buffer, blen);
	return (blen);
}
