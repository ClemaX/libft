/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 13:19:49 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 19:41:50 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		in_str(const char *set, const char c)
{
	while (*set)
		if (*(set++) == c)
			return (1);
	return (0);
}

static t_size	strtrimlen(const char *s1, const char *set)
{
	t_size	len;

	len = 0;
	while (*s1)
		if (!in_str(set, *(s1++)))
			len++;
	return (len);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	const t_size	len = strtrimlen(s1, set);
	char			*start;
	char			*s;

	start = malloc(len + 1);
	if (!(s = start))
		return (NULL);
	while (*s1)
	{
		if (!in_str(set, *s1))
			*(s++) = *s1;
		s1++;
	}
	*s = 0;
	return (start);
}
