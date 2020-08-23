/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:37:08 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:31:50 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	uintlen(unsigned int n)
{
	int len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	unsigned int	u_n;
	int				len;
	char			sign;
	char			*a;

	sign = (n < 0);
	u_n = (sign) ? -n : n;
	len = uintlen(u_n) + sign;
	if (!(a = malloc(len + 1)))
		return (NULL);
	if (sign)
		a[0] = '-';
	a[len] = 0;
	while (len-- - sign)
	{
		a[len] = u_n % 10 + '0';
		u_n /= 10;
	}
	return (a);
}
