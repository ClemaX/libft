#include <term/lexer.h>

t_tok		*token_str(const char *str, size_t length, t_tok_t type)
{
	t_tok	*token;

	if (!(token = malloc(sizeof(*token))))
		return (NULL);
	if (!(token->data = ft_strndup(str, length)))
	{
		free(token);
		return (NULL);
	}
	token->next = NULL;
	token->type = type;
	return (token);
}

const char	*token_name(t_tok_t type)
{
	static const char *names[] = {
		"<",
		"<<",
		">",
		">>",
		"|",
		"||",
		"&&",
		";",
		"(",
		")",
		NULL
	};
	t_tok_t	i;

	i = 0;
	while (type >>= 1)
		i++;
	return (names[i]);
}

void		tokens_print(t_tok *tokens)
{
	while (tokens)
	{
		//ft_dprintf(2, "[%4u]", tokens->type);
		if (tokens->type & TOK_PARAM)
			ft_dprintf(2, "%s", tokens->data);
		else if (tokens->type & TOK_INLN_MASK)
			ft_dprintf(2, "%s %s", token_name(tokens->type), tokens->data);
		else
			ft_dprintf(2, "%s", token_name(tokens->type));
		if ((tokens = tokens->next))
			ft_dprintf(2, " ");
		else
			ft_dprintf(2, "\n");
	}
}
