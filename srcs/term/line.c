/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:30:00 by chamada           #+#    #+#             */
/*   Updated: 2020/09/26 15:15:07 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term/line.h>

t_line	*line_dup(t_line *line)
{
	t_line	*new;

	if (!line || !(new = malloc(sizeof(*new))))
		return (NULL);
	new->size = line->size;
	if (!(new->data = malloc(sizeof(*new->data) * new->size)))
	{
		free(new);
		return (NULL);
	}
	ft_memcpy(new->data, line->data, line->len);
	new->len = line->len;
	new->data[new->len] = '\0';
	return (new);
}

t_line	*line_new(size_t size)
{
	t_line	*line;

	if (!(line = malloc(sizeof(*line))))
		return (NULL);
	line->size = size;
	if (!(line->data = malloc(sizeof(*line->data) * line->size)))
	{
		free(line);
		return (NULL);
	}
	line->len = 0;
	*line->data = '\0';
	line->next = NULL;
	line->prev = NULL;
	return (line);
}

void	line_add_back(t_line **line_list, t_line *line)
{
	t_line	*current;

	if (line)
	{
		if (*line_list)
		{
			current = *line_list;
			while (current->next)
				current = current->next;
			current->next = line;
		}
		else
			*line_list = line;
	}
}

size_t	line_count(t_line *line_list)
{
	size_t	count;

	count = 0;
	while (line_list)
	{
		line_list = line_list->next;
		count++;
	}
	return (count);
}
