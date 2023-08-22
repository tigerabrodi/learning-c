#include "functions.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

void handle_reallocation(char *full_string_to_be_printed, size_t needed_length, va_list args)
{
	char *new_buffer_for_full_string = (char *)realloc(full_string_to_be_printed, needed_length);
	if (new_buffer_for_full_string == NULL)
	{
		my_puts("Memory reallocation failed\n");
		free(full_string_to_be_printed);
		va_end(args);
		return;
	}
	full_string_to_be_printed = new_buffer_for_full_string;
}

void my_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int index = 0;

	int initial_string_size = strlen(format) * 2;
	char *full_string_to_be_printed = (char *)calloc(initial_string_size, sizeof(char)); // Assuming enough space

	if (full_string_to_be_printed == NULL)
	{
		my_puts("Memory allocation failed\n");
		va_end(args);
		return;
	}

	while (format[index] != '\0') // Keep looping until the end of the string
	{
		if (format[index] == '%')
		{
			index++; // Move past the '%' to the character that specifies the type

			switch (format[index])
			{
			case 'd':
			{
				int integer_arg = va_arg(args, int);
				char integer_str[12];			 // Buffer for the integer as a string; 12 is enough for 32-bit ints
				sprintf(integer_str, "%d", integer_arg); // Convert the integer to a string

				// Reallocate memory for full_string_to_be_printed if needed
				size_t current_length = strlen(full_string_to_be_printed);
				size_t needed_length = current_length + strlen(integer_str) + 1; // +1 for null-terminator

				// Handle reallocation
				if (needed_length > initial_string_size)
				{
					handle_reallocation(full_string_to_be_printed, needed_length, args);
				}

				strcat(full_string_to_be_printed, integer_str);
				break;
			}

			case 'c':
			{
				char char_arg = (char)va_arg(args, int); // Characters are promoted to int when passed
				char char_str[2] = {char_arg, '\0'};

				sprintf(char_str, "%c", char_arg);
				strcat(full_string_to_be_printed, char_str);

				break;
			}

			case 's':
			{
				char *string_arg = va_arg(args, char *);

				size_t current_length = strlen(full_string_to_be_printed);
				size_t needed_length = current_length + strlen(string_arg) + 1; // +1 for null-terminator

				// Handle reallocation
				if (needed_length > initial_string_size)
				{
					handle_reallocation(full_string_to_be_printed, needed_length, args);
				}

				strcat(full_string_to_be_printed, string_arg);

				break;
			}
			case 'f':
			{
				double double_arg = va_arg(args, double);
				char double_str[20];
				sprintf(double_str, "%f", double_arg);

				size_t current_length = strlen(full_string_to_be_printed);
				size_t needed_length = current_length + strlen(double_str) + 1;

				if (needed_length > initial_string_size)
				{
					handle_reallocation(full_string_to_be_printed, needed_length, args);
				}

				strcat(full_string_to_be_printed, double_str);

				break;
			}
			case '%':
			{
				char percent_str[2] = {'%', '\0'};
				strcat(full_string_to_be_printed, percent_str);

				break;
			}
			}
		}
		else
		{
			// Can't use strcat because it expects its second argument to be a pointer to a null-terminated string, so it will keep reading memory until it finds a null character, resulting in an error.
			size_t len = strlen(full_string_to_be_printed);
			full_string_to_be_printed[len] = format[index];
			full_string_to_be_printed[len + 1] = '\0';
		}

		index++; // Move to the next character in the format string
	}

	my_puts(full_string_to_be_printed);
	free(full_string_to_be_printed); // Free allocated memory
	va_end(args);
}
