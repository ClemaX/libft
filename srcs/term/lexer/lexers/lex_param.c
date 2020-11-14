#include <term/lexer.h>

/*
** PARAM_SIMPLE
** chars that aren't special
**
** ( char - [">|&;'\"\\"] )*
*/
static t_lex_err	lex_param_simple(t_lex_st *st, t_tok_t type)
{
	t_tok		*param;
	const char	*start;

	start = st->input;
//	ft_dprintf(2, "[LEX][PARAM][SIMPLE] Input: '%s'\n", st->input);
	while (*st->input && !is_special(*st->input))
		st->input++;
	if (st->input == start)
		return (LEX_ENOMATCH);
	if (!(param = token_strndup(start, st->input - start, TOK_SIMPLE | type))) // type no quotes
		return (LEX_EALLOC);
	token_add_back(&st->tokens, param);
	return (LEX_EOK);
}

/*
** PARAM
** Multiple PARAM_QUOTEDs or PARAM_SIMPLEs.
**
** (PARAM_QUOTED | PARAM_SIMPLE)+
*/
t_lex_err		lex_param(t_lex_st *st, t_tok_t type) // handles multiple params in a cmd token (cmd.data)
{
	t_lex_err	status;
	bool		success;
	t_lex_st	param_st;
	t_tok		*param;

	param_st = *st;
	param_st.tokens = NULL;
	status = LEX_EOK;
	success = false;
	while (status == LEX_EOK)
	{
		if ((status = lex_param_quoted(&param_st, type)) == LEX_ENOMATCH)
			status = lex_param_simple(&param_st, type); // allocates a param and set no flag
		if (!success && status == LEX_EOK)
			success = true;
	}
	if (success && status == LEX_ENOMATCH)
	{
		if (!(param = token_new(param_st.tokens, type)))
		{
			token_clr(&param_st.tokens);
			return (LEX_EALLOC);
		}
		token_add_back(&st->tokens, param);
		st->input = param_st.input;
		st->wait = param_st.wait;
		return (LEX_EOK);
	}
	return (status);
}
