#include <term/lexer.h>

char		lex_ifs(t_lex_st *st)
{
	while (ft_isspace(*st->input))
		st->input++;
	return (*st->input);
}

t_tok_t		lexer_type(char input)
{
	int		pos;
	t_tok_t	type;

	type = TOK_NONE;
	if (input && (pos = ft_strpos(LEX_SPECIAL, input)) != -1)
		type = 1 << pos;
//	ft_dprintf(2, "Type of %c: %u\n", input, type);
	return (type);
}

/* t_lex_err	token_expand(char **expanded, const char *source)
{
	
} */

/*
** Expand a command line's parameters.
**
** av will point to a NULL-terminated string array which contains each word.
**
** tokens will point to the current separator or NULL if there are no tokens
** left.
**
** returns LEX_EOK in case of success, or an error code otherwise.
*/
/* t_lex_err	tokens_expand(char ***av, t_tok **tokens)
{
	t_tok	*current;
	current = tokens;


	while (current)
	{
		if (current->type & TOK_CMD)
		{
			
		}
		current = current->next;
	}
	tokens_print(current);
	return (LEX_EOK);
}
 */
void		lexer_perror(const char *input)
{
	static const char	*new_line = "newline";
	if (!*input || *input == '\n')
		input = new_line;
	ft_dprintf(2, "minish: syntax error near unexpected token `%s'\n", input);
}

void		av_print(char *const *av)
{
	int	ac;

	ac = 0;
	while (av[ac])
	{
		ft_dprintf(2, "'%s'", av[ac]);
		ac++;
	}
	ft_dprintf(2, "ac: %d\n", ac);
}

t_lex_err	lexer_tokenize(t_lex_st *st)
{
	t_lex_err	status;
//	char		**av;

	if ((status = lex_cmd_line(st)) == LEX_ETYPE)
		lexer_perror(st->input);
	if (status == LEX_EOK)
	{
		//lexer_expand(&av, &st->tokens);

	}
	ft_dprintf(2, "[LEX] status: %d\n", status);
	return (status);
}
