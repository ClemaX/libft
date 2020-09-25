/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:30:00 by chamada           #+#    #+#             */
/*   Updated: 2020/09/25 14:15:45 by chamada          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <term/term.h>

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
	ft_memcpy(new->data, line->data, line->length);
	new->length = line->length;
	new->data[new->length] = '\0';
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
	line->length = 0;
	*line->data = '\0';
	line->next = NULL;
	line->prev = NULL;
	return (line);
}
