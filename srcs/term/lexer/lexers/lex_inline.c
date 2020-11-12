#include <term/lexer.h>

/*
** REDIR_OPERATOR
** Single and double redirection operators
**
** ">" | ">>" | "<"
*/

static t_tok_t	lex_redir_op_type(t_lex_st *st)
{
	t_tok_t		type;

	ft_dprintf(2, "[LEX][  CMD][INLINE][ REDIR][OP] Input: '%s'\n", st->input);
	type = TOK_NONE;
	if (*st->input == '>')
	{
		ft_dprintf(2, "[LEX][  CMD][INLINE][ REDIR][OP][ WR] MATCH!\n");
		st->input++;
		if (*st->input == '>')
		{
			ft_dprintf(2, "[LEX][  CMD][INLINE][ REDIR][OP][ WA] MATCH!\n");
			ft_dprintf(2, "[LEX][  CMD][INLINE][ REDIR][OP][  OR] MATCH!\n");
			type = OP_REDIR_WA;
			st->input++;
		}
		else
			type = OP_REDIR_WR;
	}
	else if (*st->input == '<')
	{
		ft_dprintf(2, "[LEX][  CMD][INLINE][ REDIR][OP][ RD] MATCH!\n");
		type = OP_REDIR_RD;
		st->input++;
	}
	else
	{
		ft_dprintf(2, "[LEX][  CMD][INLINE][ REDIR][OP] NOMATCH!\n");
	}
	return (type);
}

/*
** REDIR
** REDIR_OPERATOR followed by PARAM, separated by IFS
**
** REDIR_OPERATOR IFS PARAM
*/
static t_lex_err	lex_redir(t_lex_st *st)
{
	const t_tok_t	type = lex_redir_op_type(st);
	t_lex_err		status;

	ft_dprintf(2, "[LEX][  CMD][INLINE][ REDIR] Input: '%s'\n", st->input);
	if (type == TOK_NONE)
		return (LEX_ENOMATCH);
	if (lex_ifs(st) != LEX_EOK
	|| (status = lex_param(st, type)) == LEX_ENOMATCH)
		return (LEX_ESYNTAX);
	return (status);
}

/*
** HEREDOC
** HEREDOC_OPERATOR followed by PARAM
**
** "<<" PARAM
*/
static t_lex_err	lex_heredoc(t_lex_st *st)
{
	if (ft_strncmp(st->input, "<<", 2))
		return (LEX_ENOMATCH);
	ft_dprintf(2, "[LEX][  CMD][INLINE][HEREDOC] Input: '%s'\n", st->input);
	return (lex_param(st, OP_HEREDOC));
}

/*
** INLINE
** REDIR or HEREDOC
**
** REDIR | HEREDOC
*/
t_lex_err		lex_inline(t_lex_st *st)
{
	t_lex_err		status;

	ft_dprintf(2, "[LEX][  CMD][INLINE] Input: '%s'\n", st->input);
	if ((status = lex_redir(st)) == LEX_ENOMATCH) // alocates a token redir
		status = lex_heredoc(st); // alocates a token heredoc

	ft_dprintf(2, "[LEX][  CMD][INLINE] Status: %d\n", status);
	return (status);
}
