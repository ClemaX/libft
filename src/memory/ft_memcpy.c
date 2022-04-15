/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:03:24 by chamada           #+#    #+#             */
/*   Updated: 2020/11/12 10:50:22 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/memory.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *temp;

	if (!dst || !src)
		return (NULL);
	temp = dst;
	while (n--)
		*temp++ = *(char *)src++;
	return (dst);
}
