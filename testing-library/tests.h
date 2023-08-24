typedef void (*test_func)();

typedef struct
{
	char *suite_name;
	int test_count;
	test_func tests[max_tests];
} TestSuite;

void assert_true(int condition, const char *test_name);

void assert_false(int condition, const char *test_name);

void register_test(test_func test, TestSuite *suite);

void run_all_tests();

void run_suite(TestSuite *suite);

TestSuite create_suite(char *name);