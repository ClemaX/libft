/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:03:32 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:33:42 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strpos(const char *s, int c)
{
	const char	*pos = s;

	while (*pos && *pos != c)
		pos++;
	return ((*pos == c) ? pos - s : -1);
}
