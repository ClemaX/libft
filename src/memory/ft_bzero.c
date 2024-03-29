/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:47:01 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:31:01 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/memory.h>

void	ft_bzero(void *s, size_t n)
{
	char *temp;

	temp = s;
	while (n--)
		*temp++ = 0;
}
