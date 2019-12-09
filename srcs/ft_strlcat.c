/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 23:18:22 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 14:41:00 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>
#include <libft.h>

t_size	ft_strlcat(char *dst, const char *src, t_size size)
{
	const t_size	len_dst = ft_strlen(dst);
	const t_size	len_src = ft_strlen(src);
	t_size			i;

	i = 0;
	if (!size)
		return (len_src);
	if (size == len_dst)
		return (len_dst + len_src);
	if (size < len_dst)
		return (size + len_src);
	while (src[i] && i < size - len_dst - 1)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = 0;
	return (len_dst + len_src);
}
