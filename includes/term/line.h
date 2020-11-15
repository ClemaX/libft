/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 12:29:43 by chamada           #+#    #+#             */
/*   Updated: 2020/09/26 15:27:35 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include <stdlib.h>

typedef struct	s_line
{
	char			*data;
	size_t			len;
	size_t			size;
	struct s_line	*next;
	struct s_line	*prev;
}				t_line;

/*
**				line.c
*/
t_line			*line_dup(t_line *line);
t_line			*line_new(size_t size);

/*
**				line_edit.c
*/
int				line_insert(t_line *line, size_t at, const char *str, size_t n);
int				line_erase(t_line *line, size_t at, size_t n);
void			line_clear(t_line **line);

#endif
