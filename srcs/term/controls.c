/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:29:17 by chamada           #+#    #+#             */
/*   Updated: 2020/11/13 18:20:10 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term/term.h>

/* static int	parse_line(t_term *t, int status)
{
	size_t	i;

	status &= ~TERM_WAITING;
	i = 0;
	while (i < t->line->length)
	{
		if (status & TERM_B_SLASH)
			status &= ~TERM_B_SLASH;
		else if (!(status & TERM_S_QUOTE) && t->line->data[i] == '"')
			status ^= TERM_D_QUOTE;
		else if (!(status & TERM_D_QUOTE) && t->line->data[i] == '\'')
			status ^= TERM_S_QUOTE;
		else if (!(status & TERM_B_SLASH) && t->line->data[i] == '\\')
			status |= TERM_B_SLASH;
		i++;
	}
	return (status);
} */

int			term_cancel(t_term *t)
{
	if (t->caps.enabled)
		select_clear(t);
	*t->line->data = '\0';
	t->line->len = 0;
	return (TERM_NEWLINE | TERM_READING);
}

void		term_stop(t_term *t)
{
	const pid_t	pid
		= t->session->processes[t->session->processes[MANAGE].pid].pid;

	if (pid != 0)
		kill(pid, SIGSTOP);
}

int			term_next_line(t_term *t, int status)
{
	// TODO: Check if multi-line crashes (lex_ifs.c:11 heap-use-after-free)
	if (t->interactive)
		write(2, "\n", 1);
	if (!t->line->len)
		return (status);
	if (t->interactive)
	{
		if (t->caps.enabled)
		{
			tputs(t->caps.insert_end, 0, &ft_putchar);
			if (tcsetattr(0, 0, &t->s_ios_bkp) == -1)
				return ((status | TERM_ERROR) & ~TERM_READING);
		}
		t->exec(t->lex_st.tokens, t); // TODO: t->st = ...
		if (tcsetattr(0, 0, &t->s_ios) == -1)
			return ((status | TERM_ERROR) & ~TERM_READING);
	}
	else
		t->exec(t->lex_st.tokens, t);
	t->lex_st.tokens = NULL;
	if (t->caps.enabled)
		tputs(t->caps.insert, 0, &ft_putchar);
	if ((!t->hist.next || t->line == t->hist.next)
	&& !(t->hist.next = line_new(10)))
		return ((status | TERM_ERROR) & ~TERM_READING);
	hist_add(&t->hist, t->line);
	t->line = t->hist.next;
	t->cursor.pos.x = 0;
	t->cursor.pos.y = 0;
	return (status);
}

void		lex_reset(t_lex_st *st)
{
	token_clr(&st->tokens);
	st->input = NULL;
	st->wait = TOK_NONE;
	st->subshell_level = 0;
}

void		term_lex_error(t_term *t)
{
	const char	*input;

	if (*t->lex_st.input == '\n' || *t->lex_st.input == '\0')
		input = "newline";
	else
		input = t->lex_st.input;
	ft_dprintf(2, "%s: syntax error near unexpected token `%s'\n",
		t->name, input);
	t->st = 258;
	lex_reset(&t->lex_st);
	*t->line->data = '\0';
	t->line->len = 0;
	t->cursor.pos.x = 0;
	t->cursor.pos.y = 0;
}

int			term_new_line(t_term *t, int status)
{
	t_lex_err	lex_err;

	if (t->caps.enabled)
	{
		cursor_end_line(&t->caps, &t->cursor, t->line);
		select_clear(t);
	}
	if (!(status & TERM_WAITING))
		t->lex_st.input = t->line->data;
	if ((lex_err = lex_tokens(&t->lex_st)) == LEX_EOK)
		status = term_next_line(t, status & ~TERM_WAITING);
	else if (lex_err & LEX_EWAIT)
	{
		term_write(t, "\n", 1);
		status |= TERM_WAITING;
	}
	else
		term_lex_error(t);
	if (status & TERM_READING)
		term_write_prompt(t, status);
	return (status & ~TERM_NEWLINE);
}

int			term_erase(t_term *t, int status)
{
	if (t->cursor.pos.x > 0)
	{
		tputs(t->caps.c_left, 0, &ft_putchar);
		tputs(t->caps.c_del, 0, &ft_putchar);
		t->cursor.pos.x--;
		line_erase(t->line, t->cursor.pos.x, 1);
	}
	return (status);
}
