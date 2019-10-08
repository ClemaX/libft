/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_calloc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 22:17:12 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 22:27:41 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "types.h"
#include <stdlib.h>

void	*ft_calloc(t_size count, t_size size)
{
	void *buf;

	buf = malloc(count * size);
	if (!buf)
		return (NULL);
	while (size--)
		((char*)buf)[size] = 0;
	return (buf);
}
