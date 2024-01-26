/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 04:20:17 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:32:31 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/strings.h>

#include <libft/printf/format.h>

/*
**	fmt:	The format string
**	line:	The line on which to add text
**
**	Put the non-format parts of the format string into the line
**	Note: Returns 1 as long as there is content left
*/

static int	parse_txt(t_pf_ctx *ctx)
{
	const char	*next;

	if ((next = ft_strchr(ctx->fmt, '%')))
	{
		if (next != ctx->fmt
			&& !line_add(&ctx->line, ft_substr(ctx->fmt, 0, next - ctx->fmt), next - ctx->fmt))
		{
			line_clr(&ctx->line);
			return (0);
		}
		ctx->fmt = next + 1;
		return (1);
	}
	if (!line_add(&ctx->line, ft_strdup(ctx->fmt), ft_strlen(ctx->fmt)))
		line_clr(&ctx->line);
	return (0);
}

/*
**	ctx:	The printf context
**
**	Parse the format, converting the arguments and building a line
**
**	Note: The ctx's fmt, ap and line must be initialized
**	The line can either point to an existing list or to NULL
*/

t_line		*pf_parse_fmt(t_pf_ctx *ctx)
{
	t_spec	spec;
	int		*cnt;

	while (parse_txt(ctx) && *ctx->fmt)
	{
		if (pf_parse_spec(ctx, &spec) == FMT_ERR)
			return (line_clr(&ctx->line));
		if (spec.type == FMT_CNT)
		{
			if ((cnt = va_arg(ctx->ap, int*)))
				*cnt = line_len(ctx->line);
		}
		else if (!g_formatters[spec.type](ctx, &spec))
			return (line_clr(&ctx->line));
	}
	return (ctx->line);
}
