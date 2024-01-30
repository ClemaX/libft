#include <stddef.h>
#include <stdio.h>
#include <unit.h>
#include <expect.h>

#include <libft/hmap/hmap_i.h>

#define		expect_pair(_actual, _expected) \
	(assert((_actual) != NULL) \
	|| expect((_actual)->key, (_expected)->key) \
	| expect((_actual)->value, (_expected)->value))

static int	inexistent()
{
	const int			existent_key = 0x10;
	t_hmap_i			*map = hmap_i_new(existent_key);
	t_hmap_i_pair		*pair;
	int					err;

	err = assert(map != NULL);
	if (err)
		goto hmap_i_new_error;

	pair = hmap_i_set(map, existent_key, "user");

	err = assert(pair != NULL);
	if (err)
		goto hmap_i_set_error;

	err = expect(hmap_i_get(map, 0), NULL)
	| expect(hmap_i_get(map, existent_key * 2), NULL)
	| expect(hmap_i_get(map, existent_key * 3), NULL)
	| expect(hmap_i_get(map, existent_key + 1), NULL);

hmap_i_set_error:
	hmap_i_clr(&map, NULL);

	err |= expect(map, NULL);

hmap_i_new_error:
	return err;
}

static int	existent()
{
	const t_hmap_i_pair	expected = {.key = 0x10, .value="user"};
	t_hmap_i			*map = hmap_i_new(expected.key * 2);
	t_hmap_i_pair		*pair;
	int					err;

	err = assert(map != NULL);
	if (err)
		goto hmap_i_new_error;

	pair = hmap_i_set(map, expected.key, expected.value);

	err = assert(pair != NULL);
	if (err)
		goto hmap_i_set_error;

	pair = hmap_i_get(map, expected.key);

	err = expect_pair(pair, &expected);

hmap_i_set_error:
	hmap_i_clr(&map, NULL);

	err |= expect(map, NULL);

hmap_i_new_error:
	return err;
}

const unit	unit_hmap_hmap_i_get = {
	"hmap_i_get",
	(test[]){
		{"should return NULL on inexistent key", .test=inexistent},
		{"should return stored pair", .test=existent},
		{}
	},
};
