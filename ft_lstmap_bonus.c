/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap_bonus.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 14:51:55 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 12:53:22 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *out;
	t_list *current;

	out = NULL;
	while ((current = lst))
	{
		ft_lstadd_back(&out, ft_lstnew(f(lst->content)));
		lst = lst->next;
		if (current->content)
			del(current->content);
		free(current);
	}
	return (out);
}
