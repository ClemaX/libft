#include <libft/paths.h>

#include <unit.h>
#include <expect.h>

static int test_rel()
{
	char	path[] = "a";
	int		err;

	path_trim(path);

	err = expect(path, "a");

	return err;
}

static int test_rel_single()
{
	char	path[] = "a/";
	int		err;

	path_trim(path);

	err = expect(path, "a");

	return err;
}

static int test_rel_multiple()
{
	char	path[] = "a///";
	int		err;

	path_trim(path);

	err = expect(path, "a");

	return err;
}

static int test_abs()
{
	char	path[] = "/a";
	int		err;

	path_trim(path);

	err = expect(path, "/a");

	return err;
}


static int test_abs_single()
{
	char	path[] = "/a/";
	int		err;

	path_trim(path);

	err = expect(path, "/a");

	return err;
}

static int test_abs_multiple()
{
	char	path[] = "/a///";
	int		err;

	path_trim(path);

	err = expect(path, "/a");

	return err;
}

static int test_root()
{
	char	path[] = "/";
	int		err;

	path_trim(path);

	err = expect(path, "/");

	return err;
}

static int test_root_single()
{
	char	path[] = "//";
	int		err;

	path_trim(path);

	err = expect(path, "/");

	return err;
}

static int test_root_multiple()
{
	char	path[] = "////";
	int		err;

	path_trim(path);

	err = expect(path, "/");

	return err;
}


const unit unit_paths_path_trim = {
	.name = "path_trim",
	.tests = (test[]){
		{"should not affect trimmed relative path", test_rel},
		{"should trim trailing delim on relative path", test_rel_single},
		{"should trim trailing delims on relative path", test_rel_multiple}
,
		{"should not affect trimmed absolute path", test_abs},
		{"should trim trailing delim on absolute path", test_abs_single},
		{"should trim trailing delims on absolute path", test_abs_multiple},

		{"should not affect trimmed root path", test_root},
		{"should trim trailing delim on root path", test_root_single},
		{"should trim trailing delims on root path", test_root_multiple},

		{"should not affect trimmed relative path", test_root},
		{"should not affect trimmed relative path", test_root},

		{NULL, NULL},
	},
};
