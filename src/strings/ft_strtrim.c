/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:19:49 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:33:51 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/strings.h>
#include <stdlib.h>

static size_t	trimlen(const char *s1, const char *set)
{
	char	*s;

	s = (char*)s1;
	while (*s)
		s++;
	while (s >= s1 && ft_strchr(set, *s))
		s--;
	return (s - s1 + 1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*out;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = trimlen(s1, set);
	out = ft_substr(s1, 0, len);
	return (out);
}
