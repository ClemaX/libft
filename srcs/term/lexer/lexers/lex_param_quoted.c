#include <term/lexer.h>

/*
** PARAM_SQUOTED
** chars preceded by backslash or chars wrapped in single quotes, escaped by
** backslash.
**
** '\'' ( char - \' )* '\''
*/
t_lex_err		lex_param_squoted(t_lex_st *st, t_tok_t type)
{
	t_tok		*param;
	const char	*start;

//	ft_dprintf(2, "[LEX][PARAM][SQUOTE] Input: '%s'\n", st->input);
	if (!(st->wait & TOK_SQUOTED))
	{
		if (*st->input != '\'')
			return (LEX_ENOMATCH);
		st->input++;
		st->wait |= TOK_SQUOTED;
	}
	start = st->input;
	while (*st->input != '\0' && *st->input != '\'')
		st->input++;
	if (start == st->input || *st->input != '\'')
		return (LEX_EWAIT);
	if (!(param = token_strndup(start, st->input - start, TOK_SQUOTED | type)))
		return (LEX_EALLOC);
	token_add_back(&st->tokens, param);
	st->input++;
	st->wait &= ~TOK_SQUOTED;
	return (LEX_EOK);
}

/*
** PARAM_DQUOTED
** chars wrapped in double quotes, escaped by backslash.
**
** '"' ( ( char - ["\"\\"] ) | ( '\\' ["\"\\"] ) )* '"'
*/
t_lex_err		lex_param_dquoted(t_lex_st *st, t_tok_t type)
{
	t_tok		*param;
	const char	*start;

	if (!(st->wait & TOK_DQUOTED))
	{
		if (*st->input != '"')
			return (LEX_ENOMATCH);
//		ft_dprintf(2, "[LEX][PARAM][DQUOTE] Input: '%s'\n", st->input);
		st->input++;
		st->wait |= TOK_DQUOTED;
	}
	start = st->input;
	while (*st->input != '\0' && *st->input != '"')
	{
		st->input++;
		if (*st->input == '\\')
		{
			if (st->input != start && !(param = token_strndup(start,
				st->input - start, TOK_DQUOTED | type)))
				return (LEX_EALLOC);
			token_add_back(&st->tokens, param);
			if (!(param = token_strndup(++st->input, 1, TOK_SQUOTED | type)))
				return (LEX_EALLOC);
			token_add_back(&st->tokens, param);
			start = ++st->input;
		}
	}
	if (*st->input != '"')
		return (LEX_EWAIT);
	if (!(param = token_strndup(start, st->input - start, TOK_DQUOTED | type)))
		return (LEX_EALLOC);
	token_add_back(&st->tokens, param);
	st->input++;
	st->wait &= ~TOK_DQUOTED;
	return (LEX_EOK);
}

/*
** PARAM_QUOTED
** PARAM_SQUOTED or PARAM_DQUOTED.
**
** PARAM_SQUOTED | PARAM_DQUOTED
*/
t_lex_err			lex_param_quoted(t_lex_st *st, t_tok_t type)
{
	t_lex_err	status;

//	ft_dprintf(2, "[LEX][PARAM][QUOTED] Input: '%s'\n", st->input);
	if (st->wait & TOK_SQUOTED
	|| (status = lex_param_dquoted(st, type)) == LEX_ENOMATCH) // allocates a param and set flag DQUOTE + trim dquotes
		status = lex_param_squoted(st, type); // allocates a param and set the flag SQUOTE + trim squotes
	return (status);
}
