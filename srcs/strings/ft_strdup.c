/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:47:23 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:33:15 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*start;

	dup = malloc(ft_strlen(s1) + 1);
	if (!(start = dup))
		return (NULL);
	while (*s1)
		*dup++ = *s1++;
	*dup = 0;
	return (start);
}
