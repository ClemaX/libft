/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 22:17:12 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:30:58 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/memory.h>
#include <libft/memory.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void			*buf;
	const size_t	n_bytes = count * size;

	if (!(buf = malloc(n_bytes)))
		return (NULL);
	ft_bzero(buf, n_bytes);
	return (buf);
}
