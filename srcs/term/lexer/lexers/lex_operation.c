#include <term/lexer.h>

t_lex_err	lex_operation(t_lex_st *st)
{
	static const t_lex_fun	lexers[] = {&lex_cmd, &lex_op, &lex_cmd_line};
	t_lex_err				status;
	t_tok_t					i;
	t_lex_st				operation_st;

	operation_st = (t_lex_st){.tokens = NULL, .wait = st->wait,
		.subshell_level = st->subshell_level};
	status = LEX_EOK;
	operation_st.input = st->input,
	i = 0;
	lex_ifs(st);
	while (i < sizeof(lexers) / sizeof(*lexers)
	&& (status = lexers[i](&operation_st)) == LEX_EOK)
		i++;
	ft_dprintf(2, "[OPER] input: %s, status: %d\n", st->input, status);
	if (status == LEX_EOK)
	{
		st->input = operation_st.input;
		token_add_back(&st->tokens, operation_st.tokens);
		st->wait = operation_st.wait;
		return (LEX_EOK);
	}
	else
		token_clr(&operation_st.tokens);
	return (status);
}
