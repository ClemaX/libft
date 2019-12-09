/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 02:59:12 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 17:11:06 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# define CONTINUE 1
# define END 0
# define ERROR -1
# define NEW_LINE 2

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
