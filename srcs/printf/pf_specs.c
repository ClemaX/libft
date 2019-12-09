/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_specs.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/10 23:35:12 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 17:18:31 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <printf/specs.h>
#include <printf/numbers.h>

/*
**	fmt:	The format string
**
**	Parse an usigned integer from the format string
*/

static int	utoa(const char **fmt)
{
	int	number;

	number = 0;
	if (**fmt == '-')
		(*fmt)++;
	while (ft_isdigit(**fmt))
		number = 10 * number + *((*fmt)++) - '0';
	return (number);
}

/*
**	fmt:	The format string
**
**	Parse flags from the format string
**	Note: If MINUS and ZERO are set, ignore ZERO
*/

static char	parse_flags(const char **fmt)
{
	int		pos;
	char	flags;

	flags = 0;
	while ((pos = ft_strpos(FLAGS, **fmt)) != -1)
	{
		flags |= (1 << pos);
		(*fmt)++;
	}
	if ((flags & (MINUS | ZERO)) == (MINUS | ZERO))
		flags &= ~ZERO;
	return (flags);
}

/*
**	fmt:	The format string
**	ap:		The arguments list
**
**	Parse the field width from the format string
*/

static int	parse_width(const char **fmt, va_list ap, unsigned char *flags)
{
	int	width;

	if (**fmt == '*')
	{
		(*fmt)++;
		width = va_arg(ap, int);
		if (width < 0 && *flags & ZERO)
		{
			width = -width;
			*flags |= MINUS;
			*flags &= ~ZERO;
		}
	}
	else
		width = utoa(fmt);
	return (width);
}

/*
**	fmt:	The format string
**	ap:		The arguments list
**
**	Parse the precision from the format string
**	Note: Negative precision is ignored
*/

static int	parse_precision(const char **fmt, va_list ap)
{
	int precision;

	if (**fmt != '.')
		return (-1);
	(*fmt)++;
	if (**fmt == '*')
	{
		(*fmt)++;
		precision = va_arg(ap, int);
	}
	else
		precision = utoa(fmt);
	if (precision < 0)
		return (-1);
	return (precision);
}

/*
**	fmt:		The format string
**	width:		The argument string
**
**	Parse the format string and initialize a new spec
*/

t_spec		pf_parse_spec(const char **fmt, va_list ap)
{
	t_spec	spec;

	spec.flags = parse_flags(fmt);
	if ((spec.width = parse_width(fmt, ap, &spec.flags)) < 0)
	{
		spec.width = -spec.width;
		spec.flags |= MINUS;
	}
	spec.precision = parse_precision(fmt, ap);
	spec.size = parse_size(fmt);
	spec.type = ft_strpos(TYPES, *(*fmt)++);
	if (spec.type == PTR)
		spec.flags |= HASH;
	return (spec);
}
