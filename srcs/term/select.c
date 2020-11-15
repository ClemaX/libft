/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:57:39 by chamada           #+#    #+#             */
/*   Updated: 2020/11/12 05:16:15 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term/term.h>

void	highlight(t_term *t)
{
	if (t->clip.select.start.x != -1U && t->clip.select.end.x != -1U)
	{
		ft_dprintf(2, "[SELECT] start: %d, end: %d\n",
			t->clip.select.start.x, t->clip.select.end.x);
		tputs(tgoto(t->caps.c_move_h, 0, t->cursor.origin.x), 0, &ft_putchar);
		tputs(t->caps.c_del_line, 0, &ft_putchar);
		write(1, t->line->data, t->clip.select.start.x);
		tputs(t->caps.standout, 0, &ft_putchar);
		write(1, t->line->data + t->clip.select.start.x,
			t->clip.select.end.x - t->clip.select.start.x);
		tputs(t->caps.standout_end, 0, &ft_putchar);
		write(1, t->line->data + t->clip.select.end.x,
			t->line->len - t->clip.select.end.x);
		tputs(tgoto(t->caps.c_move_h, 0, t->cursor.origin.x + t->cursor.pos.x),
			0, &ft_putchar);
	}
}

void	select_left(t_term *t)
{
	if (t->cursor.pos.x > 0)
	{
		if (t->clip.select.start.x == -1U || t->clip.select.end.x == -1U)
		{
			t->clip.select.start.x = t->cursor.pos.x;
			t->clip.select.end.x = t->cursor.pos.x;
		}
		else
		{
			cursor_l(&t->caps, &t->cursor);
			if (t->clip.select.start.x == t->cursor.pos.x + 1)
				t->clip.select.start.x = t->cursor.pos.x;
			else
				t->clip.select.end.x = t->cursor.pos.x;
			highlight(t);
		}
	}
}

void	select_right(t_term *t)
{
	if (t->cursor.pos.x < t->line->len)
	{
		if (t->clip.select.start.x == -1U || t->clip.select.end.x == -1U)
		{
			t->clip.select.start.x = t->cursor.pos.x;
			t->clip.select.end.x = t->cursor.pos.x;
		}
		else
		{
			cursor_r(&t->caps, &t->cursor, t->line);
			if (t->clip.select.end.x == t->cursor.pos.x - 1)
				t->clip.select.end.x = t->cursor.pos.x;
			else
				t->clip.select.start.x = t->cursor.pos.x;
			highlight(t);
		}
	}
}

void	select_clear(t_term *t)
{
	if (t->clip.select.start.x != -1U || t->clip.select.end.x != -1U)
	{
		ft_dprintf(2, "[SELECT] clear\n");
		t->clip.select.start.x = -1U;
		t->clip.select.end.x = -1U;
		if (t->line)
		{
			tputs(tgoto(t->caps.c_move_h, 0, t->cursor.origin.x),
				0, &ft_putchar);
			tputs(t->caps.c_del_line, 0, &ft_putchar);
			write(1, t->line->data, t->line->len);
			tputs(tgoto(t->caps.c_move_h, 0,
				t->cursor.origin.x + t->cursor.pos.x), 0, &ft_putchar);
		}
	}
}
