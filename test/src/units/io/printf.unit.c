#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

#include <unit.h>
#include <expect.h>

#include <libft/io.h>

static int	expect_fds_test()
{
	const fd_expectation expectations[] = {
		fd_expect(STDOUT_FILENO, "TEST"),
		{},
	};
	int	ret;
	int	err;

	ret = expect_fds(expectations);

	err = ret == -1;
	if (err)
		goto expect_fds_error;

	if (ret == 0)
	{
		const int	ret = ft_printf("TEST");

		expect_fds_done();

		exit(expect(ret, 3));
	}

expect_fds_error:
	return err;
}

const unit	unit_io_printf = {
	"printf",
	(test[]){
		{"should print string without conversions", .test=expect_fds_test},
		{},
	},
};
