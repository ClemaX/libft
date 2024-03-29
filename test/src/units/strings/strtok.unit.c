#include <stdio.h>
#include <string.h>

#include <unit.h>
#include <expect.h>

#include <libft/strings.h>

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

	if (err)
		fprintf(stderr, "\tcall: ft_strtok(\"%s\", \"%s\")\n", args->str, args->delim);

	return err;
}

const unit	unit_strings_strtok = {
	.name = "strtok",
	.tests = (test[]){
		it("should tokenize with single char delims",		"a/b/c",			"/",	(const char*[]){"a",	"b",	"c", NULL}),
		it("should tokenize with multi char delims",		"aaa, bbb, ccc",	", ",	(const char*[]){"aaa",	"bbb",	"ccc", NULL}),
		it("should tokenize string starting with delim",	"/a/b/c",			"/",	(const char*[]){"a",	"b",	"c", NULL}),
		it("should tokenize string starting with delims", 	"///aaa/bb//c",		"/",	(const char*[]){"aaa",	"bb",	"c", NULL}),
		it("should tokenize string with partial delim",		"/a", 				"/ab",	(const char*[]){"/a",	NULL}),
		it("should return NULL on only delims string", 		"/a/a/a/a/a/a/a",	"/a",	(const char*[]){NULL}),
		it("should return NULL on empty string", 			"",					"xyz",	(const char*[]){NULL}),
		{},
	},
};
