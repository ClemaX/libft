/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 15:25:42 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 14:41:00 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, t_size len)
{
	const t_size	len_n = ft_strlen(needle);
	char			*index;

	if (!len_n)
		return ((char*)haystack);
	if (!len)
		return (0);
	index = ft_strchr(haystack, *needle);
	while (index && len - (index - haystack) >= len_n)
	{
		if (!ft_memcmp(index, needle, len_n))
			return (index);
		index = ft_strchr(index + 1, *needle);
	}
	return (0);
}
