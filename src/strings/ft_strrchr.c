/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 00:08:49 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:33:45 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/strings.h>

char	*ft_strrchr(const char *s, int c)
{
	char *end;

	end = (char*)s + ft_strlen(s);
	if (end != s)
		--end;
	while (end != s && *end != c)
		--end;
	return ((*end == c) ? end : NULL);
}
