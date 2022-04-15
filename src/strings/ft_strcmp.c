/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:20:47 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:33:37 by chamada          ###   ####lyon.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/types.h>

#include <libft/strings.h>

int	ft_strncmp(const char *a, const char *b, size_t n)
{
	if (!n)
		return (0);
	while (--n && *a && *a == *b)
	{
		a++;
		b++;
	}
	return ((unsigned char)*a - (unsigned char)*b);
}

int	ft_strcmp(const char *a, const char *b)
{
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return ((unsigned char)*a - (unsigned char)*b);
}

int	ft_strcmpi(const char *a, const char *b)
{
	while (*a && ft_tolower(*a) == ft_tolower(*b))
	{
		a++;
		b++;
	}
	return ((unsigned char)ft_tolower(*a) - (unsigned char)ft_tolower(*b));
}
