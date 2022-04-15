/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 23:18:22 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:33:25 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/strings.h>
#include <libft/strings.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const size_t	len_dst = ft_strlen(dst);
	const size_t	len_src = ft_strlen(src);
	size_t			i;

	i = 0;
	if (!size)
		return (len_src);
	if (size == len_dst)
		return (len_dst + len_src);
	if (size < len_dst)
		return (size + len_src);
	while (src[i] && i < size - len_dst - 1)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = 0;
	return (len_dst + len_src);
}
