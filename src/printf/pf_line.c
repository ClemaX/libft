/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:25:00 by chamada           #+#    #+#             */
/*   Updated: 2020/11/12 10:48:36 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <libft/memory.h>
#include <libft/printf/line.h>

/*
**	line:		The line to add content on
**	content:	The content to add
**	size:		The size of the content
**
**	Add content to the line elements list
**	Note: This function has no effect when size == 0
*/

t_line	*line_add(t_line **line, char *content, int size)
{
	t_line *new;

	if ((size && !content) || !(new = malloc(sizeof(*new))))
		return (NULL);
	new->content = content;
	new->size = size;
	new->next = *line;
	return ((*line = new));
}

/*
**	line:		The line to clear
**
**	Free every list element of the line and set its pointer to NULL
*/

t_line	*line_clr(t_line **line)
{
	t_line	*curr;

	while ((curr = *line))
	{
		*line = (*line)->next;
		free(curr->content);
		free(curr);
	}
	return (NULL);
}

/*
**	line:		The line to measure
**
**	Get the total length of a line
*/

size_t	line_len(const t_line *line)
{
	const t_line	*curr;
	size_t			len;

	len = 0;
	curr = line;
	while (curr)
	{
		len += curr->size;
		curr = curr->next;
	}
	return (len);
}

/*
**	dest:		The destination string
**	line:		The line to copy
**	alloc:		Boolean flag to allocate the string
**
**	Copy a line into a string, clearing it's content and returning it's length
**	Note: Returns -1 in case of error
*/

size_t	line_put(char **dest, t_line **line, char alloc)
{
	const size_t	len = line_len(*line);
	t_line			*curr;

	if (alloc && !(*dest = malloc(sizeof(**dest) * (len + 1))))
	{
		line_clr(line);
		return (-1);
	}
	*dest += len;
	**dest = '\0';
	curr = *line;
	while (curr)
	{
		*dest -= curr->size;
		ft_memcpy(*dest, curr->content, curr->size);
		curr = curr->next;
	}
	line_clr(line);
	return (len);
}
