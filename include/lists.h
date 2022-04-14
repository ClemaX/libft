#pragma once

typedef	struct	s_list
{
	struct s_list	*next;
	void			*content;
}				t_list;

typedef int		(t_cmp_fun(const void *a, const void *b));

typedef void	(t_lstadd_fun(t_list **list, t_list *elem));
typedef void	(t_lstcontent_fun(void *content));
typedef void	*(t_lstmap_fun(const void *content));
typedef void	(t_lstinsert_fun(t_list **list, t_list *elem, t_cmp_fun *cmp));

void	ft_lstadd_back(t_list **alst, t_list *elem);
void	ft_lstadd_front(t_list **alst, t_list *elem);
void	ft_lstclear(t_list **lst, t_lstcontent_fun *del);
void	ft_lstdelone(t_list *lst, t_lstcontent_fun *del);
void	ft_lstinsert(t_list **list, t_list *elem, t_cmp_fun *cmp);
void	ft_lstinsertrev(t_list **list, t_list *elem, t_cmp_fun *cmp);
void	ft_lstiter(t_list *lst, t_lstcontent_fun *del);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
void	ft_lstsort(t_list **lst, t_cmp_fun *cmp);
void	ft_lstsortrev(t_list **lst, t_cmp_fun *cmp);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstmap(t_list *lst, t_lstmap_fun *map, t_lstcontent_fun *del);
