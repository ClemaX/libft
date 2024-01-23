#include <stdio.h>
#include <string.h>

#include <expect.h>

int	expect_i(const char *label, const int actual, const int expected)
{
	int diff;

	diff = expected - actual;

	if (diff)
		print_diff(label, actual, expected);

	return diff;
}

int	expect_s(const char *label, const char *actual, const char *expected)
{
	int diff;

	diff = actual != expected && (actual == NULL || strcmp(actual, expected));

	if (diff)
		print_diff(label, actual, expected);

	return diff;
}
