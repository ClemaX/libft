#include <term/lexer.h>

static t_tok_t	inline_op_type(const char **input)
{
	t_tok_t	type;

	if ((type = lexer_type(**input) & TOK_INLN_MASK))
	{
		(*input)++;
		if (type & OP_REDIR_WR && lexer_type(**input) == OP_REDIR_WR)
		{
			(*input)++;
			type = OP_REDIR_WA;
		}
		else if (type & OP_REDIR_RD && lexer_type(**input) == OP_REDIR_RD)
		{
			(*input)++;
			type = OP_HEREDOC;
		}
	}
//	ft_dprintf(2, "Inline: %c: %d\n", (*input)[-1], type);
	return (type);
}

t_lex_err		lex_inline_op(t_lex_st *st)
{
	t_lex_err	status;
	t_tok_t		type;
	t_tok		*token;
	char		*data;

	status = LEX_ETYPE;
	if ((type = inline_op_type(&st->input))
	&& lex_ifs(st) && (status = lex_param_data(&data, &st->input)) == LEX_EOK)
	{
		if ((token = token_new(data, type)))
			token_add_back(&st->tokens, token);
		else
			status = LEX_EALLOC;
	}
//	ft_dprintf(2, "inline data: %s\n", data);
	return (status);
}

t_lex_err		lex_inline(t_lex_st *st)
{
	t_lex_err				status;
	static const t_lex_fun	lexers[] = {&lex_inline_op};
	t_lex_st				inline_st;
	t_tok_t					i;

	status = LEX_EOK;
	inline_st = (t_lex_st){.tokens = NULL, .wait = st->wait,\
		.subshell_level = st->subshell_level};
	while (status == LEX_EOK && lex_ifs(st))
	{
		inline_st.input = st->input;
		i = 0;
		while (i < sizeof(lexers) / sizeof(*lexers)
		&& (status = lexers[i](&inline_st)) == LEX_ETYPE)
			i++;
		if (status == LEX_EOK)
			st->input = inline_st.input;
	}
	if (inline_st.tokens)
	{
		token_add_back(&st->tokens, inline_st.tokens);
		st->wait = inline_st.wait;
		return (LEX_EOK);
	}
//	ft_dprintf(2, "[inline]input: %s, status: %d\n", st->input, status);
	return (status);
}
