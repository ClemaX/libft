/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 13:19:49 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 14:41:00 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static t_size	trimlen(const char *s1, const char *set)
{
	char	*s;

	s = (char*)s1;
	while (*s)
		s++;
	while (s >= s1 && ft_strchr(set, *s))
		s--;
	return (s - s1 + 1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	t_size	len;
	char	*out;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = trimlen(s1, set);
	out = ft_substr(s1, 0, len);
	return (out);
}
