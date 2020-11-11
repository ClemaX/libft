#include <term/lexer.h>

/*
** IFS
** Whitespaces
**
** ( ' ' | [\t .. \r] )*
*/
t_lex_err	lex_ifs(t_lex_st *st)
{
	while (ft_isspace(*st->input))
		st->input++;
	// TODO: Check conflicts for ')'
	if (*st->input == '\0' || *st->input == '#' || (st->subshell_level != 0 && *st->input == ')'))
		return (st->wait ? LEX_EWAIT : LEX_EEND);
	return (LEX_EOK);
}
