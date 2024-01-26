/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:53:06 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:32:55 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/scanf/ctx.h"
#include <stdarg.h>

#include <libft/types.h>

#include <libft/scanf/convert.h>

static int	parse_txt(t_sf_ctx *ctx, const char **src)
{
	while (*ctx->fmt && *ctx->fmt != '%' && *ctx->fmt == **src)
	{
		ctx->fmt++;
		(*src)++;
	}
	while (ft_isspace(**src))
		(*src)++;
	while (ft_isspace(*ctx->fmt))
		ctx->fmt++;
	return (*ctx->fmt == '%');
}

static int	parse_fmt(t_sf_ctx *ctx, const char *src)
{
	const char	*start = src;
	int			count;
	t_spec		spec;

	count = 0;
	while (parse_txt(ctx, &src) && *ctx->fmt)
	{
		if (sf_parse_spec(ctx, &spec) == FMT_ERR)
			return (0);
		else if (spec.type == FMT_CNT)
			*(va_arg(ctx->ap, int*)) = src - start;
		else if (g_converters[spec.type](ctx, &src, &spec))
			count++;
		else
			return (count);
	}
	return (count);
}

int			ft_sscanf(const char *src, const char *fmt, ...)
{
	t_sf_ctx	ctx = {
		.fmt = fmt,
	};
	int			count;

	va_start(ctx.ap, fmt);
	count = parse_fmt(&ctx, src);
	va_end(ctx.ap);
	return (count);
}
