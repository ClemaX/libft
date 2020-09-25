/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:00:47 by chamada           #+#    #+#             */
/*   Updated: 2020/09/25 14:50:41 by chamada          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_H
# define TERM_H

# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <libft.h>
# include <term.h>
# include <fcntl.h>
# include <sys/stat.h>

# define MAX_ENTRY		1024
# define BASH_ERROR_CODE 127

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

# define TERM_WAITING	(TERM_B_SLASH | TERM_S_QUOTE | TERM_D_QUOTE)
# define TERM_CONSUME	(TERM_NEWLINE | TERM_CLEAR | TERM_INT | TERM_EOF | TERM_STOP | TERM_ERASE | TERM_SUSPEND | TERM_IGNORE)

# define TAKE_FD		1
# define GIVE_FD		2

typedef struct	s_line
{
	char			*data;
	size_t			length;
	size_t			size;
	struct s_line	*next;
	struct s_line	*prev;
}				t_line;

typedef struct	s_caps
{
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

typedef struct	s_position
{
	unsigned	x;
	unsigned	y;
}				t_position;

typedef struct	s_cursor
{
	t_position	pos;
	t_position	origin;
}				t_cursor;


typedef struct	s_selection
{
	t_position	start;
	t_position	end;
}				t_selection;


typedef struct	s_hist
{
	t_line	*last;
	t_line	*curr;
	t_line	*next;
	// TODO: Remove next
}				t_hist;

typedef struct	s_pipe
{
	int			fd[2];
	int			fd_read;
	int			fd_write;
	int			in;
	int			out;
}				t_pipe;

typedef	struct	s_term
{
	char			*name;
	int				pid;
	struct termios	s_ios;
	struct termios	s_ios_bkp;
	t_cursor		cursor;
	t_selection		select;
	t_caps			caps;
	t_map			*env;
	t_line			*line;
	t_hist			hist;
	t_line			clip;
	int				(*exec)(const char*, struct s_term*);
	int				flags;
	int				fd[2];
	int				st;
}				t_term;

/*
//				term.c				
*/
int				term_prompt(int ac, const char **av, const char **envp, int (*exec)(const char*, t_term*));
void			term_write_prompt(t_term *t, int status);

/*
//				init.c
*/
int				term_init(t_term *t, const char **envp, int (*exec)(const char*, t_term*));
int				term_destroy(t_term *t);

/*
//				read.c
*/
int				term_read(t_term *t, int status);
int				term_read_control(t_term *t, int status, char c);
int				term_read_escape(t_term *t, int status);

/*
//				hist_cursor.c
*/
void			term_up(t_term *t);
void			term_down(t_term *t);

/*
//				line_cursor.c		
*/
void			term_left(t_term *t);
void			term_right(t_term *t);
void			term_start_line(t_term *t);
void			term_end_line(t_term *t);

/*
//				write.c
*/
int				term_prewrite(t_term *t, const char *str, size_t n);
int 			term_write(t_term *t, const char *str, size_t n);
void			term_clear_line(t_term *t);
void			term_clear_screen(t_term *t, int status);

/*
//				controls.c
*/
int				term_cancel(t_term *t);
void			term_stop(t_term *t);
int				term_new_line(t_term *t, int status);
int				term_erase(t_term *t, int status);

/*
//				hist.c
*/
void			hist_add(t_hist *hist, t_line *line);
void			hist_pop(t_hist *hist);
void			hist_clear(t_hist *hist);
void			hist_commit(t_hist *hist, t_line *line);

/*
//				line.c
*/
t_line			*line_dup(t_line *line);
t_line			*line_new(size_t size);

/*
//				line_edit.c
*/
int				line_insert_at(t_line *line, size_t at, const char *str, size_t n);
int				line_erase_at(t_line *line, size_t at, size_t n);
void			line_clear(t_line **line);

/*
//				select.c
*/
void			select_left(t_term *t);
void			select_right(t_term *t);
void			select_clear(t_term *t);

/*
//				clip.c
*/
char			*clip_copy(t_term *t);
char			*clip_cut(t_term *t);
int				clip_paste(t_term *t);
void			clip_clear(t_line *clip);

#endif
