/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:29:52 by chamada           #+#    #+#             */
/*   Updated: 2020/09/25 14:47:59 by chamada          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <term/term.h>

int			term_read(t_term *t, int status)
{
	int		ret;
	char	c;

	ret = read(0, &c, 1);
	if (ret == 0)
		return (status & ~TERM_READING);
	if (ret == -1)
		return ((status | TERM_ERROR) & ~TERM_READING);
	if (c == '\033')
		return (term_read_escape(t, status));
	if (ft_iscntrl(c))
		return (term_read_control(t, status, c));
	select_clear(t);
	if (!term_write(t, &c, 1))
		return ((status | TERM_ERROR) & ~TERM_READING);
	return (status);
}
