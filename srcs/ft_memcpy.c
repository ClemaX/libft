/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 16:03:24 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 12:36:56 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "types.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, t_size n)
{
	char *temp;

	temp = dst;
	while (n--)
		*(temp++) = *(char *)(src++);
	return (dst);
}
