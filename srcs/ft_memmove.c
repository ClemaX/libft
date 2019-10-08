/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 18:53:59 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 12:37:13 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "types.h"

void	*ft_memmove(void *dst, const void *src, t_size len)
{
	t_size i;

	i = 0;
	if (src < dst)
		while (i < len)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i++;
		}
	else if (dst != src)
		while (len--)
			((char*)dst)[len] = ((char*)src)[len];
	return (dst);
}