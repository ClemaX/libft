#ifndef TOKEN_H
# define TOKEN_H

# include <stdint.h>
# include <stdlib.h>

# include <libft.h>


/*
** Token types
*/
typedef uint16_t	t_tok_t;

# define TOK_NONE		0b0000000000000000

# define TOK_SEP		0b0000000000000001

# define TOK_SCOPE_IN	0b0000000000000010
# define TOK_SCOPE_OUT	0b0000000000000100

# define TOK_MSCOPE		0b0000000000000110

# define TOK_PARAM		0b0000000000001000
# define TOK_SIMPLE		0b0000000000010000
# define TOK_SQUOTED	0b0000000000100000
# define TOK_DQUOTED	0b0000000001000000

# define TOK_MQUOTED	0b0000000001100000

# define TOK_CMD		0b0000000010000000

# define OP_OR			0b0000000100000000
# define OP_AND			0b0000001000000000
# define OP_PIPE		0b0000010000000000

# define OP_M			0b0000011100000000

# define OP_REDIR_WR	0b0000100000000000
# define OP_REDIR_WA	0b0001000000000000
# define OP_REDIR_RD	0b0010000000000000
# define OP_HEREDOC		0b0100000000000000

# define OP_MREDIR		0b0111100000000000

typedef struct		s_tok
{
	t_tok_t			type;
	void			*data;
	struct	s_tok	*next;
}					t_tok;

t_tok		*token_new(void *data, t_tok_t type);
t_tok		*token_strndup(const char *input, size_t n, t_tok_t type);

void		token_add_back(t_tok **tokens, t_tok *token);
void		token_add_front(t_tok **tokens, t_tok *token);

void		token_sort(t_tok **lst, int (*cmp)(t_tok_t, t_tok_t));

size_t		token_len(t_tok *tokens);

void		token_clr(t_tok **tokens);

#endif
