#include "main.h"

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
