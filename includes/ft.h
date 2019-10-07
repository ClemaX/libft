/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 23:24:01 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/07 18:06:42 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

void	*ft_memset(void *b, int c, unsigned long len);
void	ft_bzero(void *s, unsigned long n);
void
	*ft_memcpy(void *restrict dst, const void *restrict src, unsigned long n);
void*
	ft_memccpy(void *restrict dst, const void *restrict src,
	int c, unsigned long n);

#endif
