/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_calloc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 22:17:12 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 14:41:00 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>
#include <libft.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void			*buf;
	const size_t	n_bytes = count * size;

	if (!(buf = malloc(n_bytes)))
		return (NULL);
	ft_bzero(buf, n_bytes);
	return (buf);
}
