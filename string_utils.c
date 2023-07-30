#include "main.h"

/**
 * _abs - Compute the absolute value of an integer.
 * @n: The integer to evaluate.
 *
 * Return: The absolute value of the integer.
 */
int _abs(int n)
{
	if (n < 0)
	{
		n = n * -1;
		return (n);
	}
	return (n);
}

/**
 * _ia - Convert an integer to a string representation in a given base.
 * @value: The integer value to convert.
 * @base: The base for conversion (2 to 32).
 *
 * Return: The string representation of the integer in the given base.
 */
char *_ia(int value, int base)
{
	char buffer[1024];
	int n, i;

	if (base < 2 || base > 32)
		exit(1);

	n = _abs(value);

	i = 0;
	while (n)
	{
		int r = n % base;

		r = _abs(r);
		if (r >= 10)
			buffer[i] = 65 + (r - 10);
		else
			buffer[i] = 48 + r;
		i++;
		n = n / base;
	}

	if (i == 0)
	{
		buffer[i] = '0';
		i++;
	}

	if (value < 0 && base == 10)
	{
		buffer[i] = '-';
		i++;
	}

	buffer[i] = '\0';

	return (_reverse(buffer, i));
}

/**
 * _utoa - Convert an unsigned integer to a string representation in a given base.
 * @value: The unsigned integer value to convert.
 * @base: The base for conversion (2 to 32).
 *
 * Return: The string representation of the unsigned integer in the given base.
 */
char *_utoa(unsigned int value, unsigned int base)
{
	char buffer[1024];
	unsigned int i, r;

	if (base < 2 || base > 32)
		exit(1);

	i = 0;
	while (value)
	{
		r = value % base;

		if (r >= 10)
			buffer[i] = 65 + (r - 10);
		else
			buffer[i] = 48 + r;

		i++;
		value = value / base;
	}

	if (i == 0)
	{
		buffer[i] = '0';
		i++;
	}

	buffer[i] = '\0';

	return (_reverse(buffer, i));
}

/**
 * _strlen - Compute the length of a string.
 * @s: The input string.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int count = 0;

	while (s[count] != '\0')
		count++;
	return (count);
}

/**
 * _reverse - Reverse the content of an array of characters.
 * @s: The array to be reversed.
 * @n: The number of elements in the array.
 *
 * Return: Pointer to the reversed array.
 */
char *_reverse(char *s, int n)
{
	int i, aux;

	n--;

	for (i = 0; i <= n; i++, n--)
	{
		aux = s[i];
		s[i] = s[n];
		s[n] = aux;
	}

	return (s);
}

/**
 * _copy_string - Copy a string to a buffer and return the new character count.
 * @buffer: The buffer to copy the string into.
 * @char_print: The current character count.
 * @value: The string to copy.
 *
 * Return: The updated character count.
 */
int _copy_string(char *buffer, int char_print, char *value)
{
	int k = 0;

	while (value[k])
	{
		buffer[k] = value[k];
		char_print++;
		k++;
	}
	return (char_print);
}
