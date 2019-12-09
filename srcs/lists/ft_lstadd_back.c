/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstadd_back.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 20:14:52 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 14:41:00 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (alst)
	{
		if (!*alst)
			*alst = new;
		else
			ft_lstlast(*alst)->next = new;
	}
}
