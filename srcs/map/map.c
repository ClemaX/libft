/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:55:30 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:29:58 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

t_map		*map_get(t_map *map, const char *key)
{
	while (map && ft_strncmp(map->key, key, map->key_size))
		map = map->next;
	return (map);
}

const char	*map_set(t_map **map, const char *key, const char *value)
{
	t_map		*new;
	char		*new_val;

	if (!map || !key || !value)
		return (NULL);
	if ((new = map_get(*map, key)))
	{
		if (!(new_val = ft_strdup(value)))
			return (NULL);
		free(new->value);
		return ((new->value = new_val));
	}
	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	*new = (t_map){.key=ft_strdup(key), .key_size=ft_strlen(key),
		.value=ft_strdup(value), .next=*map};
	if (!new->key || !new->value)
	{
		map_delone(new);
		return (NULL);
	}
	return ((*map = new)->value);
}

void		map_delone(t_map *elem)
{
	if (elem)
	{
		free(elem->key);
		free(elem->value);
		free(elem);
	}
}

t_map		*map_del(t_map *curr, const char *key)
{
	t_map	*next;

	if (!curr)
		return (NULL);
	if (ft_strncmp(curr->key, key, curr->key_size) == 0)
	{
		next = curr->next;
		free(curr->key);
		free(curr->value);
		free(curr);
		return (next);
	}
	curr->next = map_del(curr->next, key);
	return (curr);
}

void		map_clr(t_map **map)
{
	t_map	*next;

	while (*map)
	{
		next = (*map)->next;
		map_delone(*map);
		*map = next;
	}
	*map = NULL;
}
