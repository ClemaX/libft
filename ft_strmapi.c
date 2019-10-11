/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 21:19:45 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/11 13:07:50 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	t_size	len;
	char	*out;

	len = ft_strlen(s);
	if (!(out = malloc(len + 1)))
		return (NULL);
	out[len] = 0;
	while (len--)
		out[len] = f(len, s[len]);
	return (out);
}
