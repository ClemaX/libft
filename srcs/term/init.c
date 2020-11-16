/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:57:02 by chamada           #+#    #+#             */
/*   Updated: 2020/11/13 08:12:48 by chamada          ###   ########.fr       */
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
	return (caps->enabled = (caps->insert && caps->insert_end && caps->c_del
	&& caps->c_del_line && caps->c_move && caps->c_move_h
	&& caps->c_up && caps->c_down && caps->c_left && caps->c_right
	&& caps->k_up && caps->k_down && caps->k_left && caps->k_right));
}

static int	fatal_ios(t_term *t)
{
	struct stat	input_stat;
	const char	*term_type;
	char		term_buff[MAX_ENTRY];

	if (fstat(STDIN_FILENO, &input_stat)
	|| !(t->interactive = S_ISCHR(input_stat.st_mode))
	|| !env_set(&t->env, "PS1", TERM_PS1, false)
	|| !env_set(&t->env, "PS2", TERM_PS2, false)
	|| !(term_type = env_get(t->env, "TERM", 4))
	|| tgetent(term_buff, term_type) <= 0
	|| tcgetattr(0, &t->s_ios) == -1)
		return (0);
	t->s_ios_bkp = t->s_ios;
	t->s_ios.c_lflag &= ~(ICANON | ECHO | ISIG);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &t->s_ios) == -1)
		return (0);
	return (1);
}

int			term_init(t_term *t, const char **envp,
	int (*exec)(t_tok *tokens, t_term *term))
{
	ft_bzero(t, sizeof(*t));
	t->clip.select = (t_select){.start.x=-1U, .end.x=-1U};
	t->exec = exec;
	if (!(t->line = line_new(10))
	|| !(t->env = env_import(envp))
	|| !(t->session = start_session()))
		return (0);
	t->line->prev = t->hist.last;
	*t->line->data = '\0';
	t->line->len = 0;
	t->hist.curr = t->line;
	t->hist.next = t->line;
	if (fatal_ios(t) && fatal_caps(&t->caps))
		optional_caps(&t->caps);
	return (1);
}

int			term_destroy(t_term *t)
{
	end_session(t->session);
	token_clr(&t->lex_st.tokens);
	hist_clear(&t->hist);
	env_clr(&t->env);
	line_clear(&t->line);
	clip_clear(t);
	free(t->name);
	if (t->caps.enabled)
	{
		if (tcsetattr(0, 0, &t->s_ios_bkp) == -1)
			return (-1);
		tputs(t->caps.insert_end, 0, &ft_putchar);
	}
	return (0);
}
