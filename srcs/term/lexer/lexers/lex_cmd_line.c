#include <term/lexer.h>

t_lex_err	lex_cmd_line(t_lex_st *st)
{
	static const t_lex_fun	lexers[] = {&lex_scope, &lex_operation, &lex_cmd, \
		&lex_sep, &lex_scope};
	t_lex_err				status;
	t_tok_t					i;

	status = LEX_EOK;
	while (status == LEX_EOK && lex_ifs(st))
	{
		i = 0;
		while (i < sizeof(lexers) / sizeof(*lexers)
		&& (status = lexers[i](st)) == LEX_ETYPE)
			i++;
		ft_dprintf(2, "[LINE] input: %s, status: %d\n", st->input, status);
	}
	return ((status == LEX_EOK && st->wait) ? LEX_EWAIT : status);
}
