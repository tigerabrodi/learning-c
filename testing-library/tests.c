#include "tests.h"
#include <stdio.h>

void assert_true(int condition, const char *test_name)
{
	if (!condition)
	{
		printf("[ERROR] Test '%s' failed.\n", test_name);
	}

	printf("[INFO] Test '%s' passed.\n", test_name);
}

void assert_false(int condition, const char *test_name)
{
	if (condition)
	{
		printf("[ERROR] Test '%s' failed.\n", test_name);
	}

	printf("[INFO] Test '%s' passed.\n", test_name);
}

int test_count = 0;
const int max_tests = 100;

// array of registered tests max 100
test_func registered_tests[max_tests];

void register_test(test_func test)
{
	if (test_count < max_tests)
	{
		registered_tests[test_count] = test;
		test_count++;
	}
}

void run_all_tests()
{
	for (int i = 0; i < test_count; i++)
	{
		registered_tests[i]();
	}
}
