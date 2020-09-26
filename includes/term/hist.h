/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 12:31:02 by chamada           #+#    #+#             */
/*   Updated: 2020/09/26 15:19:56 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIST_H
# define HIST_H

# include <term/line.h>

typedef struct	s_hist
{
	t_line	*last;
	t_line	*curr;
	t_line	*next;
}				t_hist;

/*
**				hist.c
*/
void			hist_add(t_hist *hist, t_line *line);
void			hist_pop(t_hist *hist);
void			hist_clear(t_hist *hist);
void			hist_commit(t_hist *hist, t_line *line);

#endif
