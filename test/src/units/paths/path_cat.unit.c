#include <unit.h>
#include <expect.h>

#include <libft/paths.h>

struct		args
{
	const char	*a;
	const char	*b;
	const char	*expected;
};

static int	run(const struct args *args)
{
	char	path[PATH_MAX];
	int		err;

	path_cat(path, args->a, args->b);

	err = expect(path, args->expected);

	if (err)
		fprintf(stdout, "\tcall: path_cat(path, \"%s\", \"%s\")\n", args->a, args->b);

	return err;
}

const unit	unit_paths_path_cat = {
	"path_cat",
	(test[]){
		//												a			b			expected
		it("should cat relative paths", 				"a",		"b",		"a/b"),
		it("should cat . on relative path",				"a",		".",		"a"),
		it("should cat .. on relative path",			"a/b",		"..",		"a"),
		it("should cat multiple . on relative path",	"a",		"././.",	"a"),
		it("should handle empty input as a path",		"a",		"",			"a"),
		it("should handle empty input as b path",		"",			"b",		"b"),
		it("should handle absolute paths",				"/a",		"/b",		"/a/b"),
		it("should handle absolute path with root",		"/",		"/opt",		"/opt"),
		it("should handle mixed paths",					"/a",		"b",		"/a/b"),
		it("should handle complex relative paths",		"a/b/c",	"../../d",	"a/d"),
		{},
	},
};
