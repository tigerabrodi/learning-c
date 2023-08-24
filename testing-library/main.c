#include "tests.h"

void test_sample()
{
	// Passing
	assert_true(1 == 1, "Sample test");
	assert_false(1 == 2, "Sample test");

	// Failing
	assert_true(1 == 2, "Sample test");
	assert_false(1 == 1, "Sample test");
}

void test_sample2()
{
	// Passing
	assert_true(1 == 1, "test 2 Sample test");
	assert_false(1 == 2, "test 2 Sample test");

	// Failing
	assert_true(1 == 2, "test 2 Sample test");
	assert_false(1 == 1, "test 2 Sample test");
}

int main()
{
	register_test(test_sample);
	register_test(test_sample2);
	run_all_tests();
	return 0;
}
