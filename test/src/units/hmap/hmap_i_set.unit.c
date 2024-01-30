#include <stddef.h>
#include <stdio.h>
#include <unit.h>
#include <expect.h>

#include <libft/hmap/hmap_i.h>

#define		expect_pair(_actual, _expected) \
	(assert((_actual) != NULL) \
	|| expect((_actual)->key, (_expected)->key) \
	| expect((_actual)->value, (_expected)->value))

typedef struct		args
{
	const t_hmap_i_pair	*assignations;
	const t_hmap_i_pair	*expected;
}					args;

static int	run(const struct args *args)
{
	t_hmap_i			*map = hmap_i_new(16);
	t_hmap_i_pair		*pair;
	int					err;

	err = assert(map != NULL);
	if (err)
		goto hmap_i_new_error;

	for (const t_hmap_i_pair *it = args->assignations; it->next; ++it)
	{
		pair = hmap_i_set(map, it->key, it->value);
		err |= expect_pair(pair, it);
	}

	for (const t_hmap_i_pair *it = args->expected; it->next; ++it)
	{
		pair = hmap_i_get(map, it->key);
		err = expect_pair(pair, it);
	}

	hmap_i_clr(&map, NULL);

	err |= expect(map, NULL);

hmap_i_new_error:
	return err;
}

const unit	unit_hmap_hmap_i_set = {
	"hmap_i_set",
	(test[]){
		it("should store a single value", (t_hmap_i_pair[]){
			{.next = (void*)1, .key = 42, .value = (void*)0x65},
			{}
		},
		(t_hmap_i_pair[]){
			{.next = (void*)1, .key = 42, .value = (void*)0x65},
			{}
		}),
		it("should store and override a single value", (t_hmap_i_pair[]){
			{.next = (void*)1, .key = 42, .value = (void*)0x65},
			{.next = (void*)1, .key = 42, .value = (void*)0x800},
			{.next = (void*)1, .key = 43, .value = (void*)0x800},
			{.next = (void*)1, .key = 42, .value = (void*)0x64},
			{}
		},
		(t_hmap_i_pair[]){
			{.next = (void*)1, .key = 43, .value = (void*)0x800},
			{.next = (void*)1, .key = 42, .value = (void*)0x64},
			{}
		}),
		it("should store multiple values", (t_hmap_i_pair[]){
			{.next = (void*)1, .key = 42, .value = (void*)0x42},
			{.next = (void*)1, .key = 0x42, .value = (void*)0x2000},
			{.next = (void*)1, .key = 101, .value = (void*)0x32},
			{.next = (void*)1, .key = 0x101, .value = (void*)0x65},
			{}
		},
		(t_hmap_i_pair[]){
			{.next = (void*)1, .key = 42, .value = (void*)0x42},
			{.next = (void*)1, .key = 0x42, .value = (void*)0x2000},
			{.next = (void*)1, .key = 101, .value = (void*)0x32},
			{.next = (void*)1, .key = 0x101, .value = (void*)0x65},
			{}
		}),
		it("should store multiple values 2", (t_hmap_i_pair[]){
			{.next = (void*)1, .key = 1000, .value = (void*)0x2000},
			{.next = (void*)1, .key = 0, .value = (void*)0x42},
			{}
		},
		(t_hmap_i_pair[]){
			{.next = (void*)1, .key = 1000, .value = (void*)0x2000},
			{.next = (void*)1, .key = 0, .value = (void*)0x42},
			{}
		}),
		{}
	},
};
