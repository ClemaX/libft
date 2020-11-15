/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:29:29 by chamada           #+#    #+#             */
/*   Updated: 2020/09/26 15:15:03 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term/cursor.h>

void	cursor_l(t_caps *caps, t_cursor *cursor)
{
	if (cursor->pos.x > 0)
	{
		cursor->pos.x--;
		tputs(caps->c_left, 0, &ft_putchar);
	}
}

void	cursor_r(t_caps *caps, t_cursor *cursor, t_line *line)
{
	if (cursor->pos.x < line->len)
	{
		cursor->pos.x++;
		tputs(caps->c_right, 0, &ft_putchar);
	}
}

void	cursor_start_line(t_caps *caps, t_cursor *cursor)
{
	tputs(tgoto(caps->c_move_h, 0, cursor->origin.x), 0, &ft_putchar);
	cursor->pos.x = 0;
}

void	cursor_end_line(t_caps *caps, t_cursor *cursor, t_line *line)
{
	if (line && line->len)
	{
		cursor->pos.x = line->len;
		tputs(tgoto(caps->c_move_h, 0, cursor->origin.x + cursor->pos.x),
			0, &ft_putchar);
	}
}
