/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 21:19:45 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 21:37:40 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"
#include "types.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	t_size	len;
	char	*out;

	len = ft_strlen(s);
	out = malloc(len + 1);
	out[len] = 0;
	while (len--)
		out[len] = f(len, s[len]);
	return (out);
}
