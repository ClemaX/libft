/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 23:24:01 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 23:20:15 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "types.h"

#ifndef FT_H
# define FT_H

void	*ft_memset(void *b, int c, t_size len);
void	ft_bzero(void *s, t_size n);
void	*ft_memcpy(void *dst, const void *src, t_size n);
void*	ft_memccpy(void *dst, const void *src, int c, t_size n);
void	*ft_memmove(void *dst, const void *src, t_size len);
void	*ft_memchr(const void *s, int c, t_size n);
int		ft_memcmp(const void *s1, const void *s2, t_size n);
t_size	ft_strlen(const char *s);
void	*ft_calloc(t_size count, t_size size);
char	*ft_strdup(const char *s1);
t_size	ft_strlcpy(char *dst, const char *src, t_size size);
t_size	ft_strlcat(char *dst, const char *src, t_size size);

char	*ft_substr(char const *s, unsigned int start, t_size len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
