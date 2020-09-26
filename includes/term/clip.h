/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:01:38 by chamada           #+#    #+#             */
/*   Updated: 2020/09/26 15:27:10 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIP_H
# define CLIP_H

# include <libft.h>

# include <term/cursor.h>
# include <term/line.h>
# include <term/select.h>
# include <term/caps.h>
# include <term/write.h>

typedef struct	s_clip
{
	t_line		line;
	t_select	select;
}				t_clip;

/*
**				clip.c
*/
char			*clip_copy(t_cursor *cursor, t_clip *clip, t_line *line);
char			*clip_cut(t_caps *caps, t_cursor *cursor, t_clip *clip,
	t_line *line);
int				clip_paste(t_caps *caps, t_cursor *cursor, t_clip *clip,
	t_line *line);
void			clip_clear(t_clip *clip);

#endif
