/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:28:58 by chamada           #+#    #+#             */
/*   Updated: 2020/09/26 15:16:37 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term/clip.h>

char	*clip_copy(t_cursor *cursor, t_clip *clip, t_line *line)
{
	if (clip->select.start.x != -1U && clip->select.end.x != -1U)
	{
		free(clip->line.data);
		clip->line.data = NULL;
		clip->line.length = clip->select.end.x - clip->select.start.x;
		if (!clip->line.length || !line)
			return (NULL);
		ft_dprintf(2, "[CLIPBD] Copy %ld chars from %s at %d\n",
			clip->line.length, (line) ? line->data : NULL, cursor->pos.x);
		if (!(clip->line.data = ft_substr(line->data,
		clip->select.start.x, clip->line.length)))
			return (NULL);
		cursor->pos.x = clip->select.start.x;
		clip->line.size = clip->line.length + 1;
		clip->line.next = NULL;
		clip->line.prev = NULL;
	}
	return (clip->line.data);
}

char	*clip_cut(t_caps *caps, t_cursor *cursor, t_clip *clip, t_line *line)
{
	if (clip->select.start.x != -1U && clip->select.end.x != -1U)
	{
		if (!clip_copy(cursor, clip, line))
			return (NULL);
		tputs(tgoto(caps->c_move_h, 0, cursor->origin.x + cursor->pos.x),
			0, &ft_putchar);
		tputs(caps->c_del_n, clip->line.length, &ft_putchar);
		ft_dprintf(2, "[CLIPBD] Cut %ld chars from %s at %d\n",
			clip->line.length, (line) ? line->data : NULL, cursor->pos.x);
		// TODO: Fix line_erase_at with full line
		line_erase_at(line, cursor->pos.x, clip->line.length);
		select_clear(caps, cursor, &clip->select, line);
	}
	return (clip->line.data);
}

int		clip_paste(t_caps *caps, t_cursor *cursor, t_clip *clip, t_line *line)
{
	if (!clip->line.length)
		return (0);
	select_clear(caps, cursor, &clip->select, line);
	ft_dprintf(2, "[CLIPBD] Paste %ld chars to %s at %d\n", clip->line.length,
		line->data, cursor->pos.x);
	term_write(cursor, line, clip->line.data, clip->line.length);
	return (1);
}

void	clip_clear(t_clip *clip)
{
	clip->line.length = 0;
	clip->line.size = 0;
	free(clip->line.data);
	clip->line.data = NULL;
}
