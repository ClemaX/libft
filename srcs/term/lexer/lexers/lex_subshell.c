#include <term/lexer.h>

/*
** SCOPE_IN
** Opening parenthesis.
**
** '('
*/
static t_lex_err	lex_scope_in(t_lex_st *st)
{
	t_tok	*scope_in;

	if (*st->input == '(')
	{
//		ft_dprintf(2, "[LEX][SCOPE][ IN] Input: '%s'\n", st->input);
//		ft_dprintf(2, "[LEX][SCOPE][ IN] MATCH!\n");
		st->input++;
		st->wait |= TOK_SCOPE_OUT;
		st->subshell_level++;
		if (!(scope_in = token_new(NULL, TOK_SCOPE_IN)))
			return (LEX_EALLOC);
		token_add_back(&st->tokens, scope_in);
		return (LEX_EOK);
	}
	return (LEX_ENOMATCH);
}

/*
** SCOPE_OUT
** Closing parenthesis.
**
** ')'
*/
static t_lex_err	lex_scope_out(t_lex_st *st)
{
	t_tok	*scope_out;

//	ft_dprintf(2, "[LEX][SCOPE][OUT] Input: '%s'\n", st->input);
	if (*st->input == ')')
	{
//		ft_dprintf(2, "[LEX][SCOPE][OUT] MATCH!\n");
		if (st->subshell_level == 0)
			return (LEX_ESYNTAX);
		st->wait &= ~TOK_SEP;
		st->input++;
		st->subshell_level--;
		if (st->subshell_level == 0)
			st->wait &= ~TOK_SCOPE_OUT;
		if (!(scope_out = token_new(NULL, TOK_SCOPE_OUT)))
			return (LEX_EALLOC);
		token_add_back(&st->tokens, scope_out);
		return (LEX_EOK);
	}
	return (LEX_ENOMATCH);
}

/*
** SUBSHELL
** TOKENS wrapped in parenthesis.
**
** SCOPE_IN TOKENS SCOPE_OUT
*/
t_lex_err	lex_subshell(t_lex_st *st)
{
	t_lex_err	status;

//	ft_dprintf(2, "[LEX][SUBSH] Input: '%s'\n", st->input);
	// TODO: Fix scope resume
	if ((status = lex_scope_in(st)) == LEX_EOK)
	{
//		ft_dprintf(2, "[LEX][SUBSH][ IN] Status: %d, Wait: '%d'\n", status, st->wait);
		if ((status = lex_tokens(st)) == LEX_EOK
		|| (status == LEX_EWAIT && st->wait & (TOK_SCOPE_OUT | TOK_SEP)))
		{
			status = lex_scope_out(st);
//			ft_dprintf(2, "[LEX][SUBSH][OUT] Status: %d Wait: '%d'\n", status, st->wait);
		}
//		ft_dprintf(2, "[LEX][SUBSH][END] Status '%d'\n", status);
	}
	return (status);
}
