/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 02:59:12 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:17:19 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	32
# endif

# define GNL_CONTINUE	1
# define GNL_END		0
# define GNL_ERROR		-1
# define GNL_NL			2

typedef struct	s_words
{
	char			*content;
	size_t			size;
	struct s_words	*next;
}				t_words;

typedef struct	s_fd
{
	int				fd;
	char			*buffer;
	size_t			position;
	struct s_fd		*next;
}				t_fd;

int				get_next_line(int fd, char **line);
int				search_end(char *s, size_t size, char **end);
void			clear_fds(t_fd **fd_list);
void			clear_words(t_words *words);
t_fd			*del_fd(t_fd *curr, int fd);

#endif
