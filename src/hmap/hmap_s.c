#include <stddef.h>
#include <stdlib.h>

#include <libft/memory.h>
#include <libft/strings.h>
#include <libft/hmap/hmap_s.h>

/**
 * @brief Hash an input into a number in the range [0 - map_size].
 *
 * @param input		The c-string to be hashed.
 * @param map_size	The containing map's size.
 * @return size_t	The hashed value.
 */
static size_t	hash_function(const char *input, size_t map_size)
{
	size_t acc = 0;

	while (*input != '\0')
		acc += *input++;

	return acc % map_size;
}

/**
 * @brief Allocate a t_hmap_s for a given size.
 *
 * @param size	The maximal amount of elements.
 * @return t_hmap_s*
 */
t_hmap_s		*hmap_s_new(size_t size)
{
	t_hmap_s *const map = malloc(sizeof(*map) + sizeof(*map->buckets) * size);

	if (map != NULL)
	{
		map->size = size;
		map->buckets = (t_hmap_s_pair **)(map + 1);

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
 * @return t_hmap_s_pair*
 */
t_hmap_s_pair		*hmap_s_get(const t_hmap_s *const map, const char *key)
{
	const size_t index = hash_function(key, map->size);
	t_hmap_s_pair *pair = map->buckets[index];

	if (pair != NULL)
		while (pair != NULL && ft_strcmp(pair->key, key) != 0)
			pair = pair->next;
	return (pair);
}

/**
 * @brief Set a value for a key in a hash map.
 *
 * @param map	The hash-map in which to set the value.
 * @param key	The key used to retrieve the value.
 * @param value	The value to be set.
 * @return const t_hmap_s_pair*
 */
t_hmap_s_pair		*hmap_s_set(t_hmap_s *map, const char *key,
	void *const value)
{
	const size_t index = hash_function(key, map->size);
	t_hmap_s_pair **bucket = map->buckets + index;
	t_hmap_s_pair *pair = *bucket;

	while (pair != NULL && ft_strcmp(pair->key, key) != 0)
		pair = pair->next;
	if (pair == NULL)
	{
		pair = hmap_s_pair_new(key, value);

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
void				hmap_s_clr(t_hmap_s **map, void(del(void *)))
{
	size_t	i;
	if (*map)
	{
		i = 0;
		while (i < (*map)->size)
		{
			hmap_s_pair_clr((*map)->buckets + i, del);
			i++;
		}
		free(*map);
		*map = NULL;
	}
}
