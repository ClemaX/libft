#include <term/lexer.h>

static int	cmd_token_cmp(t_tok_t a, t_tok_t b)
{
	if (a & TOK_INLN_MASK && b & TOK_PARAM)
		return (1);
	if (b & TOK_INLN_MASK && a & TOK_PARAM)
		return (-1);
	return (0);
}

t_lex_err	lex_cmd(t_lex_st *st)
{
	static const t_lex_fun	lexers[] = {&lex_inline, &lex_param};
	t_lex_err				status;
	t_lex_st				cmd_st;
	t_tok_t					i;

	cmd_st = (t_lex_st){.tokens = NULL, .wait = st->wait,\
		.subshell_level = st->subshell_level};
	status = LEX_EOK;
	while (status == LEX_EOK && lex_ifs(st)) // TODO: Maybe EWAITs
	{
		cmd_st.input = st->input;
		i = 0;
		while (i < sizeof(lexers) / sizeof(*lexers)
		&& (status = lexers[i](&cmd_st)) == LEX_ETYPE)
			i++;
		ft_dprintf(2, "[CMD] input: %s, status: %d\n", st->input, status);
		if (status == LEX_EOK)
			st->input = cmd_st.input;
	}
	if (cmd_st.tokens)
	{
		token_sort(&cmd_st.tokens, &cmd_token_cmp);
		token_add_back(&st->tokens, cmd_st.tokens);
		st->wait = cmd_st.wait & ~TOK_CMD;
		return (LEX_EOK);
	}
//	ft_dprintf(2, "input: %s, status: %d\n", st->input, status);
	return (status);
}
