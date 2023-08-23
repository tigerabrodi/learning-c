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

	printf("This should be zero %d ", my_strcmp(testString1, testString2));
	printf("This should be one %d ", my_strcmp("hey", "hey"));

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

int my_strcmp(const char *str1, const char *str2)
{
	int is_same = 1;

	while (*str1 != '\0' && is_same == 1 && *str2 != '\0')
	{

		if (*str1 != *str2)
		{
			return 0;
		}

		str1++;
		str2++;
	}

	return (*str1 == '\0' && *str2 == '\0') ? 1 : 0;
}