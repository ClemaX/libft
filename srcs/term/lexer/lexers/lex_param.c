#include <term/lexer.h>

static bool	is_param(char c)
{
	return (c && !ft_isspace(c) && !lexer_type(c));
}

t_lex_err	lex_param_data(char **data, const char **input)
{
	const char	*start;

	start = *input;
	while (is_param(**input))
		(*input)++;
	if (start == *input)
		return (LEX_ETYPE);
	return ((*data = ft_strndup(start, *input - start)) ? LEX_EOK : LEX_EALLOC);
}

t_lex_err	lex_param(t_lex_st *st)
{
	t_lex_err	status;
	t_tok		*token;
	char		*data;

	status = lex_param_data(&data, &st->input);
	if (status == LEX_EOK)
	{
		token = token_new(data, TOK_PARAM);
		if (token)
			token_add_back(&st->tokens, token);
		else
		{
			free(data);
			status = LEX_EALLOC;
		}
	}
	return (status);
}
