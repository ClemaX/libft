#pragma once

#include <stddef.h>
#include <sys/types.h>

typedef ssize_t	t_hmap_int;

typedef struct	s_hmap_i_pair
{
	struct s_hmap_i_pair	*next;
	t_hmap_int				key;
	void					*value;
}				t_hmap_i_pair;


/**
 * @brief Add an integer key-value pair to a hash_map list.
 *
 * @param map	The hash-map list at the key's index.
 * @param elem 	A hash-map element matching to the key's index,
 */
void			hmap_i_pair_add(t_hmap_i_pair **bucket, t_hmap_i_pair *elem);

/**
 * @brief Allocate a new integer key-value pair.
 *
 * @param key	Index key.
 * @param value	Mapped value.
 * @return hash_map*
 */
t_hmap_i_pair	*hmap_i_pair_new(t_hmap_int i, void *value);

/**
 * @brief Clear an integer map's key-value pair list.
 *
 * @param pair	The map's bucket to be cleared,
 * @param del	The value's destructor.
 */
void			hmap_i_pair_clr(t_hmap_i_pair **pair, void(del(void *)));
