/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 03:02:45 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:29:28 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory.h>
#include <gnl.h>

#include <gnl/get_next_line.h>

static char	*get_line(t_words *words)
{
	t_words	*curr;
	char	*line;
	size_t	size;

	size = 1;
	curr = words;
	while (curr)
	{
		size += curr->size;
		curr = curr->next;
	}
	if (!(line = malloc(size)))
		return (NULL);
	line += size - 1;
	*line = '\0';
	curr = words;
	while (curr)
	{
		line -= curr->size;
		ft_memcpy(line, curr->content, curr->size);
		curr = curr->next;
	}
	clear_words(words);
	return (line);
}

static t_fd	*get_fd(t_fd **fd_list, int fd)
{
	t_fd	*curr;

	curr = *fd_list;
	while (curr)
	{
		if (curr->fd == fd)
			return (curr);
		curr = curr->next;
	}
	if (!((curr = malloc(sizeof(*curr)))
	&& (curr->buffer = malloc(BUFFER_SIZE))))
	{
		free(curr);
		return (NULL);
	}
	curr->fd = fd;
	curr->position = 0;
	curr->next = *fd_list;
	return ((*fd_list = curr));
}

static int	add_words(t_words **words, char *content, size_t size)
{
	t_words *new;

	if (!size)
		return (1);
	if (!(new = malloc(sizeof(*new))))
		return (GNL_ERROR);
	if (!(new->content = malloc(size)))
	{
		free(new);
		return (GNL_ERROR);
	}
	new->size = size;
	ft_memcpy(new->content, content, size);
	new->next = *words;
	*words = new;
	return (GNL_CONTINUE);
}

static int	gnl_parse(t_fd *fd, t_words **words, size_t size)
{
	char	*buffer;
	char	*end;
	int		state;

	if (size != BUFFER_SIZE)
		fd->buffer[size] = '\0';
	buffer = fd->buffer + fd->position;
	size -= fd->position;
	fd->position = 0;
	if ((state = search_end(buffer, size, &end)) != GNL_CONTINUE)
	{
		size = end - buffer;
		if (size < BUFFER_SIZE - 1 && fd->buffer[size + 1] != '\0')
			fd->position = end - fd->buffer + 1;
	}
	return (add_words(words, buffer, size) != GNL_ERROR ? state : GNL_ERROR);
}

int			get_next_line(int fd, char **line)
{
	static t_fd	*fd_list;
	t_fd		*curr_fd;
	t_words		*words;
	ssize_t		size;
	int			state;

	if (!line || fd < 0)
		return (GNL_ERROR);
	words = NULL;
	curr_fd = get_fd(&fd_list, fd);
	state = (curr_fd) ? GNL_CONTINUE : GNL_ERROR;
	if (state == GNL_CONTINUE && curr_fd->position)
		state = gnl_parse(curr_fd, &words, BUFFER_SIZE);
	size = 0;
	while (state == 1 && (size = read(fd, curr_fd->buffer, BUFFER_SIZE)) > 0)
		state = gnl_parse(curr_fd, &words, size);
	if (size == -1 || state == GNL_ERROR || !(*line = get_line(words)))
	{
		clear_fds(&fd_list);
		clear_words(words);
		return (GNL_ERROR);
	}
	if (state != GNL_NL)
		fd_list = del_fd(fd_list, fd);
	return (state == GNL_NL || (state == GNL_END && !size));
}
