#include "main.h"


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
