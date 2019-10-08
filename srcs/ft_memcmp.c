/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 20:47:48 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 12:36:25 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "types.h"

int	ft_memcmp(const void *s1, const void *s2, t_size n)
{
	t_size i;

	i = 0;
	while (i < n && ((unsigned char*)s1)[i] == ((unsigned char*)s2)[i])
		i++;
	return (i == n ? 0 : ((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
