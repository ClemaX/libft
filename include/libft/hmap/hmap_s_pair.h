#pragma once

typedef struct	s_hmap_s_pair
{
	const char				*key;
	void					*value;
	struct s_hmap_s_pair	*next;
}				t_hmap_s_pair;

/**
 * @brief Add a string key-value pair to a hash_map list.
 *
 * @param map	The hash-map list at the key's index.
 * @param elem 	A hash-map element matching to the key's index,
 */
void			hmap_s_pair_add(t_hmap_s_pair **bucket, t_hmap_s_pair *elem);

/**
 * @brief Allocate a new string key-value pair.
 *
 * @param key	Index key.
 * @param value	Mapped value.
 * @return hash_map*
 */
t_hmap_s_pair	*hmap_s_pair_new(const char *key, void *value);

/**
 * @brief Clear a string map's key-value pair list.
 *
 * @param pair	The map's bucket to be cleared,
 * @param del	The value's destructor.
 */
void			hmap_s_pair_clr(t_hmap_s_pair **pair, void(del(void *)));
