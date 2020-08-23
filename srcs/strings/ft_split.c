/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:28:54 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:33:08 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static size_t	splitcnt(const char *s1, const char c)
{
	size_t	count;

	count = 0;
	while (s1 && *s1)
	{
		while (*s1 == c)
			s1++;
		if (*s1)
			count++;
		s1 = ft_strchr(s1, c);
	}
	return (count);
}

static size_t	splitlen(const char *s1, const char c)
{
	const char	*s = s1;

	while (*s && *s != c)
		s++;
	return (s - s1);
}

void			*strs_unload_n(char **strs, int n)
{
	while (n)
		free(strs[--n]);
	free(strs);
	return (NULL);
}

void			*strs_unload(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	const size_t	count = splitcnt(s, c);
	char			**strs;
	size_t			len;
	size_t			i;

	if (!(strs = ft_calloc(count + 1, sizeof(strs))))
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		len = splitlen(s, c);
		if (!(strs[i] = ft_calloc(len + 1, sizeof(*strs))))
			return (strs_unload_n(strs, i));
		ft_strlcpy(strs[i++], s, len + 1);
		s += len;
	}
	return (strs);
}
