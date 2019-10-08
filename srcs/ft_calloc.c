/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_calloc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 22:17:12 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 00:21:34 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "types.h"
#include "ft.h"
#include <stdlib.h>

void	*ft_calloc(t_size count, t_size size)
{
	void *buf;

	buf = malloc(count * size);
	if (!buf)
		return (NULL);
	ft_bzero(buf, size);
	return (buf);
}
