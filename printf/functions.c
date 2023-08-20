#include "functions.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

void my_putchar(char c)
{
	write(1, &c, 1); // 1 represents STDOUT_FILENO, the standard output file descriptor
}

void my_puts(const char *str)
{
	while (*str)
	{
		my_putchar(*str++);
	}
}

void my_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int index = 0;
	char *full_string_to_be_printed = (char *)malloc(strlen(format) * 2); // Assuming enough space

	if (full_string_to_be_printed == NULL)
	{
		my_puts("Memory allocation failed\n");
		va_end(args);
		return;
	}

	while (format[index] != '\0') // Keep looping until the end of the string
	{
		if (format[index] == '%') // Check if the current character is the start of a format specifier
		{
			index++;		  // Move past the '%' to the character that specifies the type
			if (format[index] == 'd') // If it's 'd', then an integer argument is expected
			{
				int integer_arg = va_arg(args, int); // Get the next argument as an integer
								     // TODO: Convert integer_arg to string
								     // TODO: Concatenate the string to full_string_to_be_printed
			}
			// TODO: Handle other format specifiers if needed
		}
		else
		{
			// TODO: Add the character to full_string_to_be_printed since it's not part of a format specifier
		}

		index++; // Move to the next character in the format string
	}

	my_puts(full_string_to_be_printed);
	free(full_string_to_be_printed); // Free allocated memory
	va_end(args);
}
