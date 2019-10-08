/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 14:47:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 17:25:43 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*start;

	dup = malloc(ft_strlen(s1) + 1);
	if (!(start = dup))
		return (NULL);
	while (*s1)
	{
		*dup = *s1;
		s1++;
		dup++;
	}
	*dup = 0;
	return (start);
}
