/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sscanf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 17:53:06 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 17:18:11 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>
#include <scanf/specs.h>
#include <scanf/convert.h>

static int	parse_txt(const char **src, const char **fmt)
{
	while (**fmt && **fmt != '%' && **fmt == **src)
	{
		(*fmt)++;
		(*src)++;
	}
	while (ft_isspace(**src))
		(*src)++;
	while (ft_isspace(**fmt))
		(*fmt)++;
	return (**fmt == '%');
}

static int	parse_fmt(const char *src, const char *fmt, va_list ap)
{
	const char	*start = src;
	int			count;
	t_spec		spec;

	count = 0;
	while (parse_txt(&src, &fmt) && *fmt)
	{
		if ((spec = sf_parse_spec(&fmt, ap)).type == ERR)
			return (0);
		else if (spec.type == CNT)
			*(va_arg(ap, int*)) = src - start;
		else if (g_convert[spec.type](&src, spec, ap))
			count++;
		else
			return (count);
	}
	return (count);
}

int			ft_sscanf(const char *src, const char *fmt, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, fmt);
	count = parse_fmt(src, fmt, ap);
	va_end(ap);
	return (count);
}
