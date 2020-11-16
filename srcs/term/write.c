/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:30:06 by chamada           #+#    #+#             */
/*   Updated: 2020/11/13 07:50:08 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term/term.h>

// TODO: Expand PS1 and PS2 using string_expand.
void	term_write_prompt(t_term *t, int status)
{
	const char	*ps;

	if (t->interactive)
	{
		ps = env_get(t->env, (status & TERM_WAITING) ? "PS2" : "PS1", 3);
			term_prewrite(t, ps, ft_strlen(ps));
		if (t->caps.enabled)
			tputs(t->caps.insert, 0, &ft_putchar);
	}
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
	|| !line_insert(t->line, t->cursor.pos.x, str, n))
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
		write(1, t->line->data, t->line->len);
		t->cursor.pos.x = t->line->len;
	}
}
