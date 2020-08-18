#include <libft.h>
#include <stdlib.h>

char	*ft_basename(const char *path)
{
	int		i;
	char	*basename;

	i = 0;
	basename = (char *)path;
	if (!path[i])
		return (ft_strdup(""));
	while (path[i])
	{
		if (path[i] == '/' && path[i + 1])
			basename = (char *)(path + i + 1);
		i++;
	}
	basename = ft_strtrim(basename, "/");
	if (*basename)
		return (basename);
	free(basename);
	return (ft_strdup("/"));
}
