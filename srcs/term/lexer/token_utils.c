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
