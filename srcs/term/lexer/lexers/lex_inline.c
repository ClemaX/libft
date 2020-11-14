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

	type = TOK_NONE;
	if (*st->input == '>')
	{
		st->input++;
		if (*st->input == '>')
		{
			type = OP_REDIR_WA;
			st->input++;
		}
		else
			type = OP_REDIR_WR;
	}
	else if (*st->input == '<')
	{
		type = OP_REDIR_RD;
		st->input++;
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
	t_lex_st		param_st;
	t_lex_err		status;
	t_tok			*redir;

//	ft_dprintf(2, "[LEX][  CMD][INLINE][ REDIR] Input: '%s'\n", st->input);
	if (type == TOK_NONE)
		return (LEX_ENOMATCH);
	param_st = *st;
	param_st.tokens = NULL;
	if (lex_ifs(&param_st) != LEX_EOK
	|| (status = lex_param(&param_st, TOK_PARAM)) == LEX_ENOMATCH)
		return (LEX_ESYNTAX);
	if (status == LEX_EOK)
	{
		if (!(redir = token_new(param_st.tokens, type)))
		{
			token_clr(&param_st.tokens);
			return (LEX_EALLOC);
		}
		token_add_back(&st->tokens, redir);
		st->input = param_st.input;
		st->wait = param_st.wait;
	}
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
//	ft_dprintf(2, "[LEX][  CMD][INLINE][HEREDOC] Input: '%s'\n", st->input);
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

	if ((status = lex_redir(st)) == LEX_ENOMATCH) // alocates a token redir
		status = lex_heredoc(st); // alocates a token heredoc
	return (status);
}
