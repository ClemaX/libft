#pragma once

#include <stddef.h>

typedef struct	s_map
{
	char			*key;
	size_t			key_size;
	char			*value;
	struct s_map	*next;
}				t_map;

typedef int		(t_mapcmp_fun(const t_map *a, const t_map *b));

const char		*map_set(t_map **map, const char *key, const char *value);
t_map			*map_get(t_map *map, const char *key);
void			map_delone(t_map *elem);
t_map			*map_del(t_map *map, const char *key);
void			map_clr(t_map **map);
t_map			*map_load(const char **strs);
char			**map_export(t_map *map);
void			map_sort(t_map **map, t_mapcmp_fun *cmp);
int				map_cmp(t_map *a, t_map *b);
