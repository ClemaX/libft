/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:57:02 by chamada           #+#    #+#             */
/*   Updated: 2020/09/25 14:51:25 by chamada          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <term/term.h>

static int	optional_caps(t_caps *caps)
{
	char	*area;

	area = NULL;
	caps->clear = tgetstr("cl", &area);
	caps->standout = tgetstr("so", &area);
	caps->standout_end = tgetstr("se", &area);
	caps->c_del_n = tgetstr("ec", &area);
	return (caps->clear && caps->standout && caps->standout_end
	&& caps->c_del_n);
}

static int	fatal_caps(t_caps *caps)
{
	char	*area;

	area = NULL;
	caps->insert = tgetstr("im", &area);
	caps->insert_end = tgetstr("ei", &area);
	caps->c_del = tgetstr("dc", &area);
	caps->c_del_line = tgetstr("ce", &area);
	caps->c_move = tgetstr("cm", &area);
	caps->c_move_h = tgetstr("ch", &area);
	caps->c_up = tgetstr("up", &area);
	caps->c_down = tgetstr("do", &area);
	caps->c_left = tgetstr("le", &area);
	caps->c_right = tgetstr("nd", &area);
	caps->k_up = tgetstr("ku", &area);
	caps->k_down = tgetstr("kd", &area);
	caps->k_left = tgetstr("kl", &area);
	caps->k_right = tgetstr("kr", &area);
	return (caps->insert && caps->insert_end && caps->c_del && caps->c_del_line
	&& caps->c_move && caps->c_move_h
	&& caps->c_up && caps->c_down && caps->c_left && caps->c_right
	&& caps->k_up && caps->k_down && caps->k_left && caps->k_right);
}

static int	fatal_ios(t_term *t)
{
	t_map	*term_type;
	char	term_buff[MAX_ENTRY];

	if (!(term_type = map_get(t->env, "TERM"))
	|| !map_set(&t->env, "PS1", TERM_PS1)
	|| tgetent(term_buff, term_type->value) <= 0
	|| tcgetattr(0, &t->s_ios) == -1)
		return (0);
	t->s_ios_bkp = t->s_ios;
	t->s_ios.c_lflag &= ~(ICANON | ECHO | ISIG);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &t->s_ios) == -1)
		return (0);
	return (1);
}

int			term_init(t_term *t, const char **envp,
	int (*exec)(const char*, t_term*))
{
	t->pid = 0;
	t->cursor = (t_cursor){.origin={.x=0, .y=0}, .pos={.x=0, .y=0}};
	t->select = (t_selection){.start.x=-1U, .end.x=-1U};
	t->clip = (t_line){.data=NULL, .length=0, .size=0, .prev=NULL, .next=NULL};
	t->exec = exec;
	t->st = 0;
	if (!(t->line = line_new(10))
	|| !(t->env = map_load(envp)))
		return (0);
	t->hist.last = NULL;
	t->line->prev = t->hist.last;
	*t->line->data = '\0';
	t->line->length = 0;
	t->hist.curr = t->line;
	t->hist.next = t->line;
	if (!fatal_ios(t) || !fatal_caps(&t->caps))
	{
		tcsetattr(0, 0, &t->s_ios_bkp);
		return (0);
	}
	optional_caps(&t->caps);
	return (1);
}

int			term_destroy(t_term *t)
{
	hist_clear(&t->hist);
	map_clr(&t->env);
	line_clear(&t->line);
	clip_clear(&t->clip);
	free(t->name);
	if (tcsetattr(0, 0, &t->s_ios_bkp) == -1)
		return (-1);
	return (0);
}
