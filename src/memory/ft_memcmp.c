/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:47:48 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:31:09 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*u_s1 = s1;
	const unsigned char	*u_s2 = s2;
	size_t				i;

	i = 0;
	while (i < n && u_s1[i] == u_s2[i])
		i++;
	return ((i == n) ? 0 : u_s1[i] - u_s2[i]);
}
