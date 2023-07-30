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
 * _utoa - Convert an unsigned integer to a
 * string representation in a given base.
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
