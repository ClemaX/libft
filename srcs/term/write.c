/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:30:06 by chamada           #+#    #+#             */
/*   Updated: 2020/09/25 14:15:43 by chamada          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <term/term.h>

int		term_prewrite(t_term *t, const char *str, size_t n)
{
	if (write(1, str, n) < 0)
		return (0);
	t->cursor.origin.x = n;
	t->cursor.origin.y = 0;
	return (1);
}

int		term_write(t_term *t, const char *str, size_t n)
{
	if (write(1, str, n) <= 0
	|| !(line_insert_at(t->line, t->cursor.pos.x, str, n)))
		return (0);
	t->cursor.pos.x += n;
	return (1);
}

void	term_clear_line(t_term *t)
{
	term_start_line(t);
	tputs(t->caps.c_del_line, 0, &ft_putchar);
}

void	term_clear_screen(t_term *t, int status)
{
	if (t->caps.clear)
	{
		tputs(t->caps.clear, 0, &ft_putchar);
		term_write_prompt(t, status);
		write(1, t->line->data, t->line->length);
		t->cursor.pos.x = t->line->length;
	}
}
