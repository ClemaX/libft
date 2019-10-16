/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 17:28:54 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 16:20:31 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		splitcnt(const char *s1, const char c)
{
	t_size	count;

	count = 1;
	while (*s1)
	{
		while (*s1 == c)
			s1++;
		if (*s1)
			count++;
		while (*s1 && *s1 != c)
			s1++;
	}
	return (count);
}

static t_size	splitlen(const char *s1, const char c)
{
	const char	*s = s1;

	while (*s && *s != c)
		s++;
	return (s - s1);
}

char			**ft_split(char const *s, char c)
{
	const int	count = splitcnt(s, c);
	char		**strs;
	int			len;

	if (!(s && (strs = malloc(sizeof(strs) * (count + 1)))))
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		len = splitlen(s, c);
		if (!(*strs = malloc(len + 1)))
		{
			free(strs);
			return (NULL);
		}
		ft_strlcpy(*strs++, s, len + 1);
		s += len;
		while (*s == c)
			s++;
	}
	*strs = NULL;
	return (strs - count + 1);
}
