#include <stddef.h>

#include <libft/strings.h>

#include <stdio.h>
#include <unit.h>
#include <expect.h>

#include <string.h>

struct		args
{
	size_t			buffer_size;
	const char 		*base;
	const char		*appendage;
	const char		*expected;
	size_t			expected_ret;
};

static int	run(const struct args *args)
{
	char	str[args->buffer_size];
	size_t	ret;
	int		err;

	strcpy(str, args->base);

	ret = ft_strlcat(str, args->appendage, sizeof(str));

	err = expect(str, args->expected) | expect(ret, args->expected_ret);

	if (err)
		fprintf(stdout, "\tcall: ft_strlcat(\"%s\", \"%s\", %zu)\n",
			args->base, args->appendage, sizeof(str));

	return err;
}

const unit	unit_strings_strlcat = {
	"strlcat",
	//													sz	a		b		exp.	exp. ret
	(test[]){
		it("should concatenate string in big buffer",	64,	"a",	"b",	"ab",	2),
		it("should concatenate string in small buffer",	3,	"a",	"b",	"ab",	2),
		it("should concatenate until end of buffer",	2,	"a",	"b",	"a",	2),
		it("should concatenate string in empty buffer", 2,	"",		"b",	"b",	1),
		it("should concatenate empty strings", 			1,	"",		"",		"",		0),
		{},
	},
};
