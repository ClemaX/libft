#include <stddef.h>

#include <libft/strings.h>

#include <stdio.h>
#include <unit.h>
#include <expect.h>

#include <string.h>

struct		args
{
	const char	*str;
	const char	*delim;
	const char	**expected;
};

static int	run(const struct args *args)
{
	char	str[strlen(args->str) + 1];
	char	*token;
	size_t	token_i = 0;
	int		err = 0;

	strcpy(str, args->str);

	token = ft_strtok(str, args->delim);

	while (1)
	{
		err |= expect(token, args->expected[token_i]);

		if (token == NULL || args->expected[token_i] == NULL)
			break;

		token = ft_strtok(NULL, args->delim);
		++token_i;
	}

	return err;
}

const unit	unit_strings_strtok = {
	.name = "strtok",
	.tests = (test[]){
		it("should tokenize with single character delims", "a/b/c", "/", (const char*[]){"a", "b", "c", NULL}),
		{},
	},
};
