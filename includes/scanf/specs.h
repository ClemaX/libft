/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   specs.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 04:45:20 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 07:11:46 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SPECS_H
# define SPECS_H

# include <stdarg.h>

# define FLAGS	"-+ 0#*m"

# define MINUS	0b00000001
# define PLUS	0b00000010
# define SPACE	0b00000100
# define ZERO	0b00001000
# define HASH	0b00010000
# define STAR	0b00100000
# define ALLOC	0b01000000

# define TYPES	"cs%pdiuxXon"

typedef unsigned char	t_flags;

typedef enum			e_type
{
	ERR = -1, CHAR, STR, PCNT, PTR, DEC, INT, UINT, LHEX, UHEX, OCT, CNT
}						t_type;

typedef enum			e_numsize
{
	S_DEF, S_L, S_LL, S_H, S_HH
}						t_numsize;

typedef struct			s_spec
{
	t_flags		flags;
	int			width;
	int			precision;
	t_type		type;
	t_numsize	size;
}						t_spec;

t_spec					sf_parse_spec(const char **fmt, va_list ap);

#endif
