/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:29:17 by chamada           #+#    #+#             */
/*   Updated: 2020/11/04 17:53:03 by chamada          ###   ########.fr       */
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
	select_clear(&t->caps, &t->cursor, &t->clip.select, t->line);
	*t->line->data = '\0';
	t->line->length = 0;
	return (TERM_NEWLINE | TERM_READING);
}

void		term_stop(t_term *t)
{
	if (t->pid != 0)
		kill(t->pid, SIGSTOP);
}

int			term_next_line(t_term *t, int status)
{
	tputs(t->caps.insert_end, 0, &ft_putchar);
	write(1, "\n", 1);
	t->st = t->exec(t->lex_st.tokens, t); // TODO: t->st = ...
	token_clr(&t->lex_st.tokens);
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
	ft_dprintf(2, "%s: syntax error near unexpected token `%s'\n",
		t->name, t->lex_st.input);
	t->st = 258;
	lex_reset(&t->lex_st);
	*t->line->data = '\0';
	t->line->length = 0;
	t->cursor.pos.x = 0;
	t->cursor.pos.y = 0;
}

int			term_new_line(t_term *t, int status)
{
	t_lex_err	lex_err;

	cursor_end_line(&t->caps, &t->cursor, t->line);
	select_clear(&t->caps, &t->cursor, &t->clip.select, t->line);
	if (!(status & TERM_WAITING))
		t->lex_st.input = t->line->data;
	if ((lex_err = lexer_tokenize(&t->lex_st)) == LEX_EOK)
		status = term_next_line(t, status & ~TERM_WAITING);
	else if (lex_err & LEX_EWAIT)
	{
		term_write(&t->cursor, t->line, "\n", 1);
		status |= TERM_WAITING;
	}
	else
		term_lex_error(t);
	if (status & TERM_READING)
		term_write_prompt(&t->cursor, status);
	return (status & ~TERM_NEWLINE);
}

int			term_erase(t_term *t, int status)
{
	if (t->cursor.pos.x > 0)
	{
		tputs(t->caps.c_left, 0, &ft_putchar);
		tputs(t->caps.c_del, 0, &ft_putchar);
		t->cursor.pos.x--;
		line_erase_at(t->line, t->cursor.pos.x, 1);
	}
	return (status);
}
