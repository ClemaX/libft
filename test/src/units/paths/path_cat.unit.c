#include <libft/paths.h>

#include <unit.h>
#include <expect.h>

static int test_path_cat()
{
	char		result[PATH_MAX];
	int			err;

	path_cat(result, "a", "b");

	err = expect(result, "a/b");

	return err;
}

const unit unit_paths_path_cat = {
	.name = "path_cat",
	.tests = (test[]){
		{"should concatenate two paths", test_path_cat},
		{NULL, NULL},
	},
};
