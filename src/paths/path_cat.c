/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:55:39 by chamada           #+#    #+#             */
/*   Updated: 2020/12/14 15:31:55 by chamada          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <limits.h>
#include <stddef.h>

char	*path_cat(char *dest, const char *a, const char *b)
{
	const size_t	len = ft_strlen(a) + ft_strlen(b) + 1;
	char			*c;

	if (len >= PATH_MAX)
		return (NULL);
	c = dest;
	while (*a)
		*c++ = *a++;
	*c++ = PATH_DELIM;
	while (*b)
		*c++ = *b++;
	*c = '\0';
	return (dest);
}
