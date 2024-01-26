/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 04:45:20 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:38:56 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <libft/printf/ctx.h>

#define SPEC_FLAGS	"-+ 0#"

#define FL_MINUS	1
#define FL_PLUS		2
#define FL_SPACE	4
#define FL_ZERO		8
#define FL_HASH		16

#define SPEC_TYPES	"cs%pdiuxXon"

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
	NUMSZ_DEF,
	NUMSZ_L,
	NUMSZ_LL,
	NUMSZ_H,
	NUMSZ_HH,
	NUMSZ_Z,
	NUMSZ_J,
}						t_numsize;

typedef struct			s_spec
{
	t_flags		flags;
	int			width;
	int			precision;
	t_fmt_type	type;
	t_numsize	size;
}						t_spec;

t_fmt_type				pf_parse_spec(t_pf_ctx *ctx, t_spec *spec);
