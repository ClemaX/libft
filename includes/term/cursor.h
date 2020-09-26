/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 12:36:25 by chamada           #+#    #+#             */
/*   Updated: 2020/09/26 15:25:38 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_H
# define CURSOR_H

# include <libft.h>

# include <term/caps.h>
# include <term/line.h>

typedef struct	s_pos
{
	unsigned	x;
	unsigned	y;
}				t_pos;

typedef struct	s_cursor
{
	t_pos	pos;
	t_pos	origin;
}				t_cursor;

/*
**				cursor.c
*/
void			cursor_l(t_caps *caps, t_cursor *cursor);
void			cursor_r(t_caps *caps, t_cursor *cursor, t_line *line);
void			cursor_start_line(t_caps *caps, t_cursor *cursor);
void			cursor_end_line(t_caps *caps, t_cursor *cursor, t_line *line);

#endif
