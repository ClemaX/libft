/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:47:21 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:32:57 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

#include <libft/numbers.h>
#include <libft/strings.h>
#include <libft/types.h>
#include <libft/scanf/convert.h>

/*
**	Warning: The WILDCARD/STAR flag does increment the match count!
*/

static int	cvt_char(t_sf_ctx *ctx, const char **src, const t_spec *spec)
{
	char	c;

	if (!**src)
		return (0);
	if (spec->type == FMT_PCNT)
		return (*(*src)++ == '%');
	if (spec->size == NUMSZ_DEF)
		c = *(*src)++;
	else
		return (0);
	if (!(spec->flags & STAR))
		*(va_arg(ctx->ap, char*)) = c;
	return (1);
}

static int	cvt_str(t_sf_ctx *ctx, const char **src, const t_spec *spec)
{
	char	*dest;
	char	*next;
	int		len;

	next = ft_strchr(*src, ' ');
	len = (next) ? (size_t)(next - *src) : ft_strlen(*src);
	if (spec->width != -1 && spec->width < len)
		len = spec->width;
	if (!(spec->flags & STAR))
	{
		if (spec->flags & ALLOC)
		{
			if (!(dest = malloc(sizeof(*dest) * (len + 1))))
				return (0);
			*(va_arg(ctx->ap, char**)) = dest;
		}
		else
			dest = va_arg(ctx->ap, char*);
		ft_strlcpy(dest, *src, len + 1);
	}
	*src += len;
	return (1);
}

static int	cvt_num(t_sf_ctx *ctx, const char **src, const t_spec *spec)
{
	int	i;

	if (spec->size == NUMSZ_DEF && (ft_isdigit(**src) || ft_issign(**src)))
	{
		i = ft_atoi(*src);
		*src += ft_numlen(i, 10);
	}
	else
		return (0);
	*(va_arg(ctx->ap, int*)) = i;
	return (1);
}

/*
**	Format each variable according to specification
**	Note: Types are dispatched in following order: cs%pdiuxXon
*/

t_sf_cvt_fun g_converters[FMT_ENTRY_COUNT] = {
	cvt_char,
	cvt_str,
	cvt_char,
	cvt_num,
	cvt_num,
	cvt_num,
	cvt_num,
	cvt_num,
	cvt_num,
	cvt_num
};
