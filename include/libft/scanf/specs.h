/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 04:45:20 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:44:00 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdarg.h>

#include <libft/scanf/ctx.h>

#define FLAGS	"-+ 0#*m"

#define MINUS	1
#define PLUS	2
#define SPACE	4
#define ZERO	8
#define HASH	16
#define STAR	32
#define ALLOC	64

#define TYPES	"cs%pdiuxXon"

typedef unsigned char	t_flags;

typedef enum			e_fmt_type
{
	FMT_ERR = -1,
	FMT_CHAR,
	FMT_STR,
	FMT_PCNT,
	FMT_PTR,
	FMT_DEC,
	FMT_INT,
	FMT_UINT,
	FMT_LHEX,
	FMT_UHEX,
	FMT_OCT,
	FMT_CNT,
	FMT_ENTRY_COUNT,
}						t_fmt_type;

typedef enum			e_numsize
{
	NUMSZ_DEF, NUMSZ_L, NUMSZ_LL, NUMSZ_H, NUMSZ_HH
}						t_numsize;

typedef struct			s_spec
{
	t_flags		flags;
	int			width;
	int			precision;
	t_fmt_type	type;
	t_numsize	size;
}						t_spec;

t_fmt_type				sf_parse_spec(t_sf_ctx *ctx, t_spec *spec);
