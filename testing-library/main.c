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

int main()
{
	test_sample();
	return 0;
}
