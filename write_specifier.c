#include "main.h"

int write_char(char *buffer, int char_print, va_list value)
{
	int cha = va_arg(value, int);

	if (!cha)
	{
		write(1, "\0\0", 2);
		free(buffer);
		return(0);
	}

	buffer[0] = cha;
	return (char_print + 1);
}

int write_string(char *buffer, int char_print, va_list value)
{
	char *str = va_arg(value, char *);

	if (!str)
		str = "(null)";

	return(_copy_string(buffer, char_print, str));	
}

int write_percent(char *buffer, int char_print, va_list value)
{
	(void)value;
	buffer[0] = '%';
	return (char_print + 1);
}
