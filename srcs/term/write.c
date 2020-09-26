/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:30:06 by chamada           #+#    #+#             */
/*   Updated: 2020/09/26 15:15:14 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term/term.h>

void	term_write_prompt(t_cursor *cursor, int status)
{
	if (status & TERM_WAITING)
		term_prewrite(cursor, "> ", 2);
	else
		term_prewrite(cursor, TERM_PS1, sizeof(TERM_PS1) - 1);
}

int		term_prewrite(t_cursor *cursor, const char *str, size_t n)
{
	if (write(1, str, n) < 0)
		return (0);
	cursor->origin.x = n;
	cursor->origin.y = 0;
	return (n);
}

int		term_write(t_cursor *cursor, t_line *line, const char *str, size_t n)
{
	if (write(1, str, n) <= 0
	|| !(line_insert_at(line, cursor->pos.x, str, n)))
		return (0);
	cursor->pos.x += n;
	return (n);
}

void	term_clear_line(t_caps *caps, t_cursor *cursor)
{
	cursor_start_line(caps, cursor);
	tputs(caps->c_del_line, 0, &ft_putchar);
}

void	term_clear_screen(t_caps *caps, t_cursor *cursor, t_line *line,
	int status)
{
	if (caps->clear)
	{
		tputs(caps->clear, 0, &ft_putchar);
		term_write_prompt(cursor, status);
		write(1, line->data, line->length);
		cursor->pos.x = line->length;
	}
}
