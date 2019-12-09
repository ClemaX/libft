/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 17:41:40 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 14:41:00 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>

int	ft_atoi(const char *str)
{
	char			factor;
	unsigned long	max;
	unsigned long	i;

	while (ft_isspace(*str))
		str++;
	factor = (*str == '-') ? -1 : 1;
	str += (*str == '-' || *str == '+');
	max = (factor < 0) ? 0x8000000000000000UL : 0x7FFFFFFFFFFFFFFFL;
	i = 0;
	while (ft_isdigit(*str) && i < max)
		i = i * 10 + (*str++ - '0');
	if (i >= max)
		return ((factor < 0) ? 0 : -1);
	return (i * factor);
}
