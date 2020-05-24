/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_utils.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 08:35:14 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/26 21:01:35 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include <libft.h>
#include <stdlib.h>

static void	*unload_strs(char **strs, int count)
{
	while (count-- > 0 || *strs)
		free(*strs++);
	return (NULL);
}

const char	*map_add(t_map **map, const char *key, const char *value)
{
	t_map		*new;

	if (!map || !key || !value)
		return (NULL);
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

t_map		*map_load(const char **strs)
{
	t_map	*map;
	char	*key;
	char	*val;

	if (!strs || !*strs)
		return (NULL);
	map = NULL;
	while (*strs)
	{
		if (!(key = ft_strdup(*strs))
		|| !(val = ft_strchr(key, '=')))
		{
			free(key);
			return (NULL);
		}
		*val++ = '\0';
		map_add(&map, key, val);
		free(key);
		strs++;
	}
	return (map);
}

int			map_len(t_map *map)
{
	int	len;

	len = 0;
	while (map)
	{
		len++;
		map = map->next;
	}
	return (len);
}

char		**map_export(t_map *map)
{
	const int	count = map_len(map);
	int			len;
	char		**strs;
	char		**s;

	if (!count || !(strs = malloc(sizeof(*strs) * (count + 1))))
		return (NULL);
	s = strs + count;
	*s-- = NULL;
	while (map)
	{
		len = map->key_size + 1 + ft_strlen(map->value);
		if (!(*s = malloc((sizeof(**s) * len) + 1)))
			return (unload_strs(strs, count + 1));
		ft_memcpy(*s, map->key, map->key_size);
		(*s)[map->key_size] = '=';
		ft_memcpy(&(*s)[map->key_size + 1], map->value, len - map->key_size);
		(*s)[len] = '\0';
		s--;
		map = map->next;
	}
	return (strs);
}
