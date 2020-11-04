#ifndef LEXER_H
# define LEXER_H

# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>

# include <libft.h>
# include <term/env.h>
# include <term/token.h>

/*
** Token types
*/
# define TOK_NONE		0b0000000000000000

/*
** Inline operators
*/
# define OP_REDIR_RD	0b0000000000000001
# define OP_HEREDOC		0b0000000000000010
# define OP_REDIR_WR	0b0000000000000100
# define OP_REDIR_WA	0b0000000000001000

# define TOK_INLN_MASK	0b0000000000001111

/*
** Operators
*/
# define OP_PIPE		0b0000000000010000
# define OP_OR			0b0000000000100000
# define OP_AND			0b0000000001000000

# define TOK_OP_MASK	0b0000000001110000

/*
** Separators
*/
# define SEP_SEMICOL	0b0000000010000000

/*
** Scopes
*/
# define SCOPE_IN		0b0000000100000000
# define SCOPE_OUT		0b0000001000000000

# define TOK_SCOPE_MASK	0b0000001100000000

# define TOK_PARAM		0b0000010000000000

# define TOK_CMD		0b0000100000000000

# define LEX_SPECIAL	"<<>>||&;()"

//# define LEX_TERMINATOR	';'
# define LEX_VAR_SUBST	'$'
# define LEX_VAR_RETVAL	'?'
# define LEX_VAR_ASSIGN	'='

# define LEX_EMPTY		""
# define IFS_DEFAULT	" \t\n"

typedef enum		e_lex_err
{
//	LEX_ESYNT = -3, // TODO: Maybe use on operations and cmds
	LEX_ETYPE = -2,
	LEX_EALLOC = -1,
	LEX_EOK = 0,
	LEX_EWAIT = 1,
}					t_lex_err;

typedef struct		s_lex_st
{
	const char	*input;
	t_tok		*tokens;
	int			subshell_level; // TODO: $BASH_SUBSHELL
	t_tok_t		wait;
}					t_lex_st;

typedef t_lex_err	(*t_lex_fun)(t_lex_st *st);

t_lex_err			lexer_tokenize(t_lex_st *st);

t_tok_t				lexer_type(char input);
t_lex_err			lexer_expand(t_lex_st *st);

/*
** - lex_cmdline
**   - lex_sep
**   - lex_scope
**     - lex_cmd_line
**   - lex_operation
**     - lex_cmd_line
**     - lex_op
**     - lex_cmd_line
**   - lex_cmd
**     - lex_inline
**     - lex_param
*/
t_lex_err			lex_cmd_line(t_lex_st *st);

t_lex_err			lex_scope(t_lex_st *st);

t_lex_err			lex_op(t_lex_st *st);

t_lex_err			lex_sep(t_lex_st *st);
t_lex_err			lex_inline(t_lex_st *st);
t_lex_err			lex_cmd(t_lex_st *st);
t_lex_err			lex_operation(t_lex_st *st);

t_lex_err			lex_param(t_lex_st *st);
t_lex_err			lex_param_data(char **data, const char **input);
char				lex_ifs(t_lex_st *st);

#endif
