/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:25:42 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:33:39 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/memory.h>

#include <libft/strings.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const size_t	len_n = ft_strlen(needle);
	char			*index;

	if (!len_n)
		return ((char*)haystack);
	if (!len)
		return (0);
	index = ft_strchr(haystack, *needle);
	while (index && len - (index - haystack) >= len_n)
	{
		if (!ft_memcmp(index, needle, len_n))
			return (index);
		index = ft_strchr(index + 1, *needle);
	}
	return (0);
}
