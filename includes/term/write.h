/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:13:54 by chamada           #+#    #+#             */
/*   Updated: 2020/09/26 15:20:24 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE_H
# define WRITE_H

# include <stdlib.h>

# include <term/caps.h>
# include <term/cursor.h>
# include <term/line.h>

/*
**				write.c
*/
void			term_write_prompt(t_cursor *cursor, int status);
int				term_prewrite(t_cursor *cursor, const char *str, size_t n);
int				term_write(t_cursor *cursor, t_line *line,
	const char *str, size_t n);
void			term_clear_line(t_caps *caps, t_cursor *cursor);
void			term_clear_screen(t_caps *caps, t_cursor *cursor, t_line *line,
	int status);

#endif
