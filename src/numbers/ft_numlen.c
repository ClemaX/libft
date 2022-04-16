/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 23:14:04 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:31:53 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/numbers.h>

unsigned	ft_numlen(uintmax_t n, unsigned base)
{
	unsigned	len;

	len = base >= 2;
	if (len == 1)
	{
		while (n /= base)
			len++;
	}
	return (len);
}
