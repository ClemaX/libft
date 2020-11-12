/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:30:06 by chamada           #+#    #+#             */
/*   Updated: 2020/11/12 05:31:55 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term/term.h>

void	term_write_prompt(t_term *t, int status)
{
	if (status & TERM_WAITING)
		term_prewrite(t, "> ", 2);
	else
		term_prewrite(t, TERM_PS1, sizeof(TERM_PS1) - 1);
}

int		term_prewrite(t_term *t, const char *str, size_t n)
{
	if (write(2, str, n) < 0)
		return (0);
	t->cursor.origin.x = n;
	t->cursor.origin.y = 0;
	return (n);
}

int		term_write(t_term *t, const char *str, size_t n)
{
	if ((t->interactive && write(1, str, n) <= 0)
	|| !(line_insert_at(t->line, t->cursor.pos.x, str, n)))
		return (0);
	t->cursor.pos.x += n;
	return (n);
}

void	term_clear_line(t_term *t)
{
	cursor_start_line(&t->caps, &t->cursor);
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
