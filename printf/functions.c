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
	int argument_to_be_added_index = 0;

	size_t format_length = strlen(format);
	char *full_string_to_be_printed = (char *)malloc(*format + 1);
	char *arguments = (char *)malloc(*format + 1);

	// How do I distinguish between the print string and the arguments passed?
	// Is this the correct way to iterate through the arguments alone?
	while (va_arg(args, int))
	{
		int argument_list_index = 0;
		arguments[argument_index] = va_arg(args, int);
		argument_index++;
	}

	if (full_string_to_be_printed == NULL)
	{
		my_printf("Memory allocation failed\n");
		va_end(args);
	}

	while (*format != "\0")
	{
		if (format[index] == "%")
		{
			const char type_to_be_printed_index = index++;
			if (format[type_to_be_printed_index] == "d")
			{
				// Keep track of the amount of integers already accessed?
				// How do I know the position of each

				// check if type is integer (how do I do this and turn it into an integer from a string?)
				if (arguments[argument_to_be_added_index])
				{
					// add integer to string at index
					full_string_to_be_printed[index] = arguments[argument_to_be_added_index];
				}
				else
				{
					my_printf("Error: Argument type does not match format specifier\n");
					va_end(args);
				}
			}
		}
		else
		{
			full_string_to_be_printed[index] = format[index];
		}

		index++;
	}

	my_puts(full_string_to_be_printed);
}