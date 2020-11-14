#include <term/lexer.h>

/*
** CMD_SIMPLE
** PARAMs or INLINEs separated by IFS
**
** ( IFS ( PARAM | INLINE ) ) *
** TODO: Handle st->wait
*/
static t_lex_err	lex_cmd_simple(t_lex_st *st)
{
	t_lex_err		status;
	t_lex_st		cmd_st;
	t_tok			*cmd;

//	ft_dprintf(2, "[LEX][  CMD][SIMPLE] Input: '%s'\n", st->input);
	cmd_st = *st;
	if (!(cmd = token_new(NULL, TOK_CMD)))
		return (LEX_EALLOC);
	cmd->next = NULL;
	cmd->data = NULL;
	status = LEX_EOK;
	while (status == LEX_EOK && (status = lex_ifs(&cmd_st)) == LEX_EOK)
	{
		cmd_st.tokens = cmd;
		if ((status = lex_inline(&cmd_st)) == LEX_ENOMATCH) // handles redir tokens and increments input
		{
			cmd_st.tokens = cmd->data;
//			ft_dprintf(2, "[LEX][  CMD][SIMPLE][INLINE] Status: '%d'\n", status);
			status = lex_param(&cmd_st, TOK_PARAM); //handles tokens params (into the cmd token) cmd and incremenst input
//			ft_dprintf(2, "[LEX][  CMD][SIMPLE][ PARAM] Status: '%d'\n", status);
			cmd->data = cmd_st.tokens;
		}
	}
	cmd_st.tokens = cmd; // TODO: Cleanup duplicate pointers
	st->input = cmd_st.input;
	st->wait = cmd_st.wait; // TODO: | (status == LEX_EWAIT) ? TOK_CMD : TOK_NONE
	if ((!cmd->data && !cmd->next))
	{
		free(cmd);
		return (status);
	}
	// TODO: Cleanup error handling
	token_add_back(&st->tokens, cmd_st.tokens);
	return (status == LEX_ENOMATCH ? LEX_EOK : status);
}

/*
** OPERATOR
** PIPE, OR or AND operator
**
** "|" | "||" | "&&"
*/
static t_lex_err	lex_operator(t_lex_st *st)
{
	t_tok_t		type;
	t_tok		*operator;

//	ft_dprintf(2, "[LEX][  CMD][ OP] Input: '%s'\n", st->input);
	if (*st->input == '|')
	{
//		ft_dprintf(2, "[LEX][  CMD][ OP][PIPE] MATCH!\n");
		st->input++;
		if (*st->input == '|')
		{
//			ft_dprintf(2, "[LEX][  CMD][ OP][  OR] MATCH!\n");
			type = OP_OR;
			st->input++;
		}
		else
			type = OP_PIPE;
	}
	else if (!ft_strncmp(st->input, "&&", 2))
	{
//		ft_dprintf(2, "[LEX][  CMD][ OP][ AND] MATCH!\n");
		type = OP_AND;
		st->input += 2;
	}
	else
	{
//		ft_dprintf(2, "[LEX][  CMD][ OP] NOMATCH!\n");
		return (LEX_ENOMATCH);
	}
	if (!(operator = token_new(NULL, type)))
		return (LEX_EALLOC);
	token_add_back(&st->tokens, operator);
	return (LEX_EOK);
}

/*
** CMD
** SUBSHELL or CMD_SIMPLE
**
** SUBSHELL | CMD_SIMPLE
*/
t_lex_err			lex_cmd(t_lex_st *st)
{
	t_lex_err	status;

/* 	if (st->wait & TOK_SCOPE_OUT)
		return (lex_subshell(st));
	if (st->wait & TOK_CMD)
		return (lex_cmd_simple(st)); */

//	ft_dprintf(2, "[LEX][  CMD] Input: '%s'!\n", st->input);
	if ((status = lex_subshell(st)) == LEX_ENOMATCH)
		status = lex_cmd_simple(st);
	return (status);
}

/*
** OPERATION
** OPERATOR followed by IFS and CMD
**
** OPERATOR IFS CMD
*/
t_lex_err			lex_operation(t_lex_st *st)
{
	t_lex_err	status;

//	ft_dprintf(2, "[LEX][   OP] Input: '%s'\n", st->input);
	if ((status = lex_operator(st)) == LEX_EOK
	&& (status = lex_ifs(st)) == LEX_EOK)
		status = lex_cmd(st);
	return (status);
}
