#include "main.h"

/**
 * write_c - Write a character to the buffer.
 * @buffer: The buffer to write the character to.
 * @char_print: The current character count.
 * @value: The argument list containing the character to print.
 *
 * Return: The updated character count.
 */
int write_c(char *buffer, int char_print, va_list value)
{
	int cha = va_arg(value, int);

	if (!cha)
	{
		write(1, "\0\0", 2);
		free(buffer);
		exit(0);
	}

	buffer[0] = cha;
	return (char_print + 1);
}

/**
 * write_d - Write a decimal integer to the buffer.
 * @buff: The buffer to write the integer to.
 * @count: The current character count.
 * @value: The argument list containing the integer to print.
 *
 * Return: The updated character count.
 */
int write_d(char *buff, int count, va_list value)
{
	int base = 10;
	char *str = _ia(va_arg(value, int), base);

	return (_copy_string(buff, count, str));
}

/**
 * write_i - Write an integer to the buffer.
 * @buff: The buffer to write the integer to.
 * @count: The current character count.
 * @value: The argument list containing the integer to print.
 *
 * Return: The updated character count.
 */
int write_i(char *buff, int count, va_list value)
{
	int base = 10;
	char *str = _ia(va_arg(value, int), base);

	return (_copy_string(buff, count, str));
}

/**
 * write_s - Write a string to the buffer.
 * @buffer: The buffer to write the string to.
 * @char_print: The current character count.
 * @value: The argument list containing the string to print.
 *
 * Return: The updated character count.
 */
int write_s(char *buffer, int char_print, va_list value)
{
	char *str = va_arg(value, char *);

	if (!str)
		str = "(null)";

	return (_copy_string(buffer, char_print, str));
}

/**
 * write_u - Write an unsigned integer to the buffer.
 * @buff: The buffer to write the unsigned integer to.
 * @count: The current character count.
 * @value: The argument list containing the unsigned integer to print.
 *
 * Return: The updated character count.
 */
int write_u(char *buff, int count, va_list value)
{
	int base = 10;
	unsigned int integer;
	char *str;

	integer = va_arg(value, unsigned int);
	str = _utoa(integer, base);

	return (_copy_string(buff, count, str));
}
