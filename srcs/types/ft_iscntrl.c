/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:34:10 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:34:10 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iscntrl(int c)
{
	return (c >= 0 && (c < ' ' || c == 127));
}