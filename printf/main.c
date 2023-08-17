#include <unistd.h>

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

void my_printf(const char *format)
{
	my_puts(format);
}

int main()
{
	my_printf("Hello, world!\n");

	return 0;
}
