#include <term/token.h>

size_t		token_len(t_tok *tokens)
{
	size_t	length;

	length = 0;
	while (tokens)
	{
		length++;
		tokens = tokens->next;
	}
	return (length);
}

char *const	*token_export(t_tok *tokens)
{
	char		**av;
	t_tok		*next;
	size_t		i;

	if (!(av = malloc(sizeof(*av) * (token_len(tokens) + 1))))
	{
		token_clr(&tokens);
		return (NULL);
	}
	i = 0;
	while (tokens)
	{
		next = tokens->next;
		av[i++] = tokens->data;
		free(tokens);
	}
	av[i] = NULL;
	return (av);
}
