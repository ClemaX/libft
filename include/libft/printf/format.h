/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:02:48 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:27:37 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <libft/printf/line.h>
#include <libft/printf/specs.h>

typedef int			(*t_pf_fmt_fun)(t_line **line, t_spec spec, va_list *ap);

extern t_pf_fmt_fun	g_format[FMT_ENTRY_COUNT];
