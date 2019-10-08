/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 16:49:31 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 12:35:34 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "types.h"

void*
	ft_memccpy(void *restrict dst, const void *restrict src, int c, t_size n)
{
	char *restrict temp_dst;
	char *restrict temp_src;

	temp_dst = (char*)dst;
	temp_src = (char*)src;
	while (--n && *temp_src != c)
		*(temp_dst++) = *(temp_src++);
	if (n == 0)
		return (0);
	*(temp_dst++) = c;
	return (temp_dst);
}
