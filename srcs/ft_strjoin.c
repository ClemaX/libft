/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 13:02:47 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 19:35:27 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	len = ft_strlen(s1) + ft_strlen(s2);
	char			*s;

	if (!(s = malloc(len + 1)))
		return (NULL);
	while (*s1)
		*(s++) = *(s1++);
	while (*s2)
		*(s++) = *(s2++);
	*s = 0;
	return (s - len);
}
