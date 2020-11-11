#include <term/lexer.h>

/*
** PARAM_SIMPLE
** chars that aren't special
**
** ( char - [">|&;'\"\\"] )*
*/
static t_lex_err	lex_param_simple(t_lex_st *st, t_tok_t type)
{
	t_tok	*node;
	char	*data;
	size_t	size;

	// calc the
	size = 0;
	// skip spaces
	ft_dprintf(2, "[LEX][PARAM][SIMPLE] Input: '%s'\n", st->input);
	while (st->input[size] && !is_special(st->input[size]))
		size++;
	if (!size)
		return (LEX_ENOMATCH);
	size++;
	if (!(data = malloc(sizeof(*data) * (size))))
		return (LEX_EALLOC);
	// get the data
	ft_strlcpy(data, st->input, size);

	// allocate new node param
	if (!(node = token_new(data, TOK_PARAM | type))) // type no quotes
		return (LEX_EALLOC);

	// add back to data of the current token cmd
	token_add_back(&st->tokens, node);

	// skip the param
	st->input += size - 1;
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

	status = LEX_EOK;
	success = false;
	while (status == LEX_EOK)
	{
		if ((status = lex_param_quoted(st, type)) == LEX_ENOMATCH)
			status = lex_param_simple(st, type); // allocates a param and set no flag
		if (!success && status == LEX_EOK)
			success = true;
	}
	return ((success && status == LEX_ENOMATCH) ? LEX_EOK : status);
}
