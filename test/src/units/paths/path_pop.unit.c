#include <libft/paths.h>

#include <unit.h>
#include <expect.h>

struct		args
{
	const char *path;
	const char *expected;
};

static int	run(const struct args *args)
{
	char	path_buffer[PATH_MAX];

	strcpy(path_buffer, args->path);

	path_pop(path_buffer);

	return expect(path_buffer, args->expected);
}

const unit	unit_paths_path_pop = {
	"path_pop",
	(test[]){
		//													path		expected
		it("should not affect empty path",					"",			""),
		it("should not affect /",							"/",		"/"),
		it("should not affect .",							".",		"."),
		it("should pop .. to .",							"..",		"."),
		it("should pop relative path",						"a/b",		"a"),
		it("should pop relative .. path",					"../a",		".."),
		it("should pop absolute path",						"/a",		"/"),
		it("should pop // to /",							"//",		"/"),
		it("should pop /// to /",							"///",		"/"),
		it("should pop /a/b/ to /a",						"/a/b/",	"/a"),
		it("should pop /a/b// to /a",						"/a/b//",	"/a"),
		it("should pop ./ to .",							"./",		"."),
		it("should pop .// to .",							".//",		"."),
		it("should pop ../a/ to ..",						"../a/",	".."),
		it("should pop ../a// to ..",						"../a//",	".."),
		it("should pop absolute path w/ multiple delims",	"/a///b//",	"/a"),
		it("should pop relative path w/ multiple delims",	"a///b//",	"a"),
		{},
	},
};
