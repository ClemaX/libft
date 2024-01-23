#pragma once

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#include <ansi.h>

#define _fmt_diff(specifier) \
	MARKER_FAIL "\n" \
	"\t%s: " \
		"expected \"" COLOR_GREEN specifier COLOR_RESET "\" " \
		"but got \"" COLOR_RED specifier COLOR_RESET "\"\n"

#define print_diff(label, actual, expected) \
printf(_Generic((actual), \
	int: 			_fmt_diff("%i"), \
	size_t:			_fmt_diff("%zu"), \
	ssize_t:		_fmt_diff("%zi"), \
	char*:			_fmt_diff("%s"), \
	const char*:	_fmt_diff("%s") \
), (label), (expected), (actual))

#define expect_n(label, actual, expected) \
({ \
	int	diff; \
\
	diff = expected != actual; \
	if (diff) \
		print_diff(label, actual, expected); \
\
	diff; \
})

#define expect_n_decl(suffix, type) \
static inline int	expect_##suffix (const char *label, const int actual, const int expected) \
{ \
	return expect_n(label, actual, expected); \
}

expect_n_decl(i, int);
expect_n_decl(zu, size_t);
expect_n_decl(zi, ssize_t);

static inline int	expect_s(const char *label, const char *actual, const char *expected)
{
	int diff;

	diff = actual != expected && (actual == NULL || strcmp(actual, expected));

	if (diff)
		print_diff(label, actual, expected);

	return diff;
}

#define expect(actual, expected) \
_Generic((actual), \
    int:	expect_i, \
	size_t:	expect_zu, \
	ssize_t: expect_zi, \
	char*:	expect_s \
)(#actual, actual, expected)
