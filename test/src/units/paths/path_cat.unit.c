#include <libft/paths.h>

#include <unit.h>
#include <expect.h>

struct		args
{
	const char	*a;
	const char	*b;
	const char	*expected;
};

static int	run(const struct args *args)
{
	char	path[PATH_MAX];

	path_cat(path, args->a, args->b);

	return expect(path, args->expected);
}

const unit	unit_paths_path_cat = {
	"path_cat",
	(test[]){
		//												a		b		expected
		it("should concatenate relative paths", 		"a",	"b",	"a/b"),
		it("should concatenate . on relative path",		"a",	".",	"a"),
		it("should concatenate .. on relative path",	"a/b",	"..",	"a"),
		{},
	},
};
