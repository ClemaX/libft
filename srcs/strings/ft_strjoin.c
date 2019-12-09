/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 13:02:47 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 14:41:00 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*s;

	if (!(s1 || s2))
		return (NULL);
	len = 0;
	if (s1)
		len += ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	if (!(s = malloc(len + 1)))
		return (NULL);
	while (s1 && *s1)
		*s++ = *s1++;
	while (s2 && *s2)
		*s++ = *s2++;
	*s = 0;
	return (s - len);
}
