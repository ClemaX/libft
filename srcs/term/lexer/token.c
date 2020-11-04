#include <term/token.h>

t_tok		*token_new(void *data, t_tok_t type)
{
	t_tok	*token;

	if (!(token = malloc(sizeof(*token))))
		return (NULL);
	token->next = NULL;
	token->data = data;
	token->type = type;
	return (token);
}

void		token_add_back(t_tok **tokens, t_tok *token)
{
	t_tok	*current;

	if (token)
	{
		if (*tokens)
		{
			current = *tokens;
			while (current->next)
				current = current->next;
			current->next = token;
		}
		else
			*tokens = token;
	}
}

void		token_add_front(t_tok **tokens, t_tok *token)
{
	token->next = *tokens;
	*tokens = token;
}

void		token_clr(t_tok **tokens)
{
	t_tok	*current;

	while ((current = *tokens))
	{
		*tokens = current->next;
		free(current->data);
		free(current);
	}
}
