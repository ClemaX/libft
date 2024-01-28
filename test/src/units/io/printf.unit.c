#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

#include <unit.h>
#include <expect.h>

#include <libft/io.h>

const char *const	null_str = NULL;

#define				define(name, expected_content, expected_ret, ...) \
static int			name() \
{ \
	const fd_expectation expectations[] = { \
		fd_expect(STDOUT_FILENO, expected_content), \
		{}, \
	}; \
	int	ret; \
	int	err; \
\
	ret = expect_fds(expectations); \
\
	err = ret == -1; \
	if (err) \
		goto expect_fds_error; \
\
	if (ret == 0) \
	{ \
		const int	ret = ft_printf(__VA_ARGS__); \
\
		expect_fds_done(); \
\
		exit(expect(ret, expected_ret)); \
	} \
\
expect_fds_error: \
	return err; \
}

//				content		ret	fmt		...
define(none,	"TEST",		4,	"TEST")
define(s_null, "(null)",	6,	"%s",	null_str)

const unit			unit_io_printf = {
	"printf",
	(test[]){
		{"should print without conversions",		.test=none},
		{"should print '(null)' for NULL string",	.test=s_null},
		{},
	},
};
