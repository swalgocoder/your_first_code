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

char *my_int(va_list ptr_arg1)
{
int n;

char gulzar_arr[];

char *my_string;

my_string = gulzar_arr;

n = va_arg(ptr_arg1, int);

void reverse(char gulzar_arr[])
 {
     int i, j;
     char c;

     for (i = 0, j = strlen(gulzar_arr)-1; i 0);     /* delete it */
     if (sign < 0)
         gulzar_arr[i++] = '-';
     gulzar_arr[i] = '\0';
     reverse(gulzar_arr);
 }
 void utoa(unsigned int n, char gulzar_arr[])
 {
     unsigned int i;
     i = 0;
     do {       /* generate digits in reverse order */
         gulzar_arr[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
     gulzar_arr[i] = '\0';
     reverse(gulzar_arr);
 }
char *itoa(n, char *s); 

return (my_string);
}
