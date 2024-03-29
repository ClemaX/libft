/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:14:52 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:30:05 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/lists.h>

void	ft_lstadd_back(t_list **list, t_list *element)
{
	if (element != NULL)
	{
		if (*list == NULL)
			*list = element;
		else
			ft_lstlast(*list)->next = element;
	}
}
