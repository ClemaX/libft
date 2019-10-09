/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 17:41:40 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 19:50:19 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char	factor;
	int		i;

	while (ft_isspace(*str))
		str++;
	factor = *str == '-' ? -1 : 1;
	str += *str == '-' || *str == '+';
	i = 0;
	while (ft_isdigit(*str))
		i = i * 10 + (*(str++) - '0');
	return (i * factor);
}
