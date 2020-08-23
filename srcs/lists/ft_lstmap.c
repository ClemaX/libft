/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:51:55 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:30:21 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	t_list	*current;
	t_list	*new;

	out = NULL;
	while ((current = lst))
	{
		if (!(new = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&out, del);
			return (NULL);
		}
		ft_lstadd_back(&out, new);
		lst = lst->next;
		del(current->content);
		free(current);
	}
	return (out);
}
