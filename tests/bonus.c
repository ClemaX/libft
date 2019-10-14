#include "libft.h"
#include <stdlib.h>

static t_list	*mod_content(void *c1)
{
	int	*c2;

	c2 = malloc(sizeof(int));
	*c2 = (*(int*)c1) + 2;
	return (ft_lstnew(c2));
}

static void		del_content(void *c)
{
	free(c);
}

static void		print_content(void *c)
{
	ft_putnbr_fd(*(int*)c, 1);
	ft_putendl_fd("", 1);
}

static void		test_lstadd_back()
{
	int		*c1;
	int		*c2;
	t_list	*lst;

	c1 = malloc(sizeof(int));
	c2 = malloc(sizeof(int));
	*c1 = 101;
	*c2 = 42;
	lst = ft_lstnew(c1);
	ft_lstadd_back(&lst, ft_lstnew(c2));
	ft_lstiter(lst, print_content);
	ft_lstclear(&lst, del_content);
}

static void		test_lstadd_front()
{
	int		*c1;
	int		*c2;
	t_list	*lst;

	c1 = malloc(sizeof(int));
	c2 = malloc(sizeof(int));
	*c1 = 101;
	*c2 = 42;
	lst = ft_lstnew(c1);
	ft_lstadd_front(&lst, ft_lstnew(c2));
	ft_lstiter(lst, print_content);
	ft_lstclear(&lst, del_content);
}

static void		test_lstmap()
{
	int		*c1;
	int		*c2;
	t_list	*lst1;
	t_list	*lst2;

	c1 = malloc(sizeof(int));
	c2 = malloc(sizeof(int));
	*c1 = 101;
	*c2 = 42;
	lst1 = ft_lstnew(c1);
	ft_lstadd_back(&lst1, ft_lstnew(c2));
	lst2 = ft_lstmap(lst1, mod_content);
	ft_lstiter(lst2, print_content);
	ft_lstclear(&lst1, del_content);
	ft_lstclear(&lst2, del_content);
}

int				main()
{
	ft_putendl_fd("---lstadd_back---", 1);
	test_lstadd_back();
	ft_putendl_fd("---lstadd_front---", 1);
	test_lstadd_front();
	ft_putendl_fd("---lstmap---", 1);
	test_lstmap();
	return (0);
}
