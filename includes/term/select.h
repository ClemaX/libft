/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:15:27 by chamada           #+#    #+#             */
/*   Updated: 2020/09/26 15:18:56 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# include <libft.h>
# include <unistd.h>

# include <term/caps.h>
# include <term/cursor.h>
# include <term/line.h>

typedef struct	s_select
{
	t_pos	start;
	t_pos	end;
}				t_select;

/*
**				select.c
*/
void			select_left(t_caps *caps, t_cursor *cursor, t_select *select,
	t_line *line);
void			select_right(t_caps *caps, t_cursor *cursor, t_select *select,
	t_line *line);
void			select_clear(t_caps *caps, t_cursor *cursor, t_select *select,
	t_line *line);

#endif
