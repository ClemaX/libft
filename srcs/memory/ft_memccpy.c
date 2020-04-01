/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 16:49:31 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 14:41:00 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>

void*
	ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*u_dst;
	unsigned char		*u_src;
	const unsigned char	u_c = c;

	u_dst = dst;
	u_src = (unsigned char*)src;
	while (n && *u_src != u_c)
	{
		*u_dst++ = *u_src++;
		n--;
	}
	if (n == 0)
		return (0);
	*u_dst++ = u_c;
	return (u_dst);
}
