/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 22:32:49 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 19:42:44 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_size	ft_strlcpy(char *dst, const char *src, t_size size)
{
	if (size != 0)
	{
		dst[--size] = 0;
		while (size--)
			*(dst++) = *(src++);
	}
	return (ft_strlen(src));
}
