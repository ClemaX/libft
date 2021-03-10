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

#ifndef NUMBERS_H
# define NUMBERS_H

# include <stdint.h>
# include <printf/specs.h>

# define D_DEC		"0123456789"
# define D_LHEX		"0123456789abcdef"
# define D_UHEX		"0123456789ABCDEF"
# define D_OCT		"01234567"

# define R_DEC		10
# define R_HEX		16
# define R_OCT		8

/*
**					PTR,		DEC,	INT,	UINT,	LHEX,	UHEX,	OCT
*/

# define RADIX_N	7

/*
** # define RADIXES	{R_HEX,		R_DEC,	R_DEC,	R_DEC,	R_HEX,	R_HEX,	R_OCT}
** # define DIGITS	{D_LHEX,	D_DEC,	D_DEC,	D_DEC,	D_LHEX,	D_UHEX,	D_OCT}
*/

typedef struct	s_number
{
	uint64_t	value;
	char		sign;
	int			radix;
	const char	*digits;
	int			len;
	int			padding;
	int			prefix_len;
	char		prefix;
}				t_number;

t_numsize		parse_size(const char **fmt);
t_number		parse_number(va_list ap, t_spec spec);
t_number		convert_signed(va_list ap, t_spec spec);
t_number		convert_unsigned(va_list ap, t_spec spec);

#endif
