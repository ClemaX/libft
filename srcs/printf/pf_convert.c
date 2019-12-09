/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_convert.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 00:52:00 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 16:51:43 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <printf/numbers.h>
#include <libft.h>

t_numsize	parse_size(const char **fmt)
{
	if (**fmt == 'l')
	{
		if (*++(*fmt) == 'l')
		{
			(*fmt)++;
			return (S_LL);
		}
		else
			return (S_L);
	}
	else if (**fmt == 'h')
	{
		if (*++(*fmt) == 'h')
		{
			(*fmt)++;
			return (S_HH);
		}
		else
			return (S_H);
	}
	else
		return (S_DEF);
}

t_number	convert_signed(va_list ap, t_spec spec)
{
	t_number	number;
	int64_t		value;

	if (spec.size == S_HH)
		value = (signed char)va_arg(ap, int);
	else if (spec.size == S_H)
		value = (short)va_arg(ap, int);
	else if (spec.size == S_L)
		value = va_arg(ap, long);
	else if (spec.size == S_LL)
		value = va_arg(ap, long long);
	else
		value = va_arg(ap, int);
	if (value < 0)
		number.sign = '-';
	else if (spec.flags & PLUS)
		number.sign = '+';
	else if (spec.flags & SPACE)
		number.sign = ' ';
	else
		number.sign = '\0';
	number.value = (number.sign == '-') ? -value : value;
	return (number);
}

t_number	convert_unsigned(va_list ap, t_spec spec)
{
	t_number	number;

	if (spec.type == PTR)
		number.value = (uintptr_t)va_arg(ap, void*);
	else if (spec.size == S_HH)
		number.value = (unsigned char)va_arg(ap, int);
	else if (spec.size == S_H)
		number.value = (unsigned short)va_arg(ap, int);
	else if (spec.size == S_L)
		number.value = va_arg(ap, long);
	else if (spec.size == S_L)
		number.value = va_arg(ap, unsigned long);
	else if (spec.size == S_LL)
		number.value = va_arg(ap, unsigned long long);
	else
		number.value = va_arg(ap, unsigned int);
	number.sign = '\0';
	return (number);
}
