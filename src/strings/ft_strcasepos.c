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

#include <libft/strings.h>

int	ft_strcasepos(const char *str, int upper)
{
	const char	*str_it = str;
	char		lower;
	int			pos;

	lower = upper;
	if (upper >= 'a' && upper <= 'z')
		upper &= ~(1 << 5);
	else if (upper >= 'A' && upper <= 'z')
		lower |= 1 << 5;
	while (*str_it && *str_it != upper && *str_it != lower)
		str_it++;
	pos = -(*str_it != upper && *str_it != lower);
	if (!pos)
		pos = str_it - str;
	return pos;
}
