/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:57:39 by chamada           #+#    #+#             */
/*   Updated: 2020/09/26 15:15:09 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term/select.h>

void	highlight(t_caps *caps, t_cursor *cursor, t_select *select,
	t_line *line)
{
	if (select->start.x != -1U && select->end.x != -1U)
	{
		ft_dprintf(2, "[SELECT] start: %d, end: %d\n",
			select->start.x, select->end.x);
		tputs(tgoto(caps->c_move_h, 0, cursor->origin.x), 0, &ft_putchar);
		tputs(caps->c_del_line, 0, &ft_putchar);
		write(1, line->data, select->start.x);
		tputs(caps->standout, 0, &ft_putchar);
		write(1, line->data + select->start.x,
			select->end.x - select->start.x);
		tputs(caps->standout_end, 0, &ft_putchar);
		write(1, line->data + select->end.x,
			line->length - select->end.x);
		tputs(tgoto(caps->c_move_h, 0, cursor->origin.x + cursor->pos.x),
			0, &ft_putchar);
	}
}

void	select_left(t_caps *caps, t_cursor *cursor, t_select *select,
	t_line *line)
{
	if (cursor->pos.x > 0)
	{
		if (select->start.x == -1U || select->end.x == -1U)
		{
			select->start.x = cursor->pos.x;
			select->end.x = cursor->pos.x;
		}
		else
		{
			cursor_l(caps, cursor);
			if (select->start.x == cursor->pos.x + 1)
				select->start.x = cursor->pos.x;
			else
				select->end.x = cursor->pos.x;
			highlight(caps, cursor, select, line);
		}
	}
}

void	select_right(t_caps *caps, t_cursor *cursor, t_select *select,
	t_line *line)
{
	if (cursor->pos.x < line->length)
	{
		if (select->start.x == -1U || select->end.x == -1U)
		{
			select->start.x = cursor->pos.x;
			select->end.x = cursor->pos.x;
		}
		else
		{
			cursor_r(caps, cursor, line);
			if (select->end.x == cursor->pos.x - 1)
				select->end.x = cursor->pos.x;
			else
				select->start.x = cursor->pos.x;
			highlight(caps, cursor, select, line);
		}
	}
}

void	select_clear(t_caps *caps, t_cursor *cursor, t_select *select,
	t_line *line)
{
	if (select->start.x != -1U || select->end.x != -1U)
	{
		ft_dprintf(2, "[SELECT] clear\n");
		select->start.x = -1U;
		select->end.x = -1U;
		if (line)
		{
			tputs(tgoto(caps->c_move_h, 0, cursor->origin.x),
				0, &ft_putchar);
			tputs(caps->c_del_line, 0, &ft_putchar);
			write(1, line->data, line->length);
			tputs(tgoto(caps->c_move_h, 0,
				cursor->origin.x + cursor->pos.x), 0, &ft_putchar);
		}
	}
}
