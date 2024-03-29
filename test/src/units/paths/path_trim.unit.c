#include <unit.h>
#include <expect.h>

#include <libft/paths.h>

struct		args
{
	const char	*path;
	const char	*expected;
};

static int	run(const struct args *args)
{
	char	path[strlen(args->path) + 1];
	int		err;

	strcpy(path, args->path);

	path_trim(path);

	err = expect(path, args->expected);

	if (err)
		fprintf(stderr, "\tcall: path_trim(\"%s\")", args->path);

	return err;
}

const unit	unit_paths_path_trim = {
	"path_trim",
	(test[]){
		//													path		expected
		it("should not affect trimmed relative path",		"a",		"a"),
		it("should trim trailing delim on relative path",	"a/",		"a"),
		it("should trim trailing delims on relative path",	"a///",		"a"),

		it("should not affect trimmed absolute path",		"/a",		"/a"),
		it("should trim trailing delim on absolute path",	"/a/",		"/a"),
		it("should trim trailing delims on absolute path",	"/a///",	"/a"),

		it("should not affect trimmed root path",			"/", 		"/"),
		it("should trim trailing delim on root path",		"//", 		"/" ),
		it("should trim trailing delims on root path",		"////",		"/"),
		{},
	},
};
