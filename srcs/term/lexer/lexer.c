#include <term/lexer.h>

char		lex_ifs(t_lex_st *st)
{
	while (ft_isspace(*st->input))
		st->input++;
	return (*st->input);
}

t_tok_t		lexer_type(char input)
{
	int		pos;
	t_tok_t	type;

	type = TOK_NONE;
	if (input && (pos = ft_strpos(LEX_SPECIAL, input)) != -1)
		type = 1 << pos;
//	ft_dprintf(2, "Type of %c: %u\n", input, type);
	return (type);
}

t_lex_err	lexer_expand(t_lex_st *st)
{
	t_tok	*current;

	current = st->tokens;
	tokens_print(current);
	return (LEX_EOK);
}

void		lexer_perror(const char *input)
{
	static const char	*new_line = "newline";
	if (!*input || *input == '\n')
		input = new_line;
	ft_dprintf(2, "minish: syntax error near unexpected token `%s'\n", input);
}

t_lex_err	lexer_tokenize(t_lex_st *st)
{
	t_lex_err	status;

	if ((status = lex_cmd_line(st)) == LEX_ETYPE)
		lexer_perror(st->input);
	if (status == LEX_EOK)
		lexer_expand(st);
	ft_dprintf(2, "[LEX] status: %d\n", status);
	return (status);
}
