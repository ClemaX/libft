/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:33:03 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:33:04 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <libft/strings.h>

#include <libft/paths.h>

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
