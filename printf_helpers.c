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
