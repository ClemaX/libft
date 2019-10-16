/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_calloc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 22:17:12 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 12:53:55 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(t_size count, t_size size)
{
	void	*buf;
	t_size	n_bytes;

	n_bytes = count * size;
	if (!(buf = malloc(n_bytes)))
		return (NULL);
	ft_bzero(buf, count * size);
	return (buf);
}
