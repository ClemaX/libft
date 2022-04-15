/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:47:23 by chamada           #+#    #+#             */
/*   Updated: 2020/10/29 07:00:20 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/strings.h>
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*dup;
	char	*start;

	dup = malloc(ft_strlen(src) + 1);
	if (!(start = dup))
		return (NULL);
	while (*src)
		*dup++ = *src++;
	*dup = 0;
	return (start);
}

char	*ft_strndup(const char *src, size_t n)
{
	char	*dup;
	char	*start;

	if (!(dup = malloc(n + 1)))
		return (NULL);
	start = dup;
	while (*src && n--)
		*dup++ = *src++;
	*dup = '\0';
	return (start);
}
