/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_numlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/22 23:14:04 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/23 18:55:28 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	ft_numlen(unsigned long long n, unsigned base)
{
	int	len;

	if (base < 2)
		return (-1);
	len = 1;
	while (n /= base)
		len++;
	return (len);
}
