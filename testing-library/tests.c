#include "tests.h"
#include <stdio.h>

int total_tests = 0;
int passed_tests = 0;
int failed_tests = 0;

TestSuite create_suite(char *name)
{
	TestSuite new_suite;
	new_suite.suite_name = name;
	new_suite.test_count = 0;
	return new_suite;
}

void assert_true(int condition, const char *test_name)
{
	total_tests++;
	if (!condition)
	{
		printf("[ERROR] Test '%s' failed.\n", test_name);
		failed_tests++;
		return;
	}

	printf("[PASSING] Test '%s' passed.\n", test_name);
	passed_tests++;
}

void assert_false(int condition, const char *test_name)
{
	total_tests++;
	if (condition)
	{
		printf("[ERROR] Test '%s' failed.\n", test_name);
		failed_tests++;
		return;
	}

	printf("[PASSING] Test '%s' passed.\n", test_name);
	passed_tests++;
}

int test_count = 0;
const int max_tests = 100;

// array of registered tests max 100
test_func registered_tests[max_tests];

void register_test(test_func test, TestSuite *suite)
{
	if (suite->test_count < max_tests)
	{
		suite->tests[suite->test_count] = test;
		suite->test_count++;
	}
	if (test_count < max_tests)
	{
		registered_tests[test_count] = test;
		test_count++;
	}
}

void run_suite(TestSuite *suite)
{
	printf("\n=== Running suite: %s ===\n", suite->suite_name);
	for (int i = 0; i < suite->test_count; i++)
	{
		suite->tests[i]();
	}
}

void run_all_tests()
{
	for (int i = 0; i < test_count; i++)
	{
		registered_tests[i]();
	}

	printf("\n=== TEST SUMMARY ===\n");
	printf("Total Tests: %d\n", total_tests);
	printf("Passed: %d\n", passed_tests);
	printf("Failed: %d\n", failed_tests);
}
