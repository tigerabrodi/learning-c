typedef void (*test_func)();

void assert_true(int condition, const char *test_name);

void assert_false(int condition, const char *test_name);

void register_test(test_func test);

void run_all_tests();
