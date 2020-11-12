/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:00:47 by chamada           #+#    #+#             */
/*   Updated: 2020/11/12 02:16:54 by chamada          ###   ########.fr       */
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
# include <term/env.h>
# include <term/lexer.h>

# define TERM_PS1		"minish> "

# define TERM_READING	1
# define TERM_ERROR		2
# define TERM_WAITING	4
# define TERM_NEWLINE	8
# define TERM_INT		16
# define TERM_ERASE		32
# define TERM_EOF		64
# define TERM_STOP		128
# define TERM_SUSPEND	256
# define TERM_CLEAR		512
# define TERM_SELECT	1024
# define TERM_IGNORE	2048

/*
**	(TERM_NEWLINE | TERM_CLEAR | TERM_INT | TERM_EOF | TERM_STOP | TERM_ERASE
**	| TERM_SUSPEND | TERM_IGNORE)
*/
# define TERM_CONSUME	3064

typedef	struct	s_term
{
	t_env			*env;
	char			*name;
	pid_t			pid;
	int				st;
	struct termios	s_ios;
	struct termios	s_ios_bkp;
	t_lex_st		lex_st;
	t_line			*line;
	t_caps			caps;
	t_cursor		cursor;
	t_clip			clip;
	t_hist			hist;
	int				(*exec)(t_tok *tokens, struct s_term *term);
}				t_term;

/*
**				term.c
*/
int				term_prompt(int ac, const char **av, const char **envp,
	int (*exec)(t_tok *tokens, t_term *term));

/*
**				init.c
*/
int				term_init(t_term *t, const char **envp,
	int (*exec)(t_tok *tokens, t_term *term));
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
