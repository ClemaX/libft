/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:30:03 by chamada           #+#    #+#             */
/*   Updated: 2020/11/12 07:27:45 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term/term.h>

int		line_insert_at(t_line *line, size_t at, const char *str, size_t n)
{
	char	*new;
	size_t	new_len;

	if (at > line->length)
		return (0);
	new_len = line->length + n;
	if (new_len + 1 > line->size)
	{
		while (new_len + 1 > line->size)
			line->size *= 2;
		if (!(new = malloc(sizeof(*new) * line->size)))
			return (0);
		ft_strlcpy(new, line->data, line->size);
		free(line->data);
		line->data = new;
	}
	ft_memmove(line->data + at + n, line->data + at, line->length - at);
	ft_memcpy(line->data + at, str, n);
	line->length = new_len;
	line->data[line->length] = '\0';
	return (1);
}

int		line_erase_at(t_line *line, size_t at, size_t n)
{
	if (!line || line->length - at < n)
		return (0);
	if (at == line->length)
		line->length -= n;
	else
	{
		ft_memmove(line->data + at, line->data + at + n, line->length - at - n);
		line->length -= n;
	}
	line->data[line->length] = '\0';
	return (1);
}

void	line_clear(t_line **line)
{
	if (*line)
	{
		free((*line)->data);
		free(*line);
		*line = NULL;
	}
}
