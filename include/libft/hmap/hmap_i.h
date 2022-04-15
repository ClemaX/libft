#pragma once

#include <libft/hmap/hmap_i_pair.h>

typedef struct	s_hmap_i
{
	t_hmap_i_pair	**buckets;
	size_t			size;
}				t_hmap_i;

/**
 * @brief Allocate an integer hash map for a given size.
 *
 * @param size	The maximal amount of elements.
 * @return hmap_i*
 */
t_hmap_i		*hmap_i_new(size_t size);

/**
 * @brief Get a value from a key in a hash map.
 *
 * Returns NULL if inexistent
 * @param map	The hash-map in which to find the value.
 * @param key	The key associated to the value.
 * @return t_hmap_i_pair*
 */
t_hmap_i_pair	*hmap_i_get(const t_hmap_i *const map, t_hmap_int key);

/**
 * @brief Set a value for a key in an integer hash map.
 *
 * @param map	The hash-map in which to set the value.
 * @param key	The key used to retrieve the value.
 * @param value	The value to be set.
 * @return const t_hmap_i_pair*
 */
t_hmap_i_pair	*hmap_i_set(t_hmap_i *map, t_hmap_int key,
	void *const value);

/**
 * @brief Free the map's memory and set it's pointer to NULL.
 *
 * @param map	A reference to the map to be cleared.
 * @param del	The value's destructor.
 */
void			hmap_i_clr(t_hmap_i **map, void(*del(void *)));
