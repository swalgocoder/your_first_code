#ifndef H_98_H
#define H_98_H

#define BUFSIZE 10
#include <stdarg.h>

typedef struct data_types
{
	char *valid;
	char *(*f)();
} my_types;

int _putchar(char c);
int _printf(const char *format, ...);
char *(*my_valid_type(char s))(va_list);

/* printf_helpers */
char *my_char(va_list c);
char *my_string(va_list *s);
/*others  */
int my_atoi(char *s);
char *_memcpy(char *dest, char *src, unsigned int n, unsigned int bufferlen);
int _strlen(char *s);
void _puts(char *buffer, int size);
#endif
