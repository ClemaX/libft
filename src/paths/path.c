/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:55:39 by chamada           #+#    #+#             */
/*   Updated: 2020/12/14 15:31:55 by chamada          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft/strings.h>

#include <libft/paths.h>
#include <linux/limits.h>
#include <stddef.h>

char	*path_trim(char *path)
{
	char	*end;

	end = path + ft_strlen(path);
	if (end != path)
	{
		while (end != path && *--end == PATH_DELIM);
		++end;
		*end = '\0';
	}
	return (path);
}

const char	*path_unroot(const char *path)
{
	while (*path == PATH_DELIM)
		path++;
	return (path);
}

char	*path_pop(char *path)
{
	char	*end;

	if (*path == '\0')
		return path;
	end = path + ft_strlen(path) - 1;
	while (end != path && *end == PATH_DELIM)
		--end;
	while (end != path && *end != PATH_DELIM)
		--end;
	while (end != path && *end == PATH_DELIM)
		--end;
	if (end != path)
		++end;
	else
		*end++ = '.';
	*end = '\0';
	return (path);
}

char	*path_push(char *path, const char *member)
{
	char	*ret;

	ret = path;
	member = path_unroot(member);
	if (ft_strcmp(PATH_CURR, member) != 0)
	{
		if (ft_strcmp(PATH_PREV, member) == 0)
			path_pop(path);
		else
		{
			path_trim(path);
			if ((*path != '\0'
				&& ft_strlcat(path, PATH_DELIM_S, PATH_MAX) >= PATH_MAX)
				|| ft_strlcat(path, member, PATH_MAX) >= PATH_MAX)
				ret = NULL;
		}
	}
	return (ret);
}

char	*path_cat(char *dest, const char *a, const char *b)
{
	char	tmp[PATH_MAX];
	char	*member;
	int		err;

	err = (dest != a && ft_strlcpy(dest, a, sizeof(tmp)) >= PATH_MAX)
		|| ft_strlcpy(tmp, b, sizeof(tmp)) >= PATH_MAX;
	if (err == 0)
	{
		do
	{
		member = ft_strtok(tmp, PATH_DELIM_S);
		if (member == NULL)
			path_push(dest, tmp);
		else
				path_push(dest, member);
		} while (member != NULL);
	}
	return (dest);
}
