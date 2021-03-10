/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:34:08 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:30:09 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *current;

	while ((current = *lst))
	{
		del(current->content);
		*lst = current->next;
		free(current);
	}
}
