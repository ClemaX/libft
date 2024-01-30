#pragma once

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#include <ansi.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE	1024
#endif

typedef struct		fd_expectation
{
	int			fd;
	const void *content;
	size_t		length;
}					fd_expectation;

#define				_fmt_diff(specifier) \
	MARKER_FAIL "\n" \
	"\t%s: " \
		"expected \"" COLOR_FG(FG_GREEN, specifier) "\" " \
		"but got \"" COLOR_FG(FG_RED, specifier) "\"\n"

#define				print_diff(label, actual, expected) \
	printf(_Generic((actual), \
		char:			_fmt_diff("%hhd"), \
		int: 			_fmt_diff("%i"), \
		size_t:			_fmt_diff("%zu"), \
		ssize_t:		_fmt_diff("%zi"), \
		void*:			_fmt_diff("%p"), \
		char*:			_fmt_diff("%s"), \
		const char*:	_fmt_diff("%s") \
	), (label), (expected), (actual))


#define				assert(condition) \
({ \
	int	diff = !(condition); \
\
	if (diff) \
		print_diff(#condition, "false", "true"); \
\
	diff; \
})

#define				expect_n(label, actual, expected) \
({ \
	const int	diff = expected != actual; \
\
	if (diff) \
		print_diff(label, actual, expected); \
\
	diff; \
})

#define				expect_n_decl(suffix, type) \
static inline int	expect_##suffix (const char *label, type actual, type expected) __attribute__((unused)); \
static inline int	expect_##suffix (const char *label, type actual, type expected)  \
{ \
	return 			expect_n(label, actual, expected); \
}

expect_n_decl(c, char);
expect_n_decl(i, int);
expect_n_decl(zu, size_t);
expect_n_decl(zi, ssize_t);
expect_n_decl(ptr, void*);

// static inline int	expect_s(const char *label, const char *actual, const char *expected) __attribute__((unused));

static inline int	expect_s(const char *label, const char *actual, const char *expected) __attribute__((unused));
static inline int	expect_s(const char *label, const char *actual, const char *expected)
{
	int diff;

	diff = actual != expected && (actual == NULL || expected == NULL || strcmp(actual, expected));

	if (diff)
		print_diff(label, actual, expected);

	return diff;
}

int					expect_fds(const fd_expectation *expectations);
int					expect_fds_done();

#define				expect(actual, expected) \
_Generic((actual), \
	char:				expect_c, \
    int:				expect_i, \
	size_t:				expect_zu, \
	ssize_t:			expect_zi, \
	void*:				expect_ptr, \
	char*:				expect_s, \
	fd_expectation*:	expect_fds, \
	default:			expect_ptr \
)((#actual), (actual), (expected))

#define _fd_expect(_fd, _content, _length) \
	(fd_expectation){ .fd=(_fd), .content=(_content), .length=(_length) }

#define fd_expect_mem(fd, content) \
	_fd_expect((fd), (content), sizeof(content))

#define fd_expect_s(fd, content) \
	_fd_expect((fd), (content), sizeof(content) - 1)

#define fd_expect(fd, content) \
	_Generic((content), \
		char*:	fd_expect_s((fd), (content)), \
		void*:	fd_expect_mem((fd), (content)) \
	)

#define it(name, ...) {name, run, &(struct args){__VA_ARGS__}}
