/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:05:29 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:30:27 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/lists.h>

int	ft_lstsize(t_list *lst)
{
	int		size;

	if (!lst)
		return (0);
	size = 1;
	while ((lst = lst->next))
		size++;
	return (size);
}
