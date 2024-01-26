/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:02:48 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:28:51 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdarg.h>

#include <libft/scanf/specs.h>

typedef int			(*t_sf_cvt_fun)(t_sf_ctx *ctx, const char **src, const t_spec *spec);

extern t_sf_cvt_fun	g_converters[FMT_ENTRY_COUNT];
