#include <stdio.h>

// Function Prototype
size_t my_strlen(const char *str);
int my_strcmp(const char *str1, const char *str2);

int main()
{
	const char *testString1 = "Hello, World!";
	const char *testString2 = "OpenAI";

	size_t length1 = my_strlen(testString1);
	size_t length2 = my_strlen(testString2);

	printf("Length of \"%s\": %zu\n", testString1, length1);
	printf("Length of \"%s\": %zu\n", testString2, length2);

	return 0;
}

// Function Definition
size_t my_strlen(const char *str)
{
	size_t length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}

	return length;
}