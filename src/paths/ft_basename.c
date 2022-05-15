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

#include <stddef.h>
#include <stdlib.h>

#include <libft/strings.h>

#include <libft/paths.h>

size_t	ft_baselen(const char *path)
{
	const char	*basename;
	size_t		len;

	len = 0;
	if (*path != '\0')
	{
		basename = path;
		while ((path = ft_strchr(path, PATH_DELIM)) && path[1] != '\0')
			basename = path;
		while (basename[len] != '\0' && basename[len] != PATH_DELIM)
			len++;
		if (basename[len] != '\0' && len == 0)
			len++;
	}
	else
		len = 1;
	return (len);
}

char	*ft_basename(const char *path)
{
	char		*result;
	const char	*basename;

	if (*path != '\0')
	{
		basename = path;
		while ((path = ft_strchr(path, PATH_DELIM)) != NULL && path[1] != '\0')
		{
			while (*path == PATH_DELIM)
				path++;
			if (*path != '\0')
				basename = path;
			else
				break;
		}
		result = ft_strtrim(basename, (char[]){PATH_DELIM, '\0'});
		if (result != NULL)
		{
			if (*result == '\0')
			{
				free(result);
				result = ft_strdup(PATH_ROOT);
			}
		}
	}
	else
		result = ft_strdup(path);
	return (result);
}
