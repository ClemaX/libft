#include <stdlib.h>

#include <libft/printf.h>
#include <libft/strings.h>

void			*strs_unload_n(char **strs, int n)
{
	while (n)
		free(strs[--n]);
	free(strs);
	return (NULL);
}

void			*strs_unload(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (NULL);
}

void			strs_print(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		ft_dprintf(2, "strs[%d] = '%s'\n", i, av[i]);
		i++;
	}
}
