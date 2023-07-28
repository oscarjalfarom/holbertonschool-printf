#ifndef  MAIN_H
#define  MAIN_H


#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct print
{
	char *type;
	int (*f)(char *, int, va_list);
} print_t;


int _printf(const char *format, ...);
int (*get_print_function(char specifier))(char *, int, va_list);

int write_char(char *buffer, int char_print, va_list value);
int write_string(char *buffer, int char_print, va_list value);
int write_percent(char *buffer, int char_print, va_list value);


int _copy_string(char *buffer, int char_print, char *value);

#endif