/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:02:48 by chamada           #+#    #+#             */
/*   Updated: 2020/08/23 16:28:51 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

# include <scanf/specs.h>
# include <stdarg.h>

extern int	(*g_convert[10])(const char **src, t_spec spec, va_list ap);

#endif
