/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:54:04 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:30:01 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <libft/strings.h>

#include <libft/map.h>

static void	mapsplit(t_map *map, t_map **a, t_map **b)
{
	t_map	*slow;
	t_map	*fast;

	slow = map;
	fast = map->next;
	while (fast)
	{
		if ((fast = fast->next))
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*a = map;
	*b = slow->next;
	slow->next = NULL;
}

static void	*mapmergecmp(t_map *a, t_map *b, t_mapcmp_fun *cmp)
{
	t_map	*map;

	if (a == NULL)
		return (b);
	if (b == NULL)
		return (a);
	if (cmp(a, b) > 0)
	{
		map = a;
		map->next = mapmergecmp(a->next, b, cmp);
	}
	else
	{
		map = b;
		map->next = mapmergecmp(a, b->next, cmp);
	}
	return (map);
}

int			map_cmp(t_map *a, t_map *b)
{
	return (ft_strncmp(b->key, a->key, b->key_size));
}

void		map_sort(t_map **map, t_mapcmp_fun *cmp)
{
	t_map	*head;
	t_map	*a;
	t_map	*b;

	head = *map;
	if (head == NULL || head->next == NULL)
		return ;
	mapsplit(head, &a, &b);
	map_sort(&a, cmp);
	map_sort(&b, cmp);
	*map = mapmergecmp(a, b, cmp);
}
