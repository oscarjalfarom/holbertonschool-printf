#include "main.h"

/**
 * write_percent - Write a percent character to the buffer.
 * @buffer: The buffer to write the percent character to.
 * @char_print: The current character count.
 * @value: The argument list (unused).
 *
 * Return: The updated character count.
 */
int write_percent(char *buffer, int char_print, va_list value)
{
	(void)value;
	buffer[0] = '%';
	return (char_print + 1);
}
