/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:19:45 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:33:34 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/strings.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*out;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(out = malloc(len + 1)))
		return (NULL);
	out[len] = 0;
	while (len--)
		out[len] = f(len, s[len]);
	return (out);
}
