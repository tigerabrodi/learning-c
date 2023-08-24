#include "tests.h"
#include <stdio.h>

void assert_true(int condition, const char *test_name)
{
	if (!condition)
	{
		printf("[ERROR] Test '%s' failed.\n", test_name);
	}
}
