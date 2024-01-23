#include <stddef.h>

#include <libft/strings.h>

#include <stdio.h>
#include <unit.h>
#include <expect.h>

#include <string.h>

static int test_buffer_big()
{
	char	buffer[64] = {'a'};
	size_t	ret;
	int		err;

	ret = ft_strlcat(buffer, "b", sizeof(buffer));

	err = expect(buffer, "ab")
		| expect(ret, 2UL);

	return err;
}

static int test_buffer_small()
{
	char	buffer[3] = {'a'};
	size_t	ret;
	int		err;

	ret = ft_strlcat(buffer, "b", sizeof(buffer));

	err = expect(buffer, "ab")
		| expect(ret, 2UL);

	return err;
}

static int test_buffer_too_small()
{
	char	buffer[2] = {'a'};
	size_t	ret;
	int		err;

	ret = ft_strlcat(buffer, "b", sizeof(buffer));

	err = expect(buffer, "a")
		| expect(ret, 2UL);

	return err;
}

static int test_buffer_empty()
{
	char	buffer[2] = {};
	size_t	ret;
	int		err;

	ret = ft_strlcat(buffer, "b", sizeof(buffer));

	err = expect(buffer, "b")
		| expect(ret, 1UL);

	return err;
}

static int test_empty()
{
	char	buffer[1] = {};
	size_t	ret;
	int		err;

	ret = ft_strlcat(buffer, "", sizeof(buffer));

	err = expect(buffer, "")
		| expect(ret, 0UL);

	return err;
}

const unit unit_strings_strlcat = {
	.name = "strlcat",
	.tests = (test[]){
		{"should concatenate string in big buffer", test_buffer_big},
		{"should concatenate string in small buffer", test_buffer_small},
		{"should concatenate until end of buffer", test_buffer_too_small},
		{"should concatenate string in empty buffer", test_buffer_empty},
		{"should concatenate empty strings", test_empty},
		{NULL, NULL},
	},
};
