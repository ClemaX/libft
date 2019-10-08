/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 16:49:31 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 23:57:53 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "types.h"

void*
	ft_memccpy(void *dst, const void *src, int c, t_size n)
{
	char *temp_dst;
	char *temp_src;

	temp_dst = (char*)dst;
	temp_src = (char*)src;
	while (--n && *temp_src != c)
		*(temp_dst++) = *(temp_src++);
	if (n == 0)
		return (0);
	*(temp_dst++) = c;
	return (temp_dst);
}
