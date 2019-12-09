/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 18:22:46 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 17:18:24 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include <printf/specs.h>
#include <printf/line.h>
#include <printf/format.h>

/*
**	fmt:	The format string
**	line:	The line on which to add text
**
**	Put the non-format parts of the format string into the line
**	Note: Returns 1 as long as there is content left
*/

static int		parse_txt(const char **fmt, t_line **line)
{
	char	*next;

	if ((next = ft_strchr(*fmt, '%')))
	{
		if (next != *fmt)
			if (!line_add(line, ft_substr(*fmt, 0, next - *fmt), next - *fmt))
			{
				line_clr(line);
				return (0);
			}
		*fmt = next + 1;
		return (1);
	}
	if (!line_add(line, ft_strdup(*fmt), ft_strlen(*fmt)))
		line_clr(line);
	return (0);
}

/*
**	fmt:	The format string
**	ap:		The variadic arguments list
**
**	Parse the format, converting the arguments and building a line
*/

static t_line	*parse_fmt(const char *fmt, va_list ap)
{
	t_spec	spec;
	t_line	*line;
	int		*cnt;

	line = NULL;
	while (parse_txt(&fmt, &line) && *fmt)
	{
		if ((spec = pf_parse_spec(&fmt, ap)).type == ERR)
			return (line_clr(&line));
		else if (spec.type == CNT)
		{
			if ((cnt = va_arg(ap, int*)))
				*cnt = line_len(line);
		}
		else if (!g_format[spec.type](&line, spec, ap))
			return (line_clr(&line));
	}
	return (line);
}

int				ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_line	*line;
	char	*str;
	int		len;

	va_start(ap, fmt);
	line = parse_fmt(fmt, ap);
	va_end(ap);
	if ((!line || (len = line_put(&str, &line)) < 0))
		return (-1);
	write(1, str, len);
	free(str);
	return (len);
}
