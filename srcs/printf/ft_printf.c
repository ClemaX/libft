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
#include <printf/parse.h>

int				ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	ap;
	t_line	*line;
	char	*str;
	int		len;

	va_start(ap, fmt);
	line = parse_fmt(fmt, ap);
	va_end(ap);
	if (!line || (len = line_put(&str, &line, 1)) < 0)
		return (-1);
	if (write(fd, str, len) < 0)
		len = -1;
	free(str);
	return (len);
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
	if (!line || (len = line_put(&str, &line, 1)) < 0)
		return (-1);
	write(1, str, len);
	free(str);
	return (len);
}

int				ft_asprintf(char **ret, char *fmt, ...)
{
	va_list	ap;
	t_line	*line;
	int		len;

	va_start(ap, fmt);
	line = parse_fmt(fmt, ap);
	va_end(ap);
	if ((!line || (len = line_put(ret, &line, 1)) < 0))
	{
		*ret = NULL;
		return (-1);
	}
	return (len);
}

int				ft_sprintf(char *str, char *fmt, ...)
{
	va_list	ap;
	t_line	*line;
	int		len;

	va_start(ap, fmt);
	line = parse_fmt(fmt, ap);
	va_end(ap);
	if ((!line || (len = line_put(&str, &line, 0)) < 0))
		return (-1);
	return (len);
}
