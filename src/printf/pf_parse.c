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

static int	parse_txt(const char **fmt, t_line **line)
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

t_line		*parse_fmt(const char *fmt, va_list *ap)
{
	t_spec	spec;
	t_line	*line;
	int		*cnt;

	line = NULL;
	while (parse_txt(&fmt, &line) && *fmt)
	{
		spec = pf_parse_spec(&fmt, ap);
		if (spec.type == FMT_ERR)
			return (line_clr(&line));
		else if (spec.type == FMT_CNT)
		{
			if ((cnt = va_arg(*ap, int*)))
				*cnt = line_len(line);
		}
		else if (!g_format[spec.type](&line, spec, ap))
			return (line_clr(&line));
	}
	return (line);
}
