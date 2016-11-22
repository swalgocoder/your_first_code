#include <stdarg.h>
#include "holberton.h"
/**
  * my_char - converts a char to a string
  * @c: char to convert
  * Return: 2 byte string
  */
char *my_char(va_list c)
{
	char string[2];
	char *p;

	p = string;
	string[0] = va_arg(c, int);
	string[1] = '\0';
	return (p);
}
/**
  * my_string - passes a string through
  * @s: string to pass through
  * Return: unmodified string
  */
char *my_string(va_list *s)
{
	char *string;

	string = va_arg(s, char *);
	return (string);
}

#include "holberton.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * my_valid_type - ID the type specifier passed by printf with a valid_type
 * @s: Type to check given as char
 * Return: pointer function of char type, valid_type matched
 */
char *(*my_valid_type(char s))(va_list)
{
	int i;
	my_types print_types[] = {
		{"c", found_char},
		{"s", found_string},
		{NULL, NULL}
	};

	for (i = 0; print_types[i].my_char; i++)
	{

		if (s == *print_types[i].my_char)
		{
			return (print_types[i].f);
		}
	}

	/* handle NULL case */
	return (NULL);
}
