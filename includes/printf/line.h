/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:07:54 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:27:40 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include <stddef.h>

typedef struct	s_line
{
	char			*content;
	size_t			size;
	struct s_line	*next;
}				t_line;

t_line			*line_add(t_line **line, char *content, int size);
t_line			*line_clr(t_line **line);
int				line_len(t_line *line);
int				line_put(char **dest, t_line **line, char alloc);

#endif
