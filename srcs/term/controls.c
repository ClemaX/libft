/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:29:17 by chamada           #+#    #+#             */
/*   Updated: 2020/09/26 15:18:24 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term/term.h>

static int	parse_line(t_term *t, int status)
{
	size_t	i;

	status &= ~TERM_WAITING;
	i = 0;
	while (i < t->line->length)
	{
		if (status & TERM_B_SLASH)
			status &= ~TERM_B_SLASH;
		else if (!(status & TERM_S_QUOTE) && t->line->data[i] == '"')
			status ^= TERM_D_QUOTE;
		else if (!(status & TERM_D_QUOTE) && t->line->data[i] == '\'')
			status ^= TERM_S_QUOTE;
		else if (!(status & TERM_B_SLASH) && t->line->data[i] == '\\')
			status |= TERM_B_SLASH;
		i++;
	}
	return (status);
}

int			term_cancel(t_term *t)
{
	select_clear(&t->caps, &t->cursor, &t->clip.select, t->line);
	*t->line->data = '\0';
	t->line->length = 0;
	return (TERM_NEWLINE | TERM_READING);
}

void		term_stop(t_term *t)
{
	if (t->pid != 0)
		kill(t->pid, SIGSTOP);
}

int			term_new_line(t_term *t, int status)
{
	cursor_end_line(&t->caps, &t->cursor, t->line);
	select_clear(&t->caps, &t->cursor, &t->clip.select, t->line);
	if ((status = parse_line(t, status)) & TERM_WAITING)
		term_write(&t->cursor, t->line, "\n", 1);
	else
	{
		tputs(t->caps.insert_end, 0, &ft_putchar);
		write(1, "\n", 1);
		t->exec(t->line->data, t);
		tputs(t->caps.insert, 0, &ft_putchar);
		if ((!t->hist.next || t->line == t->hist.next)
		&& !(t->hist.next = line_new(10)))
			return ((status | TERM_ERROR) & ~TERM_READING);
		hist_add(&t->hist, t->line);
		t->hist.next->prev = t->hist.last;
		*t->hist.next->data = '\0';
		t->hist.next->length = 0;
		t->hist.curr = t->hist.next;
		t->line = t->hist.next;
		t->cursor.pos.x = 0;
		t->cursor.pos.y = 0;
	}
	term_write_prompt(&t->cursor, status);
	return (status & ~TERM_NEWLINE);
}

int			term_erase(t_term *t, int status)
{
	if (t->cursor.pos.x > 0)
	{
		tputs(t->caps.c_left, 0, &ft_putchar);
		tputs(t->caps.c_del, 0, &ft_putchar);
		t->cursor.pos.x--;
		line_erase_at(t->line, t->cursor.pos.x, 1);
	}
	return (status);
}
