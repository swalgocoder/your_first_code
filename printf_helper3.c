#include "holberton.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * get_valid_type - ID the type specifier passed by printf with a valid_type
 * @s: Type to check given as char
 * Return: pointer function of char type, valid_type matched
 */
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
