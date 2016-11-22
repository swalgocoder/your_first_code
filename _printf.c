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
	int i, buffer_len, buffer2_len;
	va_list ptr_arg;
	char *buffer, *buffer_2;
	char *(*switch)(va_list);

	buffer = malloc(BUFSIZE * sizeof(char));
	va_start(ptr_arg, format);
	for (i = buffer_len = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			switch = my_data_type(format[i + 1]);
			buffer_2 = switch(ptr_arg);
			buffer2_len = _strlen(buffer_2);

			if (buffer_len + buffer2_len > BUFSIZE)
			{
				_puts(buffer, buffer_len);
				_memcpy(buffer, buffer2, buffer2_len, 0);
				buffer_len = buffer2_len;
			}
			else
			{
				_memcpy(buffer, buffer2, buffer2_len, buffer_len);
				buffer_len += buffer2_len;
			}
			i++;
		}
		else
		{
			buffer[buffer_len] = format[i];
			buffer_len++;
		}
	}
	va_end(ptr_arg);
	_puts(buffer, buffer_len);
	return (buffer_len);
}
