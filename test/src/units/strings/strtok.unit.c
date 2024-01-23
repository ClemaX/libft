#include <stddef.h>

#include <libft/strings.h>

#include <stdio.h>
#include <unit.h>
#include <expect.h>

static int test_strtok_single_delim()
{
	char		str[] = "a/b/c";
	const char	*delim = "/";
	const char	*expected[] = {"a", "b", "c", NULL};
	char		*token = str;
	size_t		token_i = 0;
	int			err = 0;

	do {
		token = ft_strtok(token, delim);
		err |= expect(token, expected[token_i]);
		token_i++;
	} while (token != NULL);

	return err;
}

const unit unit_strings_strtok = {
	.name = "strtok",
	.tests = (test[]){
		{"should tokenize with single delimiters", test_strtok_single_delim},
		{NULL, NULL},
	},
};
