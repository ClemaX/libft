/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 18:53:59 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 14:41:00 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, t_size len)
{
	t_size i;

	i = 0;
	if (src > dst)
		ft_memcpy(dst, src, len);
	else if (dst != src)
		while (len--)
			((char*)dst)[len] = ((char*)src)[len];
	return (dst);
}
