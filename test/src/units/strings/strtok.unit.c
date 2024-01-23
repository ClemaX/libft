#include <stddef.h>

#include <libft/strings.h>

#include <stdio.h>
#include <unit.h>
#include <expect.h>

#include <string.h>

static int test_single_char_delim()
{
	char		str[] = "a/b/c";
	const char	*delim = "/";
	const char	*expected[] = {"a", "b", "c", NULL};
	char		*token = str;
	size_t		token_i = 0;
	int			err = 0;

	token = ft_strtok(str, delim);

	while (1)
	{
		err |= expect(token, expected[token_i]);

		if (token == NULL || expected[token_i] == NULL)
			break;

		token = ft_strtok(NULL, delim);
		++token_i;
	}

	return err;
}

const unit unit_strings_strtok = {
	.name = "strtok",
	.tests = (test[]){
		{"should tokenize with single character delimiters", test_single_char_delim},
		{NULL, NULL},
	},
};
