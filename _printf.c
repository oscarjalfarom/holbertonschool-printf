#include "main.h"

int _printf(const char *format, ...)
{
	char *buffer;
	
	int i = 0;
	int char_printf = 0;

	va_list args;
	int (*format_printer)(char *, int, va_list);

	buffer = malloc(3000); 

	if (format == NULL || buffer == NULL)
	{
		free(buffer);
		return(0);
	}

	if (format[0] == '%' && format[1] == '\0')
	{
		free(buffer);
		return(0);
	}

	va_start(args, format);

	while (format[i])
	{
		if (format[i] != '%')
		{
			buffer[char_printf] = format[i];
			char_printf++;
		}
		else
		{
			format_printer = get_print_function(format[i + 1]);

			if (!format_printer)
			{
				buffer[char_printf] = '%';
				i++;
				char_printf++;
				continue;
			}

			char_printf = format_printer(&buffer[char_printf],char_printf, args);
			i++;
		}

		i++;
	}

	write(1, buffer, char_printf);
	va_end(args);
	free(buffer);
	return(char_printf);
}


int (*get_print_function(char specifier))(char *, int, va_list)
{
	int j = 0;

	print_t format_specifiers[] = {

		{"c", write_char},
		{"s", write_string},
		{"%", write_percent},
		{NULL, NULL}
	};	

	while (format_specifiers[j].type)
	{
		if (specifier == *format_specifiers[j].type)
			break;
		j++;
	}

	return (format_specifiers[j].f);
}
