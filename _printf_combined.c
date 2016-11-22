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


///

#include "holberton.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - main print functions
 * @format: format string
 * Return: length of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	char buffer[1024], *temp;
	int i, j, z, num_of_formats, size;
	print_t c_or_str[] = {
		{"c", _printchar}, {"s", _printstring}, {"d", _printnum},
		{"i", _printnum}, {"u", _printunsign}, {"o", _printoct},
		{"x", _printhex}, {"X", _printhexUP}, {"b", _printbinary},
		{"%", _printpercent},
	};

	size = 0; temp = malloc(sizeof(char) * 2);
	if (temp == NULL)
		return (size);
	num_of_formats = sizeof(c_or_str) / sizeof(print_t);
	for (i = 0; i < 1024; i++)
		buffer[i] = '\0';
	va_start(ap, format);
	if (format != NULL)
	{
		for (i = 0; format[i] != '\0'; i++)
		{
			z = 1;
			for (j = 0; j < num_of_formats; j++)
			{
				if (format[i] == '%' &&
				    format[i + 1] == *(c_or_str[j]).format_str)
				{
					size = c_or_str[j].f(ap, buffer, size);
					z = 0, i++; break;
				}
			}
			if (z != 0)
			{
				*temp = format[i]; *(temp + 1) = '\0';
				size = _strcpy(buffer, temp, size);
			}
		}
	}
	i = size; free(temp); _print_buffer(buffer, size);
	return (i);
}


char *(*my_data_type(char s))(va_list)
{
	int i;
	my_types check_types[] = {
		{"c", my_char},
		{"s", my_string},
		{"%", my_percent},
		{"d", my_int},
		{"i", my_int},
		{NULL, NULL}
	};

	for (i = 0; check_types[i].check_char; i++)
	{

		if (s == *check_types[i].check_char)
		{
			return (check_types[i].f);
		}
	}

	/* if NULL*/
	return (NULL);
}
