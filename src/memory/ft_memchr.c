/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:43:05 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:31:06 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/memory.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*u_s;
	const unsigned char	u_c = c;

	u_s = (unsigned char*)s;
	i = 0;
	while ((i < n) && u_s[i] != u_c)
		i++;
	return ((i == n) ? 0 : u_s + i);
}
