/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:22:46 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:32:00 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include <libft/printf/parse.h>

int				ft_dprintf(int fd, const char *fmt, ...)
{
	t_pf_ctx	ctx = {
		.fmt = fmt,
	};
	t_line		*line;
	char		*str;
	int			len;

	va_start(ctx.ap, fmt);
	line = pf_parse_fmt(&ctx);
	va_end(ctx.ap);
	if (!line || (len = line_put(&str, &line, 1)) < 0)
		return (-1);
	if (write(fd, str, len) < 0)
		len = -1;
	free(str);
	return (len);
}

int				ft_printf(const char *fmt, ...)
{
	t_pf_ctx	ctx = {
		.fmt = fmt,
	};
	t_line		*line;
	char		*str;
	int			len;

	va_start(ctx.ap, fmt);
	line = pf_parse_fmt(&ctx);
	va_end(ctx.ap);
	if (!line || (len = line_put(&str, &line, 1)) < 0)
		return (-1);
	write(STDOUT_FILENO, str, len);
	free(str);
	return (len);
}

int				ft_asprintf(char **ret, char *fmt, ...)
{
	t_pf_ctx	ctx = {
		.fmt = fmt,
	};
	t_line	*line;
	int		len;

	va_start(ctx.ap, fmt);
	line = pf_parse_fmt(&ctx);
	va_end(ctx.ap);
	if ((!line || (len = line_put(ret, &line, 1)) < 0))
	{
		*ret = NULL;
		return (-1);
	}
	return (len);
}

int				ft_sprintf(char *str, char *fmt, ...)
{
	t_pf_ctx	ctx = {
		.fmt = fmt,
	};
	t_line	*line;
	int		len;

	va_start(ctx.ap, fmt);
	line = pf_parse_fmt(&ctx);
	va_end(ctx.ap);
	if ((!line || (len = line_put(&str, &line, 0)) < 0))
		return (-1);
	return (len);
}
