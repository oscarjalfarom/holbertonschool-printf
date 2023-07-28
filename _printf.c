#include "main.h"

int _printf(const char *format, ...)
{
	char *buffer;
	
	int i = 0; // variable for iterator of while loop
	int char_printf = 0; // character count to print

	va_list args; // argument list initializer
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

	va_start(args, format); // start list to loop through args

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

	write(1, buffer, char_printf); // write... to print the buffer
	va_end(args); // variadic release
	free(buffer); // malloc release
	return(char_printf); // return number of characters printed
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
