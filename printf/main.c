#include "functions.h"

int main()
{
	my_printf("Hello, world!\n");

	my_printf("Hello, world with number: %d, %d, %d\n", 1, 2, 3);

	my_printf("numbers and chars %d %d %d %c %c %c\n", 1, 2, 3, 'a', 'b', 'c');

	my_printf("handle strings %s %s %s\n", "string1", "string2", "string3");

	my_printf("handle floats %f %f %f\n", 1.0, 2.0, 3.0);

	my_printf("handle percentage sign %%\n");

	my_printf("handle width and numbers with * %*d %*d %*d\n", 5, 1, 10, 2, 15, 3);

	my_printf("handle width with numbers and * for all d, f, s, c %*d %*f %*s %55c\n", 5, 1, 10, 2.0, 15, "string", 'c');

	return 0;
}
