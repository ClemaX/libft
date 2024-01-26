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

#pragma once

#include <stddef.h>

typedef struct	s_line
{
	struct s_line	*next;
	char			*content;
	size_t			size;
}				t_line;

t_line			*line_add(t_line **line, char *content, int size);
t_line			*line_clr(t_line **line);
size_t			line_len(const t_line *line);
size_t			line_put(char **dest, t_line **line, char alloc);
