/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_substr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 12:39:22 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 15:36:14 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, t_size len)
{
	char	*substr;
	t_size	i;

	i = start;
	if (!s || !(substr = malloc(len + 1)))
		return (NULL);
	while (i - start < len)
	{
		substr[i - start] = s[i];
		i++;
	}
	substr[len] = 0;
	return (substr);
}
