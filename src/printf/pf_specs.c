/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_specs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 23:35:12 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:32:37 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include <libft/strings.h>
#include <libft/types.h>

#include <libft/printf/specs.h>
#include <libft/printf/numbers.h>

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
	while ((pos = ft_strpos(SPEC_FLAGS, **fmt)) != -1)
	{
		flags |= (1 << pos);
		(*fmt)++;
	}
	if ((flags & (FL_MINUS | FL_ZERO)) == (FL_MINUS | FL_ZERO))
		flags &= ~FL_ZERO;
	return (flags);
}

/*
**	ctx:	The scanf context
**
**	Parse the field width from the format string
*/

static int	parse_width(t_pf_ctx *ctx, unsigned char *flags)
{
	int	width;

	if (*ctx->fmt == '*')
	{
		ctx->fmt++;
		width = va_arg(ctx->ap, int);
		if (width < 0 && *flags & FL_ZERO)
		{
			width = -width;
			*flags |= FL_MINUS;
			*flags &= ~FL_ZERO;
		}
	}
	else
		width = utoa(&ctx->fmt);
	return (width);
}

/*
**	ctx:	The scanf context
**
**	Parse the precision from the format string
**	Note: Negative precision is ignored
*/

static int	parse_precision(t_pf_ctx *ctx)
{
	int precision;

	if (*ctx->fmt != '.')
		return (-1);
	++ctx->fmt;
	if (*ctx->fmt == '*')
	{
		++ctx->fmt;
		precision = va_arg(ctx->ap, int);
	}
	else
		precision = utoa(&ctx->fmt);
	if (precision < 0)
		return (-1);
	return (precision);
}

/*
**	ctx:		The scanf context
**	width:		The argument string
**
**	Parse the format string and initialize a new spec
*/

t_fmt_type	pf_parse_spec(t_pf_ctx *ctx, t_spec *spec)
{
	spec->flags = parse_flags(&ctx->fmt);
	if ((spec->width = parse_width(ctx, &spec->flags)) < 0)
	{
		spec->width = -spec->width;
		spec->flags |= FL_MINUS;
	}
	spec->precision = parse_precision(ctx);
	spec->size = pf_parse_size(ctx);
	spec->type = ft_strpos(SPEC_TYPES, *ctx->fmt++);
	if (spec->type == FMT_PTR)
		spec->flags |= FL_HASH;
	return (spec->type);
}
