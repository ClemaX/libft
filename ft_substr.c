/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_substr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 12:39:22 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 12:03:08 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, t_size len)
{
	char	*substr;

	if (!(s && start <= ft_strlen(s) && (substr = malloc(len + 1))))
		return (ft_calloc(1, 1));
	s += start;
	ft_strlcpy(substr, s, len + 1);
	return (substr);
}