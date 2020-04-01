/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 22:32:49 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 14:41:00 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t len_src;

	if (!(src && dst))
		return (0);
	len_src = ft_strlen(src);
	if (size)
	{
		while (--size && *src)
			*dst++ = *src++;
		*dst = 0;
	}
	return (len_src);
}
