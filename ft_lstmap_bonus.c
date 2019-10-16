/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 14:51:55 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 16:58:10 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(void*))
{
	t_list *out;

	if (!lst)
		return (0);
	out = f(lst->content);
	while ((lst = lst->next))
		ft_lstadd_back(&out, f(lst->content));
	return (out);
}
