/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstclear.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 20:34:08 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/11 14:26:39 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	delone(t_list *lst)
{
	free(lst);
	lst = NULL;
}

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	ft_lstiter(*lst, del);
	ft_lstiter(*lst, delone);
	lst = NULL;
}
