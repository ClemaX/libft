/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 23:24:01 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/07 20:45:58 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

void	*ft_memset(void *b, int c, unsigned long len);
void	ft_bzero(void *s, unsigned long n);
void	*ft_memcpy(void *dst, const void *src, unsigned long n);
void*	ft_memccpy(void *dst, const void *src, int c, unsigned long n);
void	*ft_memmove(void *dst, const void *src, unsigned long len);
void	*ft_memchr(const void *s, int c, unsigned long n);

#endif
