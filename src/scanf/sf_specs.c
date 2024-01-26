/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_specs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 23:35:12 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:33:00 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include <libft/types.h>
#include <libft/strings.h>

#include <libft/scanf/specs.h>

/*
**	fmt:	The format string
**
**	Parse an usigned integer from the format string
*/

static int			utoa(const char **fmt)
{
	int	number;

	number = 0;
	if (**fmt == '-')
		(*fmt)++;
	while (ft_isdigit(**fmt))
		number = 10 * number + *(*fmt)++ - '0';
	return (number);
}

static t_numsize	parse_size(t_sf_ctx *ctx)
{
	if (*ctx->fmt == 'l')
	{
		if (*++ctx->fmt == 'l')
		{
			ctx->fmt++;
			return (NUMSZ_LL);
		}
		else
			return (NUMSZ_L);
	}
	else if (*ctx->fmt == 'h')
	{
		if (*++ctx->fmt == 'h')
		{
			ctx->fmt++;
			return (NUMSZ_HH);
		}
		else
			return (NUMSZ_H);
	}
	else
		return (NUMSZ_DEF);
}

/*
**	fmt:	The format string
**
**	Parse flags from the format string
**	Note: If MINUS and ZERO are set, ignore ZERO
*/

static char			parse_flags(const char **fmt)
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
**	Parse the precision from the format string
**	Note: Negative precision is ignored
*/

static int			parse_precision(t_sf_ctx *ctx)
{
	int precision;

	if (*ctx->fmt != '.')
		return (-1);
	ctx->fmt++;
	if (*ctx->fmt == '*')
	{
		ctx->fmt++;
		precision = va_arg(ctx->ap, int);
	}
	else
		precision = utoa(&ctx->fmt);
	if (precision < 0)
		return (-1);
	return (precision);
}

/*
**	ctx:	The scanf context
**	spec:	Parsed sepcification destination
**
**	Parse the format string and initialize a new spec
*/

t_fmt_type			sf_parse_spec(t_sf_ctx *ctx, t_spec *spec)
{
	ctx->fmt++;
	spec->flags = parse_flags(&ctx->fmt);
	if (ft_isdigit(*ctx->fmt))
		spec->width = utoa(&ctx->fmt);
	else
		spec->width = -1;
	spec->precision = parse_precision(ctx);
	spec->size = parse_size(ctx);
	spec->type = ft_strpos(TYPES, *ctx->fmt++);
	if (spec->type == FMT_PTR)
		spec->flags |= HASH;
	return (spec->type);
}
