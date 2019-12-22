/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 22:02:48 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 18:17:53 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

# include <scanf/specs.h>
# include <stdarg.h>

extern int	(*g_convert[10])(const char **src, t_spec spec, va_list ap);

#endif
