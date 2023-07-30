#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct print - Structure to store format specifiers.
 * @type: The format specifier.
 * @f: Pointer to the function that handles the specifier.
 */
typedef struct print
{
	char *type;
	int (*f)(char *, int, va_list);
} print_t;

int _printf(const char *format, ...);
int (*get_print_function(char specifier))(char *, int, va_list);

int write_c(char *buffer, int char_print, va_list value);
int write_d(char *buff, int count, va_list value);
int write_i(char *buff, int count, va_list value);
int write_s(char *buffer, int char_print, va_list value);
int write_u(char *buff, int count, va_list value);
int write_percent(char *buffer, int char_print, va_list value);

int _abs(int n);
char *_ia(int value, int base);
char *_utoa(unsigned int value, unsigned int base);

int _strlen(char *s);
char *_reverse(char *s, int n);

int _copy_string(char *buffer, int char_print, char *value);

#endif /* MAIN_H */
