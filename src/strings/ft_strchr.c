/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 00:02:17 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:33:11 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/strings.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	return ((*s == c) ? (char*)s : 0);
}

char	*ft_strchrnul(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	return ((char *)s);
}
