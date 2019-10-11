/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 13:19:49 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/11 17:47:56 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		in_str(const char *set, const char c)
{
	while (*set)
		if (*(set++) == c)
			return (1);
	return (0);
}

static t_size	trimlen(const char *s1, const char *set)
{
	char	*s;
	t_size	len;

	s = (char*)s1;
	while (in_str(set, *s))
		s++;
	len = s - s1;
	while (*s)
		s++;
	len = (s - s1) - len;
	s--;
	while (s >= s1 && in_str(set, *(s--)))
		len--;
	return (len);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	t_size			len_trim;
	char			*start;
	char			*s;

	len_trim = trimlen(s1, set);
	start = malloc(len_trim + 1);
	if (!(s = start))
		return (NULL);
	s[len_trim] = 0;
	while (in_str(set, *s1))
		s1++;
	while (len_trim--)
		*(s++) = *(s1++);
	return (start);
}
