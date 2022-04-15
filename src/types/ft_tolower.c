/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:09:51 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:34:38 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/types.h>

int	ft_tolower(int c)
{
	return ((ft_isupper(c)) ? c - ('A' - 'a') : c);
}