#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

#include <unit.h>
#include <expect.h>

#include <libft/io.h>


static int	convert_none()
{
	char	stdout_content[64];
	ssize_t	read_ret;
	int		err;
	int		pipe_fds[2];
	int		pid;
	int		child_status;

	err = pipe(pipe_fds);

	if (err)
	{
		perror("pipe");
		goto pipe_error;
	}

	fflush(stdout);

	pid = fork();

	err = pid < 0;
	if (err)
	{
		perror("fork");
		goto fork_error;
	}

	if (pid == 0)
	{
		int	err = dup2(pipe_fds[STDOUT_FILENO], STDOUT_FILENO) == -1;

		close(pipe_fds[STDIN_FILENO]);


		if (err)
			perror("dup2");
		else
			ft_printf("");

		exit(err);
	}
	else
	{
		close(pipe_fds[STDOUT_FILENO]);
		err = wait(&child_status) == -1;
		if (err)
		{
			perror("wait");
			goto wait_error;
		}

		err = WIFSIGNALED(child_status);
		if (err)
		{
			fprintf(stderr, "child unexpectedly terminated with signal '%d'!\n", WTERMSIG(child_status));
			goto child_exit_error;
		}

		err = !WIFEXITED(child_status);
		if (err)
		{
			fprintf(stderr, "child process did not exit properly!\n");
			goto child_error;
		}

		err = WEXITSTATUS(child_status);
		if (err)
		{
			fprintf(stderr, "child process exited with error code '%d'!\n",
				err);
			goto child_exit_error;
		}
	}

	read_ret = read(pipe_fds[STDIN_FILENO], stdout_content, sizeof(stdout_content) - 1);

	err = read_ret == -1;
	if (err)
	{
		perror("read");
		goto read_error;
	}

	stdout_content[read_ret] = '\0';


	err = expect(read_ret, 0) | expect(stdout_content, "");

	if (err)
		fprintf(stdout, "\tcall: printf(TODO)");

	goto done;

read_error:
child_error:
wait_error:
	kill(pid, SIGKILL);

child_exit_error:
fork_error:
done:
	close(pipe_fds[0]);
	close(pipe_fds[1]);

pipe_error:
	return err;
}

const unit	unit_io_printf = {
	"printf",
	(test[]){
		{"should print string without conversions", .test=convert_none},
		{},
	},
};
