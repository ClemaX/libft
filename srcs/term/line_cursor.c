/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:29:29 by chamada           #+#    #+#             */
/*   Updated: 2020/09/25 14:16:07 by chamada          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <term/term.h>

void	term_left(t_term *t)
{
	if (t->cursor.pos.x > 0)
	{
		t->cursor.pos.x--;
		tputs(t->caps.c_left, 0, &ft_putchar);
	}
}

void	term_right(t_term *t)
{
	if (t->cursor.pos.x < t->line->length)
	{
		t->cursor.pos.x++;
		tputs(t->caps.c_right, 0, &ft_putchar);
	}
}

void	term_start_line(t_term *t)
{
	tputs(tgoto(t->caps.c_move_h, 0, t->cursor.origin.x), 0, &ft_putchar);
	t->cursor.pos.x = 0;
}

void	term_end_line(t_term *t)
{
	if (t->line && t->line->length)
	{
		t->cursor.pos.x = t->line->length;
		tputs(tgoto(t->caps.c_move_h, 0, t->cursor.origin.x + t->cursor.pos.x),
			0, &ft_putchar);
	}
}
