/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 19:43:05 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 16:43:33 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, t_size n)
{
	t_size				i;
	unsigned char		*u_s;
	const unsigned char	u_c = c;

	u_s = (unsigned char*)s;
	i = 0;
	while ((i < n) && u_s[i] != u_c)
		i++;
	return ((i == n) ? 0 : u_s + i);
}
