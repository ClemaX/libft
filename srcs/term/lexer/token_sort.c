/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:54:04 by chamada           #+#    #+#             */
/*   Updated: 2020/11/03 14:24:42 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term/token.h>

static void	lstsplit(t_tok *lst, t_tok **a, t_tok **b)
{
	t_tok	*slow;
	t_tok	*fast;

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

static void	*lstmergecmp(t_tok *a, t_tok *b, int (*cmp)(t_tok_t, t_tok_t))
{
	t_tok	*lst;

	if (a == NULL)
		return (b);
	if (b == NULL)
		return (a);
	if (cmp(a->type, b->type) >= 0)
	{
//		ft_dprintf(2, "%s is first!\n", a->data);
		lst = a;
		lst->next = lstmergecmp(a->next, b, cmp);
	}
	else
	{
//		ft_dprintf(2, "%s is first!\n", b->data);
		lst = b;
		lst->next = lstmergecmp(a, b->next, cmp);
	}
	return (lst);
}

void		token_sort(t_tok **lst, int (*cmp)(t_tok_t, t_tok_t))
{
	t_tok	*head;
	t_tok	*a;
	t_tok	*b;

	head = *lst;
	if (head == NULL || head->next == NULL)
		return ;
	lstsplit(head, &a, &b);
	token_sort(&a, cmp);
	token_sort(&b, cmp);
	*lst = lstmergecmp(a, b, cmp);
}
