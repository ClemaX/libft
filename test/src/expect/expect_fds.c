#include <stddef.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

#include <expect.h>

typedef int				pipe_fds[2];

static pid_t			child_pid;

static int				orig_fds[3] = {
	STDIN_FILENO,
	STDOUT_FILENO,
	STDERR_FILENO
};

static inline pipe_fds	*pipes_init(unsigned count)
{
	pipe_fds	*pipes = malloc(sizeof(*pipes) * count);
	int			err;
	unsigned	pipe_i;

	err = pipes == NULL;
	if (err)
		goto error;

	for (pipe_i = 0; pipe_i < count && !err; ++pipe_i)
		err = pipe(pipes[pipe_i]);

	if (err)
	{
		for (unsigned i = 0; i < pipe_i; ++i)
		{
			close(pipes[i][0]);
			close(pipes[i][1]);
		}

		free(pipes);

		pipes = NULL;
	}

error:
	return pipes;
}

static inline void	pipes_clear(pipe_fds *pipes, unsigned count)
{
	for (unsigned i = 0; i < count; ++i)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
	}

	free(pipes);
}

static inline int	pipes_fds_restore()
{
	int	err;

	err = 0;

	if (orig_fds[1] != STDOUT_FILENO)
	{
		err = dup2(orig_fds[1], STDOUT_FILENO) == -1;
		if (!err)
		{
			close(orig_fds[1]);
			orig_fds[1] = STDOUT_FILENO;
		}
	}

	if (orig_fds[2] != STDERR_FILENO)
	{
		err = dup2(orig_fds[2], STDERR_FILENO) == -1;
		if (!err)
		{
			close(orig_fds[2]);
			orig_fds[2] = STDERR_FILENO;
		}
	}

	return err;
}

static inline int	pipes_fds_dup(pipe_fds *pipes,
	const fd_expectation *expectations, unsigned count)
{
	int	err;

	orig_fds[0] = STDIN_FILENO;
	orig_fds[1] = STDOUT_FILENO;
	orig_fds[2] = STDERR_FILENO;

	err = orig_fds[STDOUT_FILENO] == -1 || orig_fds[STDERR_FILENO] == -1;
	if (err)
	{
		perror("dup");
		goto dup_error;
	}

	for (unsigned i = 0; i < count && !err; ++i)
	{
		close(pipes[i][0]);

		if (expectations[i].fd == orig_fds[1])
			orig_fds[1] = dup(expectations[i].fd);
		else if (expectations[i].fd == orig_fds[2])
			orig_fds[2] = dup(expectations[i].fd);

		err = dup2(pipes[i][1], expectations[i].fd) == -1;
	}

	if (err)
	{
		err = errno;

		pipes_fds_restore();

		fprintf(stderr, "dup2: %s\n", strerror(err));
		goto dup_error;
	}

dup_error:
	return err;
}

static inline void	on_timeout(int signo)
{
	(void)signo;
	fprintf(stderr, "Timed out, killing child with pid '%d'...\n", child_pid);
	kill(child_pid, SIGKILL);
}

static inline int	waitpid_timeout(pid_t pid, int seconds, int *status)
{
	int	err;

	child_pid = pid;

	signal(SIGALRM, on_timeout);
	alarm(seconds);

	err = waitpid(pid, status, 0) == -1;

	signal(SIGALRM, SIG_DFL);

	return err;
}

static inline void	fd_print_diff(int fd, size_t range_start, size_t range_end)
{
	const char *name;

	if (fd == STDOUT_FILENO)
		name = "stdout";
	else if (fd == STDERR_FILENO)
		name = "stderr";
	else
		name = NULL;

	if (name != NULL)
		fprintf(stdout, MARKER_FAIL "\n"
			"\t%s: output differs in range [%zu, %zu]\n",
			name, range_start, range_end);
	else
		fprintf(stdout, MARKER_FAIL "\n"
			"\tfd %d: output differs in range [%zu, %zu]\n",
			fd, range_start, range_end);
}

static inline int	expect_fd(int fd, const fd_expectation *expected)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	read_len;
	size_t	content_i;
	int		err;

	err = 0;
	content_i = 0;

	while (!err && (read_len = read(fd, buffer, sizeof(buffer))) > 0)
	{
		err = content_i + read_len > expected->length
			|| memcmp(buffer, expected->content + content_i, read_len) != 0;

		content_i += read_len;
	}

	if (read_len == -1)
	{
		err = -1;
		perror("read");
		goto read_err;
	}

	if (!err)
		err = content_i != expected->length;

	if (err)
		fd_print_diff(expected->fd, content_i - read_len, expected->length);

read_err:
	return err;
}

int					expect_fds_done()
{
	return pipes_fds_restore();
}

int					expect_fds(const fd_expectation *expectations)
{
	pipe_fds	*pipes;
	unsigned	count;
	pid_t		pid;
	int			ret;
	int			status;

	for (count = 0; expectations[count].content != NULL; ++count)
	{
		if (expectations[count].fd == STDOUT_FILENO)
			fflush(stdout);
		else if (expectations[count].fd == STDERR_FILENO)
			fflush(stderr);
	}

	pipes = pipes_init(count);

	ret = -(pipes == NULL);
	if (ret)
	{
		perror("pipes_init");
		goto pipes_error;
	}

	pid = fork();

	ret = -(pid == -1);
	if (ret)
	{
		perror("fork");
		goto fork_error;
	}

	if (pid == 0)
	{
		ret = pipes_fds_dup(pipes, expectations, count);

		free(pipes);

		if (ret)
			exit(ret);

		goto child_done;
	}

	ret = waitpid_timeout(pid, 30, &status);
	if (ret)
	{
		perror("waitpid");
		goto waitpid_error;
	}

	// TODO: Check child status

	if (!WIFEXITED(status))
	{
		ret = -2;
		goto child_error;
	}

	if (WEXITSTATUS(status) != 0)
	{
		ret = -3;
		goto child_error;
	}

	for (unsigned i = 0; i < count; ++i)
	{
		close(pipes[i][1]);
		ret |= expect_fd(pipes[i][0], &expectations[i]) != 0;
	}

	++ret;

	goto parent_done;

waitpid_error:
	kill(pid, SIGKILL);

child_error:
fork_error:
parent_done:
	pipes_clear(pipes, count);

pipes_error:
child_done:
	return	ret;
}
