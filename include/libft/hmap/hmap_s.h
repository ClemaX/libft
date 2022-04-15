#pragma once

#include <stddef.h>

#include <libft/hmap/hmap_s_pair.h>

typedef struct	s_hmap_s
{
	t_hmap_s_pair	**buckets;
	size_t			size;
}				t_hmap_s;

/**
 * @brief Allocate a string hash map for a given size.
 *
 * @param size	The maximal amount of elements.
 * @return hmap_s*
 */
t_hmap_s		*hmap_s_new(size_t size);

/**
 * @brief Get a value from a key in a hash map.
 *
 * Returns NULL if inexistent
 * @param map	The hash-map in which to find the value.
 * @param key	The key associated to the value.
 * @return t_hmap_s_pair*
 */
t_hmap_s_pair	*hmap_s_get(const t_hmap_s *const map, const char *key);

/**
 * @brief Set a value for a key in a string hash map.
 *
 * @param map	The hash-map in which to set the value.
 * @param key	The key used to retrieve the value.
 * @param value	The value to be set.
 * @return const t_hmap_s_pair*
 */
t_hmap_s_pair	*hmap_s_set(t_hmap_s *map, const char *key,
	void *const value);

/**
 * @brief Free the map's memory and set it's pointer to NULL.
 *
 * @param map	A reference to the map to be cleared.
 * @param del	The value's destructor.
 */
void			hmap_s_clr(t_hmap_s **map, void(*del(void *)));
