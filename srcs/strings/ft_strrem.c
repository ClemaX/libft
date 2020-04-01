/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrem.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 17:56:52 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 14:41:00 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static size_t	strremlen(const char *s1, const char *set)
{
	size_t	len;

	len = 0;
	while (*s1)
		if (!ft_strchr(set, *s1++))
			len++;
	return (len);
}

char			*ft_strrem(char const *s1, char const *set)
{
	const size_t	len = strremlen(s1, set);
	char			*start;
	char			*s;

	start = malloc(len + 1);
	if (!(s = start))
		return (NULL);
	while (*s1)
	{
		if (!ft_strchr(set, *s1))
			*s++ = *s1;
		s1++;
	}
	*s = 0;
	return (start);
}
