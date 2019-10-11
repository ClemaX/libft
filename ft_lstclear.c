/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstclear.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 20:34:08 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/11 13:05:25 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	ft_lstiter(*lst, del);
	ft_lstiter(*lst, ft_lstdelone);
	lst = 0;
}
