/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:00:47 by chamada           #+#    #+#             */
/*   Updated: 2020/09/26 15:26:31 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_H
# define TERM_H

# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <libft.h>
# include <fcntl.h>
# include <sys/stat.h>

# include <term/line.h>
# include <term/cursor.h>
# include <term/select.h>
# include <term/hist.h>
# include <term/caps.h>
# include <term/clip.h>

# define TERM_PS1		"minish> "

# define TERM_READING	1
# define TERM_ERROR		2
# define TERM_B_SLASH	4
# define TERM_S_QUOTE	8
# define TERM_D_QUOTE	16
# define TERM_NEWLINE	32
# define TERM_INT		64
# define TERM_ERASE		128
# define TERM_EOF		256
# define TERM_STOP		512
# define TERM_SUSPEND	1024
# define TERM_CLEAR		2048
# define TERM_SELECT	4096
# define TERM_IGNORE	8192

/*
**	(TERM_B_SLASH | TERM_S_QUOTE | TERM_D_QUOTE)
*/
# define TERM_WAITING	28

/*
**	(TERM_NEWLINE | TERM_CLEAR | TERM_INT | TERM_EOF | TERM_STOP | TERM_ERASE
**	| TERM_SUSPEND | TERM_IGNORE)
*/
# define TERM_CONSUME	12256

typedef	struct	s_term
{
	t_map			*env;
	char			*name;
	int				pid;
	int				st;
	struct termios	s_ios;
	struct termios	s_ios_bkp;
	t_line			*line;
	t_caps			caps;
	t_cursor		cursor;
	t_clip			clip;
	t_hist			hist;
	int				(*exec)(const char*, struct s_term*);
}				t_term;

/*
**				term.c
*/
int				term_prompt(int ac, const char **av, const char **envp,
	int (*exec)(const char*, t_term*));

/*
**				init.c
*/
int				term_init(t_term *t, const char **envp,
	int (*exec)(const char*, t_term*));
int				term_destroy(t_term *t);

/*
**				read.c
*/
int				term_read(t_term *t, int status);
int				term_read_control(t_term *t, int status, char c);
int				term_read_escape(t_term *t, int status);

/*
**				controls.c
*/
int				term_cancel(t_term *t);
void			term_stop(t_term *t);
int				term_new_line(t_term *t, int status);
int				term_erase(t_term *t, int status);

/*
**				hist_cursor.c
*/
void			term_up(t_term *t);
void			term_down(t_term *t);

#endif
