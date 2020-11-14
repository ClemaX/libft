#include <term/lexer.h>

/*
** SEP
** Semicolon or new-line
**
** ';' | '\n'
*/
static t_lex_err	lex_sep(t_lex_st *st)
{
	t_tok		*sep;

//	ft_dprintf(2, "[LEX][  SEP] Input: '%s'\n", st->input);
	if (*st->input == '\0')
		return (LEX_EEND);
	if (*st->input == ';' || *st->input == '\n')
	{
		st->wait &= ~TOK_SEP;
		st->input++;
		if (!(sep = token_new(NULL, TOK_SEP)))
			return (LEX_EALLOC);
		token_add_back(&st->tokens, sep);
		return (LEX_EOK);
	}
	else
		return (LEX_ENOMATCH);
}

/*
** TOKEN
** Command followed by multiple operations
**
** CMD (IFS OPERATION)*
*/
static t_lex_err	lex_token(t_lex_st *st)
{
	t_lex_err	status;

//	ft_dprintf(2, "[LEX][TOKEN] Input: '%s'\n", st->input);
	if ((status = lex_cmd(st)) == LEX_EOK)
	{
		while ((status = lex_ifs(st)) == LEX_EOK
		&& (status = lex_operation(st)) == LEX_EOK)
			;
		if (status == LEX_ENOMATCH)
			status = LEX_EOK;
	}
	return (status);
}

/*
** TOKENS
** TOKENs separated by SEP.
**
** ( IFS TOKEN IFS SEP )*
*/
t_lex_err			lex_tokens(t_lex_st *st)
{
	t_lex_err	status;

	/* if (st->wait & TOK_CMD && (status = lex_cmd(st)) != LEX_EOK)
		return (status); */

	while ((status = lex_ifs(st)) == LEX_EOK
	&& (status = lex_token(st)) == LEX_EOK
	&& (status = lex_ifs(st)) == LEX_EOK
	&& (status = lex_sep(st)) == LEX_EOK)
		;
	/* ft_dprintf(2, "[LEX][TOKNS] Status: %d, Wait: %d, Subsh-lvl: %d\n",
		status, st->wait, st->subshell_level); */
	if (status == LEX_ENOMATCH)
		return (LEX_ESYNTAX);
	if (status == LEX_EEND && st->subshell_level == 0)
		return (LEX_EOK);
	return (status);
}
