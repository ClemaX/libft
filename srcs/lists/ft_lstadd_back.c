/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstadd_back.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 20:14:52 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/01 04:51:24 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd_back(t_list **list, t_list *element)
{
	if (list)
	{
		if (!*list)
			*list = element;
		else
			ft_lstlast(*list)->next = element;
	}
}
