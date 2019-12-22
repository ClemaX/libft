/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   specs.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 04:45:20 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 18:20:01 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SPECS_H
# define SPECS_H

# include <stdarg.h>

# define FLAGS	"-+ 0#*m"

# define MINUS	(1 << 0)
# define PLUS	(1 << 1)
# define SPACE	(1 << 2)
# define ZERO	(1 << 3)
# define HASH	(1 << 4)
# define STAR	(1 << 5)
# define ALLOC	(1 << 6)

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
