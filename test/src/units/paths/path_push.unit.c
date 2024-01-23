#include <libft/paths.h>

#include <unit.h>
#include <expect.h>

struct		args
{
	const char	*base;
	const char	*appendage;
	const char	*expected;
};

static int	run(const struct args *args)
{
	char	path[PATH_MAX];

	strcpy(path, args->base);

	path_push(path, args->appendage);

	return expect(path, args->expected);
}

const unit	unit_paths_path_push = {
	"path_push",
	(test[]){
		//													base		appendage	expected
		it("should push relative path",						"/a/b",		"c",		"/a/b/c"),
		it("should push absolute path", 					"/a/b",		"/c",		"/a/b/c"),
		it("should not affect path when pushing .", 		"/a/b",		".",		"/a/b"),
		it("should not affect path when pushing . on /",	"/",		".",		"/"),
		it("should pop path when pushing ..", 				"/a/b",		"..",		"/a"),
		it("should not pop path when pushing .. on /", 		"/",		"..",		"/"),
		{},
	},
};
