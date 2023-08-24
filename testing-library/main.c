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

void test_sample3()
{
	assert_true(1 == 1, "test 3 Sample test");
	assert_false(1 == 2, "test 3 Sample test");
}

int main()
{
	TestSuite first_suite = create_suite("First Suite");

	// Register tests to the first_suite
	register_test_with_suite(test_sample, &first_suite);
	register_test_with_suite(test_sample2, &first_suite);
	register_test(test_sample3);

	// Run the specific test suite
	run_suite(&first_suite);

	// Optionally, run all tests (if you've extended `run_all_tests` to handle suites)
	// run_all_tests();

	return 0;
}
