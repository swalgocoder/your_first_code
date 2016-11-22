#include <stdlib.h>
#include <stdarg.h>
#include "holberton.h"
/**
  * my_char - char to a string
  * @my_c: char
  * Return: string
  */
char *my_char(va_list my_c)
{
	char char_str[2];
	char *ptr;

	ptr = char_str;
	char_str[0] = va_arg(my_c, int);
	char_str[1] = '\0';
	return (ptr);
}
/**
  * my_string - passes a string
  * @str: string to pass
  * Return: unmodified string
  */
char *my_string(va_list *str)
{
	char *my_string;

	my_string = va_arg(str, char *);
	return (my_string);
}
/**
  * my_percent - passes a %
  * Return: percent sign as a char string
  */
char *my_percent(void)
{
	char *my_string;

	string = "%";
	return (my_string);
}
/**
  * my_int - integers into char arrays
  * @ptr_arg1: integer to convert from va_args
  * Return: pointer to string
  */


//char *my_int(va_list ptr_arg1)
//{
//	int num;
//	int i, res, swap, expo, count;
//	char *my_string;

//	num = va_arg(ptr_arg1, int);
//	count = i = 0;
//	expo = 1;
//	num >= 0 ? (res = num * -1) : (res = num, count++);
//	swap = res;
//	while (swap <= -10)
//	{
//		expo *= 10;
//		temp /= 10;
//		count++;
//	}
//	my_string = malloc(count * sizeof(char));
//	if (n < 0)
//		my_string[i++] = '-';
//	while (expo >= 1)
//	{
//		my_string[i++] = (((res / expo) % 10) * -1 + '0');
//		expo /= 10;
//	}
//	return (my_string);
//}
//
//
//
//#include <stdio.h>
//#include <string.h>
// Function declarations
// typedef __w64 unsigned int size_t

//char *my_int(va_list ptr_arg1)
//{
//size_t strlen(const char *);
//char *strrev(char *);
//char *itoa(int, char *, int);

//int main() {
//	int num = 123;
//	char buf[5];
//	itoa(num, buf, 10);
//	printf("%s\n", buf);
//	return 0;
//}

//the above part to be deleted, for reference only///
char *my_int(va_list ptr_arg1)
{
	int n;
	char *my_string;

	n = va_arg(ptr_arg1, int);

	my_string = malloc(50 * sizeof(char));
  
size_t strlen(const char *string) 
{
	const char *s;
	s = string;
	while (*s)
		s++;
	return s - string;
}

char *strrev(char *str) 
{
	char *p1, *p2;
  char *my_string;
  
	if (!str || !*str)
		return str;
	for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) 
  {
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}
  my_string = str;
  return (my_string);
}

char *itoa(int n, char *s) 
{
	static char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	int i=0, sign, n;
  
  n = va_arg(ptr_arg1, int);
    
	if ((sign = n) < 0)
		n = -n;
	do {
		s[i++] = digits[n % 10];
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	return strrev(s);
}

char *itoa(n, my_string); 

}
