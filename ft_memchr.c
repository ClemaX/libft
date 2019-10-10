/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 19:43:05 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 15:59:47 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, t_size n)
{
	t_size i;

	i = 0;
	while (i < n && ((unsigned char*)s)[i] != (unsigned char)c)
		i++;
	return (i == n ? 0 : (void*)s + i);
}
