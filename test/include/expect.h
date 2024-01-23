#pragma once

#include <stdio.h>
#include <inttypes.h>

#define expect(actual, expected) \
_Generic((actual), \
    int:	expect_i, \
    char*:	expect_s \
)(#actual, actual, expected)

#define _fmt_diff(specifier) \
	"%s: expected \"" specifier " but got \"" specifier "\"\n"

#define print_diff(label, actual, expected) \
printf(_Generic((actual), \
	int: 			_fmt_diff("%d"), \
	char*:			_fmt_diff("%s"), \
	const char*:	_fmt_diff("%s") \
), (label), (expected), (actual))

int	expect_i(const char *label, const int actual, const int expected);
int	expect_s(const char *label, const char *actual, const char *expected);
