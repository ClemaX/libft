/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_special.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 21:13:17 by chamada           #+#    #+#             */
/*   Updated: 2020/11/12 05:17:46 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term/term.h>


// TODO: Implement home and end
// TODO: Implement del key (delete to the right)

static int	handle_alt_escape(t_term *t, int status)
{
	int		ret;
	char	c[3];

	ret = read(0, c, 3);
	if (ret == 0)
		return (status & ~TERM_READING);
	if (ret == -1)
		return ((status | TERM_ERROR) & ~TERM_READING);
	if (ret != 3)
		return (status);
	if (c[1] == '2')
	{
		if (c[2] == t->caps.k_left[2])
			select_left(t);
		else if (c[2] == t->caps.k_right[2])
			select_right(t);
		return (status | TERM_SELECT);
	}
	else if (c[1] == '5')
		ft_dprintf(2, "[PROMPT] ctrl + %c\n", c[2]);
	return (status);
}

static int	handle_control_custom(t_term *t, int status, char c)
{
	if (c == 'h' - 'a' + 1)
		return (status | TERM_ERASE);
	if (c == 'l' - 'a' + 1)
		return (status | TERM_CLEAR);
	if (c == '\n')
		return (status | TERM_NEWLINE);
	if (c == 'a' - 'a' + 1)
		cursor_start_line(&t->caps, &t->cursor);
	else if (c == 'e' - 'a' + 1)
		cursor_end_line(&t->caps, &t->cursor, t->line);
	else if (c == 'y' - 'a' + 1)
		clip_paste(t);
	else if (c == 'k' - 'a' + 1)
		clip_cut(t);
	else if (c == 'p' - 'a' + 1)
		term_up(t);
	else if (c == 'n' - 'a' + 1)
		term_down(t);
	if (c != '\n')
	{
		ft_dprintf(2, "[PROMPT] ctrl + %c (%d)\n", c + 'a' - 1, c);
		return (status | TERM_IGNORE);
	}
	return (status);
}

static void	handle_arrow_keys(t_term *t, char *c)
{
	if (c[1] == t->caps.k_up[2])
		term_up(t);
	else if (c[1] == t->caps.k_down[2])
		term_down(t);
	else if (c[1] == t->caps.k_left[2])
		cursor_l(&t->caps, &t->cursor);
	else if (c[1] == t->caps.k_right[2])
		cursor_r(&t->caps, &t->cursor, t->line);
}

int			term_read_control(t_term *t, int status, char c)
{
	if (c == t->s_ios.c_cc[VINTR])
		return (status | TERM_INT);
	if (c == t->s_ios.c_cc[VERASE])
		return (status | TERM_ERASE);
	if (c == t->s_ios.c_cc[VEOF])
		return (status | TERM_EOF);
	if (c == t->s_ios.c_cc[VSTOP])
		return (status | TERM_STOP);
	if (c == t->s_ios.c_cc[VSUSP])
		return (status | TERM_SUSPEND);
	return (handle_control_custom(t, status, c));
}

int			term_read_escape(t_term *t, int status)
{
	int		ret;
	char	c[2];

	ret = read(0, c, 2);
	if (ret == 0)
		return (status & ~TERM_READING);
	if (ret == -1)
		return ((status | TERM_ERROR) & ~TERM_READING);
	if (ret != 2)
		return (status);
	if (c[1] == '1')
		return (handle_alt_escape(t, status));
	if (status & TERM_SELECT)
	{
		status &= ~TERM_SELECT;
		select_clear(t);
	}
	handle_arrow_keys(t, c);
	return (status);
}
