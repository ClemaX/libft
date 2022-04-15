#include <stddef.h>
#include <stdlib.h>

#include <libft/memory.h>
#include <libft/strings.h>
#include <libft/hmap/hmap_i.h>

/**
 * @brief Hash an input into a number in the range [0 - map_size].
 *
 * @param input		The integer to be hashed.
 * @param map_size	The containing map's size.
 * @return size_t	The hashed value.
 */
static size_t	hash_function(t_hmap_int key, size_t map_size)
{
	return (key % map_size);
}

/**
 * @brief Allocate a t_hmap_i for a given size.
 *
 * @param size	The maximal amount of elements.
 * @return t_hmap_i*
 */
t_hmap_i		*hmap_i_new(size_t size)
{
	t_hmap_i *const map = malloc(sizeof(*map) + sizeof(*map->buckets) * size);

	if (map != NULL)
	{
		map->size = size;
		map->buckets = (t_hmap_i_pair **)(map + 1);

		ft_bzero(map->buckets, sizeof(*map->buckets) * size);
	}
	return (map);
}

/**
 * @brief Get a value from a key in a hash map.
 *
 * Returns NULL if inexistent.
 * @param map	The hash-map in which to find the value.
 * @param key	The key associated to the value.
 * @return t_hmap_i_pair*
 */
t_hmap_i_pair		*hmap_i_get(const t_hmap_i *const map, t_hmap_int key)
{
	const size_t index = hash_function(key, map->size);
	t_hmap_i_pair *pair = map->buckets[index];

	if (pair != NULL && pair->next != NULL)
		while (pair != NULL && pair->key != key)
			pair = pair->next;
	return (pair);
}

#include <libft/printf.h>

/**
 * @brief Set a value for a key in a hash map.
 *
 * @param map	The hash-map in which to set the value.
 * @param key	The key used to retrieve the value.
 * @param value	The value to be set.
 * @return const t_hmap_i_pair*
 */
t_hmap_i_pair		*hmap_i_set(t_hmap_i *map, t_hmap_int key,
	void *const value)
{
	const size_t index = hash_function(key, map->size);
	t_hmap_i_pair **bucket = map->buckets + index;
	t_hmap_i_pair *pair = *bucket;

	while (pair != NULL && pair->key != key)
		pair = pair->next;
	if (pair == NULL)
	{
		pair = hmap_i_pair_new(key, value);

		if (pair != NULL)
		{
			pair->next = *bucket;
			*bucket = pair;
		}
	}
	else
		pair->value = value;
	return (pair);
}

/**
 * @brief Free the map's memory and set it's pointer to NULL.
 *
 * @param map	A reference to the map to be cleared.
 * @param del	The value's destructor.
 */
void				hmap_i_clr(t_hmap_i **map, void(del(void *)))
{
	size_t	i;

	if (*map)
	{
		i = 0;
		while (i < (*map)->size)
		{
			hmap_i_pair_clr((*map)->buckets + i, del);
			i++;
		}
		free(*map);
		*map = NULL;
	}
}
