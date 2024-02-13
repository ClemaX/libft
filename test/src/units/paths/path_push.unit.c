#include <unit.h>
#include <expect.h>

#include <libft/paths.h>

struct		args
{
	const char	*base;
	const char	*appendage;
	const char	*expected;
};

static int	run(const struct args *args)
{
	char	path[PATH_MAX];
	int		err;

	strcpy(path, args->base);

	path_push(path, args->appendage);

	err = expect(path, args->expected);

	if (err)
		fprintf(stdout, "\tcall: path_push(\"%s\", \"%s\")\n", args->base, args->appendage);

	return err;
}

const unit	unit_paths_path_push = {
	"path_push",
	(test[]){
		//													base		appendage	expected
		it("should push relative path",						"/a/b",		"c",		"/a/b/c"),
		it("should push absolute path", 					"/a/b",		"/c",		"/a/b/c"),
		it("should push absolute path on /", 				"/",		"/opt",		"/opt"),
		it("should not affect path when pushing nothing", 	"/a/b",		"",			"/a/b"),
		it("should not affect path when pushing .", 		"/a/b",		".",		"/a/b"),
		it("should not affect path when pushing . on /",	"/",		".",		"/"),
		it("should not affect path when pushing / on /", 	"/",		"/",		"/"),
		it("should pop path when pushing ..", 				"/a/b",		"..",		"/a"),
		it("should not pop path when pushing .. on /", 		"/",		"..",		"/"),
		{},
	},
};
