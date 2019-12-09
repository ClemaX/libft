/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pow.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 03:07:53 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 00:37:53 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

long double	ft_pow(int nb, int power)
{
	long double	result;

	result = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power-- > 0)
		result *= nb;
	return (result);
}
