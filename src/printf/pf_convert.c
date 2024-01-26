/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 00:52:00 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:32:02 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <sys/types.h>

#include <libft/printf/numbers.h>

t_numsize	pf_parse_size(t_pf_ctx *ctx)
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
	else if (*ctx->fmt == 'z')
	{
		ctx->fmt++;
		return (NUMSZ_Z);
	}
	else if (*ctx->fmt == 'j')
	{
		ctx->fmt++;
		return (NUMSZ_J);
	}
	else
		return (NUMSZ_DEF);
}

t_integer	pf_convert_signed(t_pf_ctx *ctx, const t_spec *spec)
{
	t_integer	number;
	int64_t		value;

	if (spec->size == NUMSZ_HH)
		value = (signed char)va_arg(ctx->ap, int);
	else if (spec->size == NUMSZ_H)
		value = (short)va_arg(ctx->ap, int);
	else if (spec->size == NUMSZ_L)
		value = va_arg(ctx->ap, long);
	else if (spec->size == NUMSZ_LL)
		value = va_arg(ctx->ap, long long);
	else if (spec->size == NUMSZ_Z)
		value = va_arg(ctx->ap, ssize_t);
	else if (spec->size == NUMSZ_J)
		value = va_arg(ctx->ap, uintmax_t);
	else
		value = va_arg(ctx->ap, int);
	if (value < 0)
		number.sign = '-';
	else if (spec->flags & FL_PLUS)
		number.sign = '+';
	else if (spec->flags & FL_SPACE)
		number.sign = ' ';
	else
		number.sign = '\0';
	number.value = (number.sign == '-') ? -value : value;
	return (number);
}

t_integer	pf_convert_unsigned(t_pf_ctx *ctx, const t_spec *spec)
{
	t_integer	number;

	if (spec->type == FMT_PTR)
		number.value = (uintptr_t)va_arg(ctx->ap, void*);
	else if (spec->size == NUMSZ_HH)
		number.value = (unsigned char)va_arg(ctx->ap, int);
	else if (spec->size == NUMSZ_H)
		number.value = (unsigned short)va_arg(ctx->ap, int);
	else if (spec->size == NUMSZ_L)
		number.value = va_arg(ctx->ap, long);
	else if (spec->size == NUMSZ_L)
		number.value = va_arg(ctx->ap, unsigned long);
	else if (spec->size == NUMSZ_LL)
		number.value = va_arg(ctx->ap, unsigned long long);
	else if (spec->size == NUMSZ_Z)
		number.value = va_arg(ctx->ap, size_t);
	else if (spec->size == NUMSZ_J)
		number.value = va_arg(ctx->ap, uintmax_t);
	else
		number.value = va_arg(ctx->ap, unsigned int);
	number.sign = '\0';
	return (number);
}
