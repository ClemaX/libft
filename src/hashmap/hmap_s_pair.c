#include <stdlib.h>

#include <libft/hmap/hmap_s_pair.h>

/**
 * @brief Add a key-value pair to a t_hmap_s_pair list.
 *
 * @param map	The bucket at the key's index.
 * @param elem 	A key-value pair matching to the key's index,
 */
void			hmap_s_pair_add(t_hmap_s_pair **bucket, t_hmap_s_pair *elem)
{
	elem->next = *bucket;
	*bucket = elem;
}

/**
 * @brief Allocate a new key-value pair.
 *
 * @param key	Index key.
 * @param value	Mapped value.
 * @return t_hmap_s_pair*
 */
t_hmap_s_pair	*hmap_s_pair_new(const char *key, void *value)
{
	t_hmap_s_pair *const pair = malloc(sizeof(*pair));

	if (pair != NULL)
		*pair = (t_hmap_s_pair){key, value, NULL};

	return pair;
}

/**
 * @brief Clear a map's key-value pair list.
 *
 * @param pair	The map's bucket to be cleared,
 * @param del	The value's destructor.
 */
void			hmap_s_pair_clr(t_hmap_s_pair **pair, void(*del(void *)))
{
	t_hmap_s_pair *curr;

	while (*pair != NULL)
	{
		curr = *pair;
		*pair = curr->next;
		if (del != NULL)
			del(curr->value);
		free(curr);
	}
}
