/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 17:28:54 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 12:49:33 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		splitcnt(const char *s1, const char c)
{
	t_size	count;

	count = 0;
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
	char			**strs;
	char			*dest;
	char			**temp;

	if (!(s && (strs = malloc(sizeof(strs) * (splitcnt(s, c) + 1)))))
		return (NULL);
	temp = strs;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s || !(dest = malloc(splitlen(s, c) + 1)))
		{
			free(strs);
			return (NULL);
		}
		*(temp++) = dest;
		while (*s && *s != c)
			*(dest++) = *(s++);
		*(dest++) = 0;
		while (*s == c)
			s++;
	}
	*temp = NULL;
	return (strs);
}
