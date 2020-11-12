/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:02:31 by chamada           #+#    #+#             */
/*   Updated: 2020/11/12 03:18:45 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAPS_H
# define CAPS_H

# include <stdbool.h>
# include <term.h>

# define MAX_ENTRY		1024

typedef struct	s_caps
{
	bool	enabled;
	char	*insert;
	char	*insert_end;
	char	*clear;
	char	*standout;
	char	*standout_end;
	char	*k_up;
	char	*k_down;
	char	*k_left;
	char	*k_right;
	char	*c_del;
	char	*c_del_n;
	char	*c_del_line;
	char	*c_move;
	char	*c_move_h;
	char	*c_up;
	char	*c_down;
	char	*c_left;
	char	*c_right;
}				t_caps;

#endif
