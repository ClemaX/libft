#include <term/lexer.h>

t_lex_err	lex_cmd(t_lex_st *st)
{
	t_lex_err	status;
	t_lex_st	cmd_st;
	t_lex_st	inline_st;
	t_tok		*cmd_token;

	cmd_st = (t_lex_st){.tokens = NULL, .wait = st->wait,\
		.subshell_level = st->subshell_level};
	inline_st = (t_lex_st){.tokens = NULL, .wait = st->wait,\
		.subshell_level = st->subshell_level};
	status = LEX_EOK;
	cmd_token = NULL;
	while (status == LEX_EOK && lex_ifs(st)) // TODO: Maybe EWAITs
	{
		inline_st.input = st->input;
		if ((status = lex_inline(&inline_st)) == LEX_EOK)
			st->input = inline_st.input;
		else if (status != LEX_ETYPE)
			return (status);
		cmd_st.input = st->input;
		if ((status = lex_param(&cmd_st)) == LEX_EOK)
			st->input = cmd_st.input;
		else if (status != LEX_ETYPE)
			return (status);
	}
	if (cmd_st.tokens && !(cmd_token = token_new(cmd_st.tokens, TOK_CMD)))
		return (LEX_EALLOC);
	token_add_back(&st->tokens, cmd_token);
	token_add_back(&st->tokens, inline_st.tokens);
//	ft_dprintf(2, "input: %s, status: %d\n", st->input, status);
	return (cmd_token || inline_st.tokens ? LEX_EOK : LEX_ETYPE);
}
