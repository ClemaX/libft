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

#include <stdarg.h>

#define FLAGS	"-+ 0#"

#define MINUS	1
#define PLUS	2
#define SPACE	4
#define ZERO	8
#define HASH	16

#define TYPES	"cs%pdiuxXon"

typedef unsigned char	t_flags;

typedef enum			e_type
{
	ERR = -1, CHAR, STR, PCNT, PTR, DEC, INT, UINT, LHEX, UHEX, OCT, CNT
}						t_type;

typedef enum			e_numsize
{
	S_DEF, S_L, S_LL, S_H, S_HH, S_Z
}						t_numsize;

typedef struct			s_spec
{
	t_flags		flags;
	int			width;
	int			precision;
	t_type		type;
	t_numsize	size;
}						t_spec;

t_spec					pf_parse_spec(const char **fmt, va_list ap);
