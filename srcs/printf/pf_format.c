/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_format.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 21:47:21 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 16:51:50 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <libft.h>
#include <printf/specs.h>
#include <printf/line.h>
#include <printf/numbers.h>

static int	fmt_char(t_line **line, t_spec spec, va_list ap)
{
	const int	len = (spec.width > 1) ? spec.width : 1;
	const char	c = (spec.type == PCNT) ? '%' : va_arg(ap, unsigned);
	char		*content;

	if (!len)
		return (1);
	if (!(content = malloc(sizeof(*content) * len)))
		return (0);
	ft_memset(content, (spec.flags & ZERO) ? '0' : ' ', len);
	content[spec.flags & MINUS ? 0 : len - 1] = c;
	return (line_add(line, content, len) != NULL);
}

static int	fmt_str(t_line **line, t_spec spec, va_list ap)
{
	const char	*str = va_arg(ap, char*);
	const char	*src = (str) ? str : "(null)";
	int			srclen;
	int			len;
	char		*content;

	if (spec.precision == 0 && spec.width == 0)
		return (line_add(line, NULL, 0) != NULL);
	srclen = ft_strlen(src);
	if (spec.precision >= 0 && spec.precision < srclen)
		srclen = spec.precision;
	if (!(len = (spec.width > srclen) ? spec.width : srclen))
		return (1);
	if (!(content = malloc(sizeof(*content) * len)))
		return (0);
	ft_memset(content, (spec.flags & ZERO) ? '0' : ' ', len);
	ft_memcpy(content + (len - srclen) * !(spec.flags & MINUS), src, srclen);
	return (line_add(line, content, len) != NULL);
}

static void	write_num(char *dest, t_number number)
{
	dest += number.len + number.prefix_len - 1;
	while (number.len--)
	{
		*dest-- = number.digits[number.value % number.radix];
		number.value /= number.radix;
	}
	if (number.prefix)
		*dest-- = number.prefix;
	if ((number.prefix_len - (number.sign != '\0')) > 0)
		*dest-- = '0';
	if (number.sign)
		*dest = number.sign;
}

static int	fmt_num(t_line **line, t_spec s, va_list ap)
{
	const t_number	n = parse_number(ap, s);
	const int		len = n.padding + n.prefix_len + n.len;
	const char		p = ((s.flags & ZERO) && s.precision == -1) ? '0' : ' ';
	char			*content;

	if (!len)
		return (1);
	if (!(content = malloc(sizeof(*content) * len)))
		return (0);
	ft_memset(&content[(s.flags & MINUS) ? len - n.padding : 0], p, n.padding);
	write_num(&content[(s.flags & MINUS) ? 0 : n.padding], n);
	return (line_add(line, content, len) != NULL);
}

/*
**	line:	The line to add content on
**	spec:	The format specification
**	ap:		The variable-arguments list
**
**	Format each variable according to specification
**	Note: Types are dispatched in following order: cs%pdiuxXon
*/

int				(*g_format[10])(t_line**, t_spec, va_list) = {
	fmt_char,
	fmt_str,
	fmt_char,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_num
};
