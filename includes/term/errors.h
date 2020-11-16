/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:35:08 by pablo             #+#    #+#             */
/*   Updated: 2020/11/14 11:47:12 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define STD_ERROR		1
# define CMD_BAD_USE	2
# define CMD_CANT_EXEC	126
# define CMD_NOT_FOUND	127
# define INV_EXIT_ARG	128
# define SIGNAL_BASE	128


typedef enum			e_exec_status
{
	SUCCESS				= 0,
	BAD_ALLOC			= 1,
	BAD_CLOSE			= 2,
	BAD_PIPE			= 3,
	BAD_DUP2			= 4,
	BAD_FORK			= 5
}						t_exec_status;

typedef enum			e_redir_status
{
	CONTINUE			= 0,
	FILE_NOT_FOUND		= -1,
	AMBIG_REDIRECT		= -2,
	FLNAME_TO_LONG		= -3,
	RDR_BAD_ALLOC		= -4
}						t_redir_status;

#endif
