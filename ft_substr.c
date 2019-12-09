/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_substr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 12:39:22 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 20:02:10 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, t_size len)
{
	char	*substr;

	if (!(s && start <= ft_strlen(s)))
		return (ft_calloc(1, 1));
	if (!(substr = malloc(len + 1)))
		return (NULL);
	s += start;
	ft_strlcpy(substr, s, len + 1);
	return (substr);
}
