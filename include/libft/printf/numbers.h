/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:09:47 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:43:10 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>

#include <libft/printf/specs.h>

#define R_DEC		10
#define R_HEX		16
#define R_OCT		8

/*
**					PTR,		DEC,	INT,	UINT,	LHEX,	UHEX,	OCT
*/

#define RADIX_N		7

/*
** #define RADIXES	{R_HEX,		R_DEC,	R_DEC,	R_DEC,	R_HEX,	R_HEX,	R_OCT}
** #define DIGITS	{D_LHEX,	D_DEC,	D_DEC,	D_DEC,	D_LHEX,	D_UHEX,	D_OCT}
*/

typedef struct	s_integer
{
	uintmax_t	value;
	const char	*digits;
	int			radix;
	int			len;
	int			padding;
	int			prefix_len;
	char		lowercase;
	char		sign;
	char		prefix;
}				t_integer;

t_numsize		pf_parse_size(t_pf_ctx *ctx);
t_integer		pf_parse_number(t_pf_ctx *ctx, const t_spec *spec);
t_integer		pf_convert_signed(t_pf_ctx *ctx, const t_spec *spec);
t_integer		pf_convert_unsigned(t_pf_ctx *ctx, const t_spec *spec);
