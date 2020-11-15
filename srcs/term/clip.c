/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:28:58 by chamada           #+#    #+#             */
/*   Updated: 2020/11/12 05:22:52 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term/term.h>

char	*clip_copy(t_term *t)
{
	if (t->clip.select.start.x != -1U && t->clip.select.end.x != -1U)
	{
		free(t->clip.line.data);
		t->clip.line.data = NULL;
		t->clip.line.len = t->clip.select.end.x - t->clip.select.start.x;
		if (!t->clip.line.len || !t->line)
			return (NULL);
		ft_dprintf(2, "[CLIPBD] Copy %ld chars from %s at %d\n",
			t->clip.line.len, (t->line) ? t->line->data : NULL, t->cursor.pos.x);
		if (!(t->clip.line.data = ft_substr(t->line->data,
		t->clip.select.start.x, t->clip.line.len)))
			return (NULL);
		t->cursor.pos.x = t->clip.select.start.x;
		t->clip.line.size = t->clip.line.len + 1;
		t->clip.line.next = NULL;
		t->clip.line.prev = NULL;
	}
	return (t->clip.line.data);
}

char	*clip_cut(t_term *t)
{
	if (t->clip.select.start.x != -1U && t->clip.select.end.x != -1U)
	{
		if (!clip_copy(t))
			return (NULL);
		tputs(tgoto(t->caps.c_move_h, 0, t->cursor.origin.x + t->cursor.pos.x),
			0, &ft_putchar);
		tputs(t->caps.c_del_n, t->clip.line.len, &ft_putchar);
		ft_dprintf(2, "[CLIPBD] Cut %ld chars from %s at %d\n",
			t->clip.line.len, (t->line) ? t->line->data : NULL, t->cursor.pos.x);
		// TODO: Fix line_erase with full line
		line_erase(t->line, t->cursor.pos.x, t->clip.line.len);
		select_clear(t);
	}
	return (t->clip.line.data);
}

int		clip_paste(t_term *t)
{
	if (!t->clip.line.len)
		return (0);
	select_clear(t);
	ft_dprintf(2, "[CLIPBD] Paste %ld chars to %s at %d\n", t->clip.line.len,
		t->line->data, t->cursor.pos.x);
	term_write(t, t->clip.line.data, t->clip.line.len);
	return (1);
}

void	clip_clear(t_term *t)
{
	t->clip.line.len = 0;
	t->clip.line.size = 0;
	free(t->clip.line.data);
	t->clip.line.data = NULL;
}
