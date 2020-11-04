#include <term/lexer.h>

t_lex_err		lex_sep(t_lex_st *st)
{
	t_tok		*token;
	t_lex_err	status;

	status = LEX_ETYPE;
	while (lexer_type(*st->input) == SEP_SEMICOL)
	{
		st->input++;
		status = LEX_EOK;
	}
	if ((token = token_new(NULL, SEP_SEMICOL)))
		token_add_back(&st->tokens, token);
	else
		status = LEX_EALLOC;
	return (status);
}
