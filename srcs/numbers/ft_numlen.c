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

int	ft_numlen(unsigned long long n, unsigned base)
{
	int	len;

	if (base < 2)
		return (-1);
	len = 1;
	while (n /= base)
		len++;
	return (len);
}
