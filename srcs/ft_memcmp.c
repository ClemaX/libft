/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 20:47:48 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 16:44:47 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, t_size n)
{
	const unsigned char	*u_s1 = s1;
	const unsigned char	*u_s2 = s2;
	t_size				i;

	i = 0;
	while (i < n && u_s1[i] == u_s2[i])
		i++;
	return ((i == n) ? 0 : u_s1[i] - u_s2[i]);
}
