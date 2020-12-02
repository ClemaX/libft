#include <libft.h>

void	ft_lstinsert(t_list **list, t_list *elem, int (*cmp)(void*, void*))
{
	t_list	*curr;
	t_list	*prev;

	if (!(curr = *list) || cmp(elem, curr) == 0)
	{
		elem->next = curr;
		*list = elem;
	}
	else
	{
		prev = NULL;
		while (curr && cmp(elem->content, curr->content) > 0)
		{
			prev = curr;
			curr = curr->next;
		}
		elem->next = curr;
		if (prev)
			prev->next = elem;
		else
			*list = elem;
	}
}
