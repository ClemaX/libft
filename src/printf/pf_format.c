/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:47:21 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:32:05 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <libft/memory.h>
#include <libft/strings.h>

#include <libft/printf/format.h>
#include <libft/printf/numbers.h>

static int	fmt_char(t_pf_ctx *ctx, const t_spec *spec)
{
	const int	len = (spec->width > 1) ? spec->width : 1;
	const char	c = (spec->type == FMT_PCNT) ? '%' : va_arg(ctx->ap, unsigned);
	char		*content;

	if (!len)
		return (1);
	if (!(content = malloc(sizeof(*content) * len)))
		return (0);
	ft_memset(content, (spec->flags & FL_ZERO) ? '0' : ' ', len);
	content[spec->flags & FL_MINUS ? 0 : len - 1] = c;
	return (line_add(&ctx->line, content, len) != NULL);
}

static int	fmt_str(t_pf_ctx *ctx, const t_spec *spec)
{
	const char	*str = va_arg(ctx->ap, char*);
	const char	*src = (str) ? str : "(null)";
	int			srclen;
	int			len;
	char		*content;

	if (spec->precision == 0 && spec->width == 0)
		return (line_add(&ctx->line, NULL, 0) != NULL);
	srclen = ft_strlen(src);
	if (spec->precision >= 0 && spec->precision < srclen)
		srclen = spec->precision;
	if (!(len = (spec->width > srclen) ? spec->width : srclen))
		return (1);
	if (!(content = malloc(sizeof(*content) * len)))
		return (0);
	ft_memset(content, (spec->flags & FL_ZERO) ? '0' : ' ', len);
	ft_memcpy(content + (len - srclen) * !(spec->flags & FL_MINUS), src, srclen);
	return (line_add(&ctx->line, content, len) != NULL);
}

static void	write_num(char *dest, t_integer number)
{
	char	digit;
	dest += number.len + number.prefix_len - 1;
	while (number.len--)
	{
		digit = number.digits[number.value % number.radix];
		if (number.lowercase && digit >= 'A' && digit <= 'Z')
			digit |= 1 << 5;
		*dest-- = digit;
		number.value /= number.radix;
	}
	if (number.prefix)
		*dest-- = number.prefix;
	if ((number.prefix_len - (number.sign != '\0')) > 0)
		*dest-- = '0';
	if (number.sign)
		*dest = number.sign;
}

static int	fmt_num(t_pf_ctx *ctx, const t_spec *s)
{
	const t_integer	n = pf_parse_number(ctx, s);
	const int		len = n.padding + n.prefix_len + n.len;
	const char		p = ((s->flags & FL_ZERO) && s->precision == -1) ? '0' : ' ';
	char			*content;

	if (!len)
		return (1);
	if (!(content = malloc(sizeof(*content) * len)))
		return (0);
	ft_memset(&content[(s->flags & FL_MINUS) ? len - n.padding : 0], p, n.padding);
	write_num(&content[(s->flags & FL_MINUS) ? 0 : n.padding], n);
	return (line_add(&ctx->line, content, len) != NULL);
}

/*
**	line:	The line to add content on
**	spec:	The format specification
**	ap:		The variable-arguments list
**
**	Format each variable according to specification
**	Note: Types are dispatched in following order: cs%pdiuxXon
*/

t_pf_fmt_fun g_formatters[FMT_ENTRY_COUNT] = {
	fmt_char,
	fmt_str,
	fmt_char,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_num,
	NULL,
};
