#include <term/lexer.h>

t_lex_err	lex_scope(t_lex_st *st)
{
	t_tok		*token;
	t_tok_t		type;

	ft_dprintf(2, "Scope: Parsing '%s'...\n", st->input);
	if ((type = lexer_type(*st->input)) & SCOPE_IN)
	{
		st->input++;
		st->subshell_level++;
		st->wait |= SCOPE_OUT;
	}
	else if (type & SCOPE_OUT && st->subshell_level != 0)
	{
		st->input++;
		st->subshell_level--;
		if (st->subshell_level == 0)
			st->wait &= ~SCOPE_OUT;
	}
	else
		return (LEX_ETYPE);
	ft_dprintf(2, "Scope %s! depth: %d\n",
		type & SCOPE_IN ? "in" : "out", st->subshell_level);
	if ((token = token_new(NULL, type)))
		token_add_back(&st->tokens, token);
	else
		return (LEX_EALLOC);
	return (LEX_EOK); // TODO: Maybe EWAIT
}
