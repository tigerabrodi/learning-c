#include "functions.h"

int main()
{
	my_printf("Hello, world!\n");

	my_printf("Hello, world with number: %d, %d, %d\n", 1, 2, 3);

	my_printf("numbers and chars %d %d %d %c %c %c\n", 1, 2, 3, 'a', 'b', 'c');

	my_printf("handle strings %s %s %s\n", "string1", "string2", "string3");

	return 0;
}
