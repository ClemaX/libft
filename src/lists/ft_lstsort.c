/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:54:04 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:30:33 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/lists.h>
#include <stdlib.h>

static void	lstsplit(t_list *lst, t_list **a, t_list **b)
{
	t_list	*slow;
	t_list	*fast;

	slow = lst;
	fast = lst->next;
	while (fast)
	{
		if ((fast = fast->next))
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*a = lst;
	*b = slow->next;
	slow->next = NULL;
}

static void	*lstmergecmp(t_list *a, t_list *b, t_cmp_fun *cmp)
{
	t_list	*lst;

	if (a == NULL)
		return (b);
	if (b == NULL)
		return (a);
	if (cmp(a->content, b->content) > 0)
	{
		lst = a;
		lst->next = lstmergecmp(a->next, b, cmp);
	}
	else
	{
		lst = b;
		lst->next = lstmergecmp(a, b->next, cmp);
	}
	return (lst);
}

static void	*lstmergecmprev(t_list *a, t_list *b, t_cmp_fun *cmp)
{
	t_list	*lst;

	if (a == NULL)
		return (b);
	if (b == NULL)
		return (a);
	if (cmp(a->content, b->content) < 0)
	{
		lst = a;
		lst->next = lstmergecmprev(a->next, b, cmp);
	}
	else
	{
		lst = b;
		lst->next = lstmergecmprev(a, b->next, cmp);
	}
	return (lst);
}

void		ft_lstsort(t_list **lst, t_cmp_fun *cmp)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *lst;
	if (head == NULL || head->next == NULL)
		return ;
	lstsplit(head, &a, &b);
	ft_lstsort(&a, cmp);
	ft_lstsort(&b, cmp);
	*lst = lstmergecmp(a, b, cmp);
}

void		ft_lstsortrev(t_list **lst, t_cmp_fun *cmp)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *lst;
	if (head == NULL || head->next == NULL)
		return ;
	lstsplit(head, &a, &b);
	ft_lstsortrev(&a, cmp);
	ft_lstsortrev(&b, cmp);
	*lst = lstmergecmprev(a, b, cmp);
}
