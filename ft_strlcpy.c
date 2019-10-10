/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 22:32:49 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 19:19:19 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_size	ft_strlcpy(char *dst, const char *src, t_size size)
{
	const t_size len_src = ft_strlen(src);

	if (size)
	{
		while (--size && *src)
			*(dst++) = *(src++);
		*dst = 0;
	}
	return (len_src);
}
