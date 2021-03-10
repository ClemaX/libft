/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:57:59 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:29:50 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	putdigits(unsigned int u_n, int fd)
{
	char c;

	if (u_n)
	{
		c = u_n % 10 + '0';
		putdigits(u_n / 10, fd);
		ft_putchar_fd(c, fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		putdigits(-n, fd);
	}
	else
		putdigits(n, fd);
}
