/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 04:12:10 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:43:53 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdarg.h>
# include <libft.h>
# include <printf/specs.h>
# include <printf/line.h>

t_line	*parse_fmt(const char *fmt, va_list ap);

#endif
