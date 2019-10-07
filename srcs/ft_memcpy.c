/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 16:03:24 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/07 16:46:42 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void
	*ft_memcpy(void *restrict dst, const void *restrict src, unsigned long n)
{
	char *temp;

	temp = dst;
	while (n--)
		*(temp++) = *(char *)(src++);
	return (dst);
}
