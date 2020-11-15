/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:57:18 by chamada           #+#    #+#             */
/*   Updated: 2020/11/03 13:56:36 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term/term.h>

void	hist_add(t_hist *hist, t_line *line)
{
	// If there was an existing history, link it to the new line
	if (hist->last)
		hist->last->next = line;
	line->prev = hist->last;
	// Link to next also
	line->next = hist->next;

	// Clear next data
	*hist->next->data = '\0';
	hist->next->len = 0;

	// Advance existing history
	hist->last = line;
	hist->next->prev = line;
	hist->curr = hist->next;
}

void	hist_pop(t_hist *hist)
{
	t_line	*prev;

	if (hist->last)
	{
		prev = hist->last->prev;
		line_clear(&hist->last);
		hist->last = prev;
	}
}

void	hist_clear(t_hist *hist)
{
	t_line	*curr;

	while ((curr = hist->last))
	{
		hist->last = curr->prev;
		line_clear(&curr);
	}
}

void	hist_commit(t_hist *hist, t_line *line)
{
	free(hist->curr->data);
	hist->curr->data = line->data;
	hist->curr->len = line->len;
	hist->curr->size = line->size;
}
