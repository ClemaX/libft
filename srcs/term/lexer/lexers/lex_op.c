#include <term/lexer.h>

t_lex_err		lex_op(t_lex_st *st)
{
	t_tok	*token;
	t_tok_t	type;

	if (!(type = lexer_type(*st->input) & TOK_OP_MASK))
		return (LEX_ETYPE);
	st->input++;
	if (type & OP_PIPE)
	{
		if (lexer_type(*st->input) == OP_PIPE)
		{
			st->input++;
			type = OP_OR;
		}
	}
	if (type & OP_AND)
	{
		if (!(lexer_type(*st->input) & OP_AND))
			return (LEX_ETYPE);
		st->input++;
	}
	st->wait |= TOK_CMD;
	ft_dprintf(2, "op type: %d\n", type);
	if ((token = token_new(NULL, type)))
		token_add_back(&st->tokens, token);
	else
		return (LEX_EALLOC);
	return (LEX_EOK);
}
