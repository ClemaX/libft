/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 03:03:04 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 17:11:15 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <gnl/get_next_line.h>

int		search_end(char *s, size_t size, char **end)
{
	while (size && *s && *s != '\n' && size--)
		s++;
	if (size)
		return ((*(*end = s) == '\0') ? END : NEW_LINE);
	*end = NULL;
	return (CONTINUE);
}

t_fd	*del_fd(t_fd *curr, int fd)
{
	t_fd	*next;

	if (!curr)
		return (NULL);
	if (curr->fd == fd)
	{
		next = curr->next;
		free(curr->buffer);
		free(curr);
		return (next);
	}
	curr->next = del_fd(curr->next, fd);
	return (curr);
}

void	clear_fds(t_fd **fd_list)
{
	t_fd	*curr;

	if (fd_list)
	{
		while ((curr = *fd_list))
		{
			*fd_list = curr->next;
			free(curr->buffer);
			free(curr);
		}
	}
}

void	clear_words(t_words *words)
{
	t_words	*curr;

	while ((curr = words))
	{
		words = words->next;
		free(curr->content);
		free(curr);
	}
}
