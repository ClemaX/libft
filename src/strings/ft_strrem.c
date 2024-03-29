/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:56:52 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:33:47 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/strings.h>
#include <stdlib.h>

static size_t	strremlen(const char *s1, const char *set)
{
	size_t	len;

	len = 0;
	while (*s1)
		if (!ft_strchr(set, *s1++))
			len++;
	return (len);
}

char			*ft_strrem(char const *s1, char const *set)
{
	const size_t	len = strremlen(s1, set);
	char			*start;
	char			*s;

	start = malloc(len + 1);
	if (!(s = start))
		return (NULL);
	while (*s1)
	{
		if (!ft_strchr(set, *s1))
			*s++ = *s1;
		s1++;
	}
	*s = 0;
	return (start);
}
