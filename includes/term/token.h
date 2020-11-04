#ifndef TOKEN_H
# define TOKEN_H

# include <stdint.h>
# include <stdlib.h>

# include <libft.h>

typedef uint16_t	t_tok_t;

typedef struct		s_tok
{
	t_tok_t			type;
	void			*data;
	struct	s_tok	*next;
}					t_tok;

t_tok		*token_new(void *data, t_tok_t type);

void		token_add_back(t_tok **tokens, t_tok *token);
void		token_add_front(t_tok **tokens, t_tok *token);

void		token_sort(t_tok **lst, int (*cmp)(t_tok_t, t_tok_t));

void		token_clr(t_tok **tokens);

void		tokens_print(t_tok *tokens);

#endif
